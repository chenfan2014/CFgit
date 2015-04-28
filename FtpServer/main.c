#include "common.h"
#include "sysutil.h"
#include "session.h"
#include "configure.h"
#include "parse_conf.h"
#include "ftp_assist.h"


int main(int argc, char const *argv[])
{
	check_permission();

	setup_signal_chld();

	parseconf_load_file("ftpserver.conf");
	print_conf();

	init_hash();

	//创建一个监听fd
	int listenfd = tcp_server(tunable_listen_address, tunable_listen_port);

	pid_t pid;
	session_t sess;
	session_init(&sess);
	p_sess = &sess;	//配置全局变量
	
	while(1)
	{
		struct sockaddr_in addr;
		int peerfd = accept_timeout(listenfd, &addr, tunable_accept_timeout);
		if(peerfd  == -1 && errno == ETIMEDOUT)
			continue;
		else if(peerfd == -1)
			ERR_EXIT("accept_timeout");

		//获取ip地址，并在hash中添加一条记录
		uint32_t ip = addr.sin_addr.s_addr;
		sess.ip = ip;
		add_clients_to_hash(&sess, ip);
		
		if((pid = fork()) == -1)
			ERR_EXIT("fork");
		else if(pid == 0)
		{
			close(listenfd);
			
			sess.peerfd = peerfd;
			limit_num_clients(&sess);
			session_begin(&sess);
			exit(EXIT_SUCCESS);
		}
		else
		{
			//pid_to_ip
			add_pid_ip_to_hash(pid, ip);
			close(peerfd);
		}
	}

	return 0;
}


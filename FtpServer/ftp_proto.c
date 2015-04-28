#include "ftp_proto.h"
#include "common.h"
#include "sysutil.h"
#include "strutil.h"
#include "ftp_codes.h"
#include "command_map.h"
#include "trans_ctrl.h"


//子进程不断的从FTP客户端接收FTP指令，并给与回应
void handle_proto(session_t *sess)
{
	ftp_reply(sess, FTP_GREET, "(FtpServer 1.0)");
	while(1)
	{
		session_reset_command(sess); //清空状态
		
		//开始计时
		start_signal_alarm_ctrl_fd();

		//接收命令
		int ret = readline(sess->peerfd, sess->command, MAX_COMMAND);
		if(ret == -1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("readline");
		}
		else if(ret == 0)
		{
			exit(EXIT_SUCCESS);
		}
		str_trim_crlf(sess->command);
		str_split(sess->command, sess->comm, sess->args, ' ');
		str_upper(sess->comm);
		printf("COMMD=[%s], ARGS=[%s]\n", sess->comm, sess->args);

		do_command_map(sess); //执行命令映射
	}
}




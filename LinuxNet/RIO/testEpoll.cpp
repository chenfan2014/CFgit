#include <iostream>
#include <string>
#include <vector>

#include <sys/epoll.h>


using namespace std;
int main(int argc, const char *argv[])
{
    while(1)
    {
        int nfds = epoll_wait(m_epoll_fd, m_event, MAX_EVENTS, EPOLL_TEME_TOU);         
        /*
         * 等待事件发生，类似于select调用
         * int epoll_wait(int efdp, struct epoll_event *events, int max_events, int timeout);
         * events用来从内核得到事件的集合，
         * maxEvents告之内核这个events有多大
         * maxevents的值不能大于我们epoll_create的size的值
         * 该函数返回需要处理的时间数目，如果返回0则表示已经超时
         *
         */
    }
    return 0;
}

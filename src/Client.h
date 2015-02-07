//#include "sockLib.h"
#include <sys/socket.h>
//#include <linux/in.h>
//#include <linux/in6.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

//#include "strLib.h"
//#include "hostLib.h"
//#include "ioLib.h"
#include <iostream>
#include <string.h>

#include "Task.h"


typedef uint32_t UINT32;
//#define sockaddr_in sockaddr
 

/* defines */ 
#define SERVER_WORK_PRIORITY    100    /* priority of server's work task */ 
#define SERVER_STACK_SIZE       10000  /* stack size of server's work task */ 
#define SERVER_MAX_CONNECTIONS  4      /* max clients connected at a time */ 
#define REQUEST_MSG_SIZE        1024   /* max size of request message */ 
#define REPLY_MSG_SIZE          500    /* max size of reply message */ 

//16 bytes
typedef struct directions{
    int diterror;
    int status;
};

const u_short SERVER_PORT_NUM = 1180;

class TCPClient {

    private:

    sockaddr_in  serverAddr;    /* server's socket address */
    //struct directions   replyDirec;    /* buffer for reply */ 
    int                 sockAddrSize;  /* size of socket address structure */ 
    int                 sFd;           /* socket file descriptor */ 
    int                 mlen;          /* length of message */ 
    bool                m_connected;

    void *get_in_addr(struct sockaddr *sa);
    public:

    enum Request {PULL = 5, DISCONNECT = 0};

    TCPClient(char* server);

    int Connect();
    int Receive(directions*);
    int Send(Request);

    bool IsConnected();

    void CloseSocket();
};

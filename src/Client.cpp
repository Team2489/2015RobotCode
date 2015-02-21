#include "Client.h"

using namespace std;

static const int debug = 0;

void *TCPClient::get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

TCPClient::TCPClient(char *server){

    sockAddrSize = sizeof (struct sockaddr_in); 
    memset((char *) &serverAddr, 0, sockAddrSize);
    serverAddr.sin_family = AF_INET; 
//    serverAddr.sin_len = (u_char) sockAddrSize;
    serverAddr.sin_port = htons (SERVER_PORT_NUM);
    
    m_connected = false;

    /* bind not required - port number is dynamic */ 
    /* build server socket address */ 
    if ( (serverAddr.sin_addr.s_addr = inet_addr (server)) == INADDR_NONE )
        { 
        perror ("unknown server name"); 
        CloseSocket();
        } 
 
}

int TCPClient::Connect(){
	
    if ( (sFd = socket(serverAddr.sin_family, SOCK_STREAM, 0)) == ERROR )
    	{
    	perror("Why did this even fail?");
    	}
    
    /* connect to server */ 
    if (connect (sFd, (struct sockaddr *) &serverAddr, sockAddrSize) == ERROR) 
        { 
        perror ("connect"); 
        CloseSocket();
        return ERROR;
        }
    
    m_connected = true;
    return 0;
 
}

int TCPClient::Receive(directions *direc){

    //Create reply
    union{
        char reply[sizeof(directions)];
        directions replyTemp;
    };

    //Receive data
    if (recv(sFd, reply, REPLY_MSG_SIZE, 0) < 0) {
        perror ("read"); 
        CloseSocket();
        return ERROR;
    }

    //Convert from network to host byte order
    replyTemp.diterror = ntohl(replyTemp.diterror);
    replyTemp.status = ntohl(replyTemp.status);
    if (debug) {
        cout << "Status is " << replyTemp.status << endl;
    }
    *direc = replyTemp;

    return 0;

}

int TCPClient::Send(Request request){
    
    if (request == PULL) {
        if (send (sFd, (char *) &request, sizeof(request), 0) == ERROR){
            perror("write");
            CloseSocket();
            return ERROR;
        }
    }

    return 0;
    
}

bool TCPClient::IsConnected(){

    return m_connected;

}

void TCPClient::CloseSocket(){

    close(sFd);
    m_connected = false;

}


/*
int main(){
    TCPClient myClient;
    myClient.GetAddrInfo("localhost", "2489");
    myClient.Connect();
    myClient.Recieve();
    myClient.CloseSocket();
    return 0;
}*/

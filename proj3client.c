#include <stdio.h>
#include <string.h>
#include <sys_socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];
    //Create socket
    socket_desc= socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        puts("Could not create socket");
    }
    
    server.sin_addr.s_addr= inet_addr(127.0.0.1); //loopback server
    server.sin_family= AF_INET;
    server.sin_port= htons(8888);
    
    //Connect to remote server
    if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server))<0)
    {
        puts("connect error");
        return 1;
    }
    puts("Connected\n");
    
    //Send some data
    message= "Get /HTTP/1.1\r\n\r\n";
    if(send(socket_desc, message, strlen(message),0,)<0)
    {
        puts("Send failed");
        return 1;
    }
    write(socket_desc, message, strlen(message));
    puts("Data Send\n");
    
    //Receive reply from server
    if(recv(socket_desc, server_reply, 2000,0)<0)
    {
        puts("recv failed");
    }
    puts("Reply Received\n");
    puts(server_reply);
    
    return 0;
}

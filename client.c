#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>


int ET_client()
{
    
    int sockfd = -1, remote_server_connect_success = -1;
    char rbuf[20];
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("Socket failed\n");
        return -1;
    }

    printf("Socket creation Success\n");

    // Connect to Server on its address
    struct sockaddr_un remote_server;
    remote_server.sun_family = AF_UNIX;
    strcpy(remote_server.sun_path, "./LocalSock");

    remote_server_connect_success = connect(sockfd, (struct sockaddr *)&remote_server, sizeof(remote_server));
    if(remote_server_connect_success < 0)
    {
        printf("Connection failed\n");
        close(sockfd);
        return -1;
    }

    printf("Connection to Server established!\n");

    // Write to server
    write(sockfd, "Hi", 3);
    printf("CLIENT:: Data written to client\n");

    // Read to server
    read(sockfd, rbuf, sizeof(rbuf));
    printf("CLIENT::: Data read from server: %s\n", rbuf);

    close(sockfd);
    printf("Connection terminated\n");
    return 0;
}
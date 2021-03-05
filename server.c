#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

#define ET_SOCKET_FAILURE -1
#define ET_BIND_FAILURE -1
#define ET_SOCKET_PORT 7070
#define ET_EXIT_FAILURE -1
#define ET_HANDLE_ERROR(msg, err_code) do { perror(msg); exit(err_code); } while (0);

/**
 * test:
 *  gcc -o test tests/check_server.c `pkg-config --cflags --libs check`
 *	./test
 * 
 * 
 * */
int ET_server(int port)
{

    int sockfd = ET_SOCKET_FAILURE;
    int bind_rtn = ET_BIND_FAILURE;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        ET_HANDLE_ERROR("Failed to create socket!", ET_SOCKET_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind_rtn = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(bind_rtn < 0)
    {
        close(sockfd);
        ET_HANDLE_ERROR("[EASY_TCP] Bind Error:", ET_BIND_FAILURE);
    }

    printf(
        "Bind success on %s:%d\n", 
        inet_ntoa(server_addr.sin_addr),
        ntohs(server_addr.sin_port)
        );
    printf("Closing Socket...\n");


    close(sockfd);

    return 0;
}

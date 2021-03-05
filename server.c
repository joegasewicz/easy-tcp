#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

#define EASY_SOCKET_FAILURE -1
#define EASY_BIND_FAILURE -1
#define EASY_SOCKET_PORT 7070
#define EASY_EXIT_FAILURE -1
#define EASY_HANDLE_ERROR(msg, err_code) do { perror(msg); exit(err_code); } while (0);

/**
 * test:
 *  gcc -o test tests/check_server.c `pkg-config --cflags --libs check`
 *	./test
 * 
 * 
 * */
int server()
{

    int sockfd = EASY_SOCKET_FAILURE;
    int bind_rtn = EASY_BIND_FAILURE;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        EASY_HANDLE_ERROR("Failed to create socket!", EASY_SOCKET_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(EASY_SOCKET_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind_rtn = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(bind_rtn < 0)
    {
        printf("Closing socket...s\n");
        close(sockfd);
        EASY_HANDLE_ERROR("Failed to bind to server created socket", EASY_BIND_FAILURE);
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
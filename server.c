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
 * 
 * 
 * */
int ET_server(int port)
{   
    int listen_return = -1, client_session_fd = -1, read_return = -1, write_return = -1;
    int sockfd = ET_SOCKET_FAILURE;
    int bind_rtn = ET_BIND_FAILURE;
    struct sockaddr_in server_addr, client_addr;
    int client_sock_type_len;
    char read_buffer[20];

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
        "[EASY_TCP] Info: Listening on %s:%d\n", 
        inet_ntoa(server_addr.sin_addr),
        ntohs(server_addr.sin_port)
        );

    listen_return = listen(sockfd, 10);
    if(listen_return < 0)
    {
        close(sockfd);
        ET_HANDLE_ERROR("[EASY_TCP] Listen Error:", listen_return);
    }

    client_sock_type_len = sizeof(client_addr);
    client_session_fd = accept(sockfd, (struct sock_addr *)&client_addr, &client_sock_type_len);
    if(client_session_fd < 0)
    {
        close(sockfd);
        ET_HANDLE_ERROR("[EASY_TCP] Accept Error:", listen_return);
    }

    printf(
        "[EASY_TCP] Info: Client request accepted on %s:%hd\n",
        inet_ntoa(client_addr.sin_addr),
        ntohs(client_addr.sin_port)
        );

    read_return = read(client_session_fd, read_buffer, sizeof(read_buffer));
    printf("SERVER:: Reading from client: %s\n", read_buffer);
    if(read_return < 0)
    {
        ET_HANDLE_ERROR("[EASY_TCP] Read Error:", read_return);
    } 

    write_return = write(client_session_fd, read_buffer, strlen(read_buffer)+1);
    if(read_return < 0)
    {
        ET_HANDLE_ERROR("[EASY_TCP] Write Error:", write_return);
    }

    close(sockfd);

    return 0;
}

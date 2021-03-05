#include <stdio.h>
#include <string.h>
#include "et_utils.h"
#include "process.h"
#include "server.h"
#include "client.h"

#define ET_ARG_SERVER "-server"
#define ET_ARG_CLIENT "-client"
#define ET_OPTION_PORT "--port"
#define ET_OPTION_URL "--url"
#define ET_OPTION_METHOD "--method"
#define ET_OPTION_HEADERS "--headers"
#define ET_OPTION_BODY "--body"


int main(int argc, char *argv[])
{

    char option_key[20];

    if(strcmp(argv[1], ET_ARG_CLIENT) != 0 && strcmp(argv[1], ET_ARG_SERVER) != 0)
    {
        printf("Error: Incorrect arguments: %s\n", argv[1]);
        display_help();
    }

    if(strcmp(argv[1], ET_ARG_SERVER) == 0)
    {
        int server_result = ET_server();
        if(server_result < 0)
        {
            perror("Error");
            exit(server_result);
        }
    }

    if(strcmp(argv[1], ET_ARG_CLIENT) == 0) {
        int client_result = ET_client();
        if(client_result < 0)
        {
            perror("Error");
            exit(client_result);
        }
    }

    return 0;
}
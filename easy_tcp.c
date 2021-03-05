#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "et_utils.h"
#include "process.h"
#include "server.h"
#include "client.h"


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
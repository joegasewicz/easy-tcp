#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "et_utils.h"
#include "process.h"
#include "server.h"
#include "client.h"


int main(int argc, char *argv[])
{

    char option_key[20];
    Application *curr_app;
   

    if(strcmp(argv[1], ET_ARG_CLIENT) != 0 && strcmp(argv[1], ET_ARG_SERVER) != 0)
    {
        printf("Error: Incorrect arguments: %s\n", argv[1]);
        display_help();
    }


    if(strcmp(argv[1], ET_ARG_SERVER) == 0)
    {
        curr_app = create_curr_app("server");
        int server_result = ET_server(7070);
        if(server_result < 0)
        {
            perror("Error");
            exit(server_result);
        }
        exit(0);
    }

    if(strcmp(argv[1], ET_ARG_CLIENT) == 0)
    {
        curr_app = create_curr_app("client");
        int client_result = ET_client();
        if(client_result < 0)
        {
            perror("Error");
            exit(client_result);
        }
        exit(0);
    }

    return 0;
}
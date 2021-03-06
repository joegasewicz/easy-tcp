#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "et_utils.h"
#include "process.h"
#include "server.h"


int main(int argc, char *argv[])
{
    int i = 0;
    int server_result;
    char default_host[9] = "127.0.0.1";
    Application *curr_app;
    // Initiate with defaults
    curr_app = create_curr_app(default_host, 7070);
    for(;i < argc; i ++)
    {
        if(strcmp(argv[i], ET_OPTION_HOST) == 0)
        {
        strcpy(curr_app->host, argv[i]);
        }
        if(strcmp(argv[i], ET_OPTION_PORT))
        {
            curr_app->port = atoi(argv[i]);
        }
    }
    server_result = ET_server(7070);
    if(server_result < 0)
    {
        perror("Error");
        exit(server_result);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "et_utils.h"


int display_help()
{
    printf("Usage easy-tcp [option] [arguments] :\n");
    printf("Options:\n");
    printf("\t-server\t\tStart the TCP server\n");
    printf("\t-client\t\tStart the client\n");
    return 0;
}

Application *create_curr_app(char *app_name)
{
    Application *a = malloc(sizeof(Application));
    strcat(a->name, app_name);
    return a;
}
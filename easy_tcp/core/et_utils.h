#include <unistd.h>

#define ET_OPTION_PORT "--port"
#define ET_OPTION_HOST "--host"


typedef struct Application {
    char host[16];
    short port;
} Application;


int display_help();
Application *create_curr_app(char *host, short port);

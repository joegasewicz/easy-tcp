CFLAGS=-g -Wall
TEST_PATH=$(ROOT_PATH)tests/

CORE_FILES=et_utils.c process.c
SERVER_FILES=server.c
APPLICATION_FILES=easy_tcp.c $(CORE_FILES) $(SERVER_FILES)

SERVER_EXC_NAME=server
APPLICATION_EXC_NAME=easy-tcp

# test:
# gcc -o test tests/check_server.c `pkg-config --cflags --libs check`
#	./test

build:
	gcc $(CFLAGS) -o $(APPLICATION_EXC_NAME) $(APPLICATION_FILES)

run:
	./$(APPLICATION_EXC_NAME)

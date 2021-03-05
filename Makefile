CFLAGS=-g -Wall
TEST_PATH=$(ROOT_PATH)tests/

CORE_FILES=et_utils.c process.c
CLIENT_FILES=client.c
SERVER_FILES=server.c
APPLICATION_FILES=easy_tcp.c $(CORE_FILES) $(SERVER_FILES) $(CLIENT_FILES)

CLIENT_EXC_NAME=client
SERVER_EXC_NAME=server
APPLICATION_EXC_NAME=easy-tcp

build-client:
	gcc $(CFLAGS) -o $(CLIENT_EXC_NAME) $(CORE_FILES) $(CLIENT_FILES)

build-server:
	gcc $(CFLAGS) -o $(SERVER_EXC_NAME) $(CORE_FILES) $(SERVER_FILES)

run-client:
	make build-client
	./$(CLIENT_EXC_NAME)

run-server:
	make build-server
	./$(SERVER_EXC_NAME)

build:
	gcc $(CFLAGS) -o $(APPLICATION_EXC_NAME) $(APPLICATION_FILES)

run:
	./$(APPLICATION_EXC_NAME)

CFLAGS = -g -Wall
TEST_PATH = $(ROOT_PATH)tests/

CLIENT_FILES = client.c
SERVER_FILES = server.c

SERVER_FILES = 
CLIENT_EXC_NAME = client
SERVER_EXC_NAME = server

build-client:
	gcc $(CFLAGS) -o $(CLIENT_EXC_NAME) $(CLIENT_FILES)

build-server:
	gcc $(CFLAGS) -o $(SERVER_EXC_NAME) $(SERVER_FILES)

run-client:
	make build-client
	./$(CLIENT_EXC_NAME)

run-server:
	make build-server
	./$(SERVER_EXC_NAME)

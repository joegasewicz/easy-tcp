CFLAGS = -g -Wall
TEST_PATH = $(ROOT_PATH)tests/
CLIENT_FILES = $(TEST_PATH)test_client.c client.c
CLIENT_EXC_NAME = client

build-client:
	gcc $(CFLAGS) -o $(CLIENT_EXC_NAME) $(CLIENT_FILES)

run-client:
	make build-client
	./$(CLIENT_EXC_NAME)

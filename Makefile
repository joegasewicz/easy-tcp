CFLAGS=-g -Wall
TEST_PATH=$(ROOT_PATH)tests/

CORE_FILES=et_utils.c process.c
SERVER_FILES=server.c
APPLICATION_FILES=easy_tcp.c $(CORE_FILES) $(SERVER_FILES)
TEST_FILES=tests/test_server.c $(CORE_FILES) $(SERVER_FILES)

APPLICATION_EXC_NAME=easy-tcp
TEST_EXC_NAME=test-easy-tcp

build:
	gcc $(CFLAGS) -o $(APPLICATION_EXC_NAME) $(APPLICATION_FILES)

test:
	gcc $(CFLAGS) -o $(TEST_EXC_NAME) $(TEST_FILES) `pkg-config --cflags --libs cmocka`
	./$(TEST_EXC_NAME)

run:
	./$(APPLICATION_EXC_NAME)


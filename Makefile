## -----------------------------------------------------------------
## C Tasks
## -----------------------------------------------------------------

CFLAGS=-g -Wall
TEST_PATH=$(ROOT_PATH)tests/
CORE_PATH=$(ROOT_PATH)core/

CORE_FILES=$(CORE_PATH)et_utils.c $(CORE_PATH)process.c
SERVER_FILES=$(CORE_PATH)server.c
APPLICATION_FILES=$(CORE_PATH)easy_tcp.c $(CORE_FILES) $(SERVER_FILES)
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

## -----------------------------------------------------------------
## Cython Tasks
## -----------------------------------------------------------------
req:
	sudo apt-get install python3-dev
	sudo apt-get install python-dev

cython-build:
	gcc -Wall -g -c process.c -o cython_src/process.o
	gcc -Wall -g -c server.c -o cython_src/server.o



cython-compile:
	make cython-build
	ar -rc cython_src/libprocess.a cython_src/process.o
	ar -rc cython_src/libserver.a cython_src/server.o
	python3.9 setup.py build_ext --build-lib cython_src

clean:
	rm -rf cython_src/server.o\
 		   cython_src/libserver.a\
 		   cython_src/process.o\
 		   cython_src/libprocess.a\
 		   cython_src/server.c\
 		   cython_src/server.cpython-39-x86_64-linux-gnu.so\
 		   build
## -----------------------------------------------------------------
## Python Tasks
## -----------------------------------------------------------------
python-run:
	python3.9 easy_tcp.py
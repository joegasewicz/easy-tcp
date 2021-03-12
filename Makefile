## -----------------------------------------------------------------
## C Tasks
## -----------------------------------------------------------------

CFLAGS=-g -Wall
TEST_PATH=$(ROOT_PATH)tests/
CORE_PATH=$(ROOT_PATH)easy_tcp/core/
DIST_DIR=dist

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
	gcc -Wall -g -c $(CORE_PATH)process.c -o $(CORE_PATH)process.o
	gcc -Wall -g -c $(CORE_PATH)server.c -o $(CORE_PATH)server.o

cython:
	make cython-build
	ar -rc $(CORE_PATH)libprocess.a $(CORE_PATH)process.o
	ar -rc $(CORE_PATH)libserver.a $(CORE_PATH)server.o
	
	python3 setup.py build_ext --inplace --et_comp

install:
	python3 setup.py install

clean:
	$(RM) -r $(CORE_PATH)*.o $(CORE_PATH)*.a $(CORE_PATH)*.so $(CORE_PATH)lib*.a
	$(RM) -r easy_tcp/*.so 
	$(RM) -r $(CORE_PATH)__pycache__
	$(RM) -r $(CORE_PATH)__init__.py
	$(RM) -r $(CORE_PATH)cython_server.c
	$(RM) -r build
	$(RM) -r $(DIST_DIR)
	$(RM) -r venv/lib/python3.9/site-packages/easy_tcp*.* venv/lib/python3.9/site-packages/easy_tcp*

## -----------------------------------------------------------------
## Python Tasks
## -----------------------------------------------------------------
easy:
	python3.9 easy_tcp/__init__.py

pkg:
	python3.9 setup.py sdist

python-release:
	make pkg
	twine upload $(DIST_DIR)/* --verbose
	$(RM) easy_tcp/core/__init__.py

## -----------------------------------------------------------------
## Local testing
## -----------------------------------------------------------------
local:
	make clean
	make cython
	touch $(CORE_PATH)__init__.py
	make pkg
	pip uninstall easy-tcp
	make install
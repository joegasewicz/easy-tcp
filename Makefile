## -----------------------------------------------------------------
## C Tasks
## -----------------------------------------------------------------

CFLAGS=-g -Wall
TEST_PATH=$(ROOT_PATH)tests/
CORE_PATH=$(ROOT_PATH)easy_tcp/core/
CYTHON_PATH=$(ROOT_PATH)easy_tcp/
DIST_DIR=dist
VERSION=0.0.8

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
	sudo apt-get install patchelf
	sudo aot-get install auditwheel

cython-build:
	gcc $(CFLAGS) -c $(CORE_PATH)process.c -o $(CORE_PATH)process.o
	gcc $(CFLAGS) -c $(CORE_PATH)server.c -o $(CORE_PATH)server.o
	gcc $(CORE_PATH)server.o -shared -o $(CYTHON_PATH)libserver.so
	gcc $(CORE_PATH)process.o -shared -o $(CYTHON_PATH)libprocess.so
	ar -rc $(CYTHON_PATH)libprocess.a $(CORE_PATH)process.o
	ar -rc $(CYTHON_PATH)libserver.a $(CORE_PATH)server.o

cython:
	make cython-build
	python3 setup.py build_ext --inplace --et_comp

install:
	#python3 setup.py install
	pip install --force-reinstall --no-cache-dir $(DIST_DIR)/easy-tcp-$(VERSION).tar.gz
	# pip install --force-reinstall --no-cache-dir $(DIST_DIR)/easy_tcp-$(VERSION)-cp39-cp39-linux_x86_64.whl
clean:
	$(RM) -r $(CYTHON_PATH)*.o $(CYTHON_PATH)*.a $(CYTHON_PATH)*.so $(CYTHON_PATH)lib*.a
	$(RM) -r $(CYTHON_PATH)*.so $(CYTHON_PATH)*.cpython-39-x86_64-linux-gnu.so
	$(RM) -r $(CYTHON_PATH)__pycache__
	$(RM) -r $(CYTHON_PATH)cython_server.c
	$(RM) -r build dist wheelhouse
	$(RM) -r $(DIST_DIR) easy_tcp.egg-info
	$(RM) -r venv/lib/python3.9/site-packages/easy_tcp*.* venv/lib/python3.9/site-packages/easy_tcp*

## -----------------------------------------------------------------
## Python Tasks
## -----------------------------------------------------------------
easy:
	python3.9 _easy_tcp/__init__.py

pkg:
	python3.9 setup.py sdist

release:
	# make pkg
	# make repair
	twine upload dist/* --verbose

## -----------------------------------------------------------------
## Local testing
## -----------------------------------------------------------------
local:
	mv _easy_tcp easy_tcp
	make clean
	make cython
	make pkg
	pip uninstall easy-tcp
	make pkg
	make install
	# make repair
	mv easy_tcp _easy_tcp
	make check

repair:
	auditwheel repair $(DIST_DIR)/easy_tcp-$(VERSION)-cp39-cp39-linux_x86_64.whl
	pip install --force-reinstall wheelhouse/easy_tcp-$(VERSION)-cp39-cp39-manylinux1_x86_64.whl

check:
	python test.py
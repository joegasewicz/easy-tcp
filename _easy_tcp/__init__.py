import pyximport
pyximport.install()

from easy_tcp.core import cython_server

server = cython_server

if __name__ == "__main__":
    server.server()

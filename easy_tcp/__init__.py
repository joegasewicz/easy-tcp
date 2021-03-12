import pyximport
pyximport.install()

from core import cython_server

server = cython_server

if __name__ == "__main__":
    server.server()

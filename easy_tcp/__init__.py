import pyximport
pyximport.install()

from cython_src import server

if __name__ == "__main__":
    server.server()


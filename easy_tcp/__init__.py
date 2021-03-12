import pyximport
pyximport.install()

import core.cython_server

if __name__ == "__main__":
    cython_server.server()

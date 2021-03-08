cdef extern from "../process.h":
    void signal_handler(int signum)

cdef extern from "../server.h":
    int ET_server(int port)

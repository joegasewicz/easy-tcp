cdef extern from "core/server.h":
    int easy_tcp_server(int port)

def server():
    easy_tcp_server(7070)

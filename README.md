# Easy TCP
[![C/C++ CI](https://github.com/joegasewicz/easy-tcp/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/joegasewicz/easy-tcp/actions/workflows/c-cpp.yml)

TCP Client & Server


(Library still in dev, please call back soon)

### Quick Start


##### Install
```bash
git clone https://github.com/joegasewicz/easy-tcp.git
cd easy-tcp
make build
# TODO easy-tcp add to profile
```

##### Start Easy TCP Server
```bash
easy-tcp -server --port 4040
```

##### Start the Easy TCP client
```bash
easy-tcp -client \
 --url http://localhost:4040/hello \
 --method GET \
 --headers { "Content-Type": "application/json" } \
 --body {"message": "hello!"}
```

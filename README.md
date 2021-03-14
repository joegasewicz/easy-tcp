[![C/C++ CI](https://github.com/joegasewicz/easy-tcp/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/joegasewicz/easy-tcp/actions/workflows/c-cpp.yml)
![PyPI](https://img.shields.io/pypi/v/easy-tcp)

# Easy TCP
Python WSGI Server written in C

### Compatibility
Run on UNIX like systems

### Quick Start

##### Install
```bash
pip install easy-tcp
```

##### Start Easy TCP Server
```bash
easy-tcp --port 7070 --max_processes 15 --app app.py --function start_app
```

### Contributing
Please see [Contributing](CONTRIBUTING.md)

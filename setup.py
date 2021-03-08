from setuptools import setup, Extension
from Cython.Build import cythonize


setup(
    name="easy-tcp",
    zip_safe=False,
    ext_modules=cythonize(
        Extension("server",
            sources=[
                "process.c",
                "server.c",
                "cython_src/server.pyx"
            ],
        )
    )
)

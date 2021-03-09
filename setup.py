from setuptools import setup, Extension

ext_modules = []



# from Cython.Build import cythonize
# ext_modules = cythonize(
#     Extension("easy_tcp",
#               sources=[
#                   "process.c",
#                   "server.c",
#                   "cython_src/server.pyx"
#               ],
#               )
# )


ext_modules = [Extension(
    "easy_tcp",
    ["cython_src/process.c", "cython_src/server.c", ]
)]

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name="easy-tcp",
    version="0.0.4rc5",
    description="Python TCP WSGI Server",
    packages=["easy_tcp", "cython_src"],
    install_requires=[
        "cython"
    ],
    zip_safe=False,
    ext_modules=ext_modules,
    classifiers=[
        "Programming Language :: Python :: 3.9",
        "Operating System :: Unix",
    ],
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/joegasewicz/easy-tcp",
    author="Joe Gasewicz",
    author_email="joegasewicz@gmail.com",
)

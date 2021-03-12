from setuptools import setup, Extension, find_packages
import sys

compiler_directives = {"language_level": "3"}

if "--et_comp" in sys.argv:
    print("Compiling...")
    from Cython.Build import cythonize
    sys.argv.remove("--et_comp")
    ext_modules = cythonize(
        Extension(
            "easy_tcp.core.cython_server",
            [
                "easy_tcp/core/cython_server.pyx",
                "easy_tcp/core/server.c",
                "easy_tcp/core/process.c",
            ],
            install_dir=["easy_tcp/core"]
        ),
        compiler_directives=compiler_directives,
    )
else:
    ext_modules = [
        Extension(
            "cython_server",
            [
                "easy_tcp/core/server.c",
                "easy_tcp/core/process.c",
            ],
        )
    ]

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name="easy-tcp",
    version="0.0.5",
    description="Python TCP WSGI Server",
    # packages=find_packages(where="easy_tcp"),
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

    # package_dir={"": ""},
    # package_data={'*': ['*.pxd', '*.h']},
)

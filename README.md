

<p align="center"> <img src="./doc/icon.png" alt="icon" width="100" height="100" /> </p>

# Sorbet

Sorbet is a compiler or more accurately a transpiler for the esoteric programming language Brainf\*ck. The interpreter is by no means extremely fast, special or desirable to use, just as the language Brainf\*ck itself. The development of this project is purely for academic purposes and practise.

## Getting Started

To get a build of Sorbet up and running on your local machine the following tools are required:

* A working installment of the GCC compiler
* A working installment of CMake
* A working installment of Make

## Building

Building is as simple as running the following 2 commands in the root of the project:

```
$ cmake .
$ make
```

## Deployment

To interpret a Brainf\*ck source file (.bf) only a single command is needed. Run the following command in the root of the project:

```
$ ./sorbet SOURCE_FILE
```

Where `SOURCE_FILE` is the file name of the source file to be interpreted. The `examples` directory contains some non-trivial Brainf\*ck source files.

## Authors

* **Frederik Christian Slothouber** - *Initial work* - [wollemat](https://github.com/wollemat)

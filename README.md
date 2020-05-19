
<p align="center"> <img src="./icon.png" alt="icon" width="100" height="100" /> </p>

# Sorbet

Sorbet is a compiler or more accurately a transpiler for the esoteric programming language Brainf\*ck. The interpreter is by no means fast or elegant, just as the language Brainf\*ck itself. The development of this project is purely for academic purposes and practise.

## Getting Started

To get a build of Sorbet up and running on your local machine the following tools are required:

* A working installment of GCC
* A working installment of CMake
* A working installment of Make

## Building

Building is as simple as running the following command in the root of the project:

```
$ cmake . && make
```

## Deployment

Sorbet supports two types of deployment: default execution and optimized execution. The only difference between the two type is that when gcc is used to compile the generated C code a different optimization flag is used. `--default` uses the default gcc compiler flag `-O0` and `--optimzed` uses the `-O3` optimization flag.

To run a Brainf\*ck source file (.bf) run one of the following commands:

```
$ ./sorbet FILE --default
$ ./sorbet FILE --optimized
$ ./sorbet --help # Shows the man page
```

Where `FILE` is the file name or path of the source file to be run. The `examples` directory contains some non-trivial Brainf\*ck source files. For instance the generation of the famous [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set) and a solution to the [Towers of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) puzzle. Watch out the solution is over in the blink of an eye.

## Contributors

* **Frederik Christian Slothouber** - *Initial work* - [wollemat](https://github.com/wollemat)
* **Fabian Mastenbroek** - *Inspiration* - [fabianishere](https://github.com/fabianishere)
* Icon made by [freepik](https://www.flaticon.com/authors/freepik) from [www.flaticon.com](https://www.flaticon.com)

## License

This project and its code is released under the [MIT license](LICENSE.txt).


<p  align="center"> <img src="icon.png" alt="Icon" width="100" height="100" /> </p>
<h1 align="center">Sorbet</h1>
<h4 align="center">"The Lightweight Brainf*ck Transpiler"</h4>

<p align="center">
    <a href="LICENSE.md">
    <img src="https://img.shields.io/badge/license-MIT-yellow" alt="License">
</p>
      
<p align="center">
  <a href="#about">About</a> •
  <a href="#building">Building</a> •
  <a href="#deployment">Deployment</a> •
  <a href="#examples">Examples</a> •
  <a href="#contributing">Contributing</a> •
  <a href="#contributors">Contributors</a> •
  <a href="#donate">Donate</a> •
  <a href="#license">License</a>
</p>

## About

**Sorbet** is a compiler or more accurately a transpiler for the esoteric programming language [Brainf\*ck](https://en.wikipedia.org/wiki/Brainfuck). 
The interpreter is by no means fast or elegant, just as the language [Brainf\*ck](https://en.wikipedia.org/wiki/Brainfuck) itself. 
The development of this project is purely for academic purposes and practise.

## Building

Before building Sorbet please make sure that the following tools are up and running on your machine:

* A working installment of GCC
* A working installment of Make

Download the source code by running the following code in your command prompt:

```
$ git clone https://github.com/wollemat/sorbet.git
```

Or simply grab a copy of the source code as a zip file [here](https://github.com/wollemat/sorbet/archive/master.zip) for the latest release and [here](https://github.com/wollemat/sorbet/archive/develop.zip) for the *"bleeding edge"* version.

Building is as simple as running the following command in the root of the project:

```
$ make
```

This will compile the source to a binary called `sorbet` and make the binary executable. 
The executable is placed in the diretory `bin`.

If you are updating the project then cleaning it in advance might be necessary. Use the following command for this:

```
$ make clean
```

## Deployment

Running Sorbet is just as easy as building it. 
You can directly run the executable in the `bin` directory or add the binary to your `PATH` and run it like any other program. 

To run a Brainf\*ck source file (.bf) run the following command:

```
$ sorbet FILE
```

Where `FILE` is the file name or path of the Brainf*ck source file to be run. 
The `examples` directory contains some non-trivial Brainf\*ck source files. 
For instance the generation of the famous [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set) and a solution to the [Towers of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) puzzle. 
Watch out the solution is over in the blink of an eye!

## Examples

Some examples for you to get you on your way. 

```
$ sorbet examples/mandelbrot.bf

AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDEGFFEEEEDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAAAAABBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDEEEFGIIGFFEEEDDDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAAABBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDEEEEFFFI KHGGGHGEDDDDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAABBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDEEEEEFFGHIMTKLZOGFEEDDDDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAABBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDEEEEEEFGGHHIKPPKIHGFFEEEDDDDDDDDDCCCCCCCCCCBBBBBBBBBBBBBBBBBB
AAAAAAAAAABBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDEEEEEEFFGHIJKS  X KHHGFEEEEEDDDDDDDDDCCCCCCCCCCBBBBBBBBBBBBBBBB
AAAAAAAAABBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDEEEEEEFFGQPUVOTY   ZQL[MHFEEEEEEEDDDDDDDCCCCCCCCCCCBBBBBBBBBBBBBB
AAAAAAAABBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDEEEEEFFFFFGGHJLZ         UKHGFFEEEEEEEEDDDDDCCCCCCCCCCCCBBBBBBBBBBBB
AAAAAAABBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDEEEEFFFFFFGGGGHIKP           KHHGGFFFFEEEEEEDDDDDCCCCCCCCCCCBBBBBBBBBBB
AAAAAAABBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDEEEEEFGGHIIHHHHHIIIJKMR        VMKJIHHHGFFFFFFGSGEDDDDCCCCCCCCCCCCBBBBBBBBB
AAAAAABBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDEEEEEEFFGHK   MKJIJO  N R  X      YUSR PLV LHHHGGHIOJGFEDDDCCCCCCCCCCCCBBBBBBBB
AAAAABBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDEEEEEEEEEFFFFGH O    TN S                       NKJKR LLQMNHEEDDDCCCCCCCCCCCCBBBBBBB
AAAAABBCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDEEEEEEEEEEEEFFFFFGHHIN                                 Q     UMWGEEEDDDCCCCCCCCCCCCBBBBBB
AAAABBCCCCCCCCCCCCCCCCCCCCCCCCCDDDDEEEEEEEEEEEEEEEFFFFFFGHIJKLOT                                     [JGFFEEEDDCCCCCCCCCCCCCBBBBB
AAAABCCCCCCCCCCCCCCCCCCCCCCDDDDEEEEEEEEEEEEEEEEFFFFFFGGHYV RQU                                     QMJHGGFEEEDDDCCCCCCCCCCCCCBBBB
AAABCCCCCCCCCCCCCCCCCDDDDDDDEEFJIHFFFFFFFFFFFFFFGGGGGGHIJN                                            JHHGFEEDDDDCCCCCCCCCCCCCBBB
AAABCCCCCCCCCCCDDDDDDDDDDEEEEFFHLKHHGGGGHHMJHGGGGGGHHHIKRR                                           UQ L HFEDDDDCCCCCCCCCCCCCCBB
AABCCCCCCCCDDDDDDDDDDDEEEEEEFFFHKQMRKNJIJLVS JJKIIIIIIJLR                                               YNHFEDDDDDCCCCCCCCCCCCCBB
AABCCCCCDDDDDDDDDDDDEEEEEEEFFGGHIJKOU  O O   PR LLJJJKL                                                OIHFFEDDDDDCCCCCCCCCCCCCCB
AACCCDDDDDDDDDDDDDEEEEEEEEEFGGGHIJMR              RMLMN                                                 NTFEEDDDDDDCCCCCCCCCCCCCB
AACCDDDDDDDDDDDDEEEEEEEEEFGGGHHKONSZ                QPR                                                NJGFEEDDDDDDCCCCCCCCCCCCCC
ABCDDDDDDDDDDDEEEEEFFFFFGIPJIIJKMQ                   VX                                                 HFFEEDDDDDDCCCCCCCCCCCCCC
ACDDDDDDDDDDEFFFFFFFGGGGHIKZOOPPS                                                                      HGFEEEDDDDDDCCCCCCCCCCCCCC
ADEEEEFFFGHIGGGGGGHHHHIJJLNY                                                                        TJHGFFEEEDDDDDDDCCCCCCCCCCCCC
A                                                                                                 PLJHGGFFEEEDDDDDDDCCCCCCCCCCCCC
ADEEEEFFFGHIGGGGGGHHHHIJJLNY                                                                        TJHGFFEEEDDDDDDDCCCCCCCCCCCCC
ACDDDDDDDDDDEFFFFFFFGGGGHIKZOOPPS                                                                      HGFEEEDDDDDDCCCCCCCCCCCCCC
ABCDDDDDDDDDDDEEEEEFFFFFGIPJIIJKMQ                   VX                                                 HFFEEDDDDDDCCCCCCCCCCCCCC
AACCDDDDDDDDDDDDEEEEEEEEEFGGGHHKONSZ                QPR                                                NJGFEEDDDDDDCCCCCCCCCCCCCC
AACCCDDDDDDDDDDDDDEEEEEEEEEFGGGHIJMR              RMLMN                                                 NTFEEDDDDDDCCCCCCCCCCCCCB
AABCCCCCDDDDDDDDDDDDEEEEEEEFFGGHIJKOU  O O   PR LLJJJKL                                                OIHFFEDDDDDCCCCCCCCCCCCCCB
AABCCCCCCCCDDDDDDDDDDDEEEEEEFFFHKQMRKNJIJLVS JJKIIIIIIJLR                                               YNHFEDDDDDCCCCCCCCCCCCCBB
AAABCCCCCCCCCCCDDDDDDDDDDEEEEFFHLKHHGGGGHHMJHGGGGGGHHHIKRR                                           UQ L HFEDDDDCCCCCCCCCCCCCCBB
AAABCCCCCCCCCCCCCCCCCDDDDDDDEEFJIHFFFFFFFFFFFFFFGGGGGGHIJN                                            JHHGFEEDDDDCCCCCCCCCCCCCBBB
AAAABCCCCCCCCCCCCCCCCCCCCCCDDDDEEEEEEEEEEEEEEEEFFFFFFGGHYV RQU                                     QMJHGGFEEEDDDCCCCCCCCCCCCCBBBB
AAAABBCCCCCCCCCCCCCCCCCCCCCCCCCDDDDEEEEEEEEEEEEEEEFFFFFFGHIJKLOT                                     [JGFFEEEDDCCCCCCCCCCCCCBBBBB
AAAAABBCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDEEEEEEEEEEEEFFFFFGHHIN                                 Q     UMWGEEEDDDCCCCCCCCCCCCBBBBBB
AAAAABBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDEEEEEEEEEFFFFGH O    TN S                       NKJKR LLQMNHEEDDDCCCCCCCCCCCCBBBBBBB
AAAAAABBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDEEEEEEFFGHK   MKJIJO  N R  X      YUSR PLV LHHHGGHIOJGFEDDDCCCCCCCCCCCCBBBBBBBB
AAAAAAABBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDEEEEEFGGHIIHHHHHIIIJKMR        VMKJIHHHGFFFFFFGSGEDDDDCCCCCCCCCCCCBBBBBBBBB
AAAAAAABBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDEEEEFFFFFFGGGGHIKP           KHHGGFFFFEEEEEEDDDDDCCCCCCCCCCCBBBBBBBBBBB
AAAAAAAABBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDEEEEEFFFFFGGHJLZ         UKHGFFEEEEEEEEDDDDDCCCCCCCCCCCCBBBBBBBBBBBB
AAAAAAAAABBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDEEEEEEFFGQPUVOTY   ZQL[MHFEEEEEEEDDDDDDDCCCCCCCCCCCBBBBBBBBBBBBBB
AAAAAAAAAABBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDEEEEEEFFGHIJKS  X KHHGFEEEEEDDDDDDDDDCCCCCCCCCCBBBBBBBBBBBBBBBB
AAAAAAAAAAABBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDEEEEEEFGGHHIKPPKIHGFFEEEDDDDDDDDDCCCCCCCCCCBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAABBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDEEEEEFFGHIMTKLZOGFEEDDDDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAAABBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDEEEEFFFI KHGGGHGEDDDDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAAAAABBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDDEEEFGIIGFFEEEDDDDDDDDCCCCCCCCCBBBBBBBBBBBBBBBBBBBBBBBBBB

```

```
$ sorbet examples/numwarp.bf

12345678
              /\
              \/\
            /\ \/
              \
          /
          \/\
        /  \/
        \/\
       \  /
      \/\
    /\
     /\
  /\  /
   /
 \ \/
  \

```

Good Luck & Be Safe!

## Contributors

* **Frederik Christian Slothouber** - *Initial work* - [wollemat](https://github.com/wollemat)
* **Fabian Mastenbroek** - *Inspiration* - [fabianishere](https://github.com/fabianishere)

## License

<p align="center">This project and its code are released under the MIT license. Please have a look at the <a href="LICENSE.md">LICENSE.md</a> for more details.</p>
<p align="center">Icon made by <a href="https://www.flaticon.com/authors/freepik">Freepik</a> from www.flaticon.com</p>
<p align="center">copyright © <a href="https://github.com/wollemat">wollemat</a></p>

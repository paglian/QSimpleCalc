QSimpleCalc
===========

QSimpleCalc is a simple calculator that solves arithmetic expressions and linear equations. 

__This is a very simple application. I just made this application as part of a recruitment process.__

The supported operators are:
 - Addition
 - Substraction
 - Multiplication
 - Division
 - Logarithm base 10

Operators can be grouped using parentheses. Example: (2 + 2)*3

Linear equations must have only one variable declaration.
For instance: x + x + 0.5 = 10  is not allowed. It should be written as: 2*x + 0.5 = 10

### Requirements

Qt >= 4.7

### Compile & run

    cd src/qsimplecalc/
    qmake
    make
    ./QSimpleCalc         # (*)

(*) The output directory may change according the OS. For instance in Windows could be found in src/qsimplecalc/debug/

### Project structure

    |-- src                  # Sources
    |   |-- qsimplecalc      # The QSimpleCalc sources
    |   |-- testsuite        # The test suite sources
    |-- doc                  # UML documentation


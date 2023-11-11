# rpn-calculator

`dc` command-like to compute [rpn - Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) expression.

- [rpn-calculator](#rpn-calculator)
  - [Download and run](#download-and-run)
  - [Examples](#examples)
  - [How to use](#how-to-use)
  - [Supported operation](#supported-operation)
  - [Supported commands](#supported-commands)


## Download and run

To download the repo, you can either download the .zip file for this project, or use git commands as bellow :
```bash
$ git clone https://github.com/GouruRK/rpn-calculator.git
```

This repo uses the [`readline library`](https://tiswww.case.edu/php/chet/readline/rltop.html). Donwload it with 
```bash
$ sudo apt-get install libreadline-dev.
```

To compile it, go in the `rpn-calculator` folder and run the `make` command to compile it. It creates an executable `rpn`.
```bash
$ cd rpn-calculator
$ make
$ ./rpn
```

## Examples

```bash
$ ./rpn
1 3 p + 4 * p q
3
16
```

```bash
$ ./rpn
p c a 1 a c a c 0 r 1 r / % ^ a 3 ^ a 3 r ^ a 42 1984 a - - - - a 1947 - a ! 5 + ! a q
rpn: stack empty
[] <- HEAD
[1] <- HEAD
[] <- HEAD
rpn: stack empty
rpn: divide by 0
rpn: divide by 0
[1] <- HEAD
[1] <- HEAD
[3] <- HEAD
[3, 42, 1984] <- HEAD
rpn: stack empty
rpn: stack empty
[1945] <- HEAD
[-2] <- HEAD
rpn: factorial of negative number
[6] <- HEAD
```

## How to use

* Tokens must be separated by spaces or new lines
* Relatives numbers must be written as `-a`
* This implementation does not support floating numbers
* If computing a sequence triggers an error, the stack stays untouched

## Supported operation

Operation | Input | Calculated
:--------:|:-----:|:---------:
`+`       |`a b +`|`a + b`
`-`       |`a b -`|`a - b`
`*`       |`a b *`|`a * b`
`/`       |`a b /`|`a / b`
`%`       |`a b %`|`a % b`
`^`       |`a b ^`|`a ^ b`
`!`       | `a !` |`a!`

## Supported commands
* `a` : Print the stack
* `p` : Print the first element of the stack
* `r` : Reverse the top two elements of the stack
* `c` : Clear the stack
* `q` : Quit

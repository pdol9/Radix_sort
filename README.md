# sorting program

This program uses implementation of radix sort to sort positive and negative numbers in ascending order with the least instructions (moves) possible, specifically for set of 100 and 500 numbers, with following limitations:

- allowed system calls (read, write, malloc, free, exit)
- no global variables
- using only 2 stacks
- allowed operations to sort:
    ~ sa  -> swap first two elements at the top of stack A
    ~ pa  -> push element from stack B to stack A
    ~ ra  -> move element from top to bottom of stack A 
    ~ rra -> move element from bottom to top of stack A 
    ~ sb  -> swap first two elements at the top of stack B
    ~ pb  -> push element from stack A to stack B
    ~ rb  -> move element from top to bottom of stack B 
    ~ rrb -> move element from bottom to top of stack B 

Program will print to the terminal names of operations carried out to sort the stack.


## Installation

```bash
make
```

## Usage

```bash

NUMBER_SET="34 2 13 -6"

./push_swap $NUMBER_SET | wc -l

# or

./push_swap 34 2 13 -6 | wc -l

# both return value 6 [number of operations to sort the stack]


```

## Testers

```bash
./checker_linux [input]
```



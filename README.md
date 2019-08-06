# abstract_vm [[42](https://www.42.fr/) project]

## Project
The purpose of this project is to create a simple virtual machine that uses a stack to compute simple arithmetic expressions

These arithmetic expressions are provided to the machine as basic assembly programs


## Make the project

``` bash
make
```

## The assembly language
The language of AbstractVM is composed of a series of instructions, with one instruction per line

- Comments:

		Comments start with a ’;’ and finish with a newline.
		A comment can be either at the start of a line, or after an instruction.

- push V:

		Pushes the value V at the top of the stack.

		The value v must have one of the following form:
		- int8(n) : Creates an 8-bit integer with value n.
		- int16(n) : Creates a 16-bit integer with value n.
		- int32(n) : Creates a 32-bit integer with value n.
		- float(z) : Creates a float with value z.
		- double(z) : Creates a double with value z.

- pop:

		Unstacks the value from the top of the stack.

- dump:

		Displays each value of the stack, from the most recent one to the oldest one.

- assert V:

		Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction.
		The value v has the same form that those passed as parameters to the instruction push.

- add:

		Unstacks the first two values on the stack, adds them together and stacks the result.

- sub:

		Unstacks the first two values on the stack, subtracts them, then stacks the result.

- mul:

		Unstacks the first two values on the stack, multiplies them, then stacks the result.

- div:

		Unstacks the first two values on the stack, divides them, then stacks the result.

- mod:

		Unstacks the first two values on the stack, calculates the modulus, then stacks the result.

- print:

		Asserts that the value at the top of the stack is an 8-bit integer.
		Then displays the corresponding ASCII character on the standard output.

- exit:

		Terminate the execution of the current program.

### Bonus instructions

- abs:

		Unstacks the first value on the stack, apply abs to it, then stacks the result.

- min:

		Print the minimum value of the stack

- max:

		Print the maximum value of the stack

- pow:

		Unstacks the first two values on the stack, calculates the power, then stacks the result.

- not:

		Unstacks the first value on the stack, apply a bitwise NOT to it, then stacks the result.
		Only work on integer

- and:

		Unstacks the first two values on the stack, apply a bitwise AND to them, then stacks the result.
		Only work on integer

- or:

		Unstacks the first two values on the stack, apply a bitwise OR to them, then stacks the result.
		Only work on integer

- xor:

		Unstacks the first two values on the stack, apply a bitwise XOR to them, then stacks the result.
		Only work on integer

- clear:

		Clear the stack

## Usage
```
usage: ./avm [-vVcCwWeE] [filename]

If the filename is not given, the program read the commands from the standard input
When reading from the standard input, the end of the program is
indicated by the special symbol ";;" otherwise absent

optional arguments:

-v, -V			run the program in verbose mode
	print command and the stack before each action

-c, -C			print the program with syntax highlighting

-w, -W			stop the program on warning

-e, -E			don't stop the program on syntax error in stdin mode
	symply ignore the misspelled commands

```
Example
```
cat test/sample.avm
```

Return
```
; -------------
; sample.avm -
; -------------

push int32(42) ; comment
push int32(33) ; comment
add
push float(44.55)
mul
push double(42.42)
push int32(42)
dump
pop
assert double(42.42)
exit
```
Execution

```
./avm test/sample.avm
```

Return
```
42
42.42
3341.25
```

#### Exemple with verbose mode:

Execution

```
./avm -v test/sample.avm
```

Return
```
push int32(42)
stack {42}

push int32(33)
stack {33, 42}

add
stack {75}

push float(44.55)
stack {44.55, 75}

mul
stack {3341.25}

push double(42.42)
stack {42.42, 3341.25}

push int32(42)
stack {42, 42.42, 3341.25}

dump
	42
	42.42
	3341.25
stack {42, 42.42, 3341.25}

pop
stack {42.42, 3341.25}

assert double(42.42)
stack {42.42, 3341.25}

exit
```

See more on the [subject](https://github.com/zer0nim/abstract_vm/blob/master/abstract-vm.en.pdf).

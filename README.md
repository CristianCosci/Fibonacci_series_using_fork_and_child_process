# Fibonacci Series using fork to create child process :children_crossing:

A program that recursively calculates the `X`-th Fibonacci number using a **separate process for each call**.
- The X value must be passed as an argument
- This value must be between 0 and 10
- `Tip`: use the status retrieved via `waitpid` to "return" the calculated value.

I remind you that the X-th Fibonacci number is calculated in the following way:
$$
f(X) = f(X-1) + f(X-2)
$$

Initial sequence: 0 1 1 2 3 5 8 13 ...

In particular 
$$
f(0) = 0;
$$
$$
f(1) = 1
$$
$$
f(2) = f(0) + f(1) = 0 + 1 = 1 ...
$$

Example:
```bash
./fibonacci 7
13
```

### Program running instruction:
- Move to directory with the makefile and the c script
- Use 
    ```bash 
    make
    ```
    and next you can run the program with 
    ```bash
    ./fibonacci
    ```
- Use 
    ```bash
    make clean
    ```
    to remove the compilated file
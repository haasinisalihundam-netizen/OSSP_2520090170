# OSSP Mini Shell

A small Linux shell developed for the Operating Systems and System Programming laboratory.

## Features

- Reads commands from the user
- Splits commands into arguments
- Creates child processes using fork()
- Executes programs using execvp()
- Waits for child processes using waitpid()
- Supports built-in commands: cd, pwd, help and exit

## Build

```bash
make
```

## Run

```bash
make run
```

or:

```bash
./scripts/run.sh
```

## Clean Generated Files

```bash
make clean
```

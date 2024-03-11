# htoc

htoc is a command line tool that takes in a header file and will create a template c/cpp file from it.

## Installation

Clone Repository and Change Directory into the new folder.
```bash
git clone https://www.github.com/kirkseytc/htoc.git && cd htoc
```

Install Command:
```bash
sudo make install
```

## Usage

Single File Usage:
```bash
htoc example.h
```

Multiple File Usage:
```bash
htoc example1.h example2.h example3.h
```

C++ Usage:
```bash
htoc -cpp example.h
```

## Goal of Project

The goal of this project is to help teach me how to manage files and directories and to read/write files in directories in C.

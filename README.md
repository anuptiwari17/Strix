# Strix - Custom Low-Level String Library in C++

This is a minimal, zero-dependency, manual implementation of a string class in C++ for learning low-level programming, memory management, and Rule of 5.

## Features:
- Manual memory allocation (no std::string)
- Rule of 5: Copy, Move, Destroy, Assign
- Concatenation (`+` operator)
- Indexing (`[]`)
- Equality/Inequality checks
- Substring extraction (`substr`)

## How to Build & Run:
```bash
g++ main.cpp Strix.cpp -o strix
./strix

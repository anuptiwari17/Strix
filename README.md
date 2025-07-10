# 🚀 Strix — A Zero-Dependency Lightweight String Library in C++

> A fully self-written, low-level custom string class built from scratch without any standard library string utilities.
> 

---

## 📜 About the Project

**Strix** is a custom-built string class in C++ designed for:

- Practicing low-level memory management.
- Understanding Rule of Five (copy/move constructors, assignment operators).
- Implementing string operations manually without `std::string` or `<string.h>`.

✅ **Zero-dependency** (no standard string functions).

✅ **Deep dive into raw memory, OOP, and exception safety.**

✅ **Built for performance and learning core C++ internals.**

---

## 💡 Features Implemented

| Feature | Description |
| --- | --- |
| **Constructors** | Default, C-string (`const char*`), Copy, Move, and Pre-sized. |
| **Destructor** | Safely releases allocated memory. |
| **Rule of 5** | Full copy/move assignment and constructor support. |
| **Size & Access** | `size()`, `c_str()`, mutable and const indexing (`operator[]`). |
| **Equality & Inequality** | `==` and `!=` operators with efficient comparison. |
| **Relational Operators** | `<`, `>`, `<=`, `>=` — all correctly using lexicographic comparison. |
| **Concatenation** | `operator+` and `operator+=` for string joining. |
| **Substring Extraction** | `substr(start, length)` extracts part of the string. |
| **Insert & Erase** | Insert substring anywhere; erase part of the string. |
| **Replace** | Replace part of the string with another string. |
| **Clear** | Reset string to empty. |
| **Iterators (Custom)** | Supports `begin()` and `end()` to enable range-based loops (`for(auto c : str)`). |

---

## 🔧 How to Use

### Example Usage (main.cpp)

```cpp
#include <iostream>
#include "Strix.h"

int main() {
    Strix s1("Hello");
    Strix s2 = s1;  // Copy constructor
    Strix s3 = Strix("World");  // Move constructor

    std::cout << s1.c_str() << " (size: " << s1.size() << ")\n";

    s2[0] = 'Y';  // Indexing write
    std::cout << s2.c_str() << "\n";

    Strix s4 = s1 + s3;  // Concatenation
    std::cout << s4.c_str() << "\n";

    Strix sub = s4.substr(1, 4);
    std::cout << "Substring: " << sub.c_str() << "\n";

    s4.insert(5, Strix("INSERT"));
    std::cout << "After Insert: " << s4.c_str() << "\n";

    s4.erase(2, 3);
    std::cout << "After Erase: " << s4.c_str() << "\n";

    s4.replace(2, 2, Strix("XX"));
    std::cout << "After Replace: " << s4.c_str() << "\n";

    // Relational comparisons
    if (s1 < s3) std::cout << s1.c_str() << " < " << s3.c_str() << "\n";

    // Range-based loop using iterators
    for (auto ch : s1) {
        std::cout << ch << ' ';
    }
    std::cout << "\n";

    return 0;
}

```

---

## 🏗 Project Structure

```
Strix/
├── Strix.h        # Class Declaration (Public & Private APIs)
├── Strix.cpp      # Class Implementation
└── main.cpp       # Test Script

```

---

## 📚 Key Concepts Demonstrated

1. **Raw Memory Management** → Manual `new[]` and `delete[]` without STL help.
2. **Rule of Five** → Deep understanding of when and how to write:
    - Copy constructor
    - Move constructor
    - Copy assignment operator
    - Move assignment operator
    - Destructor
3. **Operator Overloading** → Building intuitive operator-based interfaces (`+`, `==`, `!=`, etc.).
4. **Iterators** → Enable seamless use with `for(auto c : str)`.

---

## 🚀 How to Compile & Run

```bash
g++ -std=c++17 main.cpp Strix.cpp -o strix
./strix

```

✅ No external dependencies required.

✅ Pure C++.

---

## 📈 Future Ideas / Improvements

- Implement memory optimizations like **Small String Optimization (SSO)**.
- Add **find** and **replace_all** methods.
- Make it **thread-safe** (with optional mutexes).
- Add **Unicode/UTF-8** support.
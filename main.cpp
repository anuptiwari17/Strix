#include <iostream>
#include "Strix.h"

void printStrix(const Strix& s, const std::string& name) {
    std::cout << name << ": \"" << s.c_str() << "\" (size: " << s.size() << ")\n";
}

int main() {
    //test 1: Constructor from const char*
    Strix s1("Hello");
    printStrix(s1, "s1");

    //test 2: Copy constructor
    Strix s2 = s1;
    printStrix(s2, "s2 (copy of s1)");

    //test 3: Move constructor
    Strix s3 = Strix("Hello again");
    printStrix(s3, "s3");

    //test 4: Equality check
    std::cout << "s1 == s2? " << (s1 == s2 ? "Yes" : "No") << "\n";
    std::cout << "s1 == s3? " << (s1 == s3 ? "Yes" : "No") << "\n";

    //test 5: Inequality check
    std::cout << "s1 != s3? " << (s1 != s3 ? "Yes" : "No") << "\n\n";

    //test 6: Concatenation operator+
    Strix s4 = s1 + s3;
    printStrix(s4, "s4 (s1 + s3)");

    //test 7: Concatenation operator+=
    s4 += s1;
    printStrix(s4, "s4 after += s1");

    //test 8: Indexing read
    std::cout << "s1[1]: " << s1[1] << "\n";

    //test 9: Indexing write
    s2[0] = 'Y';
    printStrix(s2, "Modified s2");

    //test 10: Clear
    s3.clear();
    printStrix(s3, "Cleared s3");

    //test 11: Assignment operator
    s3 = s1;
    printStrix(s3, "s3 after assignment");

    //test 12: Move assignment
    s3 = Strix("MovedIn");
    printStrix(s3, "s3 after move assignment");

    //test 13: Substring extraction
    Strix sub1 = s1.substr(0, 3);
    printStrix(sub1, "Substring of s1 (0,3)");

    //test 14: Insert
    Strix s5("Heo");
    s5.insert(2, Strix("ll"));
    printStrix(s5, "s5 after insert(2, 'll')");

    //test 15: Erase
    s5.erase(1, 2);
    printStrix(s5, "s5 after erase(1,2)");

    //test 16: Replace
    s5.replace(1, 1, Strix("AB"));
    printStrix(s5, "s5 after replace(1,1,'AB')");

    //test 17: Relational operators
    Strix a("apple");
    Strix b("banana");
    std::cout << "a < b? " << (a < b ? "Yes" : "No") << "\n";
    std::cout << "a > b? " << (a > b ? "Yes" : "No") << "\n";
    std::cout << "a <= b? " << (a <= b ? "Yes" : "No") << "\n";
    std::cout << "a >= b? " << (a >= b ? "Yes" : "No") << "\n\n";

    //test 18: Iterators (manual loop)
    Strix s6("IteratorTest");
    std::cout << "Characters in s6 using iterator: ";
    for (auto it = s6.begin(); it != s6.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\n";

    //test 19: Iterators (range-based for loop)
    std::cout << "Characters in s6 using range-based for: ";
    for (char ch : s6) {
        std::cout << ch << ' ';
    }
    std::cout << "\n";

    return 0;
}

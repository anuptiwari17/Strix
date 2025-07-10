#include <iostream>
#include "Strix.h"

int main() {
    // test 1: Constructor from const char*
    Strix s1("Hello");
    std::cout << "s1: " << s1.c_str() << " (size: " << s1.size() << ")\n";

    // test 2: Copy constructor
    Strix s2 = s1;
    std::cout << "s2 (copy of s1): " << s2.c_str() << "\n";

    // test 3: Move constructor
    Strix s3 = Strix("Hello again");
    std::cout << "s3: " << s3.c_str() << "\n";

    // test 4: Equality check
    std::cout << "s1 == s2? " << (s1 == s2 ? "Yes" : "No") << "\n";
    std::cout << "s1 == s3? " << (s1 == s3 ? "Yes" : "No") << "\n";

    // test 5: Inequality check
    std::cout << "s1 != s3? " << (s1 != s3 ? "Yes" : "No") << "\n";

    // test 6: Concatenation
    Strix s4 = s1 + s3;
    std::cout << "s4 (s1 + s3): " << s4.c_str() << "\n";

    // test 7: Indexing read
    std::cout << "s1[1]: " << s1[1] << "\n";

    // test 8: Indexing write
    s2[0] = 'Y';
    std::cout << "Modified s2: " << s2.c_str() << "\n";

    // test 9: Clear
    s3.clear();
    std::cout << "Cleared s3: '" << s3.c_str() << "' (size: " << s3.size() << ")\n";

    // test 10: Assignment operator
    s3 = s1;
    std::cout << "s3 after assignment: " << s3.c_str() << "\n";

    // test 11: Move assignment
    s3 = Strix("MovedIn");
    std::cout << "s3 after move assignment: " << s3.c_str() << "\n";


    // test 12: Substring extraction
    Strix sub1 = s1.substr(0, 3);
    std::cout << "Substring of s1 (0,3): " << sub1.c_str() << "\n\n";

    return 0;
}

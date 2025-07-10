#ifndef STRIX_H
#define STRIX_H

#include <cstddef>  // For size_t (still 0 dep)

template<typename T>
constexpr T&& moveS(T& t) noexcept {
    return static_cast<T&&>(t);
}

class Strix {
private:
    char* data_;    
    size_t size_;   

    void copyFrom(const Strix& other);
    void moveFrom(Strix&& other) noexcept;

    Strix(size_t totalSize);


public:
    Strix();                             // Default constructor
    Strix(const char* str);               // From C-string
    Strix(const Strix& other);            // Copy constructor
    Strix(Strix&& other) noexcept;        // Move constructor

    
    ~Strix();

    void clear() noexcept;

    bool operator==(const Strix& other) const noexcept;
    bool operator!=(const Strix& other) const noexcept;

    Strix& operator=(const Strix& other);
    Strix& operator=(Strix&& other) noexcept;

    Strix operator+(const Strix& other) const;


    
    size_t size() const noexcept;
    const char* c_str() const noexcept;


    // non-const : allows writing: s[0] = 'A';
    char& operator[](size_t index);

    // const : read-only: char ch = s[0];
    const char& operator[](size_t index) const;

    Strix substr(size_t start, size_t length) const;


};

#endif

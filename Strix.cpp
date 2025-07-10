#include "Strix.h"
#include <cassert>


void Strix::copyFrom(const Strix& other) {
    size_ = other.size_;
    data_ = new char[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    data_[size_] = '\0';
}

void Strix::moveFrom(Strix&& other) noexcept {
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
}


Strix::Strix(size_t totalSize) : size_(totalSize) {
    data_ = new char[size_ + 1];
    data_[size_] = '\0';
}




Strix::Strix() : data_(new char[1]{'\0'}), size_(0) {}

Strix::Strix(const char* str) {
    if (!str) {
        size_ = 0;
        data_ = new char[1]{'\0'};
        return;
    }

    size_ = 0;
    while (str[size_] != '\0') size_++;

    data_ = new char[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = str[i];
    }
    data_[size_] = '\0';
}

Strix::Strix(const Strix& other) {
    copyFrom(other);
}

Strix::Strix(Strix&& other) noexcept {
    moveFrom(moveS(other));
}



Strix::~Strix() {
    delete[] data_;
}



Strix& Strix::operator=(const Strix& other) {
    if (this != &other) {
        delete[] data_;
        copyFrom(other);
    }
    return *this;
}

Strix& Strix::operator=(Strix&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        moveFrom(moveS(other));
    }
    return *this;
}

void Strix::clear() noexcept {
    delete[] data_;
    data_ = new char[1]{'\0'};
    size_ = 0;
}

bool Strix::operator==(const Strix& other) const noexcept {
    if (this == &other) return true;

    if (size_ != other.size_) return false;

    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) return false;
    }
    return true;
}

bool Strix::operator!=(const Strix& other) const noexcept {
    return !(*this == other);
}


size_t Strix::size() const noexcept {
    return size_;
}

const char* Strix::c_str() const noexcept {
    return data_;
}




Strix Strix::operator+(const Strix& other) const {
    Strix result(size_ + other.size_);

    for (size_t i = 0; i < size_; ++i) {
        result.data_[i] = data_[i];
    }

    for (size_t i = 0; i < other.size_; ++i) {
        result.data_[size_ + i] = other.data_[i];
    }

    result.data_[result.size_] = '\0';
    return result;
}

char& Strix::operator[](size_t index) {   //non-const version
    assert(index < size_ && "Index out of range");
    return data_[index];
}


const char& Strix::operator[](size_t index) const {      //const version
    assert(index < size_ && "Index out of range");
    return data_[index];
}



Strix Strix::substr(size_t start, size_t length) const {
    if (start >= size_) {
        return Strix("");
    }

    size_t actualLength = (start + length > size_) ? (size_ - start) : length;
    
    Strix result(actualLength);

    for (size_t i = 0; i < actualLength; ++i) {
        result.data_[i] = data_[start + i];
    }
    result.data_[actualLength] = '\0';

    return result;
}

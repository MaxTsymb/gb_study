#pragma once
#include <iostream>

template<class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
protected:
    T* current;
public:
    explicit Iterator(T* current) : current(current) {}

    T& operator+ (int n) {
        return *(current + n);
    }

    T& operator- (int n) {
        return *(current - n);
    }

    T& operator++ (int) {
        return *current++;
    }

    T& operator-- (int) {
        return *current--;
    }

    T& operator++ () {
        return *++current;
    }

    T& operator-- () {
        return *--current;
    }

    bool operator!= (const Iterator& it) {
        return current != it.current;
    }

    bool operator== (const Iterator& it) {
        return current == it.current;
    }

    T& operator* () {
        return *current;
    }
};

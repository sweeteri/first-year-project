#include <iostream>
#include "vector.hpp"

using IBusko::Vector;

template <typename T> Vector<T>::Vector::Vector() noexcept {
    this->arr = new T[this->capacity];
}

template <typename T> Vector<T>::Vector::~Vector() noexcept {
    delete[] this->arr;
}

template <typename T> void Vector<T>::Vector::push_back(const T& value) noexcept {
    if (this->capacity == this->size) {
        T* new_array = new T[this->capacity * 2];

        for (std::size_t i = 0; i < this->size; i++) {
            new_array[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = new_array;
        this->capacity *= 2;
    }

    this->arr[this->size] = value;
    this->size++;
}

template <typename T> bool Vector<T>::Vector::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < this->size; i++) {
        if (this->arr[i] == value) return true;
    }
    return false;
}

template <typename T> bool Vector<T>::Vector::insert(const int position, const T& value) {
    if (position < 0 || position > this->size) {
        return false;
    }

    if (this->capacity == this->size) {
        T* new_array = new T[this->capacity * 2];

        for (std::size_t i = 0; i < this->size; i++) {
            new_array[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = new_array;
        this->capacity *= 2;
    }

    for (std::size_t i = this->size; i > position; i--) {
        this->arr[i] = this->arr[i - 1];
    }

    this->arr[position] = value;
    this->size++;

    return true;
}

template <typename T> void Vector<T>::Vector::print() const noexcept {
    for (std::size_t i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T> bool Vector<T>::Vector::remove_first(const T& value) noexcept {
    for (std::size_t i = 0; i < this->size; i++) {
        if (this->arr[i] == value) {
            for (std::size_t j = i; j < this->size - 1; j++) {
                this->arr[j] = this->arr[j + 1];
            }
            this->size--;
            return true;
        }
    }
    return false;
}

template <typename T> int Vector<T>::Vector::ssize() const noexcept {
    return this->size;
}

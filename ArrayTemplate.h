#ifndef ARRAY_TEMPLATE_ARRAYTEMPLATE_H
#define ARRAY_TEMPLATE_ARRAYTEMPLATE_H

#include <iostream>

template<typename T>
class ArrayTemplate {
public:
    explicit ArrayTemplate(int size);

    ~ArrayTemplate();

    [[maybe_unused]] ArrayTemplate(const ArrayTemplate<T> &other);

    ArrayTemplate<T> &operator=(const ArrayTemplate<T> &other);

    void display() const;

    [[maybe_unused]] [[nodiscard]] int getSize() const;

    [[nodiscard]] T getValue(int index) const;

    void setValue(int index, T value);

private:
    T *arr;
    int size{};
};

template<typename T>
ArrayTemplate<T>::ArrayTemplate(int size) : size(size) {
    arr = new T[size];
}

template<typename T>
ArrayTemplate<T>::~ArrayTemplate() {
    delete[] arr;
}

template<typename T>
[[maybe_unused]] ArrayTemplate<T>::ArrayTemplate(const ArrayTemplate<T> &other) {
    size = other.size;
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

template<typename T>
ArrayTemplate<T> &ArrayTemplate<T>::operator=(const ArrayTemplate<T> &other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<typename T>
void ArrayTemplate<T>::display() const {
    for (int i = 0; i < size; i++) {
        std::cout << getValue(i) << " ";
    }
    std::cout << std::endl;
}

template<typename T>
[[maybe_unused]] int ArrayTemplate<T>::getSize() const {
    return size;
}

template<typename T>
T ArrayTemplate<T>::getValue(int index) const {
    return arr[index];
}

template<typename T>
void ArrayTemplate<T>::setValue(int index, T value) {
    arr[index] = value;
}

#endif //ARRAY_TEMPLATE_ARRAYTEMPLATE_H

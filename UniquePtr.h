#pragma once

#include <iostream>

template<class T>
class UniquePtr {
public:
    UniquePtr();
    explicit UniquePtr(T* rawPtr);

    UniquePtr(const UniquePtr<T>& other) = delete;
    UniquePtr(UniquePtr<T>&& other);
    UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;
    UniquePtr<T>& operator=(UniquePtr<T>&& other);
    ~UniquePtr();

    UniquePtr<T>& operator=(T* rawPtr);

    void reset();

    void reset(T* ptr);

    void release();

    operator bool() const;

    T& operator*() const;

    T* operator->() const;

    T* get() const;

private:
    T* _ptr;
};

template<class T>
UniquePtr<T>::UniquePtr() {
    _ptr = nullptr;
}

template<class T>
UniquePtr<T>::UniquePtr(T* rawPtr) {
    _ptr = rawPtr;
}

template<class T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) {
    _ptr = other._ptr;
    other._ptr = nullptr;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) {
    std::swap(_ptr, other._ptr);
}

template<class T>
UniquePtr<T>::~UniquePtr() {
    delete[] _ptr;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(T* rawPtr) {
    delete[] _ptr;
    _ptr = rawPtr;
}

template<class T>
void UniquePtr<T>::reset() {
    delete[] _ptr;
    _ptr = nullptr;
}

template<class T>
void UniquePtr<T>::reset(T* ptr) {
    delete[] _ptr;
    _ptr = ptr;
}

template<class T>
void UniquePtr<T>::release() {
    _ptr = nullptr;
}

template<class T>
UniquePtr<T>::operator bool() const {
    return _ptr ? true : false;
}

template<class T>
T& UniquePtr<T>::operator*() const {
    return *_ptr;
}

template<class T>
T* UniquePtr<T>::operator->() const {
    return _ptr;
}

template<class T>
T* UniquePtr<T>::get() const {
    return _ptr;
}
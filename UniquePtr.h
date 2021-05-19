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

    void swap(const UniquePtr<T> other);

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
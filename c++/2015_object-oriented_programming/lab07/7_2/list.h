#pragma once


//! List interface
template <typename T>
class List
{
public:
    //! Thrown when removing a non-existing element
    class NoElementError {};
    virtual ~List() {}
    //! Get list length
    int virtual len() const = 0;
    //! Print list
    void virtual print() const = 0;
    //! Append new element to the list
    void virtual append(const T &value) = 0;
    //! Pop leftmost element from the list
    T virtual popleft() = 0;
protected:
    List() : length(0) {}
    int length;
};
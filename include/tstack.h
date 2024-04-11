// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
template <class T, int size>
class TStack {
private:
    T *stackPtr;
    int top;
public:
    TStack();
    ~TStack();
    void push(const T &value);
    T pop();
    bool isEmpty();
};

#endif  // INCLUDE_TSTACK_H_

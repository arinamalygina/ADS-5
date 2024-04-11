// Copyright 2021 NNTU-CS
#include "tstack.h"
#include <string>
#include <sstream>
#include <iostream>
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int getPriority(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack;
    std::string postfix = "";
    for (char &c : inf) {
        if (std::isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.pop() != '(') {
                postfix += ' ';
            }
        } else if (isOperator(c)) {
            postfix += ' ';
            while (!stack.isEmpty() &&
                getPriority(stack.pop()) >= getPriority(c)) {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty()) {
        postfix += ' ';
        postfix += stack.pop();
    }
    return postfix;
}
int eval(std::string post) {
    TStack<int, 100> stack;
    std::istringstream stream(post);
    int num1, num2;
    char op;
    while (stream >> num1) {
        if (std::isdigit(stream.peek())) {
            stack.push(num1);
        } else {
            stream >> op;
            num2 = stack.pop();
            num1 = stack.pop();
            switch (op) {
                case '+':
                    stack.push(num1 + num2);
                    break;
                case '-':
                    stack.push(num1 - num2);
                    break;
                case '*':
                    stack.push(num1 * num2);
                    break;
                case '/':
                    stack.push(num1 / num2);
                    break;
            }
        }
    }
    return stack.pop();
}

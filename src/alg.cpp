// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char op) {
  if (op == '(')
    return 0;
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return -1;
}
std::string infx2pstfx(std::string inf) {
  std::string pstfx = "";
  tstack < char, 100 > stack;

  for (int i = 0; i < inf.length(); i++) {
    if (isdigit(inf[i])) {
      while (isdigit(inf[i])) {
        pstfx += inf[i];
        i++;
      }
      pstfx += " ";
      i--;
    } else if (inf[i] == '(') {
      stack.push('(');
    } else if (inf[i] == ')') {
      while (stack.get() != '(') {
        pstfx += stack.pop();
        pstfx += " ";
      }
      stack.pop();
    } else {
      while (!stack.isEmpty() && priority(stack.get()) >= priority(inf[i])) {
        pstfx += stack.pop();
        pstfx += " ";
      }
      stack.push(inf[i]);
    }
  }

  while (!stack.isEmpty()) {
    pstfx += stack.pop();
    pstfx += " ";
  }

  return pstfx;
}

int eval(std::string pref) {
  tstack < int, 100 > stack;

  for (int i = 0; i < post.length(); i++) {
    if (isdigit(post[i])) {
      int num = 0;
      while (isdigit(post[i])) {
        num = num * 10 + (post[i] - '0');
        i++;
      }
      stack.push(num);
    } else if (post[i] != ' ') {
      int num2 = stack.pop();
      int num1 = stack.pop();

      switch (post[i]) {
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
  return stack.get();
}

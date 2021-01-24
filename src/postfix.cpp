// Copyright 2020 VladimirUspensky
#include <map>
#include <vector>
#include "MyStack.h"
#include "postfix.h"

int check_symbol(char symbol) {
    if (symbol == '+' || symbol == '-') return 1;
    else if (symbol == '*' || symbol == '/') return 2;
    else if (symbol >= '0' && symbol <= '9') return 3;
    else if (symbol == ')') return 4;
    else
        return -1;
}


std::string infix2postfix(std::string infix) {
    MyStack <char> stack(infix.size());
    std::string result;
    for (char el : infix) {
        if (el == '.') {
            result += el;
            continue;
        }
        else if (check_symbol(el) == 3) {
            result += el;
            result += ' ';
        } else if (el == '(') stack.push(el);
        else if (check_symbol(el) == 1) {
            if (check_symbol(stack.get()) <= 1 || stack.isEmpty()) stack.push(el);
            else if (check_symbol(stack.get()) == 2) {
                result += stack.pop();
                result += ' ';
                stack.push(el);
            }
        }

        else if (check_symbol(el) == 4) {
            while (!(stack.isEmpty())) {
                if (stack.get() == '(') {
                    stack.pop();
                    break;
                }

                result += stack.pop();
                result += ' ';
            }
        } else if (check_symbol(el) == 2) {
            if (check_symbol(stack.get()) == 2) {
                result += stack.pop();
                result += ' ';
                stack.push(el);
            } else {
                stack.push(el);
            }
        }
    }
    while (!(stack.isEmpty())) {
        result += stack.pop();
        result += ' ';
    }
    std::string postfix;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == ' ' && result[i + 1] == '.') {
            continue;
        } else {
            postfix += result[i];
        }
    }
    if (postfix[postfix.size() - 1] == ' ') postfix.pop_back();

    return postfix;
}

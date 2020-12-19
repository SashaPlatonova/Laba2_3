#include <iostream>
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <exception>
float div(float number1, float number2);
void calculateRPN();


int main() {
//        try {
//            float a = div(10.0f, 5.0f);
//            std::cout << a;
//        } catch (const std::exception &err) {
//
//        }
    calculateRPN();

    return 0;
}
float div(float number1, float number2){
    if(!number2){
        throw std::exception();
    } else
        return number1/number2;
}
void calculateRPN(){
    std::stack<float> stack;
    while (true) {
        std::string expression;
        std::cin >> expression;
        if(expression=="exit"){
            break;
        }
        char operation = expression[0];
        float value;
        std::istringstream iss(expression);
        if (iss >> value) {
            stack.push(value);
        } else {

            value = stack.top();
            stack.pop();
            switch (operation) {
                case '+' :
                    value += stack.top();
                    stack.pop();
                    stack.push(value);
                    continue;
                case '-':
                    value -= stack.top();
                    stack.pop();
                    stack.push(value);
                    continue;
                case '*':
                    value *= stack.top();
                    stack.pop();
                    stack.push(value);
                    continue;
                case '/':
                    try {
                        value = div(stack.top(), value);
                        stack.pop();
                        stack.push(value);
                    } catch (const std::exception &err) {

                    }

                    continue;
                case '=':
                    std::cout << "result is " << value << std::endl;
                    break;
                default:
                    std::cout << "Wrong input data" << std::endl;
                    break;
            }
        }

    }
}

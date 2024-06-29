#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            std::cout << "Error: Division by zero is not allowed." << std::endl;
            return 0;
        }
    }
};

int main() {
    double num1, num2;
    char operation;
    Calculator calc; // Create an object of Calculator class
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    double result;
    bool validOperation = true;

    switch (operation) {
        case '+':
            result = calc.add(num1, num2);
            break;
        case '-':
            result = calc.subtract(num1, num2);
            break;
        case '*':
            result = calc.multiply(num1, num2);
            break;
        case '/':
            result = calc.divide(num1, num2);
            break;
        default:
            std::cout << "Error: Invalid operation. Please use +, -, *, or /." << std::endl;
            validOperation = false;
    }

    if (validOperation && !(operation == '/' && num2 == 0)) {
        cout << "Result: " << result << std::endl;
    }

    return 0;
}

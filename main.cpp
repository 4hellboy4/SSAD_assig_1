#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

class Complex {
private:
    float real;
    float imaginary;
public:
    Complex() : real(0.0), imaginary(0.0) {}

    Complex(float a, float b) : real(a), imaginary(b) {}

    Complex operator+(Complex& other) {
        return {this->getReal() + other.getReal(), this->getImaginary() + other.getImaginary()};
    }

    Complex operator-(Complex& other) {
        return {this->getReal() - other.getReal(), this->getImaginary() - other.getImaginary()};
    }

    Complex operator*(Complex& other) {
        return {this->getReal() * other.getReal() + this->getImaginary()*other.getImaginary()*(-1), this->getImaginary()*other.getReal() + this->getReal()*other.getImaginary()};
    }

    Complex operator/(Complex& other) {
        float divider = other.getReal()*other.getReal() + other.getImaginary()*other.getImaginary();
        return {this->getReal() / divider, this->getImaginary() / divider};
    }

    bool operator==(Complex& other) {
        return (this->getReal() == other.getReal() && this->getImaginary() == other.getImaginary());
    }

    float getReal() {
        return real;
    }

    float getImaginary() {
        return imaginary;
    }


};

string getResult(Complex result) {
    ostringstream stream;
    if (result.getImaginary() < 0.0) {
        stream << fixed << setprecision(2) <<result.getReal() << "" << result.getImaginary() << "i";
    } else {
        stream << fixed << setprecision(2) <<result.getReal() << "+" << result.getImaginary() << "i";
    }
    return stream.str();
}

int main() {
    int n;

    cin >> n;

    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        string op;
        float a, b, c, d;
        cin >> op >> a >> b >> c >> d;
        Complex num1 = Complex(a,b);
        Complex num2 = Complex(c,d);
        Complex result;
        if (op == "+") {
            result = num1 + num2;
        } else if (op == "-") {
            result = num1 - num2;
        } else if (op == "*") {
            result = num1 * num2;
        } else if (op == "/") {
             Complex t = Complex(c, -d);
             result = num1*t;
             result = result / num2;
        } else {
            answer.emplace_back(num1 == num2 ? "true" : "false");
            continue;
        }
        answer.emplace_back(getResult(result));
    }

    for (string element : answer) {
        cout << element << endl;
    }

    return 0;
}
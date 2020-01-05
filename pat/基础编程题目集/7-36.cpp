#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

std::string doubleToStr(double value) {
    char* chCode;
    chCode = new (std::nothrow) char[80];
    sprintf(chCode, "%.1f", value);  // .1 是控制输出精度的，两位小数
    string strCode(chCode);
    delete[] chCode;
    return strCode;
}

class Plural {
   public:
    double real, imaginary;
    string toString(bool simple = true) {
        string str = "";
        string rs = doubleToStr(real);
        string is = doubleToStr(imaginary);
        if (simple) {
            if (is == "0.0" || is == "-0.0") {
                str = rs;
            } else {
                if (rs == "0.0" || rs == "-0.0") {
                    str = is + "i";
                } else {
                    str = rs;
                    if (imaginary > 0) {
                        str += "+";
                    }
                    str += is + "i";
                }
            }
        } else {
            str = rs;
            if (imaginary >= 0) {
                str += "+";
            }
            str += is + "i";
        }
        return str;
    }
    Plural(double r, double i) {
        real = r;
        imaginary = i;
    }
    Plural() {}
    Plural operator+(Plural b) {
        return Plural(real + b.real, imaginary + b.imaginary);
    }
    Plural operator-(Plural b) {
        return Plural(real - b.real, imaginary - b.imaginary);
    }
    Plural operator*(Plural b) {
        return Plural(real * b.real - imaginary * b.imaginary,
                      real * b.imaginary + imaginary * b.real);
    }
    Plural operator/(Plural b) {
        double div = b.real * b.real + b.imaginary * b.imaginary;
        return Plural((real * b.real + imaginary * b.imaginary) / div,
                      (imaginary * b.real - real * b.imaginary) / div);
    }
};

int main(void) {
    Plural a, b;
    scanf("%lf %lf %lf %lf", &a.real, &a.imaginary, &b.real, &b.imaginary);

    printf("(%s) + (%s) = %s\n", a.toString(false).c_str(),
           b.toString(false).c_str(), (a + b).toString().c_str());
    printf("(%s) - (%s) = %s\n", a.toString(false).c_str(),
           b.toString(false).c_str(), (a - b).toString().c_str());
    printf("(%s) * (%s) = %s\n", a.toString(false).c_str(),
           b.toString(false).c_str(), (a * b).toString().c_str());
    printf("(%s) / (%s) = %s\n", a.toString(false).c_str(),
           b.toString(false).c_str(), (a / b).toString().c_str());
}
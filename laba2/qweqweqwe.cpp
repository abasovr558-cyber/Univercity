#include <iostream>
#include <cmath>

double simpson_rule(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++; // Делаем n четным
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);

    for (int i = 2; i < n - 1; i += 2)
        sum += 2 * f(a + i * h);

    return (h / 3) * sum;
}

double function1(double x) {
    return sin(x);
}

double function2(double x) {
    return cos(x);
}

double function3(double x) {
    return sin(0.5 * x) - 0.5;
}

double upper(double x) {
    double max_val = function1(x);
    if (function2(x) > max_val) max_val = function2(x);
    if (function3(x) > max_val) max_val = function3(x);
    return max_val;
}

double lower(double x) {
    double min_val = function1(x);
    if (function2(x) < min_val) min_val = function2(x);
    if (function3(x) < min_val) min_val = function3(x);
    return min_val;
}

double diff(double x) {
    return upper(x) - lower(x);
}

int main() {
    double a = 2.0;
    double b = 4.0;
    double area = simpson_rule(diff, a, b, 1000);
    std::cout << "Приближенное значение интеграла: " << area << std::endl;
    return 0;
}
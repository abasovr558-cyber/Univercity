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

double part1(double x)
{
    return function1(x) - function3(x);
}

double part2(double x)
{
    return function2(x) - function3(x);
}

int main()
{
    const double a = 2.0;
    const double c = 3.0 * M_PI / 4.0; // точка пересечения sin и cos
    const double b = 4.0;

    double area =
        simpson_rule(part1, a, c, 1000) +
        simpson_rule(part2, c, b, 1000);

    std::cout <<  "Приближенное значение интеграла: " << area << std::endl;

    return 0;
}
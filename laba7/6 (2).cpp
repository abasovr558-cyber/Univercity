#include <iostream>

int solve(int a, int n) {
    if (n == 0) return 1;

    int half = solve(a, n / 2);

    if (n % 2 == 0) {
        return half * half;
    }
    else {
        return a * half * half;
    }
}

int main() {
    int a, n;
    std::cin >> a >> n;
    std::cout << solve(a, n);
    return 0;
}
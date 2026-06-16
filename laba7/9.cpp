#include <vector>
#include <algorithm>
#include <iostream>

int solve(int n, int M, const std::vector<int>& weights) {
    std::vector<bool> dp(M + 1, false);
    dp[0] = true;

    for (int w : weights) {
        for (int j = M; j >= w; --j) {
            if (dp[j - w]) {
                dp[j] = true;
            }
        }
    }

    for (int j = M; j >= 0; --j) {
        if (dp[j]) {
            return j;
        }
    }
    return 0;
}

int main() {
    return 0;
}
#include <vector>
#include <algorithm>
#include <iostream>

int solve(int n, int M, const std::vector<int>& weights) {
    std::vector<bool> dp(M + 1, false);
    dp[0] = true;

    // Обратный обход от M до w необходим, чтобы каждый слиток учитывался строго один раз.
    // При прямом обходе (от w до M) только что полученное значение dp[j] по цепочке 
    // обновило бы dp[j + w], то есть алгоритм посчитал бы, что у нас бесконечное число слитков веса w.
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
    int n, M, weight;
    std::vector<int> weights;
    std::cin >> n >> M;
    for (int i = 0; i < n; i++) {
        std::cin >> weight;
        weights.push_back(weight);
    }
    std::cout << solve(n, M, weights) << std::endl;
}
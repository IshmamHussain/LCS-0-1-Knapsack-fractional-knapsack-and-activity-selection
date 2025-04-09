#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int weight[] = {10, 20, 30, 25};
    int value[] = {60, 100, 120, 90};
    int W = 50;

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value in knapsack: " << dp[n][W] << endl;
    return 0;
}
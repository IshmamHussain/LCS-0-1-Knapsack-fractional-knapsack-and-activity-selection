#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getLCS(const string &X, const string &Y) {
    int m = X.size(), n = Y.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (X[i - 1] == Y[j - 1]) {
                dp[j] = prev + 1;
            } else {
                if (dp[j] < dp[j - 1]) {
                    dp[j] = dp[j - 1];
                }
            }
            prev = temp;
        }
    }
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else {
            if (dp[j] > dp[j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    return lcs;
}

int main() {
    string X, Y;
    cin >> X >> Y;
    cout << "LCS: " << getLCS(X, Y) << endl;
    return 0;
}

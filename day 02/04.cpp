#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n = 3;
    int capacity = 15;

    int weight[] = {4, 6, 8};
    int revenue[] = {40, 70, 90};

    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    revenue[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "DP Table (Intermediate Stages):\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    cout << "\nMaximum Revenue = " << dp[n][capacity] << endl;

    cout << "Selected Cargo: ";
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << char('A' + i - 1) << " ";
            w -= weight[i - 1];
        }
    }

    return 0;
}

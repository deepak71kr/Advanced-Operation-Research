#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

// piecewise production cost
double productionCost(int z) {
    if (z <= 0) return 0;
    if (z <= 3) return 10.0 * z;
    return 30.0 + 20.0 * (z - 3);
}

int main() {

    int n = 3;

    int demand[] = {3, 2, 4};
    double setup[] = {3, 7, 6};
    double hold[] = {1, 3, 2};

    int startInventory = 1;

    int maxInv = 10;

    vector<vector<double>> dp(n + 1, vector<double>(maxInv + 1, INF));
    vector<vector<int>> decision(n, vector<int>(maxInv + 1, -1));

    for (int x = 0; x <= maxInv; x++)
        dp[n][x] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int x = 0; x <= maxInv; x++) {
            for (int z = 0; z <= maxInv; z++) {

                int available = x + z;
                if (available < demand[i]) continue;

                int endInv = available - demand[i];
                if (endInv > maxInv) continue;

                double cost = 0;

                if (z > 0) cost += setup[i];
                cost += productionCost(z);
                cost += hold[i] * endInv;
                cost += dp[i + 1][endInv];

                if (cost < dp[i][x]) {
                    dp[i][x] = cost;
                    decision[i][x] = z;
                }
            }
        }
    }

    cout << "Optimal total cost = " << dp[0][startInventory] << "\n";
    cout << "Optimal production plan:\n";

    int inv = startInventory;
    for (int i = 0; i < n; i++) {
        int z = decision[i][inv];
        cout << "Period " << i + 1 << ": Produce " << z << "\n";
        inv = inv + z - demand[i];
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

double productionCost(int z) {
    return 2.0 * z;
}

int main() {

    int n = 6;

    int demand[] = {10, 15, 7, 20, 13, 25};
    double setup[] = {20, 17, 10, 18, 5, 50};
    double hold[] = {1, 1, 1, 3, 1, 1};

    int startInventory = 0;

    int maxInv = 100;

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

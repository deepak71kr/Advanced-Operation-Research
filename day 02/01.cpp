#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int INF = INT_MAX;
    int n = 5;

    vector<vector<int>> cost = {
        {0, 4, 6, INF, INF},
        {INF, 0, 3, 7, 8},
        {INF, INF, 0, 2, 6},
        {INF, INF, INF, 0, 4},
        {INF, INF, INF, INF, 0}
    };

    vector<int> dp(n, INF);
    vector<int> parent(n, -1);

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != INF && dp[i] != INF && dp[i] + cost[i][j] < dp[j]) {
                dp[j] = dp[i] + cost[i][j];
                parent[j] = i;
            }
        }

        cout << "Stage " << i << " Costs: ";
        for (int k = 0; k < n; k++) {
            if (dp[k] == INF) cout << "INF ";
            else cout << dp[k] << " ";
        }
        cout << endl;
    }

    cout << "\nMinimum cost from A to E = " << dp[4] << endl;

    cout << "Shortest Path: ";
    vector<int> path;
    for (int v = 4; v != -1; v = parent[v])
        path.push_back(v);

    for (int i = path.size() - 1; i >= 0; i--)
        cout << char('A' + path[i]) << " ";

    return 0;
}

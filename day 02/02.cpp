#include <iostream>
#include <climits>
using namespace std;

int main() {
    int INF = INT_MAX;

    int cost[5][5] = {
        {0, 4, 6, INF, INF},
        {INF, 0, 3, 7, 8},
        {INF, INF, 0, 2, 6},
        {INF, INF, INF, 0, 4},
        {INF, INF, INF, INF, 0}
    };

    int dp[5];
    int nextNode[5];

    dp[4] = 0;
    nextNode[4] = -1;

    for (int i = 3; i >= 0; i--) {
        dp[i] = INF;
        nextNode[i] = -1;

        for (int j = i + 1; j < 5; j++) {
            if (cost[i][j] != INF && cost[i][j] + dp[j] < dp[i]) {
                dp[i] = cost[i][j] + dp[j];
                nextNode[i] = j;
            }
        }

        cout << "Backward Stage " << i << " Cost = ";
        if (dp[i] == INF) cout << "INF";
        else cout << dp[i];
        cout << endl;
    }

    cout << "\nMinimum cost from A to E = " << dp[0] << endl;

    cout << "Shortest Path: ";
    int v = 0;
    while (v != -1) {
        cout << char('A' + v) << " ";
        v = nextNode[v];
    }

    return 0;
}

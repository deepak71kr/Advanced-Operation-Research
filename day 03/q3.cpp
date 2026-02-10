#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int R = 6;                    // required minimum
    int c[2] = {3, 2};            // cost coefficients
    int a[2] = {1, 2};            // contribution coefficients

    vector<int> f1(R + 1, 0);
    vector<int> f2(R + 1, 0);

    // Stage 1: x1
    for (int r = 0; r <= R; r++) {
        f1[r] = c[0] * r;
    }

    // Stage 2: x2
    for (int r = 0; r <= R; r++) {
        int best = INT_MAX;
        for (int x2 = 0; a[1] * x2 <= r; x2++) {
            int cost = c[1] * x2 + f1[r - a[1] * x2];
            best = min(best, cost);
        }
        f2[r] = best;
    }

    cout << "Minimum value of Z = " << f2[R] << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int R = 8;                         
    int c[3] = {4, 5, 3};              
    int a[3] = {2, 1, 1};              

    vector<int> f1(R + 1, 0);
    vector<int> f2(R + 1, 0);
    vector<int> f3(R + 1, 0);

    // Stage 1: x1
    for (int r = 0; r <= R; r++) {
        f1[r] = c[0] * (r / a[0]);
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

    // Stage 3: x3
    for (int r = 0; r <= R; r++) {
        int best = INT_MAX;
        for (int x3 = 0; a[2] * x3 <= r; x3++) {
            int cost = c[2] * x3 + f2[r - a[2] * x3];
            best = min(best, cost);
        }
        f3[r] = best;
    }

    cout << "Minimum value of Z = " << f3[R] << endl;

    return 0;
}

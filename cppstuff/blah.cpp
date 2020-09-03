#include <bits/stdc++.h>

using namespace std;

int main() {
    int facts[] = {1,2,3,4,5,6,7,8};
    int m = 8;
    int n = 5;
    int pressed[4];
    for (int i = 0; i<m;++i) {
        if (i < n-1) pressed[n - 2 - i] = facts[m - 1 - i];
        else {
            pressed[0] *= facts[m - 1 - i];
        }
    }
    for (int i=0;i<4;++i) cout << pressed[i] << " ";
        cout << endl;
}

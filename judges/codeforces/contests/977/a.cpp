#include <bits/stdc++.h>

using namespace std;

string n;
int k;

void solve() {
    cin >> n >> k;

    while (k--) {
        int aux = stoi(n);
        if (n.at(n.length() - 1) == '0') {
            aux /= 10;
            n = to_string(aux);
        }
        else {
            aux -= 1;
            n = to_string(aux);
        }
    }
    cout << n << endl;
}

int main () {
    solve();
}
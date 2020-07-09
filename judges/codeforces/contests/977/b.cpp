#include <bits/stdc++.h>

using namespace std;

int n;
string str;

void solve() {
    cin >> n >> str;

    int mostR = 0;
    int first, second;

    for (int i = 0; i < n-1; i++) {
        int count = 0;
        //cout << str.at(i) << endl;
        for (int j = 0; j < n-1; j++) {
            //cout << str.at(i) << " " << str.at(i + 1) << endl;
            if (str.at(i) == str.at(j) && str.at(i + 1) == str.at(j + 1))
                count++;
        }
        if (count > mostR) {
            first = i;
            second = i + 1;
            mostR = count;
        }
    }
    cout << str.at(first) << str.at(second) << endl;
}

int main () {
    solve();
}
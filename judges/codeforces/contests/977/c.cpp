#include <bits/stdc++.h>

using namespace std;

int n, k;

void solve() {
    cin >> n >> k;

    int arr[n];
    int max = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int current = 1;

    sort(arr, arr+n);

    int starts = 0;

    while (true) {
        int aux = 0;
        for (int i = starts; i < n; i++) {
            if (current < arr[i]) {
                aux = i;
                starts = i;
                break;
            }
            aux = n;
        }
        //cout << aux << endl;
        if (aux == k) {
            cout << current << endl;
            break;
        }
        if (aux > k || current > max) {
            cout << -1 << endl;
            break;
        }
        current++;
    }   
}

int main () {
    solve();
}

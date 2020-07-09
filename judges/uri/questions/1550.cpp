#include <bits/stdc++.h>

using namespace std;

int n, a, b, top, inv;
string str;

int bfs (int a, int b) {
	map<int, int> distan;
	queue<int> q;
	
	distan[a] = 0;
	q.push(a);
	
	while (!q.empty()) {
		top = q.front(); q.pop();

		if (top == b) break;

		str = to_string(top);
		reverse(str.begin(), str.end());
		inv = stoi(str);
		vector<int> son = {top + 1, inv};
		for (int i : son) {
			if (!distan.count(i)) {
				distan[i] = distan[top] + 1;
				q.push(i);
			}
		}
	}

	return distan[b];
}

int main () {
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> a >> b;
		//cout << a << " " << b << endl;
		cout << bfs(a, b) << endl;
	}
}

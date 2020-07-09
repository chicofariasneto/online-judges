#include <bits/stdc++.h>

using namespace std;

int c;
int n, m;
int shirts[6]; // XXL, XL, L, M, S, XS
string tam[] = {"XXL", "XL", "L", "M", "S", "XS"};
string people[30][2];
bool itsPossible = false;

int position (string s) {
    for (int i = 0; i < 6; i++)
        if (s == tam[i]) return i;
}

void organizeShirts (int m) {
	if (m < 0) itsPossible = true;
	if (itsPossible) return;
	
	if (shirts[position(people[m][0])] < (n / 6)) {
		shirts[position(people[m][0])]++;
		organizeShirts(m-1);
		shirts[position(people[m][0])]--;
	}
	if (shirts[position(people[m][1])] < (n / 6)) {
		shirts[position(people[m][1])]++;
		organizeShirts(m-1);
		shirts[position(people[m][1])]--;
	}
}

int main () {
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> people[i][0] >> people[i][1];
		organizeShirts(m-1);
		if (itsPossible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		for (int i = 0; i < 6; i++)
			shirts[i] = 0;
		itsPossible = false;
	}
	return 0;
}

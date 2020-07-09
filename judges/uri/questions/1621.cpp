#include <bits/stdc++.h>

using namespace std;

int x, y;
int where[501][501];

void coords (int n, int m, int position) {
    int max = n * m;
    
    while (max >= position)
		max -= m;
		
	for (int j = 0; j < m; j++)
		if (where[max / m][j] == position) {
			x = max / m;
			y = j;
			break;
		}
}

int main () {
    int n, m, aux = 1;
    while (scanf("%d %d", &n, &m) && n && m) {
        char lab[n][m];
        int visited[n][m], distance[n][m];
		queue<int> q;
		
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> lab[i][j];
                visited[i][j] = 0;
                where[i][j] = aux++;
				distance[i][j] = 0;
            }
		int auxX, auxY, keep = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (lab[i][j] == '.') {
					auxX = i;
					auxY = j;
					keep = 0;
				}
				if (!keep)
					break;
			}
			if (!keep)
				break;
		}
		aux = 1;
		visited[auxX][auxY] = 1;
		q.push(where[auxX][auxY]);
		int maxX, maxY;
		int max = -1;
		
		while(!q.empty()) {
			int aux = q.front(); q.pop();
			coords(n, m, aux);
			if (x > 0 && !visited[x - 1][y] && lab[x - 1][y] == '.') {
				visited[x - 1][y] = 1;
				distance[x - 1][y] = distance[x][y] + 1;
				if (distance[x - 1][y] > max) {
					max = distance[x - 1][y];
					maxX = x - 1;
					maxY = y;
				}
				q.push(where[x - 1][y]);
			}
			if (x < n - 1 && !visited[x + 1][y] && lab[x + 1][y] == '.') {
				visited[x + 1][y] = 1;
				distance[x + 1][y] = distance[x][y] + 1;
				if (distance[x + 1][y] > max) {
					max = distance[x + 1][y];
					maxX = x + 1;
					maxY = y;
				}
				q.push(where[x + 1][y]);
			}
			if (y > 0 && !visited[x][y - 1] && lab[x][y - 1] == '.') {
				visited[x][y - 1] = 1;
				distance[x][y - 1] = distance[x][y] + 1;
				if (distance[x][y - 1] > max) {
					max = distance[x][y - 1];
					maxX = x;
					maxY = y - 1;
				}
				q.push(where[x][y - 1]);
			}
			if (y < m - 1 && !visited[x][y + 1] && lab[x][y + 1] == '.') {
				visited[x][y + 1] = 1;
				distance[x][y + 1] = distance[x][y] + 1;
				if (distance[x][y + 1] > max) {
					max = distance[x][y + 1];
					maxX = x;
					maxY = y + 1;
				}
				q.push(where[x][y + 1]);
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				distance[i][j] = 0;
			}

		visited[maxX][maxY] = 1;
		q.push(where[maxX][maxY]);
		max = -1;
		while(!q.empty()) {
			int aux = q.front(); q.pop();
			coords(n, m, aux);
			if (x > 0 && !visited[x - 1][y] && lab[x - 1][y] == '.') {
				visited[x - 1][y] = 1;
				distance[x - 1][y] = distance[x][y] + 1;
				if (distance[x - 1][y] > max)
					max = distance[x - 1][y];
				q.push(where[x - 1][y]);
			}
			if (x < n - 1 && !visited[x + 1][y] && lab[x + 1][y] == '.') {
				visited[x + 1][y] = 1;
				distance[x + 1][y] = distance[x][y] + 1;
				if (distance[x + 1][y] > max)
					max = distance[x + 1][y];
				q.push(where[x + 1][y]);
			}
			if (y > 0 && !visited[x][y - 1] && lab[x][y - 1] == '.') {
				visited[x][y - 1] = 1;
				distance[x][y - 1] = distance[x][y] + 1;
				if (distance[x][y - 1] > max)
					max = distance[x][y - 1];
				q.push(where[x][y - 1]);
			}
			if (y < m - 1 && !visited[x][y + 1] && lab[x][y + 1] == '.') {
				visited[x][y + 1] = 1;
				distance[x][y + 1] = distance[x][y] + 1;
				if (distance[x][y + 1] > max)
					max = distance[x][y + 1];
				q.push(where[x][y + 1]);
			}
		}
		cout << max << endl;
    }
    return 0;
}
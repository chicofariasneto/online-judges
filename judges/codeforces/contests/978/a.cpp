#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

// large numbers
const ll MAXN = 1e18 + 1;
//const int MAXI = 1e9 + 1;
const int MAXI = 1e5 + 1;
// For graphs
map<int, vector<int>> adj;
map<int, bool> visited;
vector<int> nodes;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS)
{
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD)
{
    return (int)(((x % m) + m) % m);
}

int n;
int arr[MAXI];
int repeated[MAXI];
int aux = 0;
int hm = 0;

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (repeated[arr[i]] == 0)
            hm++;
        repeated[arr[i]]++;
    }
    printf("%d\n", hm);
    for (int i = 0; i < n; i++)
    {
        if (repeated[arr[i]] == 1)
        {
            if (aux == 0)
            {
                printf("%d", arr[i]);
                aux++;
            }
            else
                printf(" %d", arr[i]);
        }
        else
        {
            repeated[arr[i]]--;
        }
    }
    putchar('\n');
}

////////////////////////// Solution starts below. //////////////////////////////
int main()
{
    solve();
    return 0;
}
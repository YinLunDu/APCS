// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
/// ------- Initialization End -------

int ans = 0;

int dfs()
{
    int x;
    cin >> x;
    if (x == 0)
        return 0;
    if (x % 2 == 0) {
        int a = dfs();
        int b = dfs();
        if (a != 0) ans += abs(x - a);
        if (b != 0) ans += abs(x - b);
    } else {
        int a = dfs();
        int b = dfs();
        int c = dfs();
        if (a != 0) ans += abs(x - a);
        if (b != 0) ans += abs(x - b);
        if (c != 0) ans += abs(x - c);
    }
    return x;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    
    dfs();
    cout << ans << "\n";
    return 0;
}
#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int arr[1000005];
int f[1000005];
int dp[2][1000005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int l = n;
    set<int> s;
    s.insert(arr[n]);
    for (int i = n; i >= 1; i--)
    {
        while (l - 1 >= 1 && s.find(arr[l - 1]) == s.end())
        {
            s.insert(arr[l - 1]);
            l--;
        }
        s.erase(s.find(arr[i]));
        f[i] = l;
    }

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i % 2][j] = max(dp[i % 2][j - 1], dp[(i + 1) % 2][f[j] - 1] + j - f[j] + 1);
        }
    }
    cout << dp[k % 2][n] << "\n";

    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int a[1005], b[1005];
int dp[1005][1005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j;
    cin >> n >> m;

    for (i=1; i<=n; i++)
        cin >> a[i];
    for (j=1; j<=m; j++)
        cin >> b[j];

    fill(&dp[0][0], &dp[0][0] + 1005 * 1005, 0);

    int res = -1e18;
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            dp[i][j] = max(a[i] * b[j], dp[i-1][j-1] + a[i] * b[j]);
            res = max(res, dp[i][j]);
        }
    }

    for (i=1; i<=n; i++) {
        for (j=m; j>=1; j--) {
            dp[i][j] = max(a[i] * b[j], dp[i-1][j+1] + a[i] * b[j]);
            res = max(res, dp[i][j]);
        }
    }

    cout << res << "\n";

    return 0;
}
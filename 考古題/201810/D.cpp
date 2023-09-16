/**
 * @brief 0/1 背包 DP
 * 
 */
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int arr[100005];
bool dp[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, s, n;
    cin >> m >> s >> n;
    if (s == 0) cout << 0 << "\n";
    int i, j, sum=0;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    fill(dp, dp + 100005, 0);
    dp[0] = 1;
    for (i=1;i<=n;i++) {
        for (j=m;j>=1;j--) {
            int tmp = j-arr[i];
            if (tmp < 0) continue;
            if (dp[tmp])
                dp[j] = 1;
        }
    }
    int idx = 0;
    while (true) {
        if (m - sum + idx >= s && dp[idx])
            break;
        idx++;
    }
    cout << idx << "\n";

    return 0;
}
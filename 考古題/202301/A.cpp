#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, b;
    cin >> n;
    int mx = -1, idx, cnt = 0;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        if (b > mx) {
            mx = b;
            idx = a;
        }
        if (b == -1)
            cnt++;
    }
    int ans = mx - n - cnt*2;
    if (ans < 0)
        cout << 0 << " " << idx << "\n";
    else
        cout << ans << " " << idx << "\n";
    
    return 0;
}
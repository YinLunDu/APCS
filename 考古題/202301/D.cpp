#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

pii arr[100005];

bool cmp(pii x, pii y)
{
    if (x.second != y.second) return x.second < y.second;
    return x.first < y.first;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    cin >> n >> k;
    for (i=1;i<=n;i++)
        cin >> arr[i].first;
    for (i=1;i<=n;i++)
        cin >> arr[i].second;
    
    sort(arr+1, arr+n+1, cmp);
    
    multiset<int> s;
    for (i=1;i<=k;i++)
        s.insert(-1);

    int cnt = 0;
    for (i=1;i<=n;i++) {
        pii now = arr[i];
        auto it = s.lower_bound(now.first);
        if (it == s.begin()) continue;
        it--;
        s.erase(it);
        s.insert(now.second);
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
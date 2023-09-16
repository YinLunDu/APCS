#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

int n;
int mp[305][305];
int mx[4]={1, -1, 0, 0};
int my[4]={0, 0, 1, -1};

bool inside(int a, int b)
{
    return (1<=a && a<=n && 1<=b && b<=n ? 1 : 0);
}

bool check(int h)
{
    bool vis[305][305];
    fill(&vis[0][0], &vis[0][0]+305*305, 0);
    queue <pii> q;
    q.push({1,1});
    int i;
    while (!q.empty()) {
        pii tmp=q.front();
        int x=tmp.first, y=tmp.second;
        if (x==n && y==n)
            return true;
        q.pop();
        for (i=0;i<=3;i++) {
            if (inside(x+mx[i], y+my[i])) {
                if (!vis[ x+mx[i] ][ y+my[i] ]) {
                    if (abs( mp[ x+mx[i] ][ y+my[i] ] - mp[x][y])<=h) {
                        q.push({x+mx[i], y+my[i]});
                        vis[ x+mx[i] ][ y+my[i] ]=1;
                    }
                }
            }
        }
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i,j;
    cin >> n;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            cin >> mp[i][j];
        }
    }
    int l=0, r=1e18;
    while (l<=r) {
        int mid=(l+r)/2;
        if (check(mid)) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    int ans=l;

    int vis[305][305];
    fill(&vis[0][0], &vis[0][0]+305*305, 0);
    queue <pii> q;
    q.push({1, 1});
    int step[305][305];
    step[1][1]=0;
    while (!q.empty()) {
        pii tmp=q.front();
        int x=tmp.first, y=tmp.second;
        q.pop();
        if (x==n && y==n)
            break;
        for (i=0;i<=3;i++) {
            if (inside(x+mx[i], y+my[i])) {
                if (!vis[ x+mx[i] ][ y+my[i] ]) {
                    if (abs( mp[ x+mx[i] ][ y+my[i] ] - mp[x][y])<=ans) {
                        q.push({x+mx[i], y+my[i]});
                        vis[ x+mx[i] ][ y+my[i] ]=1;
                        step[ x+mx[i] ][ y+my[i] ]=step[x][y]+1;
                    }
                }
            }
        }
    }
    cout << ans << "\n" << step[n][n] << "\n";
    
    return 0;
}
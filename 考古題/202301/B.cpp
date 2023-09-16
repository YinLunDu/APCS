#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int arr[105][105];
char ch[105][105];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, i, j;
    string str;
    cin >> n >> m >> r;
    cin >> str;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            cin >> arr[i][j];
    int idx = 1;
    for (auto it:str) {
        ch[0][idx] = it;
        idx++;
    }

    for (i=1;i<=m;i++) {
        for (j=1;j<=n;j++) {
            int now = arr[i][j];
            ch[i][now] = ch[i-1][j];
        }
    }

    for (i=1;i<=r;i++) {
        for (j=1;j<=m;j++)
            cout << ch[j][i];
        cout << "\n";
    }

    return 0;
}
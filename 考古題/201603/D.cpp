#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[100005];
int depth[100005], ans;

int find_depth(int v, int p)
{
    int res = 0;
    for (int u:G[v])
        res = max(res, find_depth(u, v) + 1);

    return depth[v] = res;
}

void longest_distance(int v, int p)
{
    int fmx = -1, smx = -1;

    for (int u:G[v]) {
        longest_distance(u, v);
        if (depth[u] > fmx) { smx = fmx; fmx = depth[u]; }
        else if (depth[u] > smx) { smx = depth[u]; }
    }

    if (fmx >= 0 && smx >= 0)
        ans = max(ans, fmx + smx + 2);
    else if (fmx >= 0)
        ans = max(ans, fmx + 1);
}

signed main()
{
    int n, a, b, i, root;

    while (scanf("%lld", &n) != EOF) {
        fill(G, G + n, vector<int>());
        
        root = n * (n-1) / 2;

        for (i=0; i<n-1; i++) {
            scanf("%lld %lld", &a, &b);
            G[a].push_back(b);
            root -= b;
        }

        find_depth(root, -1);

        ans = 0;
        longest_distance(root, -1);

        printf("%lld\n", ans);
    }

    return 0;
}
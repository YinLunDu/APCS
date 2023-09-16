#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int dsu[40005], sz[40005];
vector<int> ops;

void init(int n)
{
    for (int i=1; i<=2*n; i++)
        dsu[i] = i, sz[i] = 1;
}

int getidx(int id, int AB)
{
    return 2 * id + AB;
}

int find(int idx)
{
    if (dsu[idx] == idx) return idx;
    return find(dsu[idx]);
}

bool merge(int a1, int b1, int a2, int b2)
{
    int x1 = find(a1);
    int y1 = find(b1);
    int x2 = find(a2);
    int y2 = find(b2);
    
    if (sz[x1] < sz[y1])
        swap(x1, y1);
    ops.push_back(y1);
    dsu[y1] = x1;
    sz[x1] += y1;

    if (sz[x2] < sz[y2])
        swap(x2, y2);
    ops.push_back(y2);
    dsu[y2] = x2;
    sz[x2] += y2;

    if (dsu[x1] == dsu[x2] || dsu[y1] == dsu[y2])
        return false;
    else
        return true;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j;
    int a, b;
    cin >> n >> m;
    init(n);
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        merge(getidx(a, 1), getidx(b, 2), getidx(a, 2), getidx(b, 1));
    }
    int p, k;
    cin >> p >> k;
    vector<int> ans;
    
    for (i=1;i<=p;i++){
        ops.clear();
        bool flag = 1;
        for (j=1;j<=k;j++){
            cin >> a >> b;
            if (!flag) continue;
            if (!merge(getidx(a, 1), getidx(b, 2), getidx(a, 2), getidx(b, 1))) {
                ans.push_back(i);
                flag = 0;
                continue;
            }
        }
        for (int it:ops) {
            dsu[it] = it;
            sz[it] = 1;
        }
    }
    for (int it:ans)
        cout << it << "\n";
    return 0;
}
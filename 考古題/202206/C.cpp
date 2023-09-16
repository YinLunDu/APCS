// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
const int INF = 1e18;
/// ------- Initialization End -------

vector <pii> mx[100005];
vector <pii> my[100005];
vector <int> dx[100005];
vector <int> dy[100005];
vector <int> X;
vector <int> Y;


int get_x(int val)
{
    return lower_bound(X.begin(), X.end(), val) - X.begin();
}

int get_y(int val)
{
    return lower_bound(Y.begin(), Y.end(), val) - Y.begin();
}

signed main()
{
    IOS
    
    int n;
    cin >> n;

    vector <pair<pii, int>> v;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        X.push_back(a);
        Y.push_back(b);
        v.push_back({{a, b}, c});
    }

    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    sort(Y.begin(), Y.end());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    
    for (auto i : v) {
        pii p = i.first;
        int d = i.second;
        dx[get_x(p.first)].push_back(p.second);
        dy[get_y(p.second)].push_back(p.first);
        mx[get_x(p.first)].push_back({p.second, d});
        my[get_y(p.second)].push_back({p.first, d});
    }

    for (int i = 0; i <= X.size(); i++) {
        sort(dx[i].begin(), dx[i].end());
        sort(mx[i].begin(), mx[i].end());
    }
    for (int i = 0; i <= Y.size(); i++) {
        sort(dy[i].begin(), dy[i].end());
        sort(my[i].begin(), my[i].end());
    }

/*
    0 : / , 1 : \
*/
/*
    0 : >
    1 : V
    2 : <
    3 : ^
*/
    int cnt = 0;
    int x = 0, y = 0, dir = 0;
    while (true) {
        if (dir == 0) {
            if (binary_search(Y.begin(), Y.end(), y)) {
                int yid = get_y(y);
                int xid = upper_bound(dy[yid].begin(), dy[yid].end(), x) - dy[yid].begin();
                if (xid < dy[yid].size()) {
                    cnt++;
                    x = my[yid][xid].first;
                    y;
                    if (my[yid][xid].second == 0)
                        dir = (dir + 4 - 1) % 4;
                    else
                        dir = (dir + 4 + 1) % 4;
                } else {
                    break;
                }
            } else {
                break;
            }
        } else if (dir == 2) {
            if (binary_search(Y.begin(), Y.end(), y)) {
                int yid = get_y(y);
                int xid = lower_bound(dy[yid].begin(), dy[yid].end(), x) - dy[yid].begin();
                xid--;
                if (xid >= 0) {
                    cnt++;
                    x = my[yid][xid].first;
                    y;
                    if (my[yid][xid].second == 0)
                        dir = (dir + 4 - 1) % 4;
                    else
                        dir = (dir + 4 + 1) % 4;
                } else {
                    break;
                }
            } else {
                break;
            }
        } else if (dir == 3) {
            if (binary_search(X.begin(), X.end(), x)) {
                int xid = get_x(x);
                int yid = upper_bound(dx[xid].begin(), dx[xid].end(), y) - dx[xid].begin();
                if (yid < dx[xid].size()) {
                    cnt++;
                    x;
                    y = mx[xid][yid].first;
                    if (mx[xid][yid].second == 0)
                        dir = (dir + 4 + 1) % 4;
                    else
                        dir = (dir + 4 - 1) % 4;
                } else {
                    break;
                }
            } else {
                break;
            }
        } else {
            if (binary_search(X.begin(), X.end(), x)) {
                int xid = get_x(x);
                int yid = lower_bound(dx[xid].begin(), dx[xid].end(), y) - dx[xid].begin();
                yid--;
                if (yid >= 0) {
                    cnt++;
                    x;
                    y = mx[xid][yid].first;
                    if (mx[xid][yid].second == 0)
                        dir = (dir + 4 + 1) % 4;
                    else
                        dir = (dir + 4 - 1) % 4;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        // dbg(x, y); ent();
    }
    cout << cnt << "\n";
    
    return 0;
}
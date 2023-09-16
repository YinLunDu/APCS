#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

void debug() {cout << "\n";}
template<class T, class ...U>
void debug(T a, U ...b) {cout << a << " "; debug(b...);}

struct item
{
    int S, T, id, cnt;
};

int s[1005], t[1005];
item order[1005], l[1005], r[1005];
int len, len_l, len_r;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, tmp;
    cin >> n >> m;

    for (i=1; i<=n; i++)
        cin >> s[i];
    for (i=1; i<=n; i++)
        cin >> t[i];

    len = 0;
    for (i=1; i<=n; i++) {
        cin >> tmp;
        order[++len] = {s[tmp], t[tmp], tmp, 0};
    }
    
    while (len > 1) {
        len_l = len_r = 0;
        for (i=1; i<=len; i+=2) {
            if (i == len) {
                l[++len_l] = order[i];
            } else {
                item X = order[i], Y = order[i+1];
                int a = X.S, b = X.T, c = Y.S, d = Y.T;
                if (a * b >= c * d) {
                    X.S = a + c * d / (2 * b);
                    X.T = b + c * d / (2 * a);
                    Y.S = c + c / 2;
                    Y.T = d + d / 2;
                    Y.cnt++;

                    l[++len_l] = X;
                    if (Y.cnt < m) r[++len_r] = Y;
                } else {
                    X.S = a + a / 2;
                    X.T = b + b / 2;
                    Y.S = c + a * b / (2 * d);
                    Y.T = d + a * b / (2 * c);
                    X.cnt++;

                    l[++len_l] = Y;
                    if (X.cnt < m) r[++len_r] = X;
                }
            }
        }
        len = 0;
        for (i=1; i<=len_l; i++)
            order[++len] = l[i];
        for (i=1; i<=len_r; i++)
            order[++len] = r[i];
    }
    cout << order[1].id << "\n";
    
    return 0;
}
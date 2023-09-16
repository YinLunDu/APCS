#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

struct item
{
    int a;
    int b;
}num[10001];

bool cmp(struct item x, struct item y)
{
    if (x.a>y.a) return false;
    else return true;
}

signed main()
{
    int n,i,s;
    cin >> n;
    for (i=0;i<=n-1;i++)
        cin >> num[i].a >> num[i].b;
    sort(num, num+n, cmp);

    for (i=0;i<=n-2;i++) {
        if (num[i+1].a<=num[i].b && num[i].b<=num[i+1].b)
            num[i].b=num[i+1].a;
        else if (num[i].b>=num[i+1].b) {
            num[i+1].b=num[i].b;
            num[i].b=num[i+1].a;
        }
    }

    s=0;
    for (i=0;i<=n-1;i++)
        s+=num[i].b-num[i].a;
    cout << s;
    return 0;
}
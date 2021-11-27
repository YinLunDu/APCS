#include <iostream>
#include <algorithm>

using namespace std;

struct object
{
    int w;
    int times;
}item[1000001];

bool cmp(struct object a, struct object b)
{
    if (a.w*b.times>b.w*a.times) return true;
    else return false;
}

int main()
{
    long long int total_weight,energy;
    int n,i;
    cin >> n;
    total_weight=0;
    for (i=0;i<=n-1;i++) {
        cin >> item[i].w;
        total_weight+=item[i].w;
    }
    for (i=0;i<=n-1;i++) cin >> item[i].times;
    sort(item, item+n, cmp);
    energy=0;
    for (i=0;i<=n-1;i++) {
        total_weight-=item[i].w;
        energy+=total_weight*item[i].times;
    }
    cout << energy;
    return 0;
}

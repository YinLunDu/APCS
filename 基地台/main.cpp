#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n,k;
vector <int> num;

bool solve(int r)//too big -> true
{
    int i,times,tail;
    times=0;tail=num[0];
    for (i=0;i<=n-1;) {
        tail=num[i]+r;
        times++;
        if (times>k) return false;
        if (num[n-1]<=tail) return true;
        while (num[i]<=tail) i++;
    }
    return false;
}

int main()
{
    int temp,i,r,R,middle;
    cin >> n >> k;
    for (i=1;i<=n;i++) {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    if (k==1)
        cout << num[n-1]-num[0];
    else {
        r=1; R=num[n-1]-num[0];
        while (r<R) {
            middle=(r+R)/2;
            if(solve(middle))
                R=middle;//too big
            else
                r=middle+1;//too small
        }
        cout << R;
    }
    return 0;
}

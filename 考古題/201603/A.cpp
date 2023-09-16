#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

signed main()
{
    int num[101],i,j,n,x,pass,nonpass;
    
    cin >> n;
    for (i=1; i<=n; i++) cin >> num[i];

    for (i=1; i<=n-1; i++) {
        for (j=1; j<=n-i; j++) {
            if (num[j]>num[j+1]) {
                x=num[j];
                num[j]=num[j+1];
                num[j+1]=x;
            }
        }
    }

    pass=101;
    nonpass=-1;

    for (i=1;i<=n;i++) {
        if (num[i]<pass && num[i]>=60) pass=num[i];
        if (num[i]>nonpass && num[i]<60) nonpass=num[i];
        cout << num[i] << " ";
    }
    cout << "\n";

    if (nonpass != -1) cout << nonpass;
    else cout << "best case";
    cout << "\n";

    if (pass != 101) cout << pass;
    else cout << "worst case";
    cout << "\n";
    
    return 0;
}
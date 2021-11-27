#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,num[21][21],big,choose[21],s,success;
    cin >> n >> m;
    s=0;
    for (i=1;i<=n;i++) {
        big=0;
        for (j=1;j<=m;j++) {
            cin >> num[i][j];
            if (num[i][j]>big)
                big=num[i][j];
        }
        choose[i]=big;
        s+=big;
    }

    cout << s << "\n";
    success=0;
    for (i=1;i<=n;i++) {
        if (s%choose[i]==0) {
            cout << choose[i] << " ";
            success=1;
        }
    }
    if (success==1) cout << "\n";
    else cout << "-1\n";
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int i,num[50000],f[50000],group=0,n,j,head;
    cin >> n;
    for (i=0;i<=n-1;i++) {
        cin >> num[i];
        f[i]=0;
    }
    for (i=0;i<=n-1;i++) {
        if (f[i]==1)
            continue;
        else {
            f[i]=1;
            j=num[i];
            while (j!=i) {
                f[j]=1;
                j=num[j];
            }
            group++;
        }
    }
    cout << group;
    return 0;
}

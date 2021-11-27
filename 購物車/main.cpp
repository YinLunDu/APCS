#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int item[101],a,b,i,j,n,x,times;
    cin >> a >> b;
    cin >> n;
    times=0;
    for (i=1;i<=n;i++) {
        for (j=1;j<=100;j++)
            item[j]=0;
        while (cin >> x) {
            if (x==0) break;
            else if (x<0) item[abs(x)]--;
            else if (x>0) item[x]++;
        }
        if (item[a]>0 && item[b]>0) times++;
    }
    cout << times << "\n";
    return 0;
}

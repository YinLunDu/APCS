#include <iostream>

using namespace std;

int main()
{
    int a1,b1,c1,a2,b2,c2,n,i,big,sum;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> n;
    big=-10101001;
    for (i=0;i<=n;i++) {
        sum=0;
        sum+=a1*i*i+b1*i+c1;
        sum+=a2*(n-i)*(n-i)+b2*(n-i)+c2;
        if (sum>big)
            big=sum;
    }
    cout << big;
    return 0;
}

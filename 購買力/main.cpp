#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,d,a,b,c,i,amount,money;
    cin >> n >> d;
    amount=0; money=0;
    for (i=1;i<=n;i++) {
        cin >> a >> b >> c;
        if (abs(a-b)>=d || abs(a-c)>=d || abs(b-c)>=d) {
            amount++;
            money+=(a+b+c)/3;
        }
    }
    cout << amount << " " << money << "\n";
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a,b,c,temp;
    cin >> a >> b >> c;
    if (a>b) {
        temp=a;
        a=b;
        b=temp;
    }
    if (b>c) {
        temp=b;
        b=c;
        c=temp;
    }
    if (a>b) {
        temp=a;
        a=b;
        b=temp;
    }
    cout << a << " " << b << " " << c << "\n";
    if (a+b<=c) cout << "No\n";
    else if (a*a+b*b==c*c) cout << "Right\n";
    else if (a*a+b*b<c*c) cout << "Obtuse\n";
    else if (a*a+b*b>c*c) cout << "Acute\n";
    return 0;
}

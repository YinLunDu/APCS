#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h,win1,win2;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    cout << a+b+c+d << ":" << e+f+g+h << "\n";
    if (a+b+c+d>e+f+g+h) win1=1;
    else win1=0;

    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    cout << a+b+c+d << ":" << e+f+g+h << "\n";
    if (a+b+c+d>e+f+g+h) win2=1;
    else win2=0;

    if (win1==1 && win2==1) cout << "Win\n";
    else if (win1==0 && win2==0) cout << "Lose\n";
    else cout << "Tie\n";
    return 0;
}

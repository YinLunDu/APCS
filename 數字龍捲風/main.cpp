#include <iostream>

using namespace std;

int i,j,k,num[51][51],direction,step;

void func()
{
    switch (direction) {
        case 0:
            for (k=1;k<=step;k++) {
                j--;
                cout << num[i][j];
            }
            direction=1;
            break;
        case 1:
            for (k=1;k<=step;k++) {
                i--;
                cout << num[i][j];
            }
            direction=2;
            break;
        case 2:
            for (k=1;k<=step;k++) {
                j++;
                cout << num[i][j];
            }
            direction=3;
            break;
        case 3:
            for (k=1;k<=step;k++) {
                i++;
                cout << num[i][j];
            }
            direction=0;
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    cin >> direction;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            cin >> num[i][j];
    step=1;
    i=(n+1)/2;
    j=(n+1)/2;
    cout << num[i][j];
    while (true) {
        if ((i==1 || i==n) && (j==1 || j==n)) break;
        func();
        func();
        step++;
    }
    func();
    func();
    func();
    cout << "\n";
    return 0;
}

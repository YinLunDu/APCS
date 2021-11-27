#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    string num;
    int i,odd=0,even=0,now;
    cin >> num;
    now=1;
    for (i=0;i<=(int)num.length()-1;i++) {
        if (now==1) {
            odd+=num[i]-'0';
            now=0;
        } else if (now==0) {
            even+=num[i]-'0';
            now=1;
        }
    }
    cout << abs(odd-even);
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool fail;
    int i;
    long long big,small,num;
    string input;
    while (cin >> input) {
        big=0; small=0;
        for (i=0;i<=(int)input.length()-1;i++) {
            if ((input[i]-'0')%2==0) {
                big=big*10+(input[i]-'0')+1;
                i++;
                break;
            } else {
                big=big*10+(input[i]-'0');
            }
        }
        for (;i<=(int)input.length()-1;i++)
            big=big*10+1;
        //cout << big << "\n";
        fail=false;
        for (i=0;i<=(int)input.length()-1;i++) {
            if ((input[i]-'0')%2==0) {
                if (input[i]=='0') {
                    fail=true;
                    break;
                } else {
                    small=small*10+(input[i]-'0')-1;
                    i++;
                    break;
                }
            } else {
                small=small*10+(input[i]-'0');
            }
        }
        if (fail==true) {
            i--;
            if (input[i]=='1' && i==0) {
                small=0;
                i++;
                for (;i<=(int)input.length()-1;i++)
                    small=small*10+9;
            } else if (input[i]=='1') {
                while (input[i]=='1') {
                    small/=10;
                    i--;
                }
                if (i>=0) {
                    if ((input[i]-'0')%2==0)
                        small--;
                    else if ((input[i]-'0')%2==1)
                        small-=2;
                } else {
                    i++;
                }
                i++;
                for (;i<=(int)input.length()-1;i++)
                    small=small*10+9;
            } else if ((input[i]-'0')%2==0) {
                small--;
                for (;i<=(int)input.length()-1;i++)
                    small=small*10+9;
            } else if ((input[i]-'0')%2==1) {
                small-=2;
                i++;
                for (;i<=(int)input.length()-1;i++)
                    small=small*10+9;
            }
        } else if (i<=(int)input.length()-1) {
            for (;i<=(int)input.length()-1;i++)
                    small=small*10+9;
        }
        num=0; i=0;
        while (i<=(int)input.length()-1) {
            num=num*10+(input[i]-'0');
            i++;
        }
        if (big-num>num-small)
            cout << num-small << "\n";
        else
            cout << big-num << "\n";
        string input;
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    stack <string> stk;
    stack <int> num;
    string input,str;
    int i,x,y,z;
    getline(cin, input);

    for (i=0;i<=(int)input.length()-1;i++) {
        if (input[i]=='f')
            stk.push("f");
        else if (input[i]=='g')
            stk.push("g");
        else if (input[i]=='h')
            stk.push("h");
        else if ('0'<=input[i] && input[i]<='9') {
            x=0;
            while ('0'<=input[i] && input[i]<='9') {
                x=x*10+input[i]-'0';
                i++;
            }
            stk.push(to_string(x));
        }
        else if (input[i]=='-') {
            x=0;i++;
            while ('0'<=input[i] && input[i]<='9') {
                x=x*10+input[i]-'0';
                i++;
            }
            stk.push( to_string(x*-1) );
        }
    }


    while (!stk.empty()) {
        str=stk.top();
        stk.pop();
        if (str.compare("f")==0) {
            x=num.top();
            num.pop();
            num.push(2*x-3);
        } else if (str.compare("g")==0) {
            x=num.top();
            num.pop();
            y=num.top();
            num.pop();
            num.push(2*x+y-7);
        } else if (str.compare("h")==0) {
            x=num.top();
            num.pop();
            y=num.top();
            num.pop();
            z=num.top();
            num.pop();
            num.push(3*x-2*y+z);
        } else {
            num.push(stoi(str));
        }
    }

    cout << num.top();
    return 0;
}

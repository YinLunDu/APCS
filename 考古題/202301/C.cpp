#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

string s;
int idx, sz;

int getnumber();
int f();
int input();

int getnumber()
{
    int now = 0;
    while (idx < sz) {
        if (!('0' <= s[idx] && s[idx] <= '9'))
            break;
        now = now*10 + (s[idx]-'0');
        idx++;
    }
    return now;
}

int f()
{
    idx += 2;
    int mx = 0, mn = 1e18;
    while (s[idx] != ')') {
        int tmp = input();
        mx = max(mx, tmp);
        mn = min(mn, tmp);
        if (s[idx] == ',') idx++;
    }
    idx++;
    return mx-mn;
}

int input()
{
    stack<int> s1;
    stack<char> s2;
    while (idx < sz) {
        if (!(s[idx] != ',' && s[idx] != ')'))
            break;
        
        if (s[idx] == 'f') {
            s1.push( f() );
        } else if (s[idx] == '+') {
            s2.push('+');
            idx++;
            continue;
        } else if (s[idx] == '*') {
            s2.push('*');
            idx++;
            continue;
        } else {
            s1.push( getnumber() );
        }

        if (!s2.empty() && s1.size() >= 2) {
            if (s2.top() == '+') {
                s2.pop();
                int a = s1.top();
                s1.pop();
                int b = s1.top();
                s1.pop();
                s1.push(a+b);
            }
        }
    }
    while (!s2.empty() && s1.size() >= 2) {
        if (s2.top() == '*') {
            s2.pop();
            int a = s1.top();
            s1.pop();
            int b = s1.top();
            s1.pop();
            s1.push(a*b);
        }
    }
    return s1.top();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s);
    idx = 0, sz = s.size();
    cout << input() << "\n";
    
    return 0;
}
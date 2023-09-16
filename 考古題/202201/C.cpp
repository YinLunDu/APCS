// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
#define arr0(x,y) loop(HEHE,0,y-1) cout << x[HEHE] << " "; cout << "\n";
#define arr1(x,y) loop(HEHE,1,y) cout << x[HEHE] << " "; cout << "\n";
#define uni(x) (x).resize(unique((x).begin(),(x).end())-(x).begin());
#define unisort(x) sort((x).begin(),(x).end()); uni((x));
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void endline() {cout << "\n";}
ostream& operator <<(ostream& os, const pii& a) { os << "[" << a.F << ", " << a.S << "]"; return os; }
ostream& operator <<(ostream& os, const pair<int, pii>& a) { os << a.F << " : [" << a.S.F << ", " << a.S.S << "]"; return os; }
/// ------- Initialization End -------

set <string> info;
int cnt = 0;
// According to the question, there is no AB + AB
// find ABA + B
void match_the_string(string s)
{
    for (int i = 1; i * 2 <= (int)s.size(); i++) {
        string A = s.substr(0, i);
        string _A = s.substr(SZ(s) - i, i);
        if (A == _A) {
            if (info.find(s.substr(i, SZ(s) - i - i)) != info.end())
                cnt++;
        }
    }
    return;
}

signed main()
{
    IOS
    
    int n;
    cin >> n;

    string s;
    vector <string> v;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        info.insert(s);
        v.push_back(s);
    }
    
    for (string it : v) {
        match_the_string(it);
    }
    cout << cnt << "\n";


    return 0;
}
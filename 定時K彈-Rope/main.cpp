#include <iostream>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main()
{
    rope <int> num;
    int i,N,M,K,now;
    cin >> N >> M >> K;
    now=0;
    for (i=1;i<=N;i++)
        num.push_back(i);
    for (i=1;i<=K;i++) {
        now+=M-1;
        now=now%(int)num.size();
        num.erase(now,1);
    }
    now=now%(int)num.size();
    cout << num[now];
    return 0;
}

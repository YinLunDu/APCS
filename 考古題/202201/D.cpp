#include <bits/stdc++.h>
#define int long long

using namespace std;

int height[200005]={0},N;
int paper[5005]={0},K;

bool able(int h)
{
    int i;
    int now = 0; /// record the paper need to put now
    int tmp = 0; /// record the continuous height
    for (i=0; i<N; i++) {
        if (now >= K) return true;

        if (height[i] >= h) {
            tmp++;
            if (tmp >= paper[now]) {
                now++;
                tmp=0;
            }
            /// not here
        } else {
            if (tmp >= paper[now])
                now++;
            tmp=0;
        }
    }

    if (now >= K) return true;
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i, mx=0;
    cin >> N >> K;
    for (i=0; i<N; i++) {
        cin >> height[i];
        if (height[i] > mx)
            mx = height[i];
    }

    for (i=0; i<K; i++)
        cin >> paper[i];

    int L,R,mid;
    L = 1;
    R = mx + 2;
    while (L < R) {
        mid = (L+R+1) / 2;
        if (able(mid)) {
            L = mid;
        } else {
            R = mid - 1;
        }
    }

    cout << R << "\n";
    return 0;
}
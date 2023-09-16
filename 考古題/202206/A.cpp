#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr+3);

    if (arr[0] == arr[1] && arr[1] == arr[2])
        cout << 3 << " " << arr[0] << "\n";
    else if (arr[0] == arr[1])
        cout << 2 << " " << arr[2] << " " << arr[1] << "\n";
    else if (arr[1] == arr[2])
        cout << 2 << " " << arr[2] << " " << arr[0] << "\n";
    else
        cout << 1 << " " << arr[2] << " " << arr[1] << " " << arr[0] << "\n";
    
    return 0;
}
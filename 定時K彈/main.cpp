#include <iostream>

using namespace std;

int num[200000];

int main()
{

    int i,j,N,M,K,now;
    cin >> N >> M >> K;
    now=0;
    for (i=0;i<=N-1;i++)
        num[i]=1;
    for (i=1;i<=K;i++) {
        for (j=1;j<=M-1;j++) { //���LM-1��
            while (num[now]==0) {
                now++;
                now=now%N;
            }
            now++;
            now=now%N;
        }
        while (num[now]==0) {
            now++;
            now=now%N;
        }
        num[now]=0; //��M���z��
    }
    now++;
    now=now%N;
    while (num[now]==0) {
        now++;
        now=now%N;
    }
    cout << now+1;
    return 0;
}

#include <iostream>

using namespace std;

unsigned long SUM[300001];

int main()
{
    int num[300001],n,i,L,R,M,small,small_index;
    scanf("%d",&n);
    SUM[0]=0;
    for (i=1;i<=n;i++) {
        scanf("%d",&num[i]);
        SUM[i]=SUM[i-1]+num[i];
    }
    L=1; R=n;
    while (L<R) {
        small=num[L];
        small_index=L;
        for (i=L+1;i<=R;i++)
            if (num[i]<small) {
                small=num[i];
                small_index=i;
            }
        M=small_index;
        if ((SUM[M-1]-SUM[L-1])>(SUM[R]-SUM[M]))
            R=M-1;
        else
            L=M+1;
    }
    printf("%d",num[R]);
    return 0;
}

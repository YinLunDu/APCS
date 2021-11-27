#include <iostream>

using namespace std;

int R,C;

bool inside(int i, int j)
{
    if (1<=i && i<=R && 1<=j && j<=C)
        return true;
    else
        return false;
}

int main()
{
    int num[101][101],add[101][101],k,m,people,i,j,x,big,small,times;
    scanf("%d %d %d %d",&R,&C,&k,&m);
    for (i=1;i<=R;i++)
        for (j=1;j<=C;j++)
            scanf("%d",&num[i][j]);
    for (x=1;x<=m;x++) {
        for (i=1;i<=R;i++)
            for (j=1;j<=C;j++)
                add[i][j]=0;
        for (i=1;i<=R;i++)
            for (j=1;j<=C;j++)
                if (num[i][j]!=-1) {
                    people=num[i][j]/k;
                    times=0;
                    if (inside(i+1,j+0)) if (num[i+1][j+0]!=-1) {add[i+1][j+0]+=people; times++;}
                    if (inside(i+0,j+1)) if (num[i+0][j+1]!=-1) {add[i+0][j+1]+=people; times++;}
                    if (inside(i-1,j-0)) if (num[i-1][j-0]!=-1) {add[i-1][j-0]+=people; times++;}
                    if (inside(i-0,j-1)) if (num[i-0][j-1]!=-1) {add[i-0][j-1]+=people; times++;}
                    add[i][j]-=people*times;
                }
        for (i=1;i<=R;i++)
            for (j=1;j<=C;j++)
                num[i][j]+=add[i][j];
    }
    big=0; small=100;
    for (i=1;i<=R;i++)
        for (j=1;j<=C;j++) {
            if (num[i][j]!=-1) {
                if (num[i][j]>big) big=num[i][j];
                if (num[i][j]<small) small=num[i][j];
            }
        }
    cout << small << "\n" << big << "\n";
    return 0;
}

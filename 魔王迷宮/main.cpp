#include <iostream>

using namespace std;

int n,m;
int table[100][100],boss[501][5];

bool outside(int a, int b)
{
    if ((0<=a)&&(a<=n-1)&&(0<=b)&&(b<=m-1))
        return false;
    else
        return true;
}

/* ªÅ0 ¬µ¼u1 */
int main()
{
    bool bang;
    int k,alive,i,j,l,x,y,bomb;
    scanf("%d %d %d",&n,&m,&k);
    for (i=0;i<=n-1;i++)
        for (j=0;j<=m-1;j++)
            table[i][j]=0;
    for (i=1;i<=k;i++)
        for (j=1;j<=4;j++)
            scanf("%d",&boss[i][j]);
    alive=k;
    while (alive>0) {
        for (i=1;i<=k;i++) {
            if (boss[i][1]!=-1) {
                x=boss[i][1];
                y=boss[i][2];
                table[x][y]=1;
                if (outside(x+boss[i][3],y+boss[i][4])) {
                    boss[i][1]=-1;
                    alive--;
                } else {
                    boss[i][1]+=boss[i][3];
                    boss[i][2]+=boss[i][4];
                }
            }
        }
        for (i=0;i<=n-1;i++) {
            for (j=0;j<=m-1;j++) {
                if (table[i][j]==1) {
                    bang=false;
                    for (l=1;l<=k;l++) {
                        if ((boss[l][1]==i)&&(boss[l][2]==j)) {
                            boss[l][1]=-1;
                            alive--;
                            bang=true;
                        }
                    }
                    if (bang==true)
                        table[i][j]=0;
                }
            }
        }
    }
    bomb=0;
    for (i=0;i<=n-1;i++) {
        for (j=0;j<=m-1;j++) {
            if (table[i][j]==1)
                bomb++;
        }
    }
    cout << bomb;
    return 0;
}

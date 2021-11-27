#include <iostream>

using namespace std;

int num[101][101],total,n,m;

bool inside(int i, int j)
{
    if (1<=i && i<=n && 1<=j && j<=m)
        return true;
    else
        return false;
}

void find_next(int *i, int *j)
{
    int small=1000000,x,y;
    x=*i;
    y=*j;
    if (inside(x+1,y+0)) if (num[x+1][y+0]<small && num[x+1][y+0]!=-1) {*i=x+1; *j=y+0; small=num[x+1][y+0];}
    if (inside(x+0,y+1)) if (num[x+0][y+1]<small && num[x+0][y+1]!=-1) {*i=x+0; *j=y+1; small=num[x+0][y+1];}
    if (inside(x-1,y-0)) if (num[x-1][y-0]<small && num[x-1][y-0]!=-1) {*i=x-1; *j=y-0; small=num[x-1][y-0];}
    if (inside(x-0,y-1)) if (num[x-0][y-1]<small && num[x-0][y-1]!=-1) {*i=x-0; *j=y-1; small=num[x-0][y-1];}
    if (small==1000000) {*i=-1; *j=-1;}
}

int main()
{
    int i,j,small=1000000,small_i,small_j,next_i,next_j;
    cin >> n >> m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            cin >> num[i][j];
            if (num[i][j]<small) {
                small=num[i][j];
                small_i=i;
                small_j=j;
            }
        }
    total=0;
    next_i=small_i;
    next_j=small_j;
    while (next_i!=-1 && next_j!=-1) {
        total+=num[next_i][next_j];
        num[next_i][next_j]=-1;
        find_next(&next_i, &next_j);
    }
    cout << total;
    return 0;
}

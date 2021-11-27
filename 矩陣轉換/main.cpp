#include <iostream>

using namespace std;

int num[11][11],R,C,M;

void turn()
{
    int i,j,temp;
    int after[11][11];
    for (i=1;i<=R;i++)
        for (j=1;j<=C;j++)
            after[j][i]=num[i][C-j+1];
    temp=R;
    R=C;
    C=temp;
    for (i=1;i<=R;i++)
        for (j=1;j<=C;j++)
            num[i][j]=after[i][j];
}

void flip()
{
    int i,j,x,y;
    int after[11][11];
    for (i=1,x=R;i<=R;i++,x--)
        for (j=1,y=1;j<=C;j++,y++)
            after[x][y]=num[i][j];

    for (i=1;i<=R;i++)
        for (j=1;j<=C;j++)
            num[i][j]=after[i][j];
}

int main()
{
    int i,j,action[11];
    while (cin >> R >> C >> M) {
        for (i=1;i<=R;i++)
            for (j=1;j<=C;j++)
                cin >> num[i][j];
        for (i=M;i>=1;i--)
            cin >> action[i];
        for (i=1;i<=M;i++) {
            if (action[i]==0) turn();
            else if (action[i]==1) flip();
        }

        cout << R << " " << C << "\n";
        for (i=1;i<=R;i++) {
            for (j=1;j<=C;j++) {
                cout << num[i][j];
                if (j<C) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

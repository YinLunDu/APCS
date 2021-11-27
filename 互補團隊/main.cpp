#include <iostream>
#include <cstring>

using namespace std;

string input;
bool str[500001][38];

int main()
{
    bool fail;
    int m,n,i,j,k,times,temp;
    scanf("%d %d",&m,&n);
    cin.ignore();
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            str[i][j]=false;
    times=0;
    for (i=1;i<=n;i++) {
        cin >> input;
        for (j=0;j<=(int)input.length()-1;j++) {
            temp=input[j]-'A';
            str[i][temp]=true;
        }
        for (j=1;j<=i-1;j++) {
            fail=false;
            for (k=0;k<=m-1;k++)
                if (!((str[i][k]==true && str[j][k]==false) || (str[i][k]==false && str[j][k]==true))) {
                    fail=true;
                    break;
                }
            if (fail==false)
                times++;
        }
    }
    cout << times;
    return 0;
}

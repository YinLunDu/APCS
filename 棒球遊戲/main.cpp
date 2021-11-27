#include <iostream>

using namespace std;

int main()
{
    string str;
    int i,j,n,player[10][6],score,out,now,base[4],temp;
    for (i=1;i<=9;i++) {
        cin >> n;
        for (j=1;j<=n;j++) {
            cin >> str;
            if (str.compare("FO")==0 || str.compare("GO")==0 || str.compare("SO")==0)
                player[i][j]=0;
            else if (str.compare("1B")==0)
                player[i][j]=1;
            else if (str.compare("2B")==0)
                player[i][j]=2;
            else if (str.compare("3B")==0)
                player[i][j]=3;
            else if (str.compare("HR")==0)
                player[i][j]=4;
        }
    }
    cin >> out;
    now=0;
    score=0;
    i=1;//¤H
    j=1;//¦¸
    base[1]=0;
    base[2]=0;
    base[3]=0;
    while (now<out) {
        switch (player[i][j]) {
            case 0:
                now++;
                if (now%3==0) {
                    base[1]=0;
                    base[2]=0;
                    base[3]=0;
                }
                break;
            case 1:
            case 2:
            case 3:
                if (base[3]==1) {
                    base[3]=0;
                    if (3+player[i][j]>=4)
                        score++;
                }
                if (base[2]==1) {
                    base[2]=0;
                    if (2+player[i][j]>=4) {
                        score++;
                    } else {
                        temp=player[i][j];
                        base[2+temp]=1;
                    }
                }
                if (base[1]==1) {
                    base[1]=0;
                    if (1+player[i][j]>=4) {
                        score++;
                    } else {
                        temp=player[i][j];
                        base[1+temp]=1;
                    }
                }
                temp=player[i][j];
                base[temp]=1;
                break;
            case 4:
                if (base[1]==1) score++;
                if (base[2]==1) score++;
                if (base[3]==1) score++;
                score++;
                base[1]=0;
                base[2]=0;
                base[3]=0;
                break;
        }
        if (i==9) {
            i=1;
            j++;
        } else {
            i++;
        }
    }
    cout << score;
    return 0;
}

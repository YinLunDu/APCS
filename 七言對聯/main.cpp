#include <iostream>

using namespace std;

/*
七言對聯有三個限制：
A: 二四不同二六同：每一句第二、四個字必須不同平仄，而第二、六個字必須相同平仄
B: 仄起平收：第一句的結尾必須為仄聲，第二句的結尾必須為平聲
C: 上下相對：第一、二句的第二、四、六個字平仄必須不同
*/
int main()
{
    bool success,output;
    int i,j,k,n,poem[8][3];
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        for (j=1;j<=2;j++)
            for (k=1;k<=7;k++)
                scanf("%d",&poem[k][j]);
        output=false;
        success=true;
        if ((poem[2][1]==poem[4][1])||(poem[2][1]!=poem[6][1])) success=false;
        if ((poem[2][2]==poem[4][2])||(poem[2][2]!=poem[6][2])) success=false;
        if (success==false) {cout << "A"; output=true;}

        if ((poem[7][1]!=1)||(poem[7][2]!=0)) {cout << "B"; output=true;}

        success=true;
        if (poem[2][1]==poem[2][2]) success=false;
        if (poem[4][1]==poem[4][2]) success=false;
        if (poem[6][1]==poem[6][2]) success=false;
        if (success==false) {cout << "C"; output=true;}

        if (output==false) cout << "None\n";
        else cout << "\n";
    }
    return 0;
}

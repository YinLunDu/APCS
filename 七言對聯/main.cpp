#include <iostream>

using namespace std;

/*
�C�����p���T�ӭ���G
A: �G�|���P�G���P�G�C�@�y�ĤG�B�|�Ӧr�������P�����A�ӲĤG�B���Ӧr�����ۦP����
B: ���_�����G�Ĥ@�y���������������n�A�ĤG�y���������������n
C: �W�U�۹�G�Ĥ@�B�G�y���ĤG�B�|�B���Ӧr�����������P
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

#include <iostream>

using namespace std;

int main()
{
    bool a,b,c;
    int aa,bb,cc,success=0;
    cin >> aa >> bb >> cc;
    if (aa==0) a=false;
    else a=true;
    if (bb==0) b=false;
    else b=true;
    if (cc==0) c=false;
    else c=true;

    if ((a&&b)==c) {
        cout << "AND\n";
        success=1;
    }
    if ((a||b)==c) {
        cout << "OR\n";
        success=1;
    }
    if (((a==true)&&(b==false)&&(c==true))||((a==false)&&(b==true)&&(c==true))||((a==true)&&(b==true)&&(c==false))||((a==false)&&(b==false)&&(c==false))) {
        cout << "XOR\n";
        success=1;
    }
    if (success==0) cout << "IMPOSSIBLE\n";
    return 0;
}

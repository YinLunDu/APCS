#include <iostream>
#include <cstring>

using namespace std;
int num[100001];
int main()
{
    int n,i,m,j,c,success,k,now;
    string str;
    cin >> n;
    //cin.ignore();
    //getline(cin, str);
    cin >> str;
    for (i=0;i<=(int)str.length()-1;i++) {
        if ('A'<=str[i]&&str[i]<='Z') num[i]=1;
        if ('a'<=str[i]&&str[i]<='z') num[i]=0;
    }
    m=0;
    for (i=0;i<=(int)str.length()-1;i++) {
        j=i;now=num[j];c=0;success=1;
        while (j+n-1<=(int)str.length()-1 && success==1) {
            for (k=j;k<=j+n-1;k++)
                if (num[k]!=now)
                    success=0;
            if (success==0) break;
            c+=n;
            j+=n;
            if (now==1) now=0;
            else if (now==0) now=1;
            if (c>m && success==1) m=c;
        }
    }
    cout << m-m%n;
    return 0;
}

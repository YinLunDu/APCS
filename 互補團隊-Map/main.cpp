#include <iostream>
#include <string.h>
#include <map>

using namespace std;

char input[1001];
map <long long, int> myMap;

int main()
{
    long long temp,compare;
    int m,n,i,j,times;
    scanf("%d %d",&m,&n);
    cin.ignore();
    times=0;
    compare=0;
    for (i=0;i<=m-1;i++)
        compare |= 1LL << i;
    for (i=1;i<=n;i++) {
        scanf("%s",input);
        temp=0;
        for (j=0;j<=(int)strlen(input)-1;j++) {
            if ('A'<=input[j] && input[j]<='Z')
                temp |= 1LL << (input[j]-'A');
            if ('a'<=input[j] && input[j]<='z')
                temp |= 1LL << (input[j]-'a'+26);
        }

        auto iter = myMap.find( compare^temp );
        if (iter != myMap.end())
            times+=myMap[ compare^temp ];

        //if (myMap.count( compare^temp )>0) times+=myMap[ compare^temp ];
        myMap[temp]++;
    }
    cout << times;
    return 0;
}

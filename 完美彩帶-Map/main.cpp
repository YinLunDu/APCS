/*
3 5
1 2 3 2 1
*/
#include <iostream>
#include <map>

using namespace std;

long double num[200000],temp;

int main()
{
    map <long double, int> myMap;
    int n,m,times,i,j,head;
    scanf("%d %d",&m,&n);

    times=0; head=0;
    for (i=0;i<=n-1;i++) {
        scanf("%llf",&temp);
        num[i]=temp;
        auto iter = myMap.find(temp);
        if (iter != myMap.end()) {
            for (j=head;j<=iter->second;j++)
                myMap.erase(myMap.find(num[j]));
            head=iter->second+1;
        }
        myMap[temp]=i;
        if (i-head+1==m) {
            myMap.erase(myMap.find(num[head]));
            head++;
            times++;
        }
    }
    printf("%d\n",times);
    return 0;
}

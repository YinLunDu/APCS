/*
3 5
1 2 3 2 1
*/
#include <iostream>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main()
{
    rope <int> num;
    int n,m,times,now,index,temp;
    scanf("%d %d",&m,&n);
    times=0;

    for (now=0;now<=n-1;now++) {
        scanf("%d",&temp);
        index=num.find(temp);
        if (0<=index && index<=(int)num.size()-1)
            num.erase(0,index+1);
        num.push_back(temp);

        if ((int)num.size()>m)
            num.erase(0,1);
        if ((int)num.size()==m) times++;
    }
    printf("%d\n",times);
    return 0;
}

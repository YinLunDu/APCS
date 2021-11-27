#include <iostream>
#include <algorithm>

using namespace std;

struct item
{
    int x;
    int y;
};

bool cmp(struct item ob1, struct item ob2)
{
    if (ob1.x<ob2.x)
        return true;
    else if (ob1.x>ob2.x)
        return false;
    else
        return ob1.y<ob2.y;
}

int main()
{
    struct item fruit[200000],now;
    int n,i,j,big,c;
    scanf("%d",&n);
    for (i=0;i<=n-1;i++) {
        scanf("%d %d",&fruit[i].x,&fruit[i].y);
    }
    sort(fruit,fruit+n,cmp);
    big=0;
    for (i=0;i<=n-1;i++) {
        c=0;
        now.x=fruit[i].x;
        now.y=fruit[i].y;
        for (j=i;j<=n-1;j++) {
            if (now.y<fruit[j].y && now.x!=fruit[j].x) {
                now.x=fruit[j].x;
                now.y=fruit[j].y;
                c++;
            }
        }
        if (c+1>big)
            big=c+1;
    }
    cout << big;
    return 0;
}

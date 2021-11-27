#include <cstdio>
#include <vector>

using namespace std;

vector <int> tree[100001];
int deep[100001],ans;

int find_deep(int now)
{
    int temp,big,leaves,i;
    leaves=tree[now][0];
    if (leaves==0) {
        deep[now]=0;
        return 0;
    } else {
        big=0;
        for (i=1;i<=leaves;i++) {
            temp=find_deep(tree[now][i]);
            if (temp>big)
                big=temp;
        }
        deep[now]=big+1;
        return big+1;
    }
}

void longest_distance(int now)
{
    int i,temp,first,second,leaves,x,y;
    leaves=tree[now][0];
    if (leaves==0) {
        return;
    } else if (leaves==1) {
        x=tree[now][1];
        temp=deep[x]+1;
        if (temp>ans)
            ans=temp;
    } else if (leaves==2) {
        x=tree[now][1];
        y=tree[now][2];
        temp=deep[x]+deep[y]+2;
        if (temp>ans)
            ans=temp;
    } else {
        first=0;second=0;
        for (i=1;i<=leaves;i++) {
            temp=tree[now][i];
            if (deep[temp]>second) {
                if (deep[temp]>first) {
                    second=first;
                    first=deep[temp];
                } else {
                    second=deep[temp];
                }
            }
        }
        temp=first+second+2;
        if (temp>ans)
            ans=temp;
    }
}

int main()
{
    bool point[100001];
    int n,a,b,i,highest;
    while (scanf("%d",&n)!=EOF) {
        for (i=0;i<=n-1;i++)
            tree[i].clear();
        for (i=0;i<=n-1;i++) {
            tree[i].push_back(0);
            point[i]=false;
        }
        for (i=1;i<=n-1;i++) {
            scanf("%d %d",&a,&b);
            tree[a].push_back(b);
            tree[a][0]++;
            point[b]=true;
        }

        for (i=0;i<=n-1;i++)
            if (point[i]==false) {
                highest=i;
                break;
            }
        find_deep(highest);

        ans=0;
        for (i=0;i<=n-1;i++)
            longest_distance(i);

        printf("%d\n",ans);
    }
    return 0;
}

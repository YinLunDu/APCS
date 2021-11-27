#include <iostream>

using namespace std;

struct item
{
   int weight;
   int left;
   int right;
}tree[2000003];

int thing[10001];

int get_weight(int node)
{
    int r,l;
    if (tree[node].left==0) {
        return tree[node].weight;
    } else {
        l=get_weight(tree[node].left);
        r=get_weight(tree[node].right);
        tree[node].weight=l+r;
        return tree[node].weight;
    }
}

int main()
{
    int n,m,i,j,l,r,a,b,c;
    scanf("%d %d",&n,&m);
    for (i=n;i<=2*n-1;i++) {
        scanf("%d",&tree[i].weight);
        tree[i].left=0;
        tree[i].right=0;
    }
    for (i=1;i<=m;i++)
        scanf("%d",&thing[i]);
    for (i=1;i<=n-1;i++) {
        scanf("%d %d %d",&a,&b,&c);
        tree[a].left=b;
        tree[a].right=c;
    }
    get_weight(1);
    for (i=1;i<=m;i++) {
        j=1;
        tree[j].weight+=thing[i];
        while (j<n) {
            l=tree[j].left;
            r=tree[j].right;
            if (tree[l].weight>tree[r].weight)
                j=r;
            else
                j=l;
            tree[j].weight+=thing[i];
        }
        cout << j << " ";
    }
    cout << "\n";
    return 0;
}

#include <iostream>

using namespace std;

int num[51][10001];

int main()
{
    int m,n,i,j,big,sum;
    int right[10001],left[10001];
    scanf("%d %d",&m,&n);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            scanf("%d",&num[i][j]);

    i=1;
    sum=0;
    for (j=1;j<=n;j++) {
        if (sum+num[i][j]<num[i][j]) {
            sum=num[i][j];
            right[j]=num[i][j];
        } else {
            sum+=num[i][j];
            right[j]=sum;
        }
    }

    sum=0;
    for (j=n;j>=1;j--) {
        if (sum+num[i][j]<num[i][j]) {
            sum=num[i][j];
            left[j]=num[i][j];
        } else {
            sum+=num[i][j];
            left[j]=sum;
        }
    }

    for (j=1;j<=n;j++) {
        if (right[j]>left[j])
            num[i][j]=right[j];
        else
            num[i][j]=left[j];
    }


    for (i=2;i<=m;i++) {
        sum=0;
        for (j=1;j<=n;j++) {
            if (sum+num[i][j]<num[i-1][j]+num[i][j]) {
                sum=num[i-1][j]+num[i][j];
                right[j]=sum;
            } else {
                sum+=num[i][j];
                right[j]=sum;
            }
        }

        sum=0;
        for (j=n;j>=1;j--) {
            if (sum+num[i][j]<num[i-1][j]+num[i][j]) {
                sum=num[i-1][j]+num[i][j];
                left[j]=sum;
            } else {
                sum+=num[i][j];
                left[j]=sum;
            }
        }

        for (j=1;j<=n;j++) {
            if (right[j]>left[j])
                num[i][j]=right[j];
            else
                num[i][j]=left[j];
        }
    }

    i=m;
    big=num[i][1];
    for (j=2;j<=n;j++)
        if (num[i][j]>big)
            big=num[i][j];

    cout << big << "\n";
    /*
    cout << "\n";
    for (i=1;i<=m;i++) {
        for (j=1;j<=n;j++) {
            cout << num[i][j] << " ";
        }
        cout << "\n";
    }
    */
    return 0;
}

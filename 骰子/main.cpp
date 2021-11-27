#include <iostream>

using namespace std;

struct cube
{
    int f;
    int b;
    int up;
    int down;
    int right;
    int left;
}item[21];

void turn_right(int number)
{
    int temp;
    temp=item[number].up;
    item[number].up=item[number].left;
    item[number].left=item[number].down;
    item[number].down=item[number].right;
    item[number].right=temp;
}

void move_forward(int number)
{
    int temp;
    temp=item[number].up;
    item[number].up=item[number].b;
    item[number].b=item[number].down;
    item[number].down=item[number].f;
    item[number].f=temp;
}

void swap_cube(int num1, int num2)
{
    swap(item[num1].up, item[num2].up);
    swap(item[num1].down, item[num2].down);
    swap(item[num1].f, item[num2].f);
    swap(item[num1].b, item[num2].b);
    swap(item[num1].left, item[num2].left);
    swap(item[num1].right, item[num2].right);
}

int main()
{
    int n,m,a,b,i;
    cin >> n >> m;
    for (i=1;i<=n;i++) {
        item[i].up=1;
        item[i].right=2;
        item[i].b=3;
        item[i].f=4;
        item[i].left=5;
        item[i].down=6;
    }
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        if (b==-1)
            move_forward(a);
        else if (b==-2)
            turn_right(a);
        else
            swap_cube(a,b);
    }
    for (i=1;i<=n;i++)
        cout << item[i].up << " ";
    cout << "\n";
    return 0;
}

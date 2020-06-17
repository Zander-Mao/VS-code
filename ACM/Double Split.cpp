#include <iostream>
#include <cstdio>
using namespace std;
int BinarySearch(int a[], int p, int size);
int main()
{
    int a[100], p, size;
    scanf("%d %d", &p, &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", BinarySearch(a, p, size));
    system("pause");
    return 0;
}
int BinarySearch(int a[], int p, int size)
{
    int L = 0;
    int R = size - 1;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (p == a[mid])
            return mid;
        else if (p > a[mid])
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}
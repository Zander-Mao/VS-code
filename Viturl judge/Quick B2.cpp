#include <iostream>
#include<vector>
using namespace std;

void quicksort(vector <int> &a, int l, int r);

int main()
{
    int n;
    int temp;
    vector <int> a;
    cin >> n;
    for (int i = 0; ; i++)
    {
        cin >> temp;
        a.push_back(temp);
        if(cin.get()=='\n')
        break;
    }
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
void quicksort(vector<int> &a, int l, int r)
{
    if (l >= r)
    {
    return;
    }
    
    int base, temp;
    int i,j;
    i=l;
    j=r;
    base = a[l];
    while (i < j)
    {
        while (a[j] >= base && i < j)
        {
            j--;
        }
        while (a[i] <= base && i < j)
        {
            i++;
        }
        if(i<j)
        {
        temp = a[i];
        a[i] = a[j];
         a[j] = temp;
        }
        
       
    }
    a[l]=a[i];
    a[i]=base;
    quicksort(a, i+1, r);
    quicksort(a, l, i-1);
}
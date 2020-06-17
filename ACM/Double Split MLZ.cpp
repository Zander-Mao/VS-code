#include <iostream>
#include <vector>
using namespace std;

int doublePart(vector<int> &array, int size, int p)
{
    int L, R, mid; //左标和右标
    L = 0;
    R = size - 1;
    while (L <= R)
    {
        mid = L + (R - L) / 2; //得出中间下标
        if (p == array[mid])   //如果查找的数刚好等于中间下标数，找到了，返回下标
        {
            return mid;
            break;
        }

        else if (p > array[mid]) //如果找的数大于中间下标数，左位数从中间+1，继续找
        {
            L = mid + 1;
        }
        else //如果找的数小于中间下标数，右位数从中间减-1，继续找
        {
            R = mid - 1;
        }
    }
    return -1; //几轮下来都，找不到，mid=小数，数字不存在，程序失败
}

int main()
{
    int p, a, size; //定义查找的数p,容器储存数字a,数组size
    vector<int> array;
    printf("请输入数组\n");
    for (int i = 0;; i++)
    {
        cin >> a;
        array.push_back(a);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    printf("请输入要查找的数字\n");
    cin >> p;
    size = array.size(); //取得数组长度
    if (doublePart(array, size, p) == -1)
    {
        cout << "数字不存在，查找失败" << endl;
    }
    else
    {

        cout << "查找的数字下标为" << doublePart(array, size, p) << endl; //调用二分法函数
    }
    system("pause");
    return 0;
}
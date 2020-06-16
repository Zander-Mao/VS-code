#include <iostream>
#include <vector> //引入vector容器
using namespace std;

void quickSort(int left, int right, vector<int> &array) //插入形参
{
    if (left >= right)
    { 
        return;
    }
    int base, teaporary, i, j; //初始化参数，基数，临时储存数，i，j；
    base = array[left]; //基数等于最左边数字
    i = left;   
    j = right;  
    while (i < j)  //左边开始递增，右边开始递减，开始循环，直到它们相遇
    {
        while (array[j] >= base && i < j)
        {
            j--;
        }
        while (array[i] <= base && i < j)
        {
            i++;
        }
        if (i < j)
        {
            teaporary = array[i];   //当两边各走一步时，交换大小数位置，小的数放左边，大的放右边
            array[i] = array[j];
            array[j] = teaporary;
        }
    }
    //基准数归位
    array[left] = array[i]; 
    array[i] = base;

    quickSort(left, i - 1, array);  //递归左边
    quickSort(i + 1, right, array); //递归右边
}

int main()
{
    vector<int> array;  //定义容器 array
    cout << "请输入一个数列" << endl;
    int s, i;   //定义整型变量s
    for (int i = 0;; i++)   //循环输入s
    {
        cin >> s;
        array.push_back(s);     //把s放进array里
        if (cin.get() == '\n')  //当输入换行（回车键）时，结束循环
            break;
    }
    int length; //array的长度
    length = array.size();  //取得array的长度
    quickSort(0, length - 1, array);    //调用快速排序法
    cout<<"快速排序后的结果为"<<endl;
    for (i = 0; i < length; i++)    //打印结果
    {
        cout << array[i] << " ";
    }
    system("pause");
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
//快速排序（从小到大）
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}
int main()
{
	int i;
	vector<int> arr{6,1,2,7,9,3,4,5,10,8};	//测试数组
	quickSort(0,9,arr);
	for(i=0;i<10;i++)
	{
		cout<<arr[i]<<endl;
	}
	system("pause");
}
#include"iostream"
using namespace std;
#include"vector"//��С����
void kuai(int left,int right,vector<int>&arr)
{
	if(left>=right)
		return;
	int i,j,base,temp;
	i=left;
	j=right;
	base=arr[left];//ȡ����ߵ���Ϊ��׼��
	while(i<j)//��׼����λ
	{
		while(arr[j]>=base&&i<j)
			j--;
		while(arr[i]<=base&&i<j)
			i++;
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	arr[left]=arr[i];
	arr[i]=base;
	kuai(left,i-1,arr);//�ݹ����
	kuai(i+1,right,arr);//�ݹ��ұ�
}
int main()
{
	int i;
	vector<int> arr{6,1,2,7,9,3,4,5,10,8};
	kuai(0,9,arr);
	for(i=0;i<10;i++)
	{
		cout<<arr[i]<<endl;
	}
	system("pause");
}
#include <iostream>
#include <vector> //����vector����
using namespace std;

void quickSort(int left, int right, vector<int> &array) //�����β�
{
    if (left >= right)
    { 
        return;
    }
    int base, teaporary, i, j; //��ʼ����������������ʱ��������i��j��
    base = array[left]; //�����������������
    i = left;   
    j = right;  
    while (i < j)  //��߿�ʼ�������ұ߿�ʼ�ݼ�����ʼѭ����ֱ����������
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
            teaporary = array[i];   //�����߸���һ��ʱ��������С��λ�ã�С��������ߣ���ķ��ұ�
            array[i] = array[j];
            array[j] = teaporary;
        }
    }
    //��׼����λ
    array[left] = array[i]; 
    array[i] = base;

    quickSort(left, i - 1, array);  //�ݹ����
    quickSort(i + 1, right, array); //�ݹ��ұ�
}

int main()
{
    vector<int> array;  //�������� array
    cout << "������һ������" << endl;
    int s, i;   //�������ͱ���s
    for (int i = 0;; i++)   //ѭ������s
    {
        cin >> s;
        array.push_back(s);     //��s�Ž�array��
        if (cin.get() == '\n')  //�����뻻�У��س�����ʱ������ѭ��
            break;
    }
    int length; //array�ĳ���
    length = array.size();  //ȡ��array�ĳ���
    quickSort(0, length - 1, array);    //���ÿ�������
    cout<<"���������Ľ��Ϊ"<<endl;
    for (i = 0; i < length; i++)    //��ӡ���
    {
        cout << array[i] << " ";
    }
    system("pause");
    return 0;
}

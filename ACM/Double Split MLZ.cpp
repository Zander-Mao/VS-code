#include <iostream>
#include <vector>
using namespace std;

int doublePart(vector<int> &array, int size, int p)
{
    int L, R, mid; //�����ұ�
    L = 0;
    R = size - 1;
    while (L <= R)
    {
        mid = L + (R - L) / 2; //�ó��м��±�
        if (p == array[mid])   //������ҵ����պõ����м��±������ҵ��ˣ������±�
        {
            return mid;
            break;
        }

        else if (p > array[mid]) //����ҵ��������м��±�������λ�����м�+1��������
        {
            L = mid + 1;
        }
        else //����ҵ���С���м��±�������λ�����м��-1��������
        {
            R = mid - 1;
        }
    }
    return -1; //�������������Ҳ�����mid=С�������ֲ����ڣ�����ʧ��
}

int main()
{
    int p, a, size; //������ҵ���p,������������a,����size
    vector<int> array;
    printf("����������\n");
    for (int i = 0;; i++)
    {
        cin >> a;
        array.push_back(a);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    printf("������Ҫ���ҵ�����\n");
    cin >> p;
    size = array.size(); //ȡ�����鳤��
    if (doublePart(array, size, p) == -1)
    {
        cout << "���ֲ����ڣ�����ʧ��" << endl;
    }
    else
    {

        cout << "���ҵ������±�Ϊ" << doublePart(array, size, p) << endl; //���ö��ַ�����
    }
    system("pause");
    return 0;
}
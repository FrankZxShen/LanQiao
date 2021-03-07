#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string.h>
using namespace std;
char Left[3][7];//��ƽ��ߵĳ������
char Right[3][7];//��ƽ�ұߵĳ������
char Result[3][7];//���ν��even,up,down

bool Isfake(char c,bool light)
//����c�����,����c�����ص�
{
    for(int i=0;i<3;++i)
    {
        char *pLeft,*pRight;//ָ�������ַ���
        if(light)
        {
            pLeft = Left[i];
            pRight=Right[i];
        }
        else//����ٱ����صģ������������߶Ի�
        {
             pLeft = Right[i];
            pRight = Left[i];
        }

    switch(Result[i][0])//��ƽ�ұߵ����
    {
    case 'u'://up
        if(strchr(pRight,c) == NULL)//c�ַ��س������ұߵ��ַ�����
            return false;
        break;
    case 'e'://even
        if(strchr(pLeft,c)||strchr(pRight,c))
            return false;
        break;
    case 'd'://down
        if(strchr(pLeft,c)==NULL)
            return false;
        break;
    }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;//��������
    while(t--)
    {
        for(int i=0;i<3;i++)
        {
            cin>>Left[i]>>Right[i]>>Result[i];
        }
        for(char c='A';c<='L';c++)
        {
            if(Isfake(c,true))
            {
                cout<<c<<"����ٵ�";
            }
            else if(Isfake(c,false))
            {
                cout<<c<<"���ؼٵ�";
            }
        }
    }
    return 0;
}

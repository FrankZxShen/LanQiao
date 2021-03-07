#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string.h>
using namespace std;
char Left[3][7];//天平左边的称量结果
char Right[3][7];//天平右边的称量结果
char Result[3][7];//三次结果even,up,down

bool Isfake(char c,bool light)
//假设c是轻的,否则c就是重的
{
    for(int i=0;i<3;++i)
    {
        char *pLeft,*pRight;//指向两边字符串
        if(light)
        {
            pLeft = Left[i];
            pRight=Right[i];
        }
        else//如果假币是重的，则称量结果两边对换
        {
             pLeft = Right[i];
            pRight = Left[i];
        }

    switch(Result[i][0])//天平右边的情况
    {
    case 'u'://up
        if(strchr(pRight,c) == NULL)//c字符必出现再右边的字符串中
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
    cin>>t;//测量组数
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
                cout<<c<<"是轻假的";
            }
            else if(Isfake(c,false))
            {
                cout<<c<<"是重假的";
            }
        }
    }
    return 0;
}

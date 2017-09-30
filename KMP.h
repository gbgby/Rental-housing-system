#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int n_next[1000010];

void get_next(char *T)
{

    int i=1,j=0;
    int len=strlen(T);
    n_next[1]=0;
    while(i<=len)
    {
        if(j==0||T[i-1]==T[j-1])        //注意此处必须是
        {
            ++i;
            ++j;
            n_next[i]=j;      //第一次执行完，next[2]=1;
        }
        else j=n_next[j];
    }
}
int KMP(char *s, char *T)
{
    int len1=strlen(s);
    int len2=strlen(T);
    int i=1,j=1;
    while(i<=len1&&j<=len2)
    {
        if(j==0||s[i-1]==T[j-1])
        {
            i++;
            j++;
        }           //不匹配就继续执行后续字符，等于0时，模式串从头比较，因此j++
        else j=n_next[j];     //S的指针不回溯，从T的k位置开始匹配
    }
    if(j>len2)  //子串结束，说明匹配成功
        return i-len2;
    else return -1;
}
//int main()

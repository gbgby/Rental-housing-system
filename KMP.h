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
        if(j==0||T[i-1]==T[j-1])        //ע��˴�������
        {
            ++i;
            ++j;
            n_next[i]=j;      //��һ��ִ���꣬next[2]=1;
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
        }           //��ƥ��ͼ���ִ�к����ַ�������0ʱ��ģʽ����ͷ�Ƚϣ����j++
        else j=n_next[j];     //S��ָ�벻���ݣ���T��kλ�ÿ�ʼƥ��
    }
    if(j>len2)  //�Ӵ�������˵��ƥ��ɹ�
        return i-len2;
    else return -1;
}
//int main()

#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<windows.h>
#include<cstring>
#include<iomanip>
#include "KMP.h"///KMP�ļ�
#include "class.h"///��װ���ļ�
#include "admin_function.h"///����Ա�����ļ�

using namespace std;

int main()///ok
{
    ios::sync_with_stdio(false);
    int flag=true;
    while(flag)
    {
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(60) << "        ��ӭ���뷿������ϵͳ          " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U           ����Ա��¼(1)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U            �û���¼(2)��           �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U            �˳�ϵͳ(3)��           �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(54) << "���������������Ĳ���(1-3)��";
        int t;
        cin>>t;
        switch(t)
        {
            case 1:admin_login();break;
            case 2:rent_handle();break;
            default: a_exit(); flag=0; break;
        }
    }
    return 0;
}

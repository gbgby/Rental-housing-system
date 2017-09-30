#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<windows.h>
#include<cstring>
#include<iomanip>
#include "KMP.h"///KMP文件
#include "class.h"///封装类文件
#include "admin_function.h"///管理员操作文件

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
        cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║           管理员登录(1)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║            用户登录(2)：           ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║            退出系统(3)：           ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(54) << "请输入您接下来的操作(1-3)：";
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

void gotoxy(int x,int y)///跳转光标函数
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void select_room()///查询房屋信息ok
{
    system("cls");
    fstream file("房屋信息.txt");
    string line;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(60) << "       房屋信息一览表          " << endl;
    cout << endl;
    cout << endl;
    cout<<"                      序号\t面积\t月租金\t状态\t房东序号"<<endl<<endl;
    while(1)
    {
        if(file.eof())
            break;
        getline(file, line);
        cout<<"                       "<<line<<endl;
    }
    file.close();
}

void select_rent()///查询用户信息ok
{
    system("cls");
    fstream file("客户信息.txt");
    string line;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(60) << "       用户信息一览表          " << endl;
    cout << endl;
    cout << endl;
    cout<<"                      序号\t名字\t性别\t联系方式\t客户身份"<<endl<<endl;
    while(!file.eof())
    {
        if(file.eof())
            break;
        getline(file, line);
        if(line[0]!=' '&&line[0]!='\t')
            cout<<"                       "<<line<<endl;
    }
    file.close();
}

void del_room(int ss)///删除房屋信息ok
{
    fstream file("房屋信息.txt", ios::in|ios::out);
    ofstream outfile("temp.txt");

    int a, b, c, d, e;
	while(!file.eof())
	{
	    file>>a>>b>>c>>d>>e;
		if(file.eof())
            break;
		if(e!=ss)
		{
		    outfile<<a<<'\t'<<b<<'\t'<<c<<"\t"<<d<<"\t"<<e<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("房屋信息.txt",ios::out);
	string line;
	fstream file1("temp.txt");
	while(!file1.eof())
	{
		getline(file1,line);
		if(file1.eof())
            break;
		outfile1<<line<<endl;
	}

	outfile1.close();
	file1.close();


	//删除2.txt
	system("del temp.txt");
///	cout<<"\t\t删除该用户人名下房屋信息成功！"<<endl;
///	system("pause");
}

void add_rent()///添加用户ok
{
    int flag=1;
    int hs[100];
    system("cls");
    memset(hs, 0, sizeof(hs));
    fstream file("客户信息.txt", ios::in|ios::out);
    int x;
    string line;
    while(!file.eof())
    {
        file>>x;
        hs[x]=1;
        getline(file,line);
        if(file.eof())
            break;
    }
    file.close();
    ofstream outfile("temp.txt");
    fstream tfile("客户信息.txt", ios::in|ios::out);

    for(int i=1;i<99;++i)
        if(!hs[i])
        {
            x=i;
            break;
        }
    ///cout<<x<<endl;
    ///system("pause");

    int s_num=1;
    while(!tfile.eof())
    {
        getline(tfile,line);
        if(tfile.eof())
            break;
        if(x==s_num)
        {
            flag=0;
            string a, b, c;
            bool d;
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t请输入您要添加的用户信息"<<endl<<endl;
            cout<<"\t\t\t姓名：";
            cin>>a;
            cout<<endl;
            cout<<"\t\t\t性别：";
            cin>>b;
            cout<<endl;
            cout<<"\t\t\t联系方式：";
            cin>>c;
            cout<<endl;
            cout<<"\t\t\t客户身份：";
            cin>>d;
            outfile<<s_num<<'\t'<<a<<'\t'<<b<<'\t'<<c<<"\t\t"<<d<<endl;
        }
        outfile<<line<<endl;
        s_num++;
    }
    if(flag)
    {
        string a, b, c;
        bool d;
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t请输入您要添加的用户信息"<<endl<<endl;
        cout<<"\t\t\t姓名：";
        cin>>a;
        cout<<endl;
        cout<<"\t\t\t性别：";
        cin>>b;
        cout<<endl;
        cout<<"\t\t\t联系方式：";
        cin>>c;
        cout<<endl;
        cout<<"\t\t\t客户身份：";
        cin>>d;
        cout<<endl;
        outfile<<s_num<<'\t'<<a<<'\t'<<b<<'\t'<<c<<"\t\t"<<d<<endl;
    }
    outfile.close();
    tfile.close();
    ofstream outfile1("客户信息.txt",ios::out);
    fstream file1("temp.txt");
    while(!file1.eof())
    {
        getline(file1,line);
        if(file1.eof())
            break;
        outfile1<<line<<endl;
    }
    outfile1.close();
    file1.close();
    system("del temp.txt");
    cout<<endl;
    cout<<"\t\t\t添加用户成功"<<endl;
    system("pause");
    return;
    /*
    int flag;
    while(1)
    {
        renter r;
        r.inper();
        system("pause");
        system("cls");
        cout<<"请选择1.继续录入"<<endl;
        cout<<"      2.返回上一级"<<endl;
        cin>>flag;
        if(flag==2)
            break;
    }
    return;
    */
}

void del_rent()///删除用户ok
{
    int flag=1;
    select_rent();
    cout<<endl;
    cout<<"\t\t\t请输入想要删除的用户序号：";
    while(flag)
    {
        int ss;
        cin>>ss;
        if(ss==0)
        {
            flag=0;
            break;
        }
        fstream file("客户信息.txt", ios::in|ios::out);
        ofstream outfile("temp.txt");
        int x;
        string line;
        cout<<endl;
        cout<<"\t\t确定删除，删除后会导致其名下的房屋信息也会删除(y/n)：";
        char s[2];
        cin>>s;
        if(s[0]=='y')
        {
            while(!file.eof())
            {
                file>>x;
                getline(file,line);
                if(file.eof())
                    break;
                if(x!=ss)
                {
                    outfile<<x<<line<<endl;
                }
            }
            file.close();
            outfile.close();

            ofstream outfile1("客户信息.txt",ios::out);
            fstream file1("temp.txt");
            while(!file1.eof())
            {
                getline(file1,line);
                if(file1.eof())
                    break;
                outfile1<<line<<endl;
            }

            outfile1.close();
            file1.close();


            //删除2.txt
            system("del temp.txt");
            del_room(ss);
            cout<<endl;
            cout<<"\t\t\t删除用户及其信息成功！"<<endl;
            system("pause");
            return;
        }
        else
        {
            cout<<endl;
            cout<<"\t\t\t请重新输入所要删除的序号";
        }
    }
}

void alert_rent()///修改用户ok
{
    select_rent();
    fstream file("客户信息.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x, ss;
	string line;
	cout<<"\t\t\t请输入您要修改的序号：";
	cin>>ss;

	while(!file.eof())
	{
	    file>>x;
		getline(file,line);
		if(file.eof())
            break;
		if(x!=ss)
		{
		    outfile<<x<<line<<endl;
		}
		//修改文件指定行
		else
		{
		    cout<<endl;
			cout<<"\t\t\t请输入要修改的内容："<<endl;
			string a, b, c;
			bool type;
			cout<<"\t\t\t姓名：";
			cin>>a;
			cout<<"\t\t\t性别(f/m)：";
			cin>>b;
			cout<<"\t\t\t联系方式：";
			cin>>c;
			cout<<"\t\t\t身份类型(0-租客，1-租户)：";
			cin>>type;
			outfile<<ss<<'\t'<<a<<'\t'<<b<<'\t'<<c<<"\t\t"<<type<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("客户信息.txt",ios::out|ios::trunc);
	fstream file1("temp.txt");

	while(!file1.eof())
	{
	    getline(file1,line);
	    if(file1.eof())
            break;
		outfile1<<line<<endl;
	}
	outfile1.close();
	file1.close();

	//删除2.txt
	system("del temp.txt");
	cout<<"\t\t\t修改成功, 即将返回上级操作"<<endl;
	system("pause");
	return;
}

void handle_rent()///管理用户菜单ok
{
    int flag=1;
    while(flag)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         查询用户信息(1)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         添加用户信息(2)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         删除用户信息(3)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         修改用户信息(4)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         返回上级菜单(5)            ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
        int t;
        cin>>t;
        switch (t)
        {
        case 1:{select_rent();system("pause");}break;
        case 2:add_rent();break;
        case 3:del_rent();break;
        case 4:alert_rent();break;
        default:flag=0;break;
        }
    }
    return;
}

void add_room()///添加房屋信息ok
{
    int flag=1;
    int hs[100];
    memset(hs, 0, sizeof(hs));
    fstream file("房屋信息.txt", ios::in|ios::out);
    int x;
    string line;
    while(!file.eof())
    {
        file>>x;
        hs[x]=1;
        getline(file,line);
        if(file.eof())
            break;
    }
    file.close();
    ofstream outfile("temp.txt");
    fstream tfile("房屋信息.txt", ios::in|ios::out);

    for(int i=1;i<99;++i)
        if(!hs[i])
        {
            x=i;
            break;
        }
    ///cout<<x<<endl;
    ///system("pause");

    int s_num=1;
    while(!tfile.eof())
    {
        getline(tfile,line);
        if(tfile.eof())
            break;
        if(x==s_num)
        {
            flag=0;
            int a, b, c, d;
            system("cls");
            cout<<endl<<endl<<endl;
            cout<<"\t\t请输入您要添加的房屋信息"<<endl;
            cout<<endl<<endl;
            cout<<"\t\t\t面积：";
            cin>>a;
            cout<<endl;
            cout<<"\t\t\t月租金：";
            cin>>b;
            cout<<endl;
            cout<<"\t\t\t房屋状态：";
            cin>>c;
            cout<<endl;
            cout<<"\t\t\t房东序号：";
            cin>>d;
            outfile<<s_num<<'\t'<<a<<'\t'<<b<<"\t"<<c<<"\t"<<d<<endl;
        }
        outfile<<line<<endl;
        s_num++;
    }
    if(flag)
    {
        int a, b, c, d;
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t请输入您要添加的房屋信息"<<endl;
        cout<<endl<<endl;
        cout<<"\t\t\t面积：";
        cin>>a;
        cout<<endl;
        cout<<"\t\t\t年租金：";
        cin>>b;
        cout<<endl;
        cout<<"\t\t\t房屋状态：";
        cin>>c;
        cout<<endl;
        cout<<"\t\t\t房东序号：";
        cin>>d;
        outfile<<s_num<<'\t'<<a<<'\t'<<b<<"\t"<<c<<"\t"<<d<<endl;
    }
    outfile.close();
    tfile.close();
    ofstream outfile1("房屋信息.txt",ios::out);
    fstream file1("temp.txt");
    while(!file1.eof())
    {
        getline(file1,line);
        if(file1.eof())
            break;
        outfile1<<line<<endl;
    }
    outfile1.close();
    file1.close();
    system("del temp.txt");
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t添加成功, 请继续操作"<<endl;
    system("pause");
    return;
}

void del_room()///删除房屋信息ok
{
    select_room();
    cout<<endl;
    cout<<"\t\t\t请输入想要删除的房屋序号：";
    int ss;
    cin>>ss;
    fstream file("房屋信息.txt", ios::in|ios::out);
    ofstream outfile("temp.txt");
	int x;
	string line;

	while(!file.eof())
	{
	    file>>x;
		getline(file,line);
		if(file.eof())
            break;
		if(x!=ss)
		{
		    outfile<<x<<line<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("房屋信息.txt",ios::out);
	fstream file1("temp.txt");
	while(!file1.eof())
	{
		getline(file1,line);
		if(file1.eof())
            break;
		outfile1<<line<<endl;
	}

	outfile1.close();
	file1.close();


	//删除2.txt
	system("del temp.txt");
	cout<<"\t\t\t删除成功！"<<endl;
	system("pause");
}

void alert_room()///修改房屋信息ok
{
    select_room();
    fstream file("房屋信息.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x, ss;
	string line;

	cout<<"\t\t\t请输入您要修改的序号：";
	cin>>ss;

	while(!file.eof())
	{
	    file>>x;
		getline(file,line);
		if(file.eof())
            break;
		if(x!=ss)
		{
		    outfile<<x<<line<<endl;
		}
		//修改文件指定行
		else
		{
		    cout<<endl;
			cout<<"\t\t\t请输入要修改的内容："<<endl;
			cout<<endl;
			int a, b, c;
			cout<<"\t\t\t面积：";
			cin>>a;
			cout<<endl;
			cout<<"\t\t\t价钱：";
			cin>>b;
			cout<<endl;
			cout<<"\t\t\t房屋状态(0-未租出，1-已租出)：";
			cin>>c;
			outfile<<ss<<'\t'<<a<<'\t'<<b<<"\t"<<c<<"\t"<<line[line.size()-1]-'0'<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("房屋信息.txt",ios::out|ios::trunc);
	fstream file1("temp.txt");

	while(!file1.eof())
	{
	    getline(file1,line);
	    if(file1.eof())
            break;
		outfile1<<line<<endl;
	}
	outfile1.close();
	file1.close();

	//删除2.txt
	system("del temp.txt");
	cout<<endl;
	cout<<"\t\t\t修改成功, 即将返回上级操作"<<endl;
	system("pause");
	return;
}

void handle_room()///管理房屋菜单ok
{
    int flag=1;
    while(flag)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         查询房屋信息(1)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         添加房屋信息(2)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         删除房屋信息(3)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         修改房屋信息(4)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         返回上级菜单(5)            ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
        int t;
        cin>>t;
        switch (t)
        {
        case 1:select_room();system("pause");break;
        case 2:add_room();break;
        case 3:del_room();break;
        case 4:alert_room();break;
        default:flag=0;break;
        }
    }
    return;
}

void cout_contract()///输出文件中合同信息ok
{
    system("cls");
    fstream file("租赁合同信息.txt");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(55) << "   租赁合同信息一览表          " << endl;
    cout << endl;
    cout << endl;
    cout<<"      序号   租客序号   房屋序号   房东序号    到期时间    总租金"<<endl<<endl;
    while(!file.eof())
    {
        int a, b, c, d, e, f, g, h;
        file>>a>>b>>c>>d>>e>>f>>g>>h;
        if(file.eof())
            break;
        cout<<"        "<<a<<"      "<<b<<"           "<<c<<"          "<<d<<"       "<<e<<" "<<f<<" "<<g<<"       "<<h<<endl<<endl;
    }
    file.close();
}

void add_contract()///增加合同信息ok
{
    system("cls");
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t欢迎来到合同信息增加页面"<<endl<<endl<<endl;
    cout<<"\t\t\t请输入租客序号：";
    int a;
    cin>>a;
    cout<<endl;
    cout<<"\t\t\t请输入房屋序号：";
    int b, c, d;
    cin>>b;
    cout<<endl;
    fstream file("房屋信息.txt");
    while(!file.eof())
    {
        int x, y, q, p, e;
        file>>x>>y>>q>>p>>e;
        if(file.eof())
            break;
        if(x==b)
        {
            c=e;
            d=q;
            break;
        }
    }
    file.close();
    contract t;
    t.inper(a, b, d, c);
}

void del_contract()///删除合同信息ok
{
    cout_contract();
    cout<<endl<<endl;
    cout<<"\t\t请输入你想删除的合同编号：";
    fstream file("租赁合同信息.txt");
    ofstream outfile("temp.txt");
	int ss, ee;
	cin>>ss;
	string line;

	while(!file.eof())
	{
	    int x, a, b;
	    file>>x>>a>>b;
		getline(file,line);
		if(file.eof())
            break;
		if(x!=ss)
		{
		    outfile<<x<<'\t'<<a<<'\t'<<b<<line<<endl;
		}
		else
        {
            ee=b;
        }
	}
	file.close();
	outfile.close();

	ofstream outfile1("租赁合同信息.txt",ios::out);
	fstream file1("temp.txt");
	while(!file1.eof())
	{
		getline(file1,line);
		if(file1.eof())
            break;
		outfile1<<line<<endl;
	}

	outfile1.close();
	file1.close();

    change_type(ee);

	//删除2.txt
	system("del temp.txt");
	cout<<endl;
	cout<<"\t\t\t删除信息成功！"<<endl;
	system("pause");

}

void alert_contract()///修改合同信息
{
    cout_contract();
    fstream file("租赁合同信息.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x, ss;
	string line;
    cout<<endl;
	cout<<"\t\t\t请输入您要修改的序号：";
	cin>>ss;

	while(!file.eof())
	{
	    file>>x;
		getline(file,line);
		if(file.eof())
            break;
		if(x!=ss)
		{
		    outfile<<x<<line<<endl;
		}
		//修改文件指定行
		else
		{
		    cout<<endl;
			cout<<"\t\t\t请输入要修改的内容："<<endl;
			cout<<endl;
			int a, b, c, d, e, f, g;
			cout<<"\t\t\t租客序号：";
			cin>>a;
			cout<<endl;
			cout<<"\t\t\t房屋序号：";
			cin>>b;
			fstream tfile("房屋信息.txt");
			while(!tfile.eof())
            {
                int x, y, z;
                string l;
                tfile>>x>>y>>z;
                getline(tfile, l);
                if(tfile.eof())
                    break;
                if(x==b)
                {
                    g=z;
                    break;
                }
            }
			tfile.close();
			cout<<endl;
			cout<<"\t\t\t房东序号：";
			cin>>c;
			cout<<endl;
			cout<<"\t\t\t截止日期："<<endl;
			cout<<endl;
			cout<<"\t\t\t    年：";
			cin>>d;
			cout<<endl;
			cout<<"\t\t\t    月：";
			cin>>e;
			cout<<endl;
			cout<<"\t\t\t    日：";
			cin>>f;
			Date d1(2017, 1, 12);
			Date d2(d, e, f);
			int _t=d2.daysOfDate();
			int _p=d1.daysOfDate();
			int __x=_t-_p;
			g=g/30*__x;
			outfile<<ss<<'\t'<<a<<'\t'<<b<<"\t"<<c<<"\t"<<d<<" "<<e<<" "<<f<<'\t'<<g<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("租赁合同信息.txt",ios::out|ios::trunc);
	fstream file1("temp.txt");

	while(!file1.eof())
	{
	    getline(file1,line);
	    if(file1.eof())
            break;
		outfile1<<line<<endl;
	}
	outfile1.close();
	file1.close();

	//删除2.txt
	system("del temp.txt");
	cout<<"\t\t\t修改成功, 即将返回上级操作"<<endl;
	system("pause");
}

void handle_contract()///管理合同菜单ok
{
    int flag=1;
    while(flag)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         查询合同信息(1)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         添加合同信息(2)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         删除合同信息(3)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         修改合同信息(4)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         返回上级菜单(5)            ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
        int t;
        cin>>t;
        switch (t)
        {
        case 1:cout_contract();system("pause");break;
        case 2:add_contract();break;
        case 3:del_contract();break;
        case 4:alert_contract();break;
        default:flag=0;break;
        }
    }
    return;
}

void admin_lower_menu()///ok
{
    int flag=1;
    while(flag)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         操作用户信息(1)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         操作房屋信息(2)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         操作合同信息(3)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         返回上级菜单(4)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
        int t;
        cin>>t;
        switch (t)
        {
        case 1:handle_rent();break;
        case 2:handle_room();break;
        case 3:handle_contract();break;
        default:flag=0;break;
        }
    }
    return;

}

void admin_login()///管理员登录ok
{
    string admin="admin";
    string password="admin";
    string a, p;
    int flag=1;
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
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║     请输入管理员账号：             ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║     请输入管理员密码：             ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "╰══════════════════╯" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    gotoxy(46, 13);
    cin>>a;
    gotoxy(46, 16);
    cin>>p;
    if(a==admin&&p==password)
        flag=0;
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
        cout << setw(60) << "║          您输入的信息有误          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║ 请重新输入管理员账号：             ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║ 请重新输入管理员密码：             ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        gotoxy(46, 13);
        cin>>a;
        gotoxy(46, 16);
        cin>>p;
        if(a==admin&&p==password)
            break;
    }
    cout<<endl<<endl<<endl<<endl;
    cout<<setw(55)<<"登陆成功， 您的身份为管理员！"<<endl;
    cout<<endl;
    system("pause");
    admin_lower_menu();
    return;
}

void rent_login()///KMP应用（用户登录）
{
    system("cls");
    char a[50], b[50];
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
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║       请输入您的名称：             ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║     请输入您的联系方式：           ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "╰══════════════════╯" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    gotoxy(46, 13);
    cin>>a;
    gotoxy(48, 16);
    cin>>b;
    ifstream infile_per;
    infile_per.open("客户信息.txt", ios::in);
    if(!infile_per||infile_per.eof())
    {
        cerr<<"找不到您的个人信息，请前去注册"<<endl;
        renter r;
        r.inper();
    }
    infile_per.close();
    char s[500];
    int flag=0;
    int t_num=3;
    do
    {
        int ss, ee;
        infile_per.open("客户信息.txt", ios::in);
        while(!infile_per.eof())
        {
            infile_per.getline(s, 200);
            get_next(a);
            int p=KMP(s, a);
            get_next(b);
            int q=KMP(s, b);
            if(p!=-1&&q!=-1)
            {
                if(strlen(a)<3||strlen(b)<3||!strcmp(a, b))
                {
                    break;
                }
                else
                {
                    flag=1;
                }
                ss=s[0]-'0';
                ee=s[strlen(s) - 1]-'0';
                ///cout<<ss<<" "<<ee<<endl;
                ///system("pause");
                ///abort();
                break;
            }
        }
        infile_per.close();
        if(!flag)
        {
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(53)<<"未查询到相关信息， 请重新输入"<<endl<<endl;
            cout<<setw(35)<<"您还有"<<--t_num<<"次机会，请谨慎"<<endl;
            system("pause");
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
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "║    请重新输入您的名称：            ║" << endl;
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "║   请重新输入您的联系方式：         ║" << endl;
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "║                                    ║" << endl;
            cout << setw(60) << "╰══════════════════╯" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            gotoxy(47, 13);
            cin>>a;
            gotoxy(50, 16);
            cin>>b;
        }
        else
        {
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(40)<<"登陆成功"<<endl;
            system("pause");
            lower_menu(ss, ee);
        }
        if(t_num<1)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t感谢您的使用"<<endl;
            exit(1);
        }

    }while(!flag);

}

void rent_handle()///用户相关操作ok
{
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << setw(60) << "╭══════════════════╮" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║         注册用户(1)：              ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║         登录用户(2)：              ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║         返回上级菜单(3)：          ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "╰══════════════════╯" << endl;
    cout << endl <<endl <<endl;
    cout<<setw(36) <<"请选择：";
    int t;
    cin>>t;
    switch (t)
    {
        case 1:
        {
            system("cls");
            renter r;
            r.inper();
            r.type_handle();
        }break;
        case 2:rent_login();break;
        default:return;
    }
}

void a_exit()///退出系统操作
{
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t您已安全退出，感谢您使用本系统"<<endl;

}

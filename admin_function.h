void gotoxy(int x,int y)///��ת��꺯��
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void select_room()///��ѯ������Ϣok
{
    system("cls");
    fstream file("������Ϣ.txt");
    string line;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(60) << "       ������Ϣһ����          " << endl;
    cout << endl;
    cout << endl;
    cout<<"                      ���\t���\t�����\t״̬\t�������"<<endl<<endl;
    while(1)
    {
        if(file.eof())
            break;
        getline(file, line);
        cout<<"                       "<<line<<endl;
    }
    file.close();
}

void select_rent()///��ѯ�û���Ϣok
{
    system("cls");
    fstream file("�ͻ���Ϣ.txt");
    string line;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(60) << "       �û���Ϣһ����          " << endl;
    cout << endl;
    cout << endl;
    cout<<"                      ���\t����\t�Ա�\t��ϵ��ʽ\t�ͻ����"<<endl<<endl;
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

void del_room(int ss)///ɾ��������Ϣok
{
    fstream file("������Ϣ.txt", ios::in|ios::out);
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

	ofstream outfile1("������Ϣ.txt",ios::out);
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


	//ɾ��2.txt
	system("del temp.txt");
///	cout<<"\t\tɾ�����û������·�����Ϣ�ɹ���"<<endl;
///	system("pause");
}

void add_rent()///����û�ok
{
    int flag=1;
    int hs[100];
    system("cls");
    memset(hs, 0, sizeof(hs));
    fstream file("�ͻ���Ϣ.txt", ios::in|ios::out);
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
    fstream tfile("�ͻ���Ϣ.txt", ios::in|ios::out);

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
            cout<<"\t\t\t��������Ҫ��ӵ��û���Ϣ"<<endl<<endl;
            cout<<"\t\t\t������";
            cin>>a;
            cout<<endl;
            cout<<"\t\t\t�Ա�";
            cin>>b;
            cout<<endl;
            cout<<"\t\t\t��ϵ��ʽ��";
            cin>>c;
            cout<<endl;
            cout<<"\t\t\t�ͻ���ݣ�";
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
        cout<<"\t\t\t��������Ҫ��ӵ��û���Ϣ"<<endl<<endl;
        cout<<"\t\t\t������";
        cin>>a;
        cout<<endl;
        cout<<"\t\t\t�Ա�";
        cin>>b;
        cout<<endl;
        cout<<"\t\t\t��ϵ��ʽ��";
        cin>>c;
        cout<<endl;
        cout<<"\t\t\t�ͻ���ݣ�";
        cin>>d;
        cout<<endl;
        outfile<<s_num<<'\t'<<a<<'\t'<<b<<'\t'<<c<<"\t\t"<<d<<endl;
    }
    outfile.close();
    tfile.close();
    ofstream outfile1("�ͻ���Ϣ.txt",ios::out);
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
    cout<<"\t\t\t����û��ɹ�"<<endl;
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
        cout<<"��ѡ��1.����¼��"<<endl;
        cout<<"      2.������һ��"<<endl;
        cin>>flag;
        if(flag==2)
            break;
    }
    return;
    */
}

void del_rent()///ɾ���û�ok
{
    int flag=1;
    select_rent();
    cout<<endl;
    cout<<"\t\t\t��������Ҫɾ�����û���ţ�";
    while(flag)
    {
        int ss;
        cin>>ss;
        if(ss==0)
        {
            flag=0;
            break;
        }
        fstream file("�ͻ���Ϣ.txt", ios::in|ios::out);
        ofstream outfile("temp.txt");
        int x;
        string line;
        cout<<endl;
        cout<<"\t\tȷ��ɾ����ɾ����ᵼ�������µķ�����ϢҲ��ɾ��(y/n)��";
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

            ofstream outfile1("�ͻ���Ϣ.txt",ios::out);
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


            //ɾ��2.txt
            system("del temp.txt");
            del_room(ss);
            cout<<endl;
            cout<<"\t\t\tɾ���û�������Ϣ�ɹ���"<<endl;
            system("pause");
            return;
        }
        else
        {
            cout<<endl;
            cout<<"\t\t\t������������Ҫɾ�������";
        }
    }
}

void alert_rent()///�޸��û�ok
{
    select_rent();
    fstream file("�ͻ���Ϣ.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x, ss;
	string line;
	cout<<"\t\t\t��������Ҫ�޸ĵ���ţ�";
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
		//�޸��ļ�ָ����
		else
		{
		    cout<<endl;
			cout<<"\t\t\t������Ҫ�޸ĵ����ݣ�"<<endl;
			string a, b, c;
			bool type;
			cout<<"\t\t\t������";
			cin>>a;
			cout<<"\t\t\t�Ա�(f/m)��";
			cin>>b;
			cout<<"\t\t\t��ϵ��ʽ��";
			cin>>c;
			cout<<"\t\t\t�������(0-��ͣ�1-�⻧)��";
			cin>>type;
			outfile<<ss<<'\t'<<a<<'\t'<<b<<'\t'<<c<<"\t\t"<<type<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("�ͻ���Ϣ.txt",ios::out|ios::trunc);
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

	//ɾ��2.txt
	system("del temp.txt");
	cout<<"\t\t\t�޸ĳɹ�, ���������ϼ�����"<<endl;
	system("pause");
	return;
}

void handle_rent()///�����û��˵�ok
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
        cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ��ѯ�û���Ϣ(1)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ����û���Ϣ(2)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ɾ���û���Ϣ(3)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �޸��û���Ϣ(4)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �����ϼ��˵�(5)            �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
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

void add_room()///��ӷ�����Ϣok
{
    int flag=1;
    int hs[100];
    memset(hs, 0, sizeof(hs));
    fstream file("������Ϣ.txt", ios::in|ios::out);
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
    fstream tfile("������Ϣ.txt", ios::in|ios::out);

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
            cout<<"\t\t��������Ҫ��ӵķ�����Ϣ"<<endl;
            cout<<endl<<endl;
            cout<<"\t\t\t�����";
            cin>>a;
            cout<<endl;
            cout<<"\t\t\t�����";
            cin>>b;
            cout<<endl;
            cout<<"\t\t\t����״̬��";
            cin>>c;
            cout<<endl;
            cout<<"\t\t\t������ţ�";
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
        cout<<"\t\t\t��������Ҫ��ӵķ�����Ϣ"<<endl;
        cout<<endl<<endl;
        cout<<"\t\t\t�����";
        cin>>a;
        cout<<endl;
        cout<<"\t\t\t�����";
        cin>>b;
        cout<<endl;
        cout<<"\t\t\t����״̬��";
        cin>>c;
        cout<<endl;
        cout<<"\t\t\t������ţ�";
        cin>>d;
        outfile<<s_num<<'\t'<<a<<'\t'<<b<<"\t"<<c<<"\t"<<d<<endl;
    }
    outfile.close();
    tfile.close();
    ofstream outfile1("������Ϣ.txt",ios::out);
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
    cout<<"\t\t\t��ӳɹ�, ���������"<<endl;
    system("pause");
    return;
}

void del_room()///ɾ��������Ϣok
{
    select_room();
    cout<<endl;
    cout<<"\t\t\t��������Ҫɾ���ķ�����ţ�";
    int ss;
    cin>>ss;
    fstream file("������Ϣ.txt", ios::in|ios::out);
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

	ofstream outfile1("������Ϣ.txt",ios::out);
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


	//ɾ��2.txt
	system("del temp.txt");
	cout<<"\t\t\tɾ���ɹ���"<<endl;
	system("pause");
}

void alert_room()///�޸ķ�����Ϣok
{
    select_room();
    fstream file("������Ϣ.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x, ss;
	string line;

	cout<<"\t\t\t��������Ҫ�޸ĵ���ţ�";
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
		//�޸��ļ�ָ����
		else
		{
		    cout<<endl;
			cout<<"\t\t\t������Ҫ�޸ĵ����ݣ�"<<endl;
			cout<<endl;
			int a, b, c;
			cout<<"\t\t\t�����";
			cin>>a;
			cout<<endl;
			cout<<"\t\t\t��Ǯ��";
			cin>>b;
			cout<<endl;
			cout<<"\t\t\t����״̬(0-δ�����1-�����)��";
			cin>>c;
			outfile<<ss<<'\t'<<a<<'\t'<<b<<"\t"<<c<<"\t"<<line[line.size()-1]-'0'<<endl;
		}
	}
	file.close();
	outfile.close();

	ofstream outfile1("������Ϣ.txt",ios::out|ios::trunc);
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

	//ɾ��2.txt
	system("del temp.txt");
	cout<<endl;
	cout<<"\t\t\t�޸ĳɹ�, ���������ϼ�����"<<endl;
	system("pause");
	return;
}

void handle_room()///�����ݲ˵�ok
{
    int flag=1;
    while(flag)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "        ��ӭ���뷿������ϵͳ          " << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ��ѯ������Ϣ(1)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ��ӷ�����Ϣ(2)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ɾ��������Ϣ(3)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �޸ķ�����Ϣ(4)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �����ϼ��˵�(5)            �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
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

void cout_contract()///����ļ��к�ͬ��Ϣok
{
    system("cls");
    fstream file("���޺�ͬ��Ϣ.txt");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(55) << "   ���޺�ͬ��Ϣһ����          " << endl;
    cout << endl;
    cout << endl;
    cout<<"      ���   ������   �������   �������    ����ʱ��    �����"<<endl<<endl;
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

void add_contract()///���Ӻ�ͬ��Ϣok
{
    system("cls");
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t��ӭ������ͬ��Ϣ����ҳ��"<<endl<<endl<<endl;
    cout<<"\t\t\t�����������ţ�";
    int a;
    cin>>a;
    cout<<endl;
    cout<<"\t\t\t�����뷿����ţ�";
    int b, c, d;
    cin>>b;
    cout<<endl;
    fstream file("������Ϣ.txt");
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

void del_contract()///ɾ����ͬ��Ϣok
{
    cout_contract();
    cout<<endl<<endl;
    cout<<"\t\t����������ɾ���ĺ�ͬ��ţ�";
    fstream file("���޺�ͬ��Ϣ.txt");
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

	ofstream outfile1("���޺�ͬ��Ϣ.txt",ios::out);
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

	//ɾ��2.txt
	system("del temp.txt");
	cout<<endl;
	cout<<"\t\t\tɾ����Ϣ�ɹ���"<<endl;
	system("pause");

}

void alert_contract()///�޸ĺ�ͬ��Ϣ
{
    cout_contract();
    fstream file("���޺�ͬ��Ϣ.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x, ss;
	string line;
    cout<<endl;
	cout<<"\t\t\t��������Ҫ�޸ĵ���ţ�";
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
		//�޸��ļ�ָ����
		else
		{
		    cout<<endl;
			cout<<"\t\t\t������Ҫ�޸ĵ����ݣ�"<<endl;
			cout<<endl;
			int a, b, c, d, e, f, g;
			cout<<"\t\t\t�����ţ�";
			cin>>a;
			cout<<endl;
			cout<<"\t\t\t������ţ�";
			cin>>b;
			fstream tfile("������Ϣ.txt");
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
			cout<<"\t\t\t������ţ�";
			cin>>c;
			cout<<endl;
			cout<<"\t\t\t��ֹ���ڣ�"<<endl;
			cout<<endl;
			cout<<"\t\t\t    �꣺";
			cin>>d;
			cout<<endl;
			cout<<"\t\t\t    �£�";
			cin>>e;
			cout<<endl;
			cout<<"\t\t\t    �գ�";
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

	ofstream outfile1("���޺�ͬ��Ϣ.txt",ios::out|ios::trunc);
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

	//ɾ��2.txt
	system("del temp.txt");
	cout<<"\t\t\t�޸ĳɹ�, ���������ϼ�����"<<endl;
	system("pause");
}

void handle_contract()///�����ͬ�˵�ok
{
    int flag=1;
    while(flag)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "        ��ӭ���뷿������ϵͳ          " << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ��ѯ��ͬ��Ϣ(1)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ��Ӻ�ͬ��Ϣ(2)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ɾ����ͬ��Ϣ(3)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �޸ĺ�ͬ��Ϣ(4)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �����ϼ��˵�(5)            �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
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
        cout << setw(60) << "        ��ӭ���뷿������ϵͳ          " << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �����û���Ϣ(1)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ����������Ϣ(2)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ������ͬ��Ϣ(3)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �����ϼ��˵�(4)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
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

void admin_login()///����Ա��¼ok
{
    string admin="admin";
    string password="admin";
    string a, p;
    int flag=1;
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
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U     ���������Ա�˺ţ�             �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U     ���������Ա���룺             �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
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
        cout << setw(60) << "        ��ӭ���뷿������ϵͳ          " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
        cout << setw(60) << "�U          ���������Ϣ����          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U �������������Ա�˺ţ�             �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U �������������Ա���룺             �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
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
    cout<<setw(55)<<"��½�ɹ��� �������Ϊ����Ա��"<<endl;
    cout<<endl;
    system("pause");
    admin_lower_menu();
    return;
}

void rent_login()///KMPӦ�ã��û���¼��
{
    system("cls");
    char a[50], b[50];
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
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U       �������������ƣ�             �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U     ������������ϵ��ʽ��           �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    gotoxy(46, 13);
    cin>>a;
    gotoxy(48, 16);
    cin>>b;
    ifstream infile_per;
    infile_per.open("�ͻ���Ϣ.txt", ios::in);
    if(!infile_per||infile_per.eof())
    {
        cerr<<"�Ҳ������ĸ�����Ϣ����ǰȥע��"<<endl;
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
        infile_per.open("�ͻ���Ϣ.txt", ios::in);
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
            cout<<setw(53)<<"δ��ѯ�������Ϣ�� ����������"<<endl<<endl;
            cout<<setw(35)<<"������"<<--t_num<<"�λ��ᣬ�����"<<endl;
            system("pause");
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
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�U    �����������������ƣ�            �U" << endl;
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�U   ����������������ϵ��ʽ��         �U" << endl;
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�U                                    �U" << endl;
            cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
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
            cout<<setw(40)<<"��½�ɹ�"<<endl;
            system("pause");
            lower_menu(ss, ee);
        }
        if(t_num<1)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t��л����ʹ��"<<endl;
            exit(1);
        }

    }while(!flag);

}

void rent_handle()///�û���ز���ok
{
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << setw(60) << "�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U         ע���û�(1)��              �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U         ��¼�û�(2)��              �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U         �����ϼ��˵�(3)��          �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
    cout << endl <<endl <<endl;
    cout<<setw(36) <<"��ѡ��";
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

void a_exit()///�˳�ϵͳ����
{
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t���Ѱ�ȫ�˳�����л��ʹ�ñ�ϵͳ"<<endl;

}

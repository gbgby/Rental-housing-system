class Date///��������ʱ�����
{
private:
    int year, month, day;
public:
    Date(){year=0; month=0; day=0;}
    Date(int a, int b, int c):year(a), month(b), day(c){}
    ~Date(){}
    void inter()
    {
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t�������������޵Ľ�ֹ����"<<endl;
        cout<<endl;
        cout<<"\t\t\t�������ڣ� �꣺";
        cin>>year;
        cout<<endl;
        cout<<"\t\t\t           �£�";
        cin>>month;
        cout<<endl;
        cout<<"\t\t\t           �գ�";
        cin>>day;
    }

    bool cmp()
    {
        if(year>=2017)
        {
            if(day>11)
                return true;
            if(month>1)
                return true;
            if(year>2017)
                return true;
            return false;
        }
        return false;
    }
    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
    bool isLeap(int year)//�ж��Ƿ�������
    {
        return (year%4==0&&year%100!=0)||year%400==0;//�淵��Ϊ1����Ϊ0
    }
    int daysOfMonth(int year,int month)
    {
        int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(month!=2)
            return day[month-1];
        else
            return 28+isLeap(year);
    }
    int daysOfDate()//����һ��������
    {
        int days=day;
        for(int y=1;y<year;y++)//������
            days+=365+isLeap(y);
        for(int m=1;m<month;m++)//������
            days+=daysOfMonth(year,m);
        return days;
    }
    int daysOfDate(Date d)//����һ��������
    {
        int days=d.day;
        for(int y=1;y<d.year;y++)//������
            days+=365+isLeap(y);
        for(int m=1;m<d.month;m++)//������
            days+=daysOfMonth(d.year,m);
        return days;
    }
};

class person///��������person����
{
private:
    string name;
    char sex; ///f or m;
    string tel;
public:
    person(){}
    person(string a, char b, string c):name(a), tel(c){sex=b;}
    ~person(){cout<<"����ϵ����ɾ��"<<endl;}
    void outer()
    {
        cout<<"�ͻ�������"<<name<<endl;
        cout<<"�ͻ��Ա�"<<sex<<endl;
        cout<<"�ͻ���ϵ��ʽ��"<<tel<<endl;
    }
    void inper()
    {
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t¼���û���Ϣ"<<endl;
        cout<<endl<<endl;
        cout<<"\t\t\t�������û�����";
        cin>>name;
      ///  const char *t_name=name.c_str();
        cout<<endl;
        cout<<"\t\t\t��ϵ��ʽ��";
        cin>>tel;
        cout<<endl;
        cout<<"\t\t\t�Ա�(m/f)��";
        cin>>sex;
        cout<<endl;
    }
    char get_sex(){return sex;}
    string get_name(){return name;}
    string get_tel(){return tel;}
};

int judge_repeat(const char *a)///�ж��Ƿ����ظ���Ϣ
{
    int flag=1;
    fstream file("�ͻ���Ϣ.txt");
    while(!file.eof())
    {
        char line[500];
        file.getline(line, 200);
        if(file.eof())
            break;
        char *p=strstr(line, a);
        if(!p)
        {
            continue;
        }
        else
        {
            flag=0;
            break;
        }
    }
    file.close();
    return flag;
}

void select_contract(int ss)///���Ҹ��˵ĺ�ͬ��Ϣ
{
    int flag=1;
    system("cls");
    fstream file("���޺�ͬ��Ϣ.txt");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout<<"      ���   ������   �������   �������    ����ʱ��       �����"<<endl<<endl;
    while(!file.eof())
    {
        int a, b, c, d;
        string line;
        file>>a>>b>>c>>d;
        getline(file, line);
        if(file.eof())
            break;
        if(b==ss||d==ss)
        {
            flag=0;
            cout<<'\t'<<a<<'\t'<<b<<"\t   "<<c<<"          "<<d<<"  "<<line<<endl<<endl;
        }

    }
    if(flag)
        cout<<endl<<endl<<endl<<"\t\t\t�ǳ���Ǹ��δ��ѯ�������Ϣ"<<endl;
    file.close();
    system("pause");
}

void change_per(int ss)///�޸��û���Ϣok
{
    fstream file("�ͻ���Ϣ.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x;
	string line;
	system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t���������ĸ�����Ϣ"<<endl;
    cout<<endl<<endl;
	cout<<"\t\t���\t����\t�Ա�\t��ϵ��ʽ\t�ͻ����"<<endl<<endl;

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
		    cout<<"\t\t"<<x<<line<<endl;
		    cout<<endl<<endl;
			cout<<"\t\t\t������Ҫ�޸ĵ����ݣ�"<<endl;
			cout<<endl;
			string a, b, c;
			bool type;
			cout<<"\t\t\t������";
			cin>>a;
			cout<<endl;
			cout<<"\t\t\t�Ա�(f/m)��";
			cin>>b;
			cout<<endl;
			cout<<"\t\t\t��ϵ��ʽ��";
			cin>>c;
			cout<<endl;
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
	cout<<endl<<endl;
	cout<<"\t\t\t�޸ĳɹ�, ���������ϼ�����"<<endl;
	system("pause");
	return;
}

void change_rom(int ss, int ee)///�޸ķ�����Ϣok
{
   /// cout<<ss<<" "<<ee<<endl;
   /// system("pause");
    if(ee)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t���������ķ�����Ϣ"<<endl;
        cout<<endl<<endl;
        cout<<"\t\t���\t���\t�����\t״̬\t�������"<<endl<<endl;

        fstream file("������Ϣ.txt");
        ofstream outfile("temp.txt",ios::out|ios::trunc);


        while(!file.eof())
        {
            int a, b, c, d, e;
            file>>a>>b>>c>>d>>e;

            if(file.eof())
                break;
            if(e!=ss)
            {
                outfile<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'<<e<<endl;
            }

            else
            {
                cout<<"\t\t"<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'<<e<<endl;
                cout<<endl<<endl;
                cout<<"\t\t\t������Ҫ�޸ĵ����ݣ�"<<endl;
                cout<<endl;
                int x, y, z;
                cout<<"\t\t\t���������";
                cin>>x;
                cout<<endl;
                cout<<"\t\t\t���������";
                cin>>y;
                cout<<endl;
                cout<<"\t\t\t��������״̬(0-δ�����1-�����)��";
                cin>>z;
                outfile<<a<<'\t'<<x<<'\t'<<y<<'\t'<<z<<'\t'<<e<<endl;
            }
        }
        file.close();
        outfile.close();

        ofstream outfile1("������Ϣ.txt",ios::out|ios::trunc);
        fstream file1("temp.txt");

        string line;

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
        cout<<endl<<endl;
        cout<<"\t\t\t�޸ĳɹ�"<<endl;
        system("pause");
        return;
    }
    else
    {
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t���Ǹе��쳣��Ǹ��"<<endl;
        cout<<"\t\t\tδ��ѯ��������ط�����Ϣ��"<<endl;
        system("pause");
    }
}

class house///��ʱ��ȡ�ռ�
{
public:
    int h_num;///���
    int h_size;///���
    int h_price;///�����
    int h_renter;///�������
    bool h_state;///״̬
};

void creat_tree_down(house *a, int i, int n)///�����ѽṹ
{
    house temp=a[i];
    int j=2*i+1;
    while(j<n)
    {
        if(j+1<n&&a[j].h_size>a[j+1].h_size)
            ++j;
        if(temp.h_size<=a[j].h_size)
            break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=temp;
}

void creat_tree(house *a, int n)///�����ѽṹ
{
    for(int i=n/2-1; i>=0; --i)
        creat_tree_down(a, i, n);
}

void delet_tree(house *a, int i, int n)///ɾ���Ѷ�Ԫ��
{
    swap(a[0], a[n-1]);
    creat_tree_down(a, 0, n-1);
}

void sort_head(house *a, int n)///���ж�����
{
    for(int i=n-1;i>0;--i)
    {
        swap(a[0], a[i]);
        creat_tree_down(a, 0, i);
    }
}

bool cmp1(house h1, house h2)
{
    return h1.h_size>h2.h_size;
}

bool cmp3(house h1, house h2)
{
    return h1.h_size<h2.h_size;
}

bool cmp2(house h1, house h2)
{
    return h1.h_price<h2.h_price;
}

bool cmp4(house h1, house h2)
{
    return h1.h_price>h2.h_price;
}

bool cmp5(house h1, house h2)
{
    double x=h1.h_price/h1.h_size;
    double y=h2.h_price/h2.h_size;
    return x<y;
}

house t_house[20];

void change_type(int ss)///���ķ���״̬
{
    fstream file("������Ϣ.txt");
    ofstream outfile("temp.txt",ios::out|ios::trunc);
    while(!file.eof())
    {
        int a, b, c, e;
        bool d;
        file>>a>>b>>c>>d>>e;
        if(a==ss)
            d=!d;
        if(file.eof())
            break;
        outfile<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\t'<<e<<endl;

    }
    file.close();
    outfile.close();

    ofstream outfile1("������Ϣ.txt",ios::out|ios::trunc);
	fstream file1("temp.txt");

	string line;

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
	///system("del temp.txt");
}

int house_sort(int x)///ʵ�ַ���������(�����򣬿�������)
{
    ifstream infile_rm;
    infile_rm.open("������Ϣ.txt", ios::in);
    if(!infile_rm)
    {
        cerr<<"�򿪴���"<<endl;
        abort();
    }
    int i=0;
    while(!infile_rm.eof())
    {
        int a, b, c, d, e;
        infile_rm>>a>>b>>c>>d>>e;
        t_house[i].h_state=d;
        if(!d)
        {
            t_house[i].h_num=a;
            t_house[i].h_size=b;
            t_house[i].h_price=c;
            t_house[i].h_renter=e;
            if(infile_rm.eof())
                break;
            i++;
        }

    }
    infile_rm.close();
    /*
    for(int j=0;j<i-1;++j)
        cout<<r[j].h_num<<" "<<r[j].h_size<<" "<<r[j].h_price<<" "<<r[j].h_renter<<endl;
    */
    if(x==2)
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
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U      ���������С��������(1)��     �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U      ��������Ӵ�С����(2)��     �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
        int z;
        cin>>z;
        if(z!=2)
        {
            sort(t_house, t_house+i, cmp3);
        }

        else
        {
            creat_tree(t_house, i);
            sort_head(t_house, i);
            ///sort(t_house, t_house+i, cmp1);
        }

    }
    else if(x==3)
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
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U      ��������С��������(1)��     �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U      �������Ӵ�С����(2)��     �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
        int z;
        cin>>z;
        if(z==1)
            sort(t_house, t_house+i, cmp2);
        else
            sort(t_house, t_house+i, cmp4);
    }
    else if(x==4)
    {
        sort(t_house, t_house+i, cmp5);
    }
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(60) << "        ��ӭ���뷿������ϵͳ          " << endl;
    cout << endl;
    cout << endl;
    cout<<"                        ���\t���\t�����\t�������"<<endl<<endl;
    for(int j=0;j<i;++j)
        if(t_house[j].h_state==0)
            cout<<"                        "<<t_house[j].h_num<<"\t"<<t_house[j].h_size<<"\t"<<t_house[j].h_price<<"\t"<<t_house[j].h_renter<<endl<<endl;
    cout<<endl;
    return i;
}

class contract:public Date///��װ��ͬ��
{
private:
    int con_num;///��ͬ���
    int rent_num;///���ҵı��
    int buy_num;///��ҵı��
    int sum_price;///���ݼ�
    int room_num;///���ݱ��
public:
    contract(){select_num();}
    ~contract(){cout<<"�ú�ͬ��ʧЧ"<<endl;}
    int get_buy_num(){return buy_num;}
    int get_rent_num(){return rent_num;}
    void inper(int x, int y, int z, int p)
    {
        room_num=y;
        rent_num=p;
        buy_num=x;
        sum_price=z;
        cout<<endl<<endl;
        Date::inter();
        while(!cmp())
        {
            cout<<"\t\t\t�������ڴ�������������";
            //system("pause");
            Date::inter();
        }
        int tt=daysOfDate();
        Date d(2017, 1, 11);
        int td=daysOfDate(d);
        int t_day=tt-td;
        double t_price=sum_price/30;
        double t_sum=t_price*t_day;
        cout<<endl<<endl;

        cout<<"\t\t����Ҫ����"<<t_sum/10<<"Ԫ�Ķ���"<<t_sum/5<<"��Ѻ��"<<endl;
        cout<<endl;
        cout<<"\t\t��ȷ���Ƿ���ɣ����ɺ��ͬ���ἴʱ��Ч!(y/n)";
        char _tt[2];
        cin>>_tt;
        if(_tt[0]=='y')
        {
            change_type(room_num);
            ofstream outfile;
            outfile.open("���޺�ͬ��Ϣ.txt", ios::app);
            outfile<<con_num<<'\t'<<buy_num<<'\t'<<room_num<<'\t'<<rent_num<<'\t'<<get_year()<<' '<<get_month()<<' '<<get_day()<<'\t'<<t_sum<<endl;
            outfile.close();
            cout<<endl;
            cout<<"\t\t\t���ɳɹ�, �ú�ͬ��ʱ��Ч��"<<endl;
            system("pause");
        }
        else
        {
            cout<<endl;
            cout<<"\t\t��������һ�������������"<<endl;
            system("pause");
            return;
        }

    }
    void select_num()
    {
        fstream file;
        file.open("���޺�ͬ��Ϣ.txt",ios::in);
        char ch=file.get();
        if(file.eof())
        {
            con_num=1;
            file.close();
            return;
        }

        int hs[100];
        system("cls");
        memset(hs, 0, sizeof(hs));
        fstream file1("���޺�ͬ��Ϣ.txt", ios::in|ios::out);
        int x;
        string line;
        while(!file1.eof())
        {
            file1>>x;
            hs[x]=1;
            getline(file1,line);
            if(file.eof())
                break;
        }
        file1.close();

        for(int i=1;i<99;++i)
            if(!hs[i])
            {
                x=i;
                break;
            }
        ///cout<<x<<endl;
        ///system("pause");
        con_num=x;
    }

};

void answer_sort(int ss)///ȷ��������Ϣok
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
    cout << setw(60) << "�U   ���ݰ����������(1)��            �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U   ���ݰ����������(2)��            �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U   ���ݰ��ռ۸�����(3)��            �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U   ���ݰ����Լ۱�����(�ɸߵ���)(4)  �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�U                                    �U" << endl;
    cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;     cout<<endl;
    cout<<endl;
    cout<<endl;
    int flag=1;
    cout<<setw(36) <<"��ѡ��";
    int x;
    cin>>x;
    int i=house_sort(x);
    cout<<endl<<endl;
    cout<<setw(50)<<"��ѡ�������з��ݵ���ţ�";
    while(flag)
    {
        int y;
        cin>>y;
        for(int j=0;j<i;++j)
            if(y==t_house[j].h_num)
            {
                y=j;
                break;
            }
        cout<<endl;
        cout<<"                        ���\t���\t�����\t�������"<<endl<<endl;
        cout<<"                        "<<t_house[y].h_num<<"\t"<<t_house[y].h_size<<"\t"<<t_house[y].h_price<<"\t"<<t_house[y].h_renter<<endl<<endl;
        cout<<"                 ��ȷ���Ƿ�Ϊ������Ҫ�ķ������飬 ȷ��(y/n)��";
        char s[2];
        cin>>s;
        if(s[0]=='y')
        {
            flag=0;
            contract c;
            c.inper(ss, t_house[y].h_num, t_house[y].h_price, t_house[y].h_renter);
            break;
        }
        else
        {
            cout<<setw(50)<<"������ѡ�������з��ݵ���ţ�";
        }
    }
}

void lower_menu(int ss, int ee)///�¼��˵�ok
{
    int flag=1;
    do
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
        cout << setw(60) << "�U         ��ѯ��ͬ��Ϣ(1)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �޸ĸ�����Ϣ(2)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �޸ķ�����Ϣ(3)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         ������ͬ��Ϣ(4)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�U         �����ϼ��˵�(5)��          �U" << endl;
        cout << setw(60) << "�U                                    �U" << endl;
        cout << setw(60) << "�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"��ѡ��";
        int x;
        cin>>x;
        switch (x)
        {
            case 1:select_contract(ss);break;
            case 2:change_per(ss);break;
            case 3:change_rom(ss, ee);break;
            case 4:answer_sort(ss);break;
            default:flag=0;break;
        }
    }while(flag);

}

class room///������װ������
{
private:
    int room_num;
    int room_size;
    int room_price;
    bool room_state;
public:
    room()
    {
        room_state=0;///δ�۳�
        get_numer();
    }
    room(int a, int b):room_size(a), room_price(b)
    {
        room_state=0;
        get_numer();
        cout<<"�÷�������¼�� ����Ϊ"<<room_num<<endl;
    }
    ~room(){cout<<"�÷����ѱ�ɾ��"<<endl;}
    int get_room_size(){return room_size;}
    int get_room_price(){return room_price;}
    bool get_room_state(){return room_state;}
    int get_room_num(){return room_num;}
    void get_numer()
    {
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
        for(int i=1;i<99;++i)
            if(!hs[i])
            {
                x=i;
                break;
            }
        room_num=x;
    }
    void inper()
    {
        cout<<endl<<endl;
        cout<<"\t\t\t���뷿�������";
        cin>>room_size;
        cout<<endl;
        cout<<"\t\t\t������ۣ�";
        cin>>room_price;
        cout<<endl;
        cout<<"\t\t\t�÷�������¼�� ����Ϊ"<<room_num<<endl;
    }
};

class renter:public person///��װ�û���
{
private:
    int this_num;///��ǰ���
    int room_sum;///����Ҫ�������������
    int room_num[12];///�������������ķ��ݱ��
    bool type;///������ 0Ϊ�⻧ 1Ϊ���⻧
public:
    renter()
    {
        get_numer();
    }
    ~renter()
    {
        if(type==1)
            cout<<"���⻧";
        else
            cout<<"�����";
        cout<<"����ѱ�ɾ��"<<endl;
    }
    void inper()
    {
        while(1)
        {
            person::inper();
            cout<<"\t\t\t�ͻ�����(0-����ͻ���1-����ͻ�)��";
            cin>>type;
            const char *a=get_name().c_str();
        //    cout<<a<<endl;
        //    system("pause");

            if(judge_repeat(a))
                break;
            else
            {
                cout<<endl<<endl<<endl;
                cout<<"\t\t���������Ϣ�ѱ�ע�ᣬ����������"<<endl;
                system("pause");
            }

        }
        ofstream outfile("temp.txt");
        fstream tfile("�ͻ���Ϣ.txt", ios::in|ios::out);
        string line;
        int s_num=1;

        while(!tfile.eof())
        {
            getline(tfile,line);
            if(tfile.eof())
                break;
            if(this_num==s_num)
            {
                outfile<<this_num<<'\t'<<get_name()<<'\t'<<get_sex()<<'\t'<<get_tel()<<"\t\t"<<type<<endl;
            }
            outfile<<line<<endl;
            s_num++;
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
        cout<<endl<<endl;
        cout<<"\t\t\t���¼��ɹ�"<<endl;

    }
    void type_handle()
    {
        if(type==1)
        {
            cout<<endl<<endl;
            cout<<"\t\t\t����������ݣ�����Ϊ������¼�뷿����Ϣ"<<endl;
            system("pause");
            system("cls");
            typing_room();
        }
        else
        {
            system("pause");
            system("cls");
            int ss=this_num;
            int ee=type;
            lower_menu(ss, ee);
        }
    }
    int get_this_num()
    {
        return this_num;
    }
    void get_numer()
    {
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
        for(int i=1;i<99;++i)
            if(!hs[i])
            {
                x=i;
                break;
            }
        this_num=x;

    }
    void typing_room()///¼�뷿����Ϣ
    {
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t��������Ҫ¼��ķ�����Ϣ"<<endl;
        room r;
        r.inper();
        ofstream outfile_rm;
        outfile_rm.open("������Ϣ.txt", ios::app);
        if(!outfile_rm)
        {
            cerr<<"�򿪴���"<<endl;
            abort();
        }
        outfile_rm<<r.get_room_num()<<'\t'<<r.get_room_size()<<'\t'<<r.get_room_price()<<"\t"<<r.get_room_state()<<"\t"<<this_num<<endl;
        outfile_rm.close();
        cout<<endl<<endl;
        cout<<"\t\t������Ϣ¼��ɹ���ҳ�漴����ת���������һ������"<<endl;
        system("pause");
        int ss=this_num;
        int ee=type;
        lower_menu(ss, ee);
    }
};

class Date///初步构造时间基类
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
        cout<<"\t\t\t请输入您想租赁的截止日期"<<endl;
        cout<<endl;
        cout<<"\t\t\t输入日期， 年：";
        cin>>year;
        cout<<endl;
        cout<<"\t\t\t           月：";
        cin>>month;
        cout<<endl;
        cout<<"\t\t\t           日：";
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
    bool isLeap(int year)//判断是否是闰年
    {
        return (year%4==0&&year%100!=0)||year%400==0;//真返回为1，假为0
    }
    int daysOfMonth(int year,int month)
    {
        int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(month!=2)
            return day[month-1];
        else
            return 28+isLeap(year);
    }
    int daysOfDate()//计算一共的天数
    {
        int days=day;
        for(int y=1;y<year;y++)//计算年
            days+=365+isLeap(y);
        for(int m=1;m<month;m++)//计算月
            days+=daysOfMonth(year,m);
        return days;
    }
    int daysOfDate(Date d)//计算一共的天数
    {
        int days=d.day;
        for(int y=1;y<d.year;y++)//计算年
            days+=365+isLeap(y);
        for(int m=1;m<d.month;m++)//计算月
            days+=daysOfMonth(d.year,m);
        return days;
    }
};

class person///初步构造person基类
{
private:
    string name;
    char sex; ///f or m;
    string tel;
public:
    person(){}
    person(string a, char b, string c):name(a), tel(c){sex=b;}
    ~person(){cout<<"该联系人已删除"<<endl;}
    void outer()
    {
        cout<<"客户姓名："<<name<<endl;
        cout<<"客户性别："<<sex<<endl;
        cout<<"客户联系方式："<<tel<<endl;
    }
    void inper()
    {
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t录入用户信息"<<endl;
        cout<<endl<<endl;
        cout<<"\t\t\t请输入用户名：";
        cin>>name;
      ///  const char *t_name=name.c_str();
        cout<<endl;
        cout<<"\t\t\t联系方式：";
        cin>>tel;
        cout<<endl;
        cout<<"\t\t\t性别(m/f)：";
        cin>>sex;
        cout<<endl;
    }
    char get_sex(){return sex;}
    string get_name(){return name;}
    string get_tel(){return tel;}
};

int judge_repeat(const char *a)///判断是否有重复信息
{
    int flag=1;
    fstream file("客户信息.txt");
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

void select_contract(int ss)///查找个人的合同信息
{
    int flag=1;
    system("cls");
    fstream file("租赁合同信息.txt");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout<<"      序号   租客序号   房屋序号   房东序号    到期时间       总租金"<<endl<<endl;
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
        cout<<endl<<endl<<endl<<"\t\t\t非常抱歉！未查询到相关信息"<<endl;
    file.close();
    system("pause");
}

void change_per(int ss)///修改用户信息ok
{
    fstream file("客户信息.txt");
	ofstream outfile("temp.txt",ios::out|ios::trunc);
    int x;
	string line;
	system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t以下是您的个人信息"<<endl;
    cout<<endl<<endl;
	cout<<"\t\t序号\t名字\t性别\t联系方式\t客户身份"<<endl<<endl;

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
		    cout<<"\t\t"<<x<<line<<endl;
		    cout<<endl<<endl;
			cout<<"\t\t\t请输入要修改的内容："<<endl;
			cout<<endl;
			string a, b, c;
			bool type;
			cout<<"\t\t\t姓名：";
			cin>>a;
			cout<<endl;
			cout<<"\t\t\t性别(f/m)：";
			cin>>b;
			cout<<endl;
			cout<<"\t\t\t联系方式：";
			cin>>c;
			cout<<endl;
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
	cout<<endl<<endl;
	cout<<"\t\t\t修改成功, 即将返回上级操作"<<endl;
	system("pause");
	return;
}

void change_rom(int ss, int ee)///修改房屋信息ok
{
   /// cout<<ss<<" "<<ee<<endl;
   /// system("pause");
    if(ee)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\t\t\t以下是您的房屋信息"<<endl;
        cout<<endl<<endl;
        cout<<"\t\t序号\t面积\t月租金\t状态\t房东序号"<<endl<<endl;

        fstream file("房屋信息.txt");
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
                cout<<"\t\t\t请输入要修改的内容："<<endl;
                cout<<endl;
                int x, y, z;
                cout<<"\t\t\t房屋面积：";
                cin>>x;
                cout<<endl;
                cout<<"\t\t\t房屋年租金：";
                cin>>y;
                cout<<endl;
                cout<<"\t\t\t房屋租赁状态(0-未租出，1-已租出)：";
                cin>>z;
                outfile<<a<<'\t'<<x<<'\t'<<y<<'\t'<<z<<'\t'<<e<<endl;
            }
        }
        file.close();
        outfile.close();

        ofstream outfile1("房屋信息.txt",ios::out|ios::trunc);
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
        cout<<"\t\t\t修改成功"<<endl;
        system("pause");
        return;
    }
    else
    {
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t我们感到异常抱歉。"<<endl;
        cout<<"\t\t\t未查询到您的相关房屋信息！"<<endl;
        system("pause");
    }
}

class house///临时读取空间
{
public:
    int h_num;///序号
    int h_size;///面积
    int h_price;///年租金
    int h_renter;///房东序号
    bool h_state;///状态
};

void creat_tree_down(house *a, int i, int n)///调整堆结构
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

void creat_tree(house *a, int n)///构建堆结构
{
    for(int i=n/2-1; i>=0; --i)
        creat_tree_down(a, i, n);
}

void delet_tree(house *a, int i, int n)///删除堆顶元素
{
    swap(a[0], a[n-1]);
    creat_tree_down(a, 0, n-1);
}

void sort_head(house *a, int n)///进行堆排序
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

void change_type(int ss)///更改房屋状态
{
    fstream file("房屋信息.txt");
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

    ofstream outfile1("房屋信息.txt",ios::out|ios::trunc);
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

	//删除2.txt
	///system("del temp.txt");
}

int house_sort(int x)///实现房屋排序功能(堆排序，快速排序)
{
    ifstream infile_rm;
    infile_rm.open("房屋信息.txt", ios::in);
    if(!infile_rm)
    {
        cerr<<"打开错误"<<endl;
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
        cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║      按照面积从小到大排序(1)：     ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║      按照面积从大到小排序(2)：     ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
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
        cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║      按照租金从小到大排序(1)：     ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║      按照租金从大到小排序(2)：     ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
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
    cout << setw(60) << "        欢迎进入房屋租赁系统          " << endl;
    cout << endl;
    cout << endl;
    cout<<"                        序号\t面积\t月租金\t主人序号"<<endl<<endl;
    for(int j=0;j<i;++j)
        if(t_house[j].h_state==0)
            cout<<"                        "<<t_house[j].h_num<<"\t"<<t_house[j].h_size<<"\t"<<t_house[j].h_price<<"\t"<<t_house[j].h_renter<<endl<<endl;
    cout<<endl;
    return i;
}

class contract:public Date///封装合同类
{
private:
    int con_num;///合同编号
    int rent_num;///卖家的编号
    int buy_num;///买家的编号
    int sum_price;///房屋价
    int room_num;///房屋编号
public:
    contract(){select_num();}
    ~contract(){cout<<"该合同已失效"<<endl;}
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
            cout<<"\t\t\t输入日期错误，请重新输入";
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

        cout<<"\t\t您需要缴纳"<<t_sum/10<<"元的定金及"<<t_sum/5<<"的押金"<<endl;
        cout<<endl;
        cout<<"\t\t请确认是否缴纳，缴纳后合同将会即时生效!(y/n)";
        char _tt[2];
        cin>>_tt;
        if(_tt[0]=='y')
        {
            change_type(room_num);
            ofstream outfile;
            outfile.open("租赁合同信息.txt", ios::app);
            outfile<<con_num<<'\t'<<buy_num<<'\t'<<room_num<<'\t'<<rent_num<<'\t'<<get_year()<<' '<<get_month()<<' '<<get_day()<<'\t'<<t_sum<<endl;
            outfile.close();
            cout<<endl;
            cout<<"\t\t\t缴纳成功, 该合同即时生效！"<<endl;
            system("pause");
        }
        else
        {
            cout<<endl;
            cout<<"\t\t将返回上一级，请继续操作"<<endl;
            system("pause");
            return;
        }

    }
    void select_num()
    {
        fstream file;
        file.open("租赁合同信息.txt",ios::in);
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
        fstream file1("租赁合同信息.txt", ios::in|ios::out);
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

void answer_sort(int ss)///确定房屋信息ok
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
    cout << setw(60) << "║   房屋按照序号排序(1)：            ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║   房屋按照面积排序(2)：            ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║   房屋按照价格排序(3)：            ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║   房屋按照性价比排序(由高到低)(4)  ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "║                                    ║" << endl;
    cout << setw(60) << "╰══════════════════╯" << endl;     cout<<endl;
    cout<<endl;
    cout<<endl;
    int flag=1;
    cout<<setw(36) <<"请选择：";
    int x;
    cin>>x;
    int i=house_sort(x);
    cout<<endl<<endl;
    cout<<setw(50)<<"请选择所看中房屋的序号：";
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
        cout<<"                        序号\t面积\t月租金\t主人序号"<<endl<<endl;
        cout<<"                        "<<t_house[y].h_num<<"\t"<<t_house[y].h_size<<"\t"<<t_house[y].h_price<<"\t"<<t_house[y].h_renter<<endl<<endl;
        cout<<"                 请确定是否为您所需要的房屋详情， 确定(y/n)：";
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
            cout<<setw(50)<<"请重新选择所看中房屋的序号：";
        }
    }
}

void lower_menu(int ss, int ee)///下级菜单ok
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
        cout << setw(60) << "╭══════════════════╮" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         查询合同信息(1)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         修改个人信息(2)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         修改房屋信息(3)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         建立合同信息(4)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "║         返回上级菜单(5)：          ║" << endl;
        cout << setw(60) << "║                                    ║" << endl;
        cout << setw(60) << "╰══════════════════╯" << endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(36) <<"请选择：";
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

class room///初步封装房屋类
{
private:
    int room_num;
    int room_size;
    int room_price;
    bool room_state;
public:
    room()
    {
        room_state=0;///未售出
        get_numer();
    }
    room(int a, int b):room_size(a), room_price(b)
    {
        room_state=0;
        get_numer();
        cout<<"该房屋已收录， 其编号为"<<room_num<<endl;
    }
    ~room(){cout<<"该房屋已被删除"<<endl;}
    int get_room_size(){return room_size;}
    int get_room_price(){return room_price;}
    bool get_room_state(){return room_state;}
    int get_room_num(){return room_num;}
    void get_numer()
    {
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
        cout<<"\t\t\t输入房屋面积：";
        cin>>room_size;
        cout<<endl;
        cout<<"\t\t\t房屋租价：";
        cin>>room_price;
        cout<<endl;
        cout<<"\t\t\t该房屋已收录， 其编号为"<<room_num<<endl;
    }
};

class renter:public person///封装用户类
{
private:
    int this_num;///当前编号
    int room_sum;///所需要或租出房屋总数
    int room_num[12];///下联的所供给的房屋编号
    bool type;///其类型 0为租户 1为被租户
public:
    renter()
    {
        get_numer();
    }
    ~renter()
    {
        if(type==1)
            cout<<"该租户";
        else
            cout<<"该租客";
        cout<<"身份已被删除"<<endl;
    }
    void inper()
    {
        while(1)
        {
            person::inper();
            cout<<"\t\t\t客户类型(0-求租客户，1-出租客户)：";
            cin>>type;
            const char *a=get_name().c_str();
        //    cout<<a<<endl;
        //    system("pause");

            if(judge_repeat(a))
                break;
            else
            {
                cout<<endl<<endl<<endl;
                cout<<"\t\t您输入的信息已被注册，请重新输入"<<endl;
                system("pause");
            }

        }
        ofstream outfile("temp.txt");
        fstream tfile("客户信息.txt", ios::in|ios::out);
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
        cout<<endl<<endl;
        cout<<"\t\t\t身份录入成功"<<endl;

    }
    void type_handle()
    {
        if(type==1)
        {
            cout<<endl<<endl;
            cout<<"\t\t\t鉴于您的身份，即将为您安排录入房屋信息"<<endl;
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
        for(int i=1;i<99;++i)
            if(!hs[i])
            {
                x=i;
                break;
            }
        this_num=x;

    }
    void typing_room()///录入房屋信息
    {
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t请输入您要录入的房屋信息"<<endl;
        room r;
        r.inper();
        ofstream outfile_rm;
        outfile_rm.open("房屋信息.txt", ios::app);
        if(!outfile_rm)
        {
            cerr<<"打开错误"<<endl;
            abort();
        }
        outfile_rm<<r.get_room_num()<<'\t'<<r.get_room_size()<<'\t'<<r.get_room_price()<<"\t"<<r.get_room_state()<<"\t"<<this_num<<endl;
        outfile_rm.close();
        cout<<endl<<endl;
        cout<<"\t\t房屋信息录入成功。页面即将跳转，请进行下一步操作"<<endl;
        system("pause");
        int ss=this_num;
        int ee=type;
        lower_menu(ss, ee);
    }
};


#include<bits/stdc++.h>
#define MAXSIZE 10000
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
struct Book{
    string num;
    string name;
    float price;
};
typedef struct{
    Book *elem;//存储空间基地址
    int length;//当前长度
}Sqlist;
//--------------------------顺序表的初始化---------------------------
Satus InitList(Sqlist &L){//构造空的顺序表L
    L.elem=new Book[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);//存储分配失败退出
    L.length=0;//空表长度为0
    return OK;
}
//--------------------------顺序表的取值---------------------------
Status GetElem(Sqlist L,int i,Book &e){
    if(i<1||i>L.length)  return ERROR;
    e=L.elem[i-1];
    return OK;
}
//--------------------------顺序表的查找---------------------------
int locateElem(Sqlist L,string s)
{
    for(int i=0;i<L.length;i++)

        if(s==L.elem[i].name)
            return i+1;//查找成功，返回序号i+1;

    return 0;

}
//--------------------------顺序表的插入---------------------------
Satus ListInsert(Sqlist &L,int i,Book e)
{
    if(i<1||i<L.length+1) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]==L.elem[j];
    }
       L.elem[i-1]=e;
       ++L.length;
       return OK;
}
//--------------------------顺序表的删除---------------------------
Status ListDelete(Sqlist &L,int i)
{
    if(i<1||i>L.length) return false;
    for(j=i;j<L.length;j++)
        L.elem[j-1]=L.elem[j];
    --L.length;
    return OK;

}
int main()
{
    Sqlist L;
    int i=0,temp,a,c,choose;
    string name;
    Book e;
    string head1,head2,head3;
    cout<<"1.建表"<<endl;
    cout<<"2.输入"<<endl;
    cout<<"3.取值"<<endl;
    cout<<"4.查找"<<endl;
    cout<<"5.插入"<<endl;
    cout<<"6.删除"<<endl;
    cout<<"7.输出"<<endl;
    cout<<"0.退出"<<endl;
    choose=-1;
    while(choose!=0)
    {
        cout<<"请选择：";
        cin>>choose;
        switch(choose)
        {
           case 1://建表
               if(InitList(L)) cout<<"成功建立顺序表"<<endl;
               else cout<<"创建顺序表失败"<<endl;
               break;
           case 2: //输入
               i=0;
               L.elem=new Book[MAXSIZE];
               if(!L.elem) exit(OVERFLOW);
               L.length=0;
               fstream file;
               file.open("bool.txt");
               if(!file){
                 cout<<"错误！未找到文件"<<endl;
                 exit(ERROR);

               }
               file>>head1>>head2>>head3;
               while(!file.eof())
               {
                   file>>L.elem[i].num>>L.elem[i].name>>L.elem[i].price;
                   i++;

               }
               cout<<"输入 book.txt 信息完毕！"<<endl;
               L.length=i;
               file.close();
               break;
           case 3://取值
               cout<<"输入要取值的位置:"<<endl;
               cin>>i;
               temp=GetElem(L,i,e);
               if(temp!=0)
               {
                   cout<<"查找成功！"<<endl;
                   cout<<"第"<<i<<"本图书的信息是："<<endl;
                   cout<<left<<setw(15)<<e.num<<"\t"<<left<<setw(50)<<e.name<<"\t"<<left<<setw(5)<<e.price<<endl;

               }
                else cout<<"查找失败！"<<endl;
                break;
           case 4://查找
               cout<<"请输入要查找图书的名字:"<<endl;
               cin>>name;
               temp=locateElem(L,name);
               if(temp!=0) 	cout << "查找成功\n";
				cout << "编号：" << L.elem[temp - 1].num <<"书名："<<L.elem[temp-1].name<<"价格："<<L.elem[temp-1].price<< endl ;
                else cout<<"查ListDelete(Sqlist &L,int i)找失败！"<<endl;
                break;
           case 5://插入
              cout << "请输入插入的位置和书本信息，包括：编号 书名 价格（用空格隔开）:";
              cin>>a;
              cin>>e.num<<e.name<<e.price;
              if(ListInsert(L,a,e))
               cout<<"插入成功！"<<endl;
               else cout<<"插入失败！"<<endl;
               break;

           case 6://删除
               cout<<"请输入所要删除书籍的位置：";
               cin>>c;
               if(ListDelete(L,c))
                cout<<"删除成功！"<<endl;
               else cout<<"删除失败"<<endl;
               break;
           case 7://顺序表的输出
	            cout << "当前图书系统信息（顺序表）读出:\n";
                 for(i=0;i<L.length;i++)
                	cout << left << setw(15) << L.elem[i].num << "\t" << left
						<< setw(50) << L.elem[i].name << "\t" << left
						<< setw(5) << L.elem[i].price << endl;
                break;
           case 0:
                choose=0;
        }

    }


    return 0;
}

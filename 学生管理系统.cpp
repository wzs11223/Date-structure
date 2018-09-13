
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
    Book *elem;//�洢�ռ����ַ
    int length;//��ǰ����
}Sqlist;
//--------------------------˳���ĳ�ʼ��---------------------------
Satus InitList(Sqlist &L){//����յ�˳���L
    L.elem=new Book[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);//�洢����ʧ���˳�
    L.length=0;//�ձ���Ϊ0
    return OK;
}
//--------------------------˳����ȡֵ---------------------------
Status GetElem(Sqlist L,int i,Book &e){
    if(i<1||i>L.length)  return ERROR;
    e=L.elem[i-1];
    return OK;
}
//--------------------------˳���Ĳ���---------------------------
int locateElem(Sqlist L,string s)
{
    for(int i=0;i<L.length;i++)

        if(s==L.elem[i].name)
            return i+1;//���ҳɹ����������i+1;

    return 0;

}
//--------------------------˳���Ĳ���---------------------------
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
//--------------------------˳����ɾ��---------------------------
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
    cout<<"1.����"<<endl;
    cout<<"2.����"<<endl;
    cout<<"3.ȡֵ"<<endl;
    cout<<"4.����"<<endl;
    cout<<"5.����"<<endl;
    cout<<"6.ɾ��"<<endl;
    cout<<"7.���"<<endl;
    cout<<"0.�˳�"<<endl;
    choose=-1;
    while(choose!=0)
    {
        cout<<"��ѡ��";
        cin>>choose;
        switch(choose)
        {
           case 1://����
               if(InitList(L)) cout<<"�ɹ�����˳���"<<endl;
               else cout<<"����˳���ʧ��"<<endl;
               break;
           case 2: //����
               i=0;
               L.elem=new Book[MAXSIZE];
               if(!L.elem) exit(OVERFLOW);
               L.length=0;
               fstream file;
               file.open("bool.txt");
               if(!file){
                 cout<<"����δ�ҵ��ļ�"<<endl;
                 exit(ERROR);

               }
               file>>head1>>head2>>head3;
               while(!file.eof())
               {
                   file>>L.elem[i].num>>L.elem[i].name>>L.elem[i].price;
                   i++;

               }
               cout<<"���� book.txt ��Ϣ��ϣ�"<<endl;
               L.length=i;
               file.close();
               break;
           case 3://ȡֵ
               cout<<"����Ҫȡֵ��λ��:"<<endl;
               cin>>i;
               temp=GetElem(L,i,e);
               if(temp!=0)
               {
                   cout<<"���ҳɹ���"<<endl;
                   cout<<"��"<<i<<"��ͼ�����Ϣ�ǣ�"<<endl;
                   cout<<left<<setw(15)<<e.num<<"\t"<<left<<setw(50)<<e.name<<"\t"<<left<<setw(5)<<e.price<<endl;

               }
                else cout<<"����ʧ�ܣ�"<<endl;
                break;
           case 4://����
               cout<<"������Ҫ����ͼ�������:"<<endl;
               cin>>name;
               temp=locateElem(L,name);
               if(temp!=0) 	cout << "���ҳɹ�\n";
				cout << "��ţ�" << L.elem[temp - 1].num <<"������"<<L.elem[temp-1].name<<"�۸�"<<L.elem[temp-1].price<< endl ;
                else cout<<"��ListDelete(Sqlist &L,int i)��ʧ�ܣ�"<<endl;
                break;
           case 5://����
              cout << "����������λ�ú��鱾��Ϣ����������� ���� �۸��ÿո������:";
              cin>>a;
              cin>>e.num<<e.name<<e.price;
              if(ListInsert(L,a,e))
               cout<<"����ɹ���"<<endl;
               else cout<<"����ʧ�ܣ�"<<endl;
               break;

           case 6://ɾ��
               cout<<"��������Ҫɾ���鼮��λ�ã�";
               cin>>c;
               if(ListDelete(L,c))
                cout<<"ɾ���ɹ���"<<endl;
               else cout<<"ɾ��ʧ��"<<endl;
               break;
           case 7://˳�������
	            cout << "��ǰͼ��ϵͳ��Ϣ��˳�������:\n";
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

# include <iostream>
# include "Student.h"
# include <fstream>
using namespace std;
int GetName(string m,int n,Student a[]);
void write(Student a[],int n);
void read(Student a[],int n);
void Cin(Student a[],int n);
void Print(Student a[],int n);
void Remove(Student a[],int n);
void Fix(Student a[],int n);
void Add(Student a[]);
void Search(Student a[],int n);
int x1,n;
int main(){
   Student a[300];
   int b=1;
   cout<<"请选择下面的一个项目："<<endl;
   int i;
   for(;b!=9;){
   cout<<"1 创建"<<endl<<"2 添加"<<endl<<"3 查询"<<endl<<"4 修改"<<endl<<"5 删除"<<endl<<"6 显示"<<endl<<"7 文件导入"<<endl<<"8 文件导出"<<endl<<"9 退出"<<endl;
   cout<<"请选择:";
   cin>>b;
   switch(b){
      case 1:cout<<"请输入学生人数：";cin>>n;x1=n;Cin(a,n);break;
      case 2:Add(a);break;
      case 3:Search(a,x1);break;
      case 4:Fix(a,x1);break;
      case 5:Remove(a,x1);break;
      case 6:Print(a,x1);break;
      case 7:read(a,x1);break;
      case 8:write(a,x1);break;
      case 9:break;
      default:break;
   }
   cout<<endl;
   }   
   system("pause");
   return 0;
}
int GetName(string m,int n,Student a[]){
   int i,j=0;
   for(i=0;i<n;i++){
         if(a[i].getNum()==m){
         j++;
         break;
         }
      }
   if(j==0)  return -1;
   else    return i;
}
void write(Student a[],int n){
   ofstream outfile("student.dat",ios::out);
      if(!outfile){
         cout<<"open student.dat error!";
         exit(1);
      }
      else{
      for(int i=0;i<n;i++){
         outfile<<a[i].getNum()<<" "<<a[i].getNam()<<" "<<a[i].getSex()<<" "<<a[i].getAge()<<" "<<a[i].getClass()<<" "<<a[i].getCollege()<<" "<<a[i].getMajor()<<endl;
      }
      cout<<"文件导出成功";
      outfile.close();
      }
}
void read(Student a[],int n){
   char ch;
   int i=0;
      ifstream infile("student.dat",ios::in);
      if(!infile){
         cout<<"open student.dat error!";
         exit(1);
      }
      else{
      while(infile.get(ch)){
         cout<<ch;
      }
      cout<<"文件导入成功"<<endl;
      infile.close();
      }
}
void Cin(Student a[],int n){
      for(int i=0;i<n;i++)
      a[i].Cin();
}
void Add(Student a[]){
      x1++;
      a[x1-1].add();
      cout<<"添加完成"<<endl;
}
void Search(Student a[],int n){
    int m,i,p=0,q=0,r=0;
      cout<<"请选择序号1.按学号2.按班级3.按专业";
      cin>>m;
      if(m==1){
      string f;
      cin>>f;
      for(i=0;i<n;i++){
         if(a[i].getNum()==f){
         cout<<"找到学生信息:";
         a[i].Cout();
         r=1;
         break;
         }
      }
      if(r==0)
      cout<<"未找到该学生的信息"<<endl;
      }
      if(m==2){
         string c;
         cin>>c;
         for(i=0;i<n;i++){
         if(a[i].getClass()==c){
         cout<<"找到学生信息:";
         a[i].Cout();
         p=1;
         }
      }
      if(p==0)
      cout<<"未找到该学生的信息"<<endl;
      }
      if(m==3){
         string major;
         cin>>major;
         for(i=0;i<n;i++){
         if(a[i].getMajor()==major){
         cout<<"找到学生信息:";
         a[i].Cout();
         q=1;
         }
      }
      if(q==0)
      cout<<"未找到该学生的信息"<<endl;
      }
}
void Fix(Student a[],int n){
   int i;
   string e;
      cout<<"请输入学生学号：";
      cin>>e;
      i=GetName(e,n,a);
      if(i==-1)
      cout<<"未找到该学生的信息"<<endl;
      else{
      a[i].Fix();
      cout<<"修改成功"<<endl;
      }
}
void Remove(Student a[],int n){
    cout<<"请输入学生学号：";
      string s;
      cin>>s;
      if(GetName(s,n,a)!=-1){
      for(int i=GetName(s,n,a);i<n-1;i++){
      a[i]=a[i+1];
      }
      x1--;
      cout<<"删除成功";
      }
      else
      cout<<"未找到学生信息"<<endl;
}
void Print(Student a[],int n){
   for(int i=0;i<x1;i++)
      a[i].Cout();
}
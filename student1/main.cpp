# include <iostream>
# include "Student.h"
# include <fstream>
#include<algorithm>
using namespace std;
int GetName(int m,int n,Student a[]);
void write(Student a[],int n);
void read(Student a[],int n);
void Cin(Student a[],int n);
void Print(Student a[],int n);
void Add(Student a[],int n);
void Search(Student a[],int n);
void Sum(Student a[],int n);
bool comp(Student a,Student b);
int x1=0,n;
int main(){
   Student a[300];
   int b=0;
   cout<<"请选择下面的一个项目："<<endl;
   for(;b!=9;){
   cout<<"1 创建"<<endl<<"2 添加"<<endl<<"3 汇总"<<endl<<"4 排序"<<endl<<"5 查询"<<endl<<"6 显示"<<endl<<"7 文件导入"<<endl<<"8 文件导出"<<endl<<"9 退出"<<endl;
   cout<<"请选择:";
   cin>>b;
   if(b==9)break;
   switch(b){
      case 1:cout<<"请输入学生人数：";cin>>n;x1=n;Cin(a,n);break;
      case 2:Add(a,x1);break;
      case 3:Sum(a,x1);break;
      case 4:sort(a,a+x1,comp);cout<<"排序完毕";;break;
      case 5:Search(a,x1);break;
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
int GetName(int m,int n,Student a[]){
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
         outfile<<a[i].getNum()<<" "<<a[i].getNam()<<" "<<a[i].getMath()<<" "<<a[i].getYu()<<" "<<a[i].getEng()<<" "<<a[i].getPhy()<<endl;
      }
      cout<<"文件导出成功"<<endl;
      }
      outfile.close();
}
void read(Student a[],int n){
   char ch;
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
      }
}
void Cin(Student a[],int n){
      int s1=0;
      for(int i=0;i<n;i++){
      a[i].Cin1();
      if(s1==a[i].getNum()){
         cout<<"请重新输入学号：";
         a[i].Cin1();
      }
      a[i].Cin();
      s1=a[i].getNum();
      }
}
void Add(Student a[],int n){
      cout<<"请输入添加到第几行：";
      int s;
      cin>>s;
      x1++;
      int x=x1-1;
      cout<<"请输入要添加的学生信息：";
      if(s<=x){
      for(int i=x1-2;i>s-2;i--){
         a[i+1]=a[i];
      }
      a[s-1].add();
      }
      else{
      a[x1-1].add();
      }
      cout<<"添加完成"<<endl;
}
void Search(Student a[],int n){
      int i;
      int f;
      cin>>f;
      i=GetName(f,n,a);
      if(i==-1)
      cout<<"未找到该学生的信息"<<endl;
      else{
      cout<<"找到学生信息：";
      a[i].Cout();
      }
}
void Print(Student a[],int n){
   for(int i=0;i<n;i++)
      a[i].Cout();
}
void Sum(Student a[],int n){
   for(int i=0;i<n;i++){
      a[i].Sum();
      a[i].Average();
   }
   cout<<"汇总完成";
}
bool comp(Student a,Student b){
   return a.sum>b.sum;
} 
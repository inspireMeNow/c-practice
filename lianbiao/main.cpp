# include <iostream>
# include "link.h"
# include <fstream>
#include<algorithm>
using namespace std;
int main(){
   link <int>a;
   for(;;){
   cout<<"请输入序号：1、创建"<<endl<<"2、插入"<<endl<<"3、删除"<<endl<<"4、遍历输出"<<endl<<"5、查询"<<endl<<"6、退出";
   int n;
   cin>>n;
   if(n==6){
      break;
   }
   switch(n){
      case 1:a.phead=a.create();break;
      case 2:
      cout<<"请输入要插入的整数：";
      int m,n;
      cin>>n;
      cout<<"请输入插入位置：";
      cin>>m;
      a.phead=a.insert(m-2,n,a.phead);break;
      case 3:
      cout<<"请输入要删除的整数:";
      cin>>n;
      a.phead=a.deleted(n,a.phead);break;
      case 4:a.Print(a.phead);break;
      case 5:a.Search(a.phead);break;
      default:break;
   }
   }
   system("pause");
   return 0;
}
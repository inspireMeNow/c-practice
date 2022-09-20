# include "Child.h"
using namespace std;
int main(){
   int n;
   int startId;
   int m;
   char ch;
   for(;;){
   cout<<"请输入人数：";
   cin>>n;
   cout<<"请输入报的数字：";
   cin>>m;
   cout<<"请输入从第几个人开始：";
   cin>>startId;
   Child a;
   if(n>m&&startId<n){
   a.ShunXu(m,n,startId);
   cout<<"是否继续输入";
   }
   else
   cout<<"输入错误，是否继续输入";
   cin>>ch;
   if(ch=='n'||ch=='N')
   break;
   }
   system("pause");
   return 0;
}
# include <iostream>
# include <cstring>
# include <fstream>
using namespace std;
class Child{
   public:
   int num;
   Child *next;
   Child *create(int n,Child *phead){
    phead=new Child;
    Child *p,*q;
    phead->num=1;
    q=phead;
    for(int i=2;i<=n;i++){
       p=new Child;
       p->num=i;
       q->next=p;
       q=p;
    }
    q->next=phead;
    return phead;
   }
   void ShunXu(int m,int n,int startid){
      Child *phead,*p,*q;
      phead=create(n,phead);
      for(int i=1;i<=n;i++){
         p=phead;
         int j=startid;
         for(int j=1;j<m-1;j++)
         p=p->next;
         q=p->next;
         cout<<q->num<<" ";
         p->next=q->next;
         delete q;
         phead=p->next;
      }
      cout<<endl;
   }
};
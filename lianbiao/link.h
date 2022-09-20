# include <iostream>
# include <cstring>
# include <assert.h>
using namespace std;
template <class T>
class link{
   public:
   T data;
   link *next;
   link *phead;
   link *create(){
      link *ps=NULL;
      link *pend=NULL;
      link *phead=NULL;
      ps=new link;
      cin>>ps->data;
      while(ps->data!=0){
         if(phead==NULL)
         phead=ps;
         else
         pend->next=ps;
         pend=ps;
         ps=new link;
         cin>>ps->data;
      }
      pend->next=NULL;
      delete ps;
      cout<<"整数读入成功"<<endl;
      return phead;
   }
   void Search(link *phead){
      cout<<"请输入你要查询的整数：";
      int i=0,j=0;
      T n;
      cin>>n;
      link *node=phead;
      while(node){
      i++;
      if(node->data==n){
         cout<<"该整数在第"<<i<<"个节点上"<<endl;
         j++;
      }
      node=node->next;
      }
      if(j==0)
      cout<<"找不到数字"<<n<<endl;
   }
   void Print(link *phead){
      cout<<"所有整数分别为：";
      link *node=phead;
      while(node){
         cout<<node->data;
         if(node->next)
            cout<<" ";
         node=node->next;
      }
      cout<<endl;
   }
   link *insert(int m,int n,link *phead){
      link *p1=new link;
      link *curhead;
      p1->data=n;
      if(phead==NULL){
         phead=p1;
         p1->next=NULL;
         return phead;
      }
      curhead=phead;
      for(int i=0;i<m&&nullptr!=curhead;i++,curhead=curhead->next);
         assert(nullptr!=curhead);
         link *q=new link;
         q->data=n;
         q->next=curhead->next;
         curhead->next=q;
      cout<<"整数插入成功"<<endl;
      return phead;
   }
   link *deleted(T n,link *phead){
      link *danghead=phead;
      link *qianhead=NULL;
      while(n!=danghead->data&&danghead->next!=NULL){
         qianhead=danghead;
         danghead=qianhead->next;
      }
      if(n==danghead->data){
      if(danghead==phead)
      phead=danghead->next;
      else
      qianhead->next=danghead->next;
      cout<<"成功删除节点"<<n<<endl;
      }
      else
      cout<<"未找到数据"<<n<<endl;
      delete danghead;
      return phead;
   }
};
# include <iostream>
# include <cstring>
# include <fstream>
using namespace std;
class Contact{
   public:
      Contact *next;
      Contact *phead;
   Contact *create(int n){
      Contact *ps=NULL;
      Contact *pend=NULL;
      Contact *phead=NULL;
      ps=new Contact;
      ps->next=NULL;
      pend=ps;
      for(int i=0;i<n;i++){
         phead=new Contact;
         phead->Cin();
         phead->next=pend->next;
         pend->next=phead;
         pend=phead;
      }
      cout<<"联系人创建成功"<<endl;
      return ps;
   }
   void Cin(){
      cin>>num>>name>>sex>>age>>phone>>telephone;
   }
   void Cout(){
      cout<<num<<" "<<name<<" "<<sex<<" "<<age<<" "<<phone<<" "<<telephone; 
   }
   void Search(Contact *phead){
      cout<<"请输入你要查询的联系人的姓名或手机号：";
      int i=0,j=0;
      string n;
      cin>>n;
      Contact *node=phead;
      while(node){
      i++;
      if(node->name==n||node->phone==n){
         cout<<"找到该联系人的信息：";
         node->Cout();
         j++;
      }
      node=node->next;
      }
      if(j==0)
      cout<<"找不到该联系人的信息"<<n<<endl;
   }
   void Correct(Contact *phead){
      cout<<"请输入你要修改的联系人的姓名：";
      int i=0,j=0;
      string n;
      cin>>n;
      Contact *node=phead;
      while(node){
      i++;
      if(node->name==n){
         cout<<"请修改电话信息：";
         cin>>node->phone>>node->telephone;
         j++;
      }
      node=node->next;
      }
      if(j==0)
      cout<<"找不到该联系人的信息"<<n<<endl;
   }
   Contact *insert(Contact *phead){
      Contact *p1=new Contact;
      cout<<"请输入要添加的联系人信息：";
      p1->Cin();
      p1->next=phead->next;
      phead->next=p1;
      return phead;
   }
   void Print(Contact *phead){
      cout<<"所有联系人分别为：";
      Contact *node=phead;
      while(node){
         node->Cout();
         if(node->next)
            cout<<endl;
         node=node->next;
      }
      cout<<endl;
   }
   Contact *deleted(Contact *phead){
      cout<<"支持删除的联系人信息：1、姓名2、编号3、宅电4、手机电话"<<endl;
      string b;
      cout<<"请输入要删除的联系人的信息：";
      cin>>b;
      Contact *danghead=phead;
      Contact *qianhead=NULL;
      while(b!=danghead->num&&b!=danghead->name&&b!=danghead->phone&&b!=danghead->telephone&&danghead->next!=NULL){
         qianhead=danghead;
         danghead=qianhead->next;
      }
      if(b==danghead->num||b==danghead->name||b==danghead->phone||b==danghead->telephone){
      if(danghead==phead)
      phead=danghead->next;
      else
      qianhead->next=danghead->next;
      cout<<"成功删除节点"<<b<<endl;
      }
      else
      cout<<"未找到数据"<<b<<endl;
      delete danghead;
      return phead;
   }
   Contact *Daoru(int n){
      char ch;
      Contact *ps=NULL;
      Contact *pend=NULL;
      Contact *phead=NULL;
     ifstream infile("Contact.dat",ios::in);
     if(!infile){
        cout<<"打开文件失败！"<<endl;
        exit(0);
     }
     while(infile.get(ch)){
        ps=new Contact;
        ps->next=NULL;
        pend=ps;
        for(int i=0;i<n;i++){
         phead=new Contact;
         infile>>phead->num>>phead->name>>phead->sex>>phead->age>>phead->phone>>phead->telephone;
         phead->next=pend->next;
         pend->next=phead;
         pend=phead;
      }
     }
     cout<<"文件导入成功"<<endl;
     infile.close();
     return ps;
   }
   void Daochu(){
        ofstream outfile("Contact.dat",ios::out);
        if(!outfile){
           cout<<"打开文件失败";
           exit(0);
        }
         Contact *node=phead;
      while(node){
         outfile<<node->num<<" "<<node->name<<" "<<node->sex<<" "<<node->age<<" "<<node->phone<<" "<<node->telephone;
         if(node->next)
            outfile<<endl;
         node=node->next;
      }
      outfile<<endl;
      outfile.close();
      cout<<"文件导出成功"<<endl;
   }
   private:
   string name;
   char sex;
   string age;
   string phone;
   string telephone;
   string num;
};
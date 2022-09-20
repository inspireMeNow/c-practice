# include "Contact.h"
using namespace std;
int main(){
   Contact a;
   for(;;){
   cout<<"请选择下面的一个项目：1、创建"<<endl<<"2、添加"<<endl<<"3、查询"<<endl<<"4、修改"<<endl<<"5、删除"<<endl<<"6、显示"<<endl<<"7、文件导入"<<endl<<"8、文件导出"<<endl<<"9、退出"<<endl<<"请选择：";
   int b;
   cin>>b;
   if(b==9)break;
   switch(b){
      case 1:
      cout<<"请输入要添加的联系人人数：";
      int n;
      cin>>n;
      a.phead=a.create(n);break;
      case 2:a.phead=a.insert(a.phead);break;
      case 3:a.Search(a.phead);break;
      case 4:a.Correct(a.phead);break;
      case 5:a.phead=a.deleted(a.phead);break;
      case 6:a.Print(a.phead);break;
      case 7:a.phead=a.Daoru(n);break;
      case 8:a.Daochu();break;
      default:break;
   }
   }
   system("pause");
   return 0;
}
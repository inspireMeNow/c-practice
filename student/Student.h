# include <iostream>
# include <cstring>
using namespace std;
class Student{
   private:
   string num;
   string name;
   string sex;
   string age;
   string classes;
   string college;
   string major;
   public:
   Student(){}
   Student(string a,string b,string c,string d,string e,string f,string g):num(a),name(b),sex(c),age(d),classes(e),college(f),major(g){}
   void Cin(){
   cin>>num>>name>>sex>>age>>classes>>college>>major;
   }
   string getNum(){
      return num;
   }
   string getClass(){
      return classes;
   }
   string getMajor(){
      return major;
   }
   string getNam(){
      return name;
   }
   string getCollege(){
      return college;
   }
   string getSex(){
      return sex;
   }
   string getAge(){
      return age;
   }
   void Fix(){
      cout<<"请输入要修改的信息：";
      cin>>name>>sex>>age>>classes>>college>>major;
   }
   void Cout(){
      cout<<num<<" "<<name<<" "<<sex<<" "<<age<<" "<<classes<<" "<<college<<" "<<major<<endl;
   }
   void add(){
      cout<<"请输入要添加的学生信息：";
      Cin();
   }
};
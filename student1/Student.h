# include <iostream>
# include <cstring>
using namespace std;
class Student{
   private:
   int num;
   string name;
   int math;
   int chinese;
   int english;
   int physics;
   public:
   int sum;
   double average;
   Student(){}
   Student(int n,string nam,int m,int ch,int en,int p):num(n),name(nam),math(m),chinese(ch),english(en),physics(p){}
   void Cin(){
   cout<<"请输入成绩：";
   cin>>math;
   for(;math<0||math>100;){
      cout<<"请重新输入：";
      cin>>math;
   }
   cin>>chinese;
   for(;chinese<0||chinese>100;){
      cout<<"请重新输入：";
      cin>>chinese;
   }
   cin>>english;
   for(;english<0||english>100;){
      cout<<"请重新输入：";
      cin>>english;
   }
   cin>>physics;
   for(;physics<0||physics>100;){
      cout<<"请重新输入：";
      cin>>physics;
   }
   }
   void Cin1(){
   cout<<"请输入姓名和学号：";
   cin>>num>>name;
   }
   int getNum(){
      return num;
   }
   string getNam(){
      return name;
   }
   int getYu(){
      return chinese;
   }
   int getMath(){
      return math;
   }
   int getEng(){
      return english;
   }
   int getPhy(){
      return physics;
   }
   double getAver(){
      return average;
   }
   int getSum(){
      return sum;
   }
   void Cout(){
      cout<<num<<" "<<name<<" "<<" "<<math<<" "<<chinese<<" "<<english<<" "<<physics<<" "<<sum<<" "<<average<<endl;
   }
   void add(){
      Cin();
   }
void Sum(){
   sum=chinese+math+english+physics;
}
void Average(){
   average=(double)sum/4;
}
};
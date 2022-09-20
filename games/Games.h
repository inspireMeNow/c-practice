# include <iostream>
# include <cmath>
# include <ctime>
# include <stdlib.h>
# define random(x)(rand()%x)
using namespace std;
class Games{
    private:
    int n;
    int time=0;
    public:
    Games(int t):time(t){}
    void Born(){
        n=random(10000);
  }
  bool JudgeTime(int t){
       if(t<=time)
       return 0;
       else
       return 1;
  }
   void Judge(int guess){
       if(guess<n)
       cout<<"ตอมห"<<endl;
       else
       cout<<"ธ฿มห"<<endl;
   }
   int getN(){
       return n;
   }
};
# include "Games.h"
using namespace std;
int main(){
    int time1;
    cout<<"请输入游戏时间：";
    cin>>time1;
    Games a(time1);
    for(;;){
    time_t i,k;
    cout<<"请猜数：";
    int count;
    a.Born();
    k=time(NULL);
    cin>>count;
    while(a.getN()!=count){
    a.Judge(count);
    cin>>count;
    i=time(NULL);
    if(a.JudgeTime((int)i-k)){
    cout<<"很遗憾，未能在规定时间内猜出正确数字，该数字为"<<a.getN()<<endl;
    break;
    }
    }
    if(a.getN()==count){
    cout<<"恭喜！正确猜出数字"<<a.getN()<<endl;
    }
    cout<<"是否继续游戏:y/n"<<endl;
    char c;
    cin>>c;
    if(c=='n')
    break;
    }
    system("pause");
    return 0;
}
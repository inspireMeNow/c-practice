# include "Games.h"
using namespace std;
int main(){
    int a,b;
    Games c;
    for(;;){
    cout<<"请输入位置:(坐标)";
    c.Cin();
    c.Judge();
    c.Disp();
    if(c.Judge2()!=0||c.Judge1()==1)
    break;
    } 
    cout<<"游戏结束，";
    if(c.Judge2()==1)
    cout<<"计算机胜出！"<<endl;
    else if(c.Judge2()==2)
    cout<<"玩家胜出！"<<endl;
    else if(c.Judge2()==0&&c.Judge1()==1)
    cout<<"平手！"<<endl;
    system("pause");
    return 0;
}
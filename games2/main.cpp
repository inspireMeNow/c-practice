# include "Games.h"
using namespace std;
int main(){
    Games b;
    char c;
    int i;
    for(i=1;;i++){
        b.Random();
        cout<<"请选择：1、石头2、剪刀3、布"<<endl;
        int a;
        cin>>a;
    switch(b.Judge(a)){
        case 1:
        cout<<"赢了"<<endl;break;
        case 0:
        cout<<"输了"<<endl;break;
        case 2:
        cout<<"平手"<<endl;break;
        default:break;
    }
    b.Analyze(a);
    cout<<"玩的次数："<<i<<endl;
    cout<<"是否继续游戏(y/n)";
    cin>>c;
    if(c=='n')
    break;
    }
    system("pause");
    return 0;
}
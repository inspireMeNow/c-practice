# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdlib.h>
using namespace std;
class Games{
    private:
    int n;
    int a[3][3]={0,0,0,0,0,0,0,0,0};
    int c,b;
    public:
    void Cin(){
        int m,n;
        for(;!Judge1();){
        cin>>m>>n;
        if(a[m-1][n-1]==1||(m>3||m<1||n>3||n<1)||a[m-1][n-1]==2){
            cout<<"请重新输入：";
        }
        else{
        a[m-1][n-1]=2;
        break;
        }
        }
    }
    void Disp(){
       cout<<"-----"<<endl;
       for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
               if(a[i][j]==2)
               cout<<"O ";  
               else if(a[i][j]==1)
               cout<<"X ";
               else
               cout<<"* ";
           }
           cout<<endl;
       }
       cout<<"-----"<<endl;
    }
    int JiFen(int i,int j){
          int sum=0;
          if(a[i][0]==a[i][1]||a[i][1]==a[i][2]||a[0][j]==a[1][j]||a[1][j]==a[2][j]||a[0][0]){
             if(a[i][1]==1||a[1][j]==1)sum=sum+50;
             else if(a[i][1]==2||a[1][j]==2)sum=sum+25;
             else sum=sum+4;
          }
          else if((a[i][0]!=a[i][1]&&a[i][1]!=a[i][2])||(a[0][j]!=a[1][j]&&a[1][j]!=a[2][j])){
            if(a[i][0]==1||a[i][1]==1||a[i][2]==1||a[0][j]==1||a[1][j]==1||a[2][j]==1)
            sum=sum+10;
            else if(a[i][0]==2||a[i][1]==2||a[i][2]==2||a[0][j]==2||a[1][j]==2||a[2][j]==2)
            sum=sum+8;
            else
            sum=sum+0;
          }
          else if((i==j||i==2-j)&&(a[0][0]==a[1][1]||a[1][1]==a[2][2]||a[0][2]==a[1][1]||a[1][1]==a[2][0])){
             if(a[1][1]==1)sum=sum+50;
             else if(a[1][1]==2)sum=sum+25;
             else sum=sum+4;
          }
          else if((i==j||i==2-j)&&((a[0][0]!=a[1][1]&&a[1][1]!=a[2][2])||(a[0][2]!=a[1][1]&&a[1][1]!=a[2][0]))){
            if(a[0][0]==1||a[2][2]==1||a[1][1]==1||a[0][2]==1||a[1][1]==1||a[2][0]==1)
            sum=sum+10;
            else if(a[0][0]==2||a[2][2]==2||a[1][1]==2||a[0][2]==2||a[1][1]==2||a[2][0]==2)
            sum=sum+8;
            else
            sum=sum+0;
          }
          else
             sum=sum+0;
          return sum;
      }
    void Judge(){
        int i,j,sum[9]={0,0,0,0,0,0,0,0,0},k=0,p[9],q[9];
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(a[i][j]==0){
                    sum[k]=JiFen(i,j);
                    p[k]=i;
                    q[k]=j;
                    k++;
                }
            }
        }
        if(k!=0){
        int max=0;
        for(int m=0;m<9;m++){
        if(max<sum[m])max=m;
        }
        a[p[max]][q[max]]=1;
    }
    }
    bool Judge1(){
        int i,j,flag=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(a[i][j]==0){
                    flag=1;
                }
            }
        }
        if(flag==0)return 1;
        else return 0;
    }
    int Judge2(){
                if(a[0][0]==a[0][1]&&a[0][0]==a[0][2]){
                  if(a[0][0]==1)return 1;
                  else if(a[0][0]==2) return 2;
                  else return 0;
                }
                else if(a[1][0]==a[1][1]&&a[1][0]==a[1][2]){
                  if(a[1][0]==1)return 1;
                  else if(a[1][0]==2) return 2;
                  else return 0;
                }
                else if(a[2][0]==a[2][1]&&a[2][0]==a[2][2]){
                  if(a[2][0]==1)return 1;
                  else if(a[2][0]==2) return 2;
                  else return 0;
                }
                else if(a[0][0]==a[1][0]&&a[0][0]==a[2][0]){
                  if(a[0][0]==1)return 1;
                  else if(a[0][0]==2)return 2;
                  else return 0;
                }
                else if(a[0][1]==a[1][1]&&a[0][1]==a[2][1]){
                  if(a[0][1]==1)return 1;
                  else if(a[0][1]==2)return 2;
                  else return 0;
                }
                else if(a[0][2]==a[1][2]&&a[0][2]==a[2][2]){
                  if(a[0][2]==1)return 1;
                  else if(a[0][2]==2)return 2;
                  else return 0;
                }
                else if(a[0][0]==a[1][1]&&a[0][0]==a[2][2]){
                  if(a[0][0]==1)return 1;
                  else if(a[0][0]==2)return 2;
                  else return 0;
                }
                else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]){
                  if(a[0][2]==1)return 1;
                  else if(a[0][2]==2)return 2;
                  else return 0;
                }
                else
                  return 0;
    }
};
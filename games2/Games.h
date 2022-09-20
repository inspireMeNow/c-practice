# include <iostream>
# include <cmath>
# include <ctime>
# include <stdlib.h>
# include <algorithm>
using namespace std;
class Games{
 private:
 int n;
 int r;
 int a[1000],i=0;
 public:
 void Random(){
     r=rand()%3+1;
 }
 int getR(){
    return r;
 }
 int Judge(int s){
    if(r==1&&s==2)
       return 0;
    if(r==1&&s==1)
       return 2;
    if(r==1&&s==3)
       return 1;
    if(r==2&&s==2)
       return 2;
    if(r==2&&s==1)
       return 1;
    if(r==2&&s==3)
       return 0;
    if(r==3&&s==2)
       return 1;
    if(r==3&&s==1)
       return 0;
    if(r==3&&s==3)
       return 2;
 }
 void Analyze(int s){
    i++;
    a[i]=s;
    int b[3]={0,0,0},max=0,k;
    for(int k=0;k<i;k++){
       if(a[i]==1)
         b[0]++;
       if(a[i]==2)
         b[1]++;
       if(a[i]==3)
         b[2]++;
    }
    max=a[0];
    for(k=0;k<3;k++){
     if(b[k]>max)
      max=b[k];
    }
    for(k=0;k<3;k++){
       if(max==b[k])
       break;
    }
    if(k==0){
      r=3;
    }
    if(k==1){
      r=1;
    }
    if(k==3){
      r=2;
    }
 }
};
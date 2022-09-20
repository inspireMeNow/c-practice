# include "Line.h"
using namespace std;
void DianJu();
void ZhiJu();
void PingJu();
void Danwei();
void Judge();
bool JudgeLine(Line s,Plane s2);
int main(){
    for(;;){
    cout<<"请输入序号："<<endl<<"1、计算距离"<<endl<<"2、计算单位向量"<<endl<<"3、判断点和线的关系"<<endl<<"4、退出"<<endl;
    int a;
    cin>>a;
    if(a==1){
    cout<<"1.计算两点距离："<<endl<<"2.计算点与直线之间的距离"<<endl<<"3.计算点和面之间的距离"<<endl;
    cout<<"请输入序号:";
    int n;
    cin>>n;
    switch(n){
        case 1:DianJu();break;
        case 2:ZhiJu();break;
        case 3:PingJu();break;
        default:break;
    }
    }
    else if(a==2){
        Danwei();
    }
    else if(a==3){
        Judge();
    }
    else
    break;
    }
    system("pause");
    return 0;
}
void DianJu(){
    double a,b;
    double c,d;
    double e,f;
    cout<<"请分别输入两点的坐标：";
        cin>>a>>b>>c>>d>>e>>f;
        Point g(a,b,c),h(d,e,f);
        cout<<g.getS(h)<<endl;
}
void ZhiJu(){
        double a,b,c;
        cout<<"请输入点的坐标："<<endl;
        cin>>a>>b>>c;
        Point s1(a,b,c);
        Line s2;
        cout<<"点到直线的距离为"<<s2.Distance(s1)<<endl;
}
void PingJu(){
       cout<<"请输入点的坐标：";
       double e,f,g;
       cin>>e>>f>>g;
       Point q(e,f,g);
       cout<<"请输入平面方程：";
       double a,b,c,d;
       cin>>a>>b>>c>>d;
       Plane p(a,b,c,d);
       cout<<"点到平面的距离为"<<p.S(q)<<endl;
}
void Danwei(){
    cout<<"请输入序号：1、计算空间直线的单位方向向量"<<endl<<"2、计算空间平面的单位法向量"<<endl;
        int w;
        cin>>w;
        if(w==1){
            Line w1;
            w1=w1.Create();
            w1=w1.Danwei();
            cout<<"直线的单位方向向量为:("<<w1.getA()<<","<<w1.getB()<<","<<w1.getC()<<")"<<endl;
        }
        else{
           double n,b,c,d;
           cout<<"请输入平面方程：";
           cin>>n>>b>>c>>d;
           Plane s1(n,b,c,d);
           s1=s1.Danwei();
           cout<<"平面的单位法向量为:("<<s1.getA()<<","<<s1.getB()<<","<<s1.getC()<<")"<<endl;
        }
}
void Judge(){
    cout<<"请输入序号："<<endl<<"1、点和线的关系"<<endl<<"2、线和线的关系"<<endl<<"3、点和平面的关系"<<endl<<"4、线和平面的关系"<<endl<<"5、平面和平面的关系"<<endl;
    int n;
    cin>>n;
    if(n==1){
        Line a;
        cout<<"请输入点的坐标：";
        int s1,s2,s3;
        cin>>s1>>s2>>s3;
        Point b(s1,s2,s3);
        if(fabs(a.Distance(b))<1e-6)
        cout<<"点在直线上"<<endl;
        else
        cout<<"点在直线外"<<endl;
    }
    else if(n==2){
        Line t1,t2;
        t1=t1.Create();
        t2=t2.Create();
        if(t1.Judge(t2)&&t1.getD()!=t2.getD())
          cout<<"直线和直线平行"<<endl;
        else if(t1.Judge(t2)&&t1.getD()==t2.getD())
          cout<<"直线和直线重合";
        else
          cout<<"直线和直线相交"<<endl;
    }
    else if(n==3){
       cout<<"请输入点的坐标：";
       double e,f,g;
       cin>>e>>f>>g;
       Point q(e,f,g);
       cout<<"请输入平面方程：";
       double a,b,c,d;
       cin>>a>>b>>c>>d;
       Plane p(a,b,c,d);
       if(p.S(q)==0)
       cout<<"点在平面上";
       else
       cout<<"点在平面外";
    }
    else if(n==4){
       Line s1;
       s1=s1.Create();
       double a,b,c,d;
       cout<<"请输入平面方程：(方程为ax+by+cz+d=0，输入a,b,c,d的值)";
       cin>>a>>b>>c>>d;
       Plane s2(a,b,c,d);
       if(JudgeLine(s1,s2))
       cout<<"直线与平面垂直"<<endl;
       else if(s1.getA()*s2.getA()+s1.getB()*s2.getB()+s1.getC()*s2.getC()==0)
       cout<<"直线与平面平行"<<endl;
       else
       cout<<"直线和平面相交"<<endl;
    }
    else if(n==5){
       double a,b,c,d,e,f,g,h;
       cout<<"请输入两平面方程：(方程为ax+by+cz+d=0，输入a,b,c,d的值)";
       cin>>a>>b>>c>>d>>e>>f>>g>>h;
       Plane s2(a,b,c,d),s3(e,f,g,h);
       double q=s2.getD()>s3.getD()?s2.getD():s3.getD();
       if(s3.Judge(s2)&&s2.getD()!=s3.getD())
           cout<<"两平面平行"<<endl;
       else if(s3.Judge(s2)&&q/s2.getD()==(int)(q/s2.getD())&&q/s3.getC()==(int)(q/s3.getC()))
           cout<<"两平面重合"<<endl;
       else
           cout<<"两平面相交"<<endl;
    }
    else
       return;
}
bool JudgeLine(Line s,Plane s2){
      double q1=s.getA()>s2.getA()?s.getA():s2.getA();
      double q2=s.getB()>s2.getB()?s.getB():s2.getB();
      double q3=s.getC()>s2.getC()?s.getC():s2.getC();
      if(q1/s2.getA()==(int)(q1/s2.getA())&&q1/s.getA()==(int)(q1/s.getA()))
        if(q2/s2.getB()==(int)(q2/s2.getB())&&q2/s.getB()==(int)(q2/s.getB()))
          if(q3/s2.getC()==(int)(q3/s2.getC())&&q3/s.getC()==(int)(q3/s.getC()))
             return 1;
          else
             return 0;
        else
           return 0;
      else
        return 0;
   }
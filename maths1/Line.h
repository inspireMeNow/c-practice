# include "Point.h"
# include "Plane.h"
class Line{
   public:
   Line(){}
   Line(double m,double n,double p):a(m),b(n),c(p){
      d=0;
   }
   Line(double m,double n,double p,double q):a(m),b(n),c(p),d(q){}
   double Distance(Point a){
        cout<<"直线的创建方式：1.两点确定 2.相交平面确定";
        int m;
        cin>>m;
        if(m==1){
            double x1,y1,z1;
            double x2,y2,z2;
            cout<<"请输入两点坐标：";
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            Point b(x1,y1,z1),d(x2,y2,z2);
            Point c=b-a;
            b=b-d;
            return fabs(b.getCheng(c))/b.getS1();
        }
        if(m==2){
           double n,b,c,d,e,f,g,h;
           cout<<"请输入两相交平面的方程：(方程为ax+by+cz+d=0，输入a,b,c,d的值)";
           cin>>n>>b>>c>>d>>e>>f>>g>>h;
           Plane s1(n,b,c,d),s2(e,f,g,h);
           s1=s1-s2;
           double z1=s1.Get(1,1),z2=s1.Get(1,2);
           Point p(1,1,z1),w(1,2,z2);
           Point q=p-a;
           p=p-w;
           return fabs(p.getCheng(q))/p.getS1();
        }
        else
           return 0;
   }
   Line Create(){
       cout<<"直线的创建方式：1.两点确定 2.相交平面确定";
        int m;
        cin>>m;
        if(m==1){
            double x1,y1,z1;
            double x2,y2,z2;
            cout<<"请输入两点坐标：";
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            Point b(x1,y1,z1),d(x2,y2,z2);
            b=b-d;
            return Line(b.getX(),b.getY(),b.getZ()); 
        }
        else{
           double n,b,c,d,e,f,g,h;
           cout<<"请输入两相交平面的方程：(方程为ax+by+cz+d=0，输入a,b,c,d的值)";
           cin>>n>>b>>c>>d>>e>>f>>g>>h;
           Plane s1(n,b,c,d),s2(e,f,g,h);
           s1=s1-s2;
           return Line(s1.getA(),s2.getB(),s2.getC(),s2.getD()); 
        }
   }
   Line Danwei(){
    double s=sqrt(a*a+b*b+c*c);
    return Line(a/s,b/s,c/s);
   }
   bool Judge(Line s){
      double q1=s.getA()>a?s.getA():a;
      double q2=s.getB()>b?s.getB():b;
      double q3=s.getC()>c?s.getC():c;
      if(q1/a==(int)(q1/a)&&q1/s.getA()==(int)(q1/s.getA()))
        if(q2/b==(int)(q2/b)&&q2/s.getB()==(int)(q2/s.getB()))
          if(q3/c==(int)(q3/c)&&q3/s.getC()==(int)(q3/s.getC()))
             return 1;
          else
             return 0;
        else
           return 0;
      else
        return 0;
   }
   double getA(){
      return a;
   }
   double getB(){
      return b;
   }
   double getC(){
      return c;
   }
   double getD(){
      return d;
   }
   private:
        double a;
        double b;
        double c;
        double d;
};
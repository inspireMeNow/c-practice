# include <cmath>
class Plane{
private:
double a,b,c,d,s;
public:
Plane(){}
Plane(double s,double t,double w,double y):a(s),b(t),c(w),d(y){}
Plane Danwei(){
    s=sqrt(a*a+b*b+c*c);
    return Plane(a/s,b/s,c/s,d);
}
Plane operator-(Plane &m){
    return Plane(a-m.a,b-m.b,c-m.c,d-m.d);
}
double getD(){
    return d;
}
double getC(){
    return c;
}
double getB(){
    return b;
}
double getA(){
    return a;
}
double Get(double m,double n){
    return (-d-a*m-b*n)/c;
}
double S(Point m1){
    Point m2(1,1,Get(1,1));
    Point m3(a,b,c);
    m1=m1-m2;
    return fabs(m3.getCheng(m1))/m3.getS1();
}
   bool Judge(Plane s){
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
};
# include <iostream>
# include <cmath>
using namespace std;
class Point{
   double x;
   double y;
   double z;
   public:
   Point(double a,double b,double c):x(a),y(b),z(c){
   }
   double getX(){
       return x;
   }
   double getY(){
       return y;
   }
   double getZ(){
       return z;
   }
   double getCheng(Point a){
   return a.getX()*x+a.getY()*y+a.getZ()*z;
   }
   double getCha(Point a){
   return sqrt(pow(a.getZ()*y-a.getX()*z,2)+pow(a.getX()*z-a.getZ()*x,2)+pow(a.getY()*x-a.getX()*y,2));
   }
   double getS(Point a){
       return sqrt(pow(a.x-x,2)+pow(a.y-y,2)+pow(a.z-z,2));
   }
   Point operator-(Point &a){
       return Point(x-a.getX(),y-a.getY(),z-a.getZ());
   }
   double getS1(){
       return sqrt(x*x+y*y+z*z);
   }
   Point DanWei(){
       double s=sqrt(x*x+y*y+z*z);
       return Point(x/s,y/s,z/s);
   }
};
# include <iostream>
# include <cmath>
using namespace std;
class Point{
   double x;
   double y;
   public:
   Point(){}
   Point(double a,double b):x(a),y(b){
   }
   double getS(){
       return sqrt(x*x+y*y);
   }
   Point operator-(Point a){
       return Point(x-a.x,y-a.y);
   }
};
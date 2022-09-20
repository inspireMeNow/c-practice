# include "Point.h"
class Triangle{
   public:
   bool judge1(double s1,double s2,double s3){
    if(fabs(s1-s2)<1e-6&&fabs(s2-s3)<1e-6)
    return 1;
    else
    return 0;
   }
   bool judge2(double s1,double s2,double s3){
       if(fabs(s1-s2)<1e-6||fabs(s2-s3)<1e-6||fabs(s1-s3)<1e-6)
       return 1;
       else
       return 0;
   }
   bool judge3(double s1,double s2,double s3){
       if(fabs(s1*s1+s2*s2-s3*s3)<1e-6||fabs(s1*s1+s3*s3-s2*s2)<1e-6||fabs(s3*s3+s2*s2-s1*s1)<1e-6)
       return 1;
       else
       return 0;
   }
   bool judge4(double s1,double s2,double s3){
     if(judge2(s1,s2,s3)&&judge3(s1,s2,s3))
     return 1;
     else
     return 0;
   }
   bool judge(double s1,double s2,double s3){
       if(s1+s2-s3>=1e-6&&s1+s3-s2>=1e-6&&s3+s2-s1>=1e-6)
          return 1;
       else
          return 0;
   }
};
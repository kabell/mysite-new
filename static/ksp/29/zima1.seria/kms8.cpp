#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define PI 3.14159265


double u(double x){
    return x*PI/180;}
    
    double m(double x){
           return x*x;
           }

int main(){
 
 double a,b,c,d;
 
 cin>>a>>b>>c>>d;
 
 float v,k,l,p;
 
 v=sin(a*PI/180)*sin(b*PI/180)*sin((a+b)*PI/180);
 l=sin(d*PI/180)*sin(c*PI/180)*cos((a+b)*PI/180)  ; 
 
 
 
 k=sin(a*PI/180)*sin(d*PI/180)*sin((b+c)*PI/180);
 p=sin(b*PI/180)*sin(c*PI/180)*cos((b+c)*PI/180)  ;    
    


double g,h;

g=m(sin(d(a)))+m(sin(d(b)))
 
cout<<g<<endl<<h<<endl;
 
 cin.get();
 cin.get();   
    
    
    
    
}

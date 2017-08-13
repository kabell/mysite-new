#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;




typedef struct
{ int x,y;
} point;

point p[10];	
point o[20];	/* obal */
int np, no=9;





int ccw(point a, point b, point c){
     
long ax=a.x, ay=a.y, bx=b.x, by=b.y, cx=c.x, cy=c.y;    
     
 
     
     long ux = bx-ax, uy = by-ay;
    long vx = cx-ax, vy = cy-ay;
    long res = ux*vy - uy*vx;    
     


     
     
     
     
     
  return res;   
     }

void insert(int i)
{
  /* pokým sa toèíme doprava */
  while (no>=2 && 
    ccw(o[no-2],o[no-1],p[i]) < 0)
      no--;
  /* nový bod */
  o[np++]=p[i];
}


 

void hull()
{
  int i;
  /* zaèíname */
  o[0]=p[0]; o[1]=p[1];

  /* dolný obal */
  for(i=no;i>=0;i--){
    insert(i);
    cout<<"ok"<<endl;
}
  /* obal sú body o[0..no-1] */
}


int main(){
 for(long i=0;i<4;i++)
 cin>>p[i].y>>p[i].x;
  for(long i=0;i<no;i++)
 cout<<p[i].y<<" "<<p[i].x<<endl;
 hull();
 cout<<endl;
 for(int i=0;i<=9;i++) cout<<o[i].y<<" "<<o[i].x<<endl;
 cin.get();
 cin.get();
 
 
} 
    
    
    
    
    
    
    
    
    
    



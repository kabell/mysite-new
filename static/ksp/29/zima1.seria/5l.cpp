#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;







int main(){
    
    long lama;
    cin>>lama;
    for(long p=1; p<=lama;p++){
    
    long x1,x2,y1,y2;
long a=0;
long b=0;
long k=6000, l=6000;
    bool pole[k][l];
    long s,r;

    cin>>s>>r;
    
    for(long i=0; i<r;i++)
             for(long i1=0; i1<s;i1++)
             cin>>pole[i][i1];
    
//nacitanie

  while(0==0){
                       b=0;
                     while(pole[a][b]==0 && b<s)
                     b++;
                                        if( pole[a][b]!=0 ){y1=a; break;}
    a++;
}




a=r-1;
                      b=s-1;
while(0==0){
                      b=s-1;
                     while(pole[a][b]==0  && b>=0)
                   b--;
                   if( pole[a][b]!=0 ){y2=a; break;}
    a--;
}


a=r-1;
b=s-1;
while(0==0){
                     a=r-1;
                     while(pole[a][b]==0 && a>=0)
                     a--;
                                        if( pole[a][b]!=0 ){x2=b; break;}
    b--;
}



a=0;
 b=0;
while(0==0){
                     a=0;
                     while(pole[a][b]==0 && a<=r)
                     a++;
                                        if( pole[a][b]!=0 ){x1=b; break;}
    b++;
}










//find
long err=0;
long pos0=s;
         long c=0;
for(long i=y1;i<=(y2-y1)/3+y1;i++){
c=0;
         while(pole[i][c]==0){
                              c++;
                              }
                              if(c>pos0){

                                        err=1;
                                        break;
                                        }
                                         pos0=c;
                                        }  
 pos0=0  ;                                     

                                                 for(long i=y1;i<=(y2-y1)/3+y1;i++){
c=x2;
         while(pole[i][c]==0){
                              c--;
                              }

                              if(c<pos0){

                                        err=1;
                                        break;
                                        }
                                        pos0=c;
                                        } 
                                        
                                        
                                        
pos0=y2;                                        
   for(long i=x1;i<=(x2-x1)/3+x1;i++){
c=0;
         while(pole[c][i]==0){
                              c++;
                              }
                              if(c>pos0){

                                        err=1;
                                        break;
                                        }
                                        pos0=c;
                                        }
 pos0=0;                                        
   for(long i=x1;i<=(x2-x1)/3+x1;i++){
c=y2;
         while(pole[c][i]==0){
                              c--;
                              }
                              if(c<pos0){

                                        err=1;
                                        break;
                                        }
                                        pos0=c;
                                        }                                       
  //opak                                      
pos0=s;
c=0;
for(long i=y2;i>=2*(y2-y1)/3+y1;i--){
c=0;
         while(pole[i][c]==0){
                              c++;
                              }
                              if(c>pos0){

                                        err=1;
                                        break;
                                        }
                                         pos0=c;
                                        }  
 pos0=0  ;                                     

                                                 for(long i=y2;i>=2*(y2-y1)/3+y1;i--){
c=x2;
         while(pole[i][c]==0){
                              c--;
                              }

                              if(c<pos0){

                                        err=1;
                                        break;
                                        }
                                        pos0=c;
                                        } 
                                        
                                        
                                        
pos0=y2;                                        
   for(long i=x2;i>=2*(x2-x1)/3+x1;i--){
c=0;
         while(pole[c][i]==0){
                              c++;
                              }
                              if(c>pos0){

                                        err=1;
                                        break;
                                        }
                                        pos0=c;
                                        }
 pos0=0;                                        
   for(long i=x2;i>=2*(x2-x1)/3+x1;i--){
c=y2;
         while(pole[c][i]==0){
                              c--;
                              }
                              if(c<pos0){

                                        err=1;
                                        break;
                                        }
                                        pos0=c;
                                        }                                                                           
if(err==1) cout<<"banan"<<endl;
else cout<<"pomaranc"<<endl;
}       







    
}

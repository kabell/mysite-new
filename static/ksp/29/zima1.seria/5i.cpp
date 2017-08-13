#include <iostream>



#include <stdio.h>

using namespace std;





    bool pole[2100][2100];
     long x1;
     long x2;

     long y2;
     long y_1;


long test(long y,long x){
    long f=1;
    long g=0;
    for(long i=x+1; i<=x2; i++)
    if(pole[y][i]==1){ g=1;break;}
    f*=g;
    
    g=0;
    if(f==1){
    for(long i=x-1; i>=x1; i--)
    if(pole[y][i]==1){ g=1;break;}
        f*=g;
        }
g=0;
    if(f==1){
    for(long i=y-1; i>=y_1; i--)
    if(pole[i][x]==1){ g=1;break;}
        f*=g;
        }
            if(f==1){
g=0;
    for(long i=y+1; i<=y2; i++)
    if(pole[i][x]==1){ g=1;break;}
        f*=g;
}
    return f;}











  /////////////////////////////////////////////////main////////////////////////////   
int main(){

   
    long lama;
    cin>>lama;
    for(long p=1; p<=lama;p++){

 
x1=0;x2=0;y_1=0;y2=0;
long a=0;
long b=0;


    for(long i=0; i<=2050;i++){
    for(long i1=0; i1<=2050;i1++){
    pole[i][i1]=0;}
}
    long s,r;

    cin>>s>>r;

    
    for(long i=1; i<=r;i++)
             for(long i1=1; i1<=s;i1++)
 scanf("%d",&pole[i][i1]);
    
//nacitanie

  while(0==0){
                       b=1;
                     while(pole[a][b]==0 && b<=s)
                     b++;
                                        if( pole[a][b]!=0 ){y_1=a; break;}
    a++;
}




a=r;
                      b=s;
while(0==0){
                      b=s;
                     while(pole[a][b]==0  && b>0)
                   b--;
                   if( pole[a][b]!=0 ){y2=a; break;}
    a--;
}


a=r;
b=s;
while(0==0){
                     a=r;
                     while(pole[a][b]==0 && a>0)
                     a--;
                                        if( pole[a][b]!=0 ){x2=b; break;}
    b--;
}



a=1;
 b=1;
while(0==0){
                     a=1;
                     while(pole[a][b]==0 && a<=r)
                     a++;
                                        if( pole[a][b]!=0 ){x1=b; break;}
    b++;
}










//find
int err=0;
long long sum=0;

for(long i=x1; i<=x2;i++)
for(long i1=y_1; i1<=y2; i1++){
if(pole[i1][i]==0 && test(i1,i)==1) sum++;
else if(pole[i1][i]==1) sum++;
         }
         
long q=0;
 if(x2-x1>y2-y_1)q=sum*100/((x2-x1+1 )*(x2-x1 +1));
 else q=sum*100/((y2-y_1 +1)*(y2-y_1+1 ));
 
 if(q<50) err=1;
                                                                     
if(err==1) cout<<"banan"<<endl;
else cout<<"pomaranc"<<endl;
}       






    
}

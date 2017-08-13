#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;




int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}





int main(){
long long n;
cin>>n;

long long * pole=new long long[n+1];
for(long i=0;i<n;i++)
cin>>pole[i];



 qsort (pole, n, sizeof(long long), compare);

long long pos=0,naj=0;
long long pocet=1;
while(pos<n){
             if(pole[pos]==pole[pos+1])pocet++;
             else{
                  if(pocet>naj)naj=pocet;
                  pocet=1;
                  }
                  pos++;

    }
    
    int zvys=0;
    if (n%naj!=0) zvys=1;

                  
                   cout<<naj<<"\n"<<(n/naj)+ zvys<<endl;
                  
                  
                  
             


                 cin.get();
                 cin.get();
                 return 0;
                 } 

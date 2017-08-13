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
    long n,r;
    cin>>n>>r;
 long pole1[100020];
 long pole2[100020];

    for(long i=0; i<n;i++)
    scanf("%d",&pole1[i]);
    //cin>>pole1[i];
    for(long i=0; i<r;i++)
    scanf("%d",&pole2[i]);
    
   //qsort (pole1, n, sizeof(long), compare);
   // qsort (pole2, r, sizeof(long), compare);
   long nz=1000000;
   long rz=1000000;
   long nk=0;
   long rk=0;
   for(long i=0; i<n; i++){
            if(pole1[i]<nz) nz=pole1[i];
            }
      for(long i=0; i<r; i++){
            if(pole2[i]<rz) rz=pole2[i];
            }
         for(long i=0; i<n; i++){
            if(pole1[i]>nk) nk=pole1[i];
            }
            for(long i=0; i<r; i++){
            if(pole2[i]>rk) rk=pole2[i];
            }
    
    if(nz<rz && nk<rk){


    
   if(nk>rz ) printf("2\n"); 
   
   //cout<<"2"<<endl;
   
   else printf("1\n"); 
   
   // cout<<"1"<<endl;
   
   
   
   
   
   
                                       }
                                       else  printf("-1\n"); 
                                       
                                       // cout<<"-1"<<endl;


                                       
                                       
                                       }

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
string a,b;
    
   cin>>a>>b;

   long p=0;
   long m=0;
   long long sum=0;

   
   for(long i=0;i<=n;i++){
            long pos=0;
            if(a[i]!=b[i]){
                           if(b[i]=='P'){pos=b.find_first_of('M',i+1);
                           m=pos;

                           b[i]='M';
                           b[pos]='P';

                           }
                           else{ pos=b.find_first_of('P',i+1);
                           
                           p=pos;

                           b[i]='P';
                           b[pos]='M';}

                                                      sum+=pos-i;

                           }

                           }
                           
                           
                           
                           cout<<sum<<endl;
                           

cin.get();
cin.get();
}
    

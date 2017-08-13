#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;


int main(){
    long n;
    long long sum=0;
    cin>>n;
    long * pole= new long[n];
    for(long i=1;i<=n;i++){
    cin>>pole[i];
    sum+=pole[i];
}
long priemer=sum/n;
long pocet=0;
for(long i=1; i<=n;i++)
if(pole[i]>priemer) pocet++;
cout<<pocet<<endl;
cin.get();
cin.get();
}

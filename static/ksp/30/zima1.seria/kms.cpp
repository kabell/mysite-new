#include<iostream>
 using namespace std;


bool over(long long t){

long long sum=1;
while(true){
sum*=2;
if(sum==t) return true;
else if(sum>t) return false;


}

}




int main(){

long long cis1=1,cis2=1,cis3=3;

int pos=3;

while(true){
pos++;


cis1=cis2;
cis2=cis3;
cis3=cis1+cis2+1;



cout<<pos<<" ";
if(over(cis3+1)==true)
cout<<cis3;
cout<<endl;









}
















}

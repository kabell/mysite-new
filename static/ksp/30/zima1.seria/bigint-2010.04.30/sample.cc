// Sample program demonstrating the use of the Big Integer Library.

// Standard libraries
#include <string>
#include <iostream>

// `BigIntegerLibrary.hh' includes all of the library headers.
#include "BigIntegerLibrary.hh"

using namespace std;

bool over(BigInteger t){

BigInteger sum=1;
while(true){
sum*=2;
if(sum==t) return true;
else if(sum>t) return false;


}

}




int main(){

BigInteger cis1=1,cis2=1,cis3=3;

int pos=3;

while(true){
pos++;


cis1=cis2;
cis2=cis3;
cis3=cis1+cis2+1;



cout<<pos<<" "<<cis3;;
if(over(cis3+1)==true)
cout<<" OK";
cout<<endl;









}
















}

/*
The original sample program produces this output:

3141592653589793238462643383279
314424
313894
83252135
1185
134
0xFF
0xFF00FFFF
0xFF00FF00
0x1FFFE00000
0x3F
314^0 = 1
314^1 = 314
314^2 = 98596
314^3 = 30959144
314^4 = 9721171216
314^5 = 3052447761824
314^6 = 958468597212736
314^7 = 300959139524799104
314^8 = 94501169810786918656
314^9 = 29673367320587092457984
314^10 = 9317437338664347031806976
12
8
1931

*/

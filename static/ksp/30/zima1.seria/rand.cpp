#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;




int main(){

  srand ( time(NULL) );
long long pocet=rand()%10000;
long long dlzka=rand()%(pocet-2)+2;
cout<<pocet<<" "<<dlzka<<endl;
  /* generate secret number: */
for(int i=1; i<=pocet; i++)
cout<< rand()%200000-100000<<" ";
cout<<endl;
cout<<rand()%100000<<endl;







}

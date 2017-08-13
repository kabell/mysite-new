#include <iostream>




using namespace std;

int main(){

   long pocet;
   cin >> pocet;
   while(pocet!=0){
      float xa,ya,xb,yb,xc,yc;
      cin >> xa  >> ya  >> xb >> yb >> xc>> yc;

      xb-=xa;
      yb-=ya;
      xc-=xa;
      yc-=ya;

      float func=yb/xb;

      float posyc=func*xc;



      if(xb>0){
      if(posyc<yc) cout<<"vlavo\n";
      else if(posyc>yc) cout <<"vpravo\n";
      else cout <<"rovno\n";
      }
      else if(xb<0){
      if(posyc<yc) cout<<"vpravo\n";
      else if(posyc>yc) cout <<"vlavo\n";
      else cout <<"rovno\n";
      }

      else if(xb==0 && yb<0){
      if(xc<0) cout<<"vpravo\n";
      else if(xc>0) cout <<"vlavo\n";
      else cout <<"rovno\n";
      }

      else if(xb==0 && yb>0){
      if(xc<0) cout<<"vlavo\n";
      else if(xc>0) cout <<"vpravo\n";
      else cout <<"rovno\n";
      }

          pocet--;

                  }












 cin.get();
  cin.get();
}

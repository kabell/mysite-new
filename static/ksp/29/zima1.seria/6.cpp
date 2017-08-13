#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;
     long menu[52];
               long cisla[52];
    long pmenu,pocetk;
        long  dava,  pcisla;
    
    
    long find(long cislo){
         long err=0;
        for (long i=1; i<=pmenu;i++){
             if(cislo%menu[i]==0){
                                  err=1;

                                  break;
                                  }
                                  }
            if(err==0){
                       for (long i=1; i<=pmenu;i++){
                           cout<<menu[i]<<" ";
                           if(menu[i]<cislo)
                           if(find(cislo-menu[i])==1){ err=1; break;};
                           }
                           }
                           

                       
         if(err==1){
         
         return 1;

         }
         
         else return 0;
         
         
         
         
         }




int main(){
    

    
    cin >> pocetk >>pmenu>>pcisla>>dava;

     for(long i=1; i<=pmenu; i++) cin>>menu[i];

     for(long i=1; i<=pcisla; i++) cin>>cisla[i];
     
     /////////////begin////////////////
     long err=0;
     
if(find(100)==1) cout<<" nekonecno"<<endl;
  
     
     

cin.get();
cin.get();
}
     
     
     
     
    
    

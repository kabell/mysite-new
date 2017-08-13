#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;


string d;
string zatvorka;
long operacia(long pos1, long mod);
void zatvorky();

long convertint(string l){

  istringstream buffer(l);
    long cislo;
 buffer >> cislo;
 return cislo;
}


string convertstr(long cislo){
 ostringstream buffer;
 buffer << cislo;
 string vysledok = buffer.str();
return vysledok;
}






     string operacia(long pos0,long pos1, long pos2, long mod){



string cislo1,cislo2;

         cislo1 = zatvorka.substr(pos0,pos1-pos0);


        cislo2 =zatvorka.substr(pos1+1,pos2-pos1-1);



long cisl1=convertint(cislo1);
long cisl2=convertint(cislo2);




       long vysledok=1;
         if(mod == 1){
if(cisl2>0){
vysledok=pow(cisl1,cisl2);
}
}



     else if(mod == 2)
     vysledok = convertint(cislo1) * convertint(cislo2);
     else if(mod == 3)
    vysledok = convertint(cislo1) / convertint(cislo2);
     else if(mod == 4)
      vysledok = convertint(cislo1) + convertint(cislo2);
     else if(mod == 5)
     vysledok = convertint(cislo1) - convertint(cislo2);






return convertstr(vysledok);
}


void parse(){

string temp;
     while(zatvorka.find_last_of('^')!=string::npos){

     long pos1 = zatvorka.find_last_of('^');
     long pos0 = zatvorka.find_last_of("+-*/^", pos1-1);
if(pos0==string::npos) pos0=0;
else {
  pos0 = zatvorka.find_last_of("0123456789", pos0);
     if(pos0==string::npos) pos0=0;
     else
     pos0 ++;
     }

     long pos2 = zatvorka.find_first_of("+-*/^", pos1+1);
     if(pos2==string::npos) pos2=zatvorka.length()-1;

     temp=operacia(pos0+1,pos1,pos2,1);

     zatvorka.replace(pos0+1,pos2-pos0-1,temp);


 }


      while(zatvorka.find_first_of("*/")!=string::npos){

     long pos1 = zatvorka.find_first_of("*/");
     long pos0 = zatvorka.find_last_of("+-*/^", pos1-1);
if(pos0==string::npos) pos0=0;
else {
  pos0 = zatvorka.find_last_of("0123456789", pos0);
     if(pos0==string::npos) pos0=0;
     else
     pos0 ++;
     }

     long pos2 = zatvorka.find_first_of("+-*/^", pos1+2);



     if(pos2==string::npos) pos2=zatvorka.length()-1;


     if(zatvorka.find_first_of('*')==pos1)

     temp=operacia(pos0+1,pos1,pos2,2);
     else  temp=operacia(pos0+1,pos1,pos2,3);

     zatvorka.replace(pos0+1,pos2-pos0-1,temp);


 }




      while(zatvorka.find_first_of("+-",2)!=string::npos){

     long pos1 = zatvorka.find_first_of("+-");
     long pos0 = zatvorka.find_last_of("+-*/^", pos1-1);
if(pos0==string::npos) pos0=0;
else {
  pos0 = zatvorka.find_last_of("0123456789", pos0);
     if(pos0==string::npos) pos0=0;
     else
     pos0 ++;
     }

     long pos2 = zatvorka.find_first_of("+-*/^", pos1+2);


     if(pos2==string::npos) pos2=zatvorka.length()-1;

     if(zatvorka.find_first_of('+')==pos1)

     temp=operacia(pos0+1,pos1,pos2,4);
     else  temp=operacia(pos0+1,pos1,pos2,5);

     zatvorka.replace(pos0+1,pos2-pos0-1,temp);

 }






}













void zatvorky(){
while(d.find_first_of(')')!=string::npos){
     long pos2 = d.find_first_of(')');
     long pos0 = d.find_last_of('(',pos2-1);

       zatvorka=d.substr(pos0,pos2-pos0+1);
       d.replace(pos0,pos2-pos0+1,"",0);

       parse();
       zatvorka.replace(0,1,"",0);
       zatvorka.replace(zatvorka.length()-1,1,"",0);


d.insert(pos0,zatvorka);

}

}











int main() {

    string temp;

 while(cin >> d){
      d='('+d+')';
zatvorky();







            cout <<d<<endl;


            }
            cin.get();
            cin.get();
}

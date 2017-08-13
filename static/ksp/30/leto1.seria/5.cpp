#include <iostream>
#include <cstring>
#include<string>
#include<vector>

using namespace std;
string s;




vector<string> S;
vector<string> S1;
bool vypisuj=0;





bool is_numeric(string st){

if (st.length()==0) return false;

if(st[0]!='X' && st[0]!='N' && (st[0]>57 || st[0]<48)) return false;
for(int i=1; i<st.length(); i++)
if(st[i]>57 || st[i]<48) return false;

return true;
}

bool is_time(string &st){

if(st.length()==5){
if(st[0]>57 || st[0]<48) return false;
if(st[1]>57 || st[1]<48) return false;
if(st[2]!=':') return false;
if(st[3]>57 || st[3]<48) return false;
if(st[4]>57 || st[4]<48) return false;

}
if(st.length()!=5) return false;

return true;

}



string orez(string st){
int zac;
int kon;
string r;

for(int i=0; i<st.length(); i++)
if(st[i]!=' ' && st[i]!='\t'){ zac=i; break;}

for(int i=st.length()-1; i>=0; i--)
if(st[i]!=' ' && st[i]!='\t'){ kon=i; break;}

for(int i=zac; i<st.length(); i++)
r.append(1,st[i]);

if(r.length()>0)

return r;

return "";


}

int main ()
{


while(getline (std::cin,s))
{

string t;

if(s.find("<table width=\"600\">")!=string::npos) vypisuj=1;

if(s.length()<200 || vypisuj==0) continue;

int tag=0;
int pocet=0;
for(int i=0; i<s.length(); i++){
if(s[i]=='<') tag=1;
if(tag==0) t.append(1,s[i]);
if(s[i]=='>'){
tag=0;


if(t.length()>0)t=orez(t);


if(t.length()>0){
	S.push_back(t);
	 t.clear();
	}
}

if(tag==0) pocet++;

}

}

//cout<<"mama"<<endl;
/*
int nasledujs=0;
for(auto it=S.begin(); it!=S.end(); it++)
{
string h=*it;
if(h.find("NasledujÃ�ï¿½Ã�Âºce spojenia")!=string::npos) nasledujs=1;

if(nasledujs==1)
{
if(is_numeric(h))
cout<<h<<" num"<<endl;
else if(is_time(h))
cout<<h<<" time"<<endl;
else cout<<h<<endl;
}
}
*/

int nasledujs=0;
for(auto it=S.begin(); it!=S.end(); it++)
{
string h=*it;
if(h.find("spojenia")!=string::npos) nasledujs=1;

if(nasledujs==1)
{
if(h!=" ")
S1.push_back(h);
//cout<<h<<endl;
}
}
//cout<<"oco"<<endl;
//string l="N93";
//cout<<is_numeric(l);
//S1.push_back("kabell");
string kabell="kabell";
S1.push_back(kabell);

bool koncim=false;
bool prva=true;
auto it=S1.begin();

while(true){

while((*it).find("Spojenie")==string::npos && is_numeric(*it)==false){

it++;
//cout<<*it<<endl;
}
if((*it).find("Spojenie")!=string::npos && prva==false) cout<<endl;
if(prva==true) prva=false;

//cout<<"ok"<<endl;

while(is_numeric(*it)==false)
it++;
cout<<*it<<endl;

while(is_time(*it)==false)
it++;
cout<<*it<<" ";
it++;
//it++;
cout<<*it<<endl;


while(*it!="kabell" && (*it).find("Spojenie")==string::npos && is_numeric(*it)==false)
it++;

if(*it=="kabell") koncim=true;

while(is_time(*it)==false) it--;

cout<<*it<<" ";
it++;
//it++;
cout<<*it<<endl;

if(koncim==true) break;
}














}

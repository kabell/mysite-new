#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

struct zak{

long long id;
long long cas;
long long ch;

};

zak ms(long long id,long long cas,long long ch){
	zak t;
	t.id=id;
	t.cas=cas;
	t.ch=ch;
	return t;
}



class mycomparison
{
	public:
	  bool operator() (const zak& a, const zak & b) const
	    {
		    if(a.ch==b.ch) return a.cas>b.cas;
	    return (a.ch<b.ch);
	  }
};




int main(){

priority_queue< zak, vector<zak>, mycomparison > Q;
long long p=0;
string s;
do{


cin>>s;
if(s=="dalsi"){if(Q.size()>0){ cout<<(Q.top()).id<<"\n";Q.pop();} else cout<<"-1\n";}
else if(s=="pacient"){

long long id,ch;
cin>>id>>ch;
	Q.push(ms(id,p,ch));

}


p++;
}
while(s!="koniec");


}


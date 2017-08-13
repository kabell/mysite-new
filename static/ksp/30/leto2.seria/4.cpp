#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

long long INF=987654321;




int main(){



int n,p;
cin>>n>>p;

queue<long long>Q;

Q.push(0);
Q.push(0);

long long pos=0,poc=INF;

for(int i=1; i<=n; i++){
	long long a,b;
	cin>>a>>b;

	for(long long j=max(pos,b-p); j<a; j++){
		while(Q.size()>0){
			if(Q.front()<=j){
				Q.pop();
				poc=min(Q.front(),poc);
				Q.pop();

			}
			else break;
		}

	Q.push(j+p);
	Q.push(poc+1);

	}

	while(Q.size()>0){
		if(Q.front()<b){
			Q.pop();
			Q.pop();
		}
		else break;
	}
	poc=INF;
	pos=b;
}



while(Q.size()>0){

	Q.pop();
	poc=min(poc,Q.front());
	Q.pop();

}


if(poc>=INF)
	cout<<"-1"<<endl;
else cout<<poc<<endl;


}

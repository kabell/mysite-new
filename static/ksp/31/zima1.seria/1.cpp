#include<iostream>
#include<vector>

using namespace std;

vector<vector<char> >V;

int main(){

int t,n;
cin>>t>>n;
V.resize(147,vector<char>(147,'1'));

for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
        V[i][j]='0';


if(t==1){

bool g=false;

for(int i=1; i<=n; i++){
if(g==false){
for(int j=1; j<=n; j++)
    V[i][j]='>';
V[i][n]='v';
}
else{
for(int j=n; j>0; j--)
    V[i][j]='<';
V[i][1]='v';
}
g=1-g;
}
if(g==false)
    V[n][1]='+';
else V[n][n]='+';
}

//type 2


if(t==2){

    bool g=false;

    for(int i=1; i<=n; i++){
        if(g==false){
            for(int j=1; j<=n; j++)
                    V[j][i]='v';
            V[n][i]='>';
        }
        else{
            for(int j=n; j>0; j--)
                    V[j][i]='^';
            V[1][i]='>';
        }
        g=1-g;
    }
    if(g==false)
            V[1][n]='+';
    else V[n][n]='+';
} 


//type 3

if(t==3){
int smer=1;
int x=1,y=1;
while(true){
if(smer==1){
for(x; x<=n; x++){
if(V[y][x]=='0')V[y][x]='>';
else break;
}
V[y][--x]='0';
smer=2;
}
if(smer==2){
for(y; y<=n; y++){
    if(V[y][x]=='0')V[y][x]='v';
    else break;
}
V[--y][x]='0';
smer=3;
}
if(smer==3){
    for(x; x>0; x--){
        if(V[y][x]=='0')V[y][x]='<';
        else break;
    }
    V[y][++x]='0';
    smer=4;
}
if(smer==4){
        for(y; y>0; y--){
                if(V[y][x]=='0')V[y][x]='^';
                    else {break;}
        }
        V[++y][x]='0';
        smer=1;
}
if(V[x+1][y]!='0' && V[x-1][y]!='0' && V[x][y+1]!='0' && V[x][y-1]!='0')
break;
}

V[y][x]='+';
}

//type 4


if(t==4){
    int smer=1;
    int x=1,y=1;
    while(true){
        if(smer==1){
            for(x; x<=n; x++){
                if(V[x][y]=='0')V[x][y]='v';
                else break;
            }
            V[--x][y]='0';
            smer=2;
        }
        if(smer==2){
            for(y; y<=n; y++){
                    if(V[x][y]=='0')V[x][y]='>';
                        else break;
            }
            V[x][--y]='0';
            smer=3;
        }
        if(smer==3){
                for(x; x>0; x--){
                            if(V[x][y]=='0')V[x][y]='^';
                                    else break;
                                        }
                    V[++x][y]='0';
                        smer=4;
        }
        if(smer==4){
                    for(y; y>0; y--){
                                        if(V[x][y]=='0')V[x][y]='<';
                                                            else {break;}
                                                                    }
                            V[x][++y]='0';
                                    smer=1;
        }
        if(V[x+1][y]!='0' && V[x-1][y]!='0' && V[x][y+1]!='0' && V[x][y-1]!='0')
            break;
    }

    V[x][y]='+';
}





for(int i=1; i<=n; i++){
for(int j=1; j<=n; j++)
cout<<V[i][j];
cout<<endl;
}
}

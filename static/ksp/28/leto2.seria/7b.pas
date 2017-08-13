program uradnici;


var

zoznam: array[1..100000,1..2] of longint;
cesta: array[1..100000] of longint;
fronta: array[1..100000] of longint;
obsadene: array[1..100000] of boolean;

i,i1,i2,i3,a,b,c,n,x: longint;

begin

readln(n);

for i:=1 to n-1 do begin
readln(a,b);
zoznam[i,1]:=a;
zoznam[i,2]:=b;
end;



x:=1;
a:=0;
b:=0;
repeat

for i:=1 to n-1 do begin
if (zoznam[i,1]=x) or (zoznam[i,2]=x) then begin
if zoznam[i,1]=x then begin 
cesta[zoznam[i,2]]:=x; 
inc(a); 
fronta[a]:=zoznam[i,2];
end

else begin
cesta[zoznam[i,1]]:=x;
inc(a); 
fronta[a]:=zoznam[i,1];
end;

zoznam[i,1]:=0;
zoznam[i,2]:=0;
end;
end;
inc(b);
x:=fronta[b];
until x=0;




for i:=1 to n do begin
readln(a);
x:=0;
if a=1 then begin writeln('0'); obsadene[1]:=true; end
else begin
obsadene[a]:=true;

repeat
a:=cesta[a];
if obsadene[a]=true then 
inc(x);

until a=1;

writeln(x);
end;
end;


readln;
end.














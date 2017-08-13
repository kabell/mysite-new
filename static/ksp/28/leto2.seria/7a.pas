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
if a<b then
cesta[b]:=a
else 
cesta[a]:=b;
end;



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














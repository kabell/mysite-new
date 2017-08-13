program obed;

var 
pole: array[1..100001] of longint;
data: array[1..100001] of boolean;
i,i1,n,x:longint;

begin
readln(n);
for i:=1 to n do begin
readln(x);
pole[i]:=x;

end;
pole[n+1]:=2000000;


for i:=1 to n do begin


if pole[i]>i then begin data[pole[i]]:=true; end

else if pole[i]=i then begin
i1:=0;
repeat
inc(i1);
until (pole[i1]>pole[i]) or (i1=i);
if pole[i1]>pole[i] then data[pole[i]]:=true;

end


else if pole[i]<i then begin

i1:=i;
repeat
inc(i1);
until (pole[i1]<pole[i]) or (i1>=n);
if pole[i1]<pole[i] then data[pole[i]]:=true;

end;

end;

for i:=1 to n do 
if data[i]=true then writeln(i);
readln;
end.
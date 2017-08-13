program obvod;

var pole:array[1..205,1..205] of string;

poz:array[1..2] of integer;
poz1:array[1..2] of integer;

start:array[1..2] of integer;
s,v: ansistring;
x,y,i,i1,z,z1,t: integer;








begin

for i:=1 to 202 do
for i1:=1 to 202 do
pole[i][i1]:='.';
readln(x,y);

for i:=1 to x do begin
readln(s);
for i1:=1 to y do begin
pole[i+1][i1+1]:=s[i1];

end;
end;


i:=1;
repeat
i1:=1;
repeat
if pole[i][i1]='o' then begin start[1]:=i; start[2]:=i1; end;
i1:=i1+1;
until (pole[i][i1-1]='o') or (i1=y+2);
i:=i+1;

until pole[i-1][i1-1]='o';





if pole[start[1]+3][start[2]]='o' then begin
if pole[start[1]+1][start[2]]='|' then writeln('svieti')
else writeln('nesvieti');
end
else
if pole[start[1]][start[2]+3]='o' then begin
if pole[start[1]][start[2]+1]='-' then writeln('svieti')
else writeln('nesvieti');
end;























readln;
end.








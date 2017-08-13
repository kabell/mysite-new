program domino;

var pole:array[1..100,1..2] of shortint;

pocet:array[1..6,1..3] of integer;

mnozstvo,i,a,b,poradie,kon,x,y,konec,z,k,l,error: integer;

begin

read(mnozstvo);
for i:=1 to mnozstvo do begin
readln(a,b);
pocet[a][1]:=pocet[a][1]+1;
pocet[b][1]:=pocet[b][1]+1;
pole[i][1]:=a;
pole[i][2]:=b;
if a=b then
pocet[a][2]:=pocet[a][2]+1;
poradie:=poradie+1;
end;

for i:=1 to 6 do begin
if pocet[i][1] mod 2 = 1 then begin
kon:=kon+1;
pocet[i][3]:=1;
end;


{if pocet[i][1]-pocet[i][2]*2=0 then error:=1;}
end;
{zistenie poctu neparnych}
{nacitanie vstupu}

writeln(error);
readln;


if (kon=2) and (error=0) then begin{ak je neparny pocet 2}
i:=0;
repeat
i:=i+1;
until pocet[i][3]=1;
a:=i;
repeat
i:=i+1;
until pocet[i][3]=1;

b:=i;
writeln('Da sa');
{zistenie ktore su neparne}
if (kon=2) and (pocet[a][2]>0)  then begin{ak je pocet dvojitych viac ako0}
for y:=1 to pocet[a][2] do begin
i:=0;
repeat
i:=i+1
until (pole[i][1]=a) and (pole[i][2]=a);
write(pole[i][1],'',pole[i][2],' ');
x:=pole[i][2];
pole[i][1]:=0;
pole[i][2]:=0;
end;
end
{najdenie a vypisanie dvojice}
else begin
i:=0;
repeat
i:=i+1
until (pole[i][1]=a) or (pole[i][2]=a);
write(pole[i][1],'',pole[i][2],' ');
x:=pole[i][2];
pole[i][1]:=0;
pole[i][2]:=0;
end;



i:=0;
repeat
i:=i+1
until ((pole[i][1]=b) or (pole[i][2]=b)) and (pole[i][1]<>pole[i][2]);

k:=pole[i][1];
l:=pole[i][2];
pole[i][1]:=0;
pole[i][2]:=0;
{najdenie konca}







{vypisanie ostatnych}
for i:=2 to mnozstvo-1-pocet[b][2] do begin
if pocet[x][2]>0 then begin

for z:=1 to pocet[x][2] do begin
y:=0;
repeat
y:=y+1;
until (pole[y][1]=x) and (pole[y][2]=x);
write(pole[y][1],'',pole[y][2],' ');
pole[y][1]:=0;
pole[y][2]:=0;
end;
pocet[x][2]:=0;
end;



y:=0;
repeat
y:=y+1;
until (pole[y][1]=x) or (pole[y][2]=x);
if pole[y][1]=x then begin
write(pole[y][1],'',pole[y][2],' ');
x:=pole[y][2];
pole[y][1]:=0;
pole[y][2]:=0;
end
else begin
write(pole[y][2],'',pole[y][1],' ');
x:=pole[y][1];
pole[y][1]:=0;
pole[y][2]:=0;
end;


if k=x then
write(k,'',l,' ')
else write(l,'',k,' ');

for z:=1 to pocet[b][2] do
write(b,'',b,' ');

end;

end;

writeln(kon);
writeln(pole[1][1],' ',pole[1][2]);
writeln(pole[2][1],' ',pole[2][2]);
readln;



if (kon=0) and (error=0) then begin
writeln('Da sa');
write(pole[1][1],'',pole[1][2],' ');
x:=pole[1][2];
pole[1][1]:=0;
pole[1][1]:=0;
for i:=2 to mnozstvo do begin
y:=0;
repeat
y:=y+1;
until (pole[y][1]=x) or (pole[y][2]=x);
if pole[y][1]=x then begin
write(pole[y][1],'',pole[y][2],' ');
x:=pole[y][2];
pole[y][2]:=0;
pole[y][1]:=0;
end

else begin

write(pole[y][2],'',pole[y][1],' ');
x:=pole[y][1];
pole[y][2]:=0;
pole[y][1]:=0;
end;
end;
readln;
end;





if error=1 then
writeln('Neda sa');
readln;
end.
Meno: Michal Korbela
�kola: Gybmn�zium J.J. B�novce nad B. Radlinsk�ho 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
�loha �.2 - Zdrojak

program age;

var pole:array[1..100,1..100] of char;
i,i1,x2,x1,y1,y2,r,s:integer;
ch:string;

begin

readln(r,s);
for i:=1 to r do begin
readln(ch);
for i1:=1 to s do 
pole[i][i1]:=ch[i1];

end;
						{na��tanie vstupu a ulo�enie do po�a}
i:=1;
						{zistenie na ktor�ch riadkoch sa nach�dza kraj pevniny(ostrovu)}
repeat
i:=i+1;
i1:=1;
repeat
i1:=i1+1;
until (pole[i][i1]='#') or (i1=s);
until (pole[i][i1]='#') or (i=r);
if i<r then
x1:=i;


i:=r;
repeat
i:=i-1;
i1:=1;
repeat
i1:=i1+1;
until (pole[i][i1]='#') or (i1=s);
until (pole[i][i1]='#') or (i=1);
if i>1 then
x2:=i;

						{zistenie v ktor�ch stlpcoch sa nach�dza kraj penvniny}
i1:=1;

repeat
i1:=i1+1;
i:=1;
repeat
i:=i+1;
until (pole[i][i1]='#') or (i=r);
until (pole[i][i1]='#') or (i1=s);
if i<s then
y1:=i1;

i1:=s;

repeat
i1:=i1-1;
i:=1;
repeat
i:=i+1;
until (pole[i][i1]='#') or (i=r);
until (pole[i][i1]='#') or (i1=s);
if i>1 then
y2:=i1;

						{ohrani�enie ostrova galeonami vodorovne}
for i:=x1-1 to x2+1 do begin
pole[i][y1-1]:='G';
pole[i][y2+1]:='G';
end;
						{ohrani�enie ostrova galeonami zvisle}
for i:=y1-1 to y2+1 do begin
pole[x1-1][i]:='G';
pole[x2+1][i]:='G';
end;

writeln('');					{oddelenie zadania od v�stupu ktor� ani nemus� by�}
for i:=1 to r do begin 				{Vyp�sanie v�stupu}
for i1:=1 to s do begin
write(pole[i][i1]);

end;
writeln();
end;
readln;
end.
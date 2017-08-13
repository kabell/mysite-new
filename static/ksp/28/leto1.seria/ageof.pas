Meno: Michal Korbela
Škola: Gybmnázium J.J. Bánovce nad B. Radlinského 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
Úloha è.2 - Zdrojak

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
						{naèítanie vstupu a uloenie do po¾a}
i:=1;
						{zistenie na ktorıch riadkoch sa nachádza kraj pevniny(ostrovu)}
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

						{zistenie v ktorıch stlpcoch sa nachádza kraj penvniny}
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

						{ohranièenie ostrova galeonami vodorovne}
for i:=x1-1 to x2+1 do begin
pole[i][y1-1]:='G';
pole[i][y2+1]:='G';
end;
						{ohranièenie ostrova galeonami zvisle}
for i:=y1-1 to y2+1 do begin
pole[x1-1][i]:='G';
pole[x2+1][i]:='G';
end;

writeln('');					{oddelenie zadania od vıstupu ktoré ani nemusí by}
for i:=1 to r do begin 				{Vypísanie vıstupu}
for i1:=1 to s do begin
write(pole[i][i1]);

end;
writeln();
end;
readln;
end.
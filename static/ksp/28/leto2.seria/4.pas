Meno: Michal Korbela
�kola: Gybmn�zium J.J. B�novce nad B. Radlinsk�ho 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
�loha �.4 - K�d


program veze;

var
pole: array[1..100,1..2] of longint;
x,y,z,i,i1,n: longint;

begin
readln(n);

for i:=1 to n do begin

readln(x,y,z);
pole[i,1]:=x;{na��tanie vstupu - bod kde le�� ve�a s nena��ta}
pole[i,2]:=z;

end;
x:=0;
for i:=1 to n do begin{testuje sa ka�d� ve�a s ka�dou}
for i1:=1 to n do begin
if (pole[i,1]<pole[i1,1]) and (pole[i,2]>pole[i1,2]) then begin
pole[i1,1]:=0;
pole[i1,2]:=0;{ ak je ve�a me�ia- vyma�e sa}
writeln(i1);{vyp�e sa poradov� ��slo ve�e}
inc(x);
end;
end;
end;
if x=0 then writeln('nemozno zburat ziadnu vezu');
readln;
end.


 
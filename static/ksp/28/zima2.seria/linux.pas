meno: Michal Korbela
�kola: gymn�zium J.J B�novce nad Bebravou
trieda: kvinta
Pr�klad �.2




program linux;

uses crt;
var
bal: array[1..1000,1..1000] of integer;
zaz: array[1..1000] of integer;
pocet,i,k,h,l,m,z: integer;

begin
clrscr;
writeln('zadajte pocet balickov: ');
readln(pocet);
for i:=1 to pocet do begin {na��tanie vstupu}
writeln('zadajte pocet balickov a zoznam: ');
read(bal[i][1]);
for k:=2 to bal[i][1]+1 do read(bal[i][k]);
readln;
end;






for i:=1 to pocet do {vytvorenie zoznamu bal��kov - pokia� je 1 bal��ek je v zozname, ak 0 bal��ek nie je v zozname}
zaz[i]:=1;


for i:=1 to pocet do {pre��tanie jednotliv�ch zvislosti bal��kov}
for h:=2 to bal[i][1]+1 do
if zaz[bal[i][h]]=1 then zaz[bal[i][h]]:=0;{ak sa bal��ek v zozname nach�dza( je 1) vyma�e ho (zap�e 0)}

for i:=1 to pocet do
if zaz[i]=1 then write(i,' ');{vyp�sanie bal��kov ktor� zostali}
readln;
end.


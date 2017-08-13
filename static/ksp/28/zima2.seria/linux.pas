meno: Michal Korbela
škola: gymnázium J.J Bánovce nad Bebravou
trieda: kvinta
Príklad è.2




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
for i:=1 to pocet do begin {naèítanie vstupu}
writeln('zadajte pocet balickov a zoznam: ');
read(bal[i][1]);
for k:=2 to bal[i][1]+1 do read(bal[i][k]);
readln;
end;






for i:=1 to pocet do {vytvorenie zoznamu balíèkov - pokia¾ je 1 balíèek je v zozname, ak 0 balíèek nie je v zozname}
zaz[i]:=1;


for i:=1 to pocet do {preèítanie jednotlivých zvislosti balíèkov}
for h:=2 to bal[i][1]+1 do
if zaz[bal[i][h]]=1 then zaz[bal[i][h]]:=0;{ak sa balíèek v zozname nachádza( je 1) vymaže ho (zapíše 0)}

for i:=1 to pocet do
if zaz[i]=1 then write(i,' ');{vypísanie balíèkov ktoré zostali}
readln;
end.


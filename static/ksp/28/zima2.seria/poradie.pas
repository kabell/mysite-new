meno: Michal Korbela
�kola: gymn�zium J.J B�novce nad Bebravou
trieda: kvinta
Pr�klad �.1




program poradie;

uses crt;
var i,cislo:integer;
c: array[1..1000] of integer;
begin
clrscr;
writeln('zadajte pocet cisel: ');
readln(cislo);

writeln('zadajte cisla> ');

for i:=1 to cislo do
Read(c[i]);{na��tanie vstupu}
readln;

if c[1] < c[2] then begin{zmie�anie prv�ch 3, aby postupnos� nikdy nebola st�paj�ca a ani klesaj�ca}
write(c[1],' ');
if c[2] < c[3] then write(c[3],' ',c[2],' ')
else write(c[2],' ',c[3],' ');
end
else begin
 write(c[2],' ');
 if c[3] < c[1] then write(c[1],' ',c[3],' ')
else write(c[3],' ',c[1],' ')
end;
if cislo >= 4 then begin
for i:=4 to cislo do

write(c[i],' ');{vyp�sanie ostatn�ch ��sel}

end;
readln;
end.

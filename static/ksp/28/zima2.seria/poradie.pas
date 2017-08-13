meno: Michal Korbela
škola: gymnázium J.J Bánovce nad Bebravou
trieda: kvinta
Príklad è.1




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
Read(c[i]);{naèítanie vstupu}
readln;

if c[1] < c[2] then begin{zmiešanie prvıch 3, aby postupnos nikdy nebola stúpajúca a ani klesajúca}
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

write(c[i],' ');{vypísanie ostatnıch èísel}

end;
readln;
end.

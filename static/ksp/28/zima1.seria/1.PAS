program Tabulka;
uses crt; 

var R,S,a,b,l:integer;         {jednoduch� pomocn� premenn� a - pri cykle na vpisovanie znakov do riadkov(po�et stlpcov),}
{ b - na ur�ovanie po�tu riadkov, ak je l 0 tak sa vyp�e riadok ktor� pozost�va zo +- a ked je 1 tak z | ,}
begin
clrscr;
write('Zadaj cisla: ');         {zad�te ��sla}
ReadLn(R,S);

l:=0; {l je nastaven� na za�iatok tj, ako prv� sa bude vypisova� +-}
for b:=1 to R do {cyklus ktor� ur�uje po�et riadkov}
begin
if l=0 then
begin

for a:=1 to S do
begin
write('+-');

end;



writeln('+');{zakon�� sa riadok}
l:=1;{l je nastaven� �e sa bude vypisova� telo bunky | a medzera}
end;






if l=1 then


begin {cyklus na v�pis tela teda r�ry a medzery}
for a:=1 to S do
begin
write('| ');

end;
writeln('|');{zakon�� sa riadok}
l:=0;

end;








end;
for a:=1 to S do {zakon�ia sa st�pce tak �e sa vyp�e riadok so +-}
begin
write('+-');

end;



writeln('+');{dokon�� sa riadok tj. prav� doln� znak tabulky}


readln
end.
    
    


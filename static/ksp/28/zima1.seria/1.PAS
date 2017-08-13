program Tabulka;
uses crt; 

var R,S,a,b,l:integer;         {jednoduché pomocné premenné a - pri cykle na vpisovanie znakov do riadkov(poèet stlpcov),}
{ b - na urèovanie poètu riadkov, ak je l 0 tak sa vypíše riadok ktorı pozostáva zo +- a ked je 1 tak z | ,}
begin
clrscr;
write('Zadaj cisla: ');         {zadáte èísla}
ReadLn(R,S);

l:=0; {l je nastavené na zaèiatok tj, ako prvé sa bude vypisova +-}
for b:=1 to R do {cyklus ktorı urèuje poèet riadkov}
begin
if l=0 then
begin

for a:=1 to S do
begin
write('+-');

end;



writeln('+');{zakonèí sa riadok}
l:=1;{l je nastavené e sa bude vypisova telo bunky | a medzera}
end;






if l=1 then


begin {cyklus na vıpis tela teda rúry a medzery}
for a:=1 to S do
begin
write('| ');

end;
writeln('|');{zakonèí sa riadok}
l:=0;

end;








end;
for a:=1 to S do {zakonèia sa ståpce tak e sa vypíše riadok so +-}
begin
write('+-');

end;



writeln('+');{dokonèí sa riadok tj. pravı dolnı znak tabulky}


readln
end.
    
    


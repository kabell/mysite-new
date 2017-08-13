meno: Michal Korbela
škola: gymnázium J.J Bánovce nad Bebravou
trieda: kvinta
Príklad è.3





program dochodca;

uses crt;
var y,x,po,a,i,pocet:integer;
cisla: array[1..1000,1..2] of integer;
poradie: array[1..1000,1..2] of integer;
begin
clrscr;
writeln('zadajte pocet cisel: ');
readln(pocet);

writeln('zadajte cisla> ');{naèítanie vstupu}
for i:=1 to pocet do begin
Read(cisla[i][1]);
cisla[i][2]:=i mod 2;{èíslam sa priradí aj ich pozícia (buï 0 alebo 1)}
poradie[i][1]:=cisla[i][1];{èísla sa skopírujú do nového zoznamu}
poradie[i][2]:=cisla[i][2];{skopíruje sa aj ich pozícia}
end;
readln;

i:=1;
while i <= pocet-1 do begin {usporiadanie èísel v novom zozname}
if poradie[i][1] > poradie[i+1][1] then begin
po:=poradie[i+1][1];
poradie[i+1][1]:=poradie[i][1];
poradie[i][1]:=po;
i:=1;
end
else i:=i+1;
end;
for i:=1 to pocet do begin
if i mod 2=1 then poradie[i][2]:=1
else poradie[i][2]:=0;
end;



po:=1;
x:=1;
y:=1;
while x<=pocet+1 do begin {Vyh¾adanie daného èísla v druhom zozname(v zozname v ktorom sú už èísla usporiadané a porovnanie zvyškov po delení 2. Ak zvyšky nesúhlasia, premenná x nadobudne hodnotu poèet+1 a cyklus je ukonèený a program vypíše Nie. Potom premenná po nadobudne hodnotu 10 èo znamená, že Ano nebude vypísané.}
        y:=1;
        a:=1;
        while a=1 do begin

                if cisla[x][1]<>poradie[y][1] then begin a:=1; y:=y+1; end
                else begin
                y:=y+1;
                a:=2;
                end;

        end;
        if cisla[x][2]<>poradie[y-1][2] then
                 begin
                  writeln('nie');
                     y:=y+1;
                     a:=2;
                     x:=pocet+1;
                     po:=10;
                     end;
                x:=x+1;
        end;
        if po<>10 then writeln('ano');

readln;
end.

Meno: Michal Korbela
Škola: Gybmnázium J.J. Bánovce nad B. Radlinského 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
Úloha è.4 - Kód


program veze;

var
pole: array[1..100,1..2] of longint;
x,y,z,i,i1,n: longint;

begin
readln(n);

for i:=1 to n do begin

readln(x,y,z);
pole[i,1]:=x;{naèítanie vstupu - bod kde leží veža s nenaèíta}
pole[i,2]:=z;

end;
x:=0;
for i:=1 to n do begin{testuje sa každá veža s každou}
for i1:=1 to n do begin
if (pole[i,1]<pole[i1,1]) and (pole[i,2]>pole[i1,2]) then begin
pole[i1,1]:=0;
pole[i1,2]:=0;{ ak je veža mešia- vymaže sa}
writeln(i1);{vypíše sa poradové èíslo veže}
inc(x);
end;
end;
end;
if x=0 then writeln('nemozno zburat ziadnu vezu');
readln;
end.


 
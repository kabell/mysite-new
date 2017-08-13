const nekonecno = 123456789;
var R, C, K, r0, c0, rF, cF, r1, c1, r2, c2, i, j: longint;
mapa, vzdialenost: array [1..1000, 1..1000] of longint;
fronta: array [1..1000047, 1..2] of longint;
fz, fk: longint; { premenne ukazujuce na zaciatok a *za* koniec fronty }
begin
{ nacitame vstup }
Read(R, C, K, r0, c0, rF, cF);
for i := 1 to R do
for j := 1 to C do
Read(mapa[i, j]);
{ inicializujeme premenne }
for i := 1 to R do
for j := 1 to C do
vzdialenost[i, j] := nekonecno;
vzdialenost[r0, c0] := 0;
fz := 1;
fk := 2;
fronta[fz, 1] := r0;
fronta[fz, 2] := c0;
{ prehladavame graf }
while fk > fz do begin
{ vyberieme z fronty vrchol }
r1 := fronta[fz, 1];
c1 := fronta[fz, 2];
Inc(fz);
{ najdeme vsetky vrcholy, kam sa mozeme pohnut }
for i := -2 to 2 do
for j := -2 to 2 do begin
r2 := r1 + i;
c2 := c1 + j;
{ overime, ci smieme spravit krok z [r1, c1] na [r2, c2] }
if (r2 < 1) or (r2 > R) or (c2 < 1) or (c2 > C) then
Continue;
if abs(mapa[r2, c2] - mapa[r1, c1]) > K then
Continue;
{ ak sme na [r2, c2] este neboli, zaradime ho do fronty }
if vzdialenost[r2, c2] <> nekonecno then
Continue;
vzdialenost[r2, c2] := vzdialenost[r1, c1] + 1;
fronta[fk, 1] := r2;
fronta[fk, 2] := c2;
Inc(fk);
end;
end;
{ vypiseme vystup }
if vzdialenost[rF, cF] = nekonecno then
WriteLn('Artur, mas smolu.')
else
WriteLn(vzdialenost[rF, cf]);
readln;
readln;
end.

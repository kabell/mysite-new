Meno: Michal Korbela
Škola: Gybmnázium J.J. Bánovce nad B. Radlinského 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
Úloha è.4 - Zdrojak



program tymy1;
var
pole:array[1..100,1..3] of integer;
pocet:array[1..100] of integer;
tymy,k1,k2,i,i1,i2,i3,zak1,zak2,n,m:integer;



begin

readln(n,m);
for i:=1 to m do begin					{Naèítanie vstupu kamarátstvo pripisujeme vdy iakovi ktorı má menšie èíslo}
readln(k1,k2);
if k1<k2 then begin
inc(pocet[k1]);
pole[k1][pocet[k1]]:=k2;
end
else begin
inc(pocet[k2]);
pole[k2][pocet[k2]]:=k1;
end;
end;

tymy:=0;						{Zatia¾ máme 0 tımov}

for i:=1 to n-2 do begin 				{otestujeme všetkıch okrem poslednıch 2 - tí nám u nepomôu, pretoe k tomu poterebujeme ešte 3.}
if pocet[i]>1 then begin				{Ak sa s ním kamarátia aspoò 2 zaèneme inak nemá dôvod ho testova}
i1:=0;
repeat
inc(i1);
i2:=i1;
repeat
inc(i2);
if pole[i][i1] < pole[i][i2] then begin
zak1:=pole[i][i1];
zak2:=pole[i][i2];					{vyberieme si z z nich 2}
end
else begin
zak1:=pole[i][i2];
zak2:=pole[i][i1];
end;




i3:=0;
repeat
inc(i3);
until (pole[zak1][i3]=zak2) or (i3=pocet[zak1]);	{Ak sa majú navzájom kamaráti 2. sa musí kamaráti s 3.}

if pole[zak1][i3]=zak2 then begin			{Vieme , e 1. sa kamaráti s 2. a 3. a druhı sa kamaráti s 3. - vyhrali sme}
inc(tymy);						{zvıšime poèet tımov o 1}
pocet[zak1]:=0;						{títo sa u nemôu s nikím kamaráti}
pocet[zak2]:=0;
end;
until (pole[zak1][i3]=zak2) or (i2=pocet[i]);
until (pole[zak1][i3]=zak2) or (i1=pocet[i]-1);
end;
end;

writeln(tymy);
readln;
end.







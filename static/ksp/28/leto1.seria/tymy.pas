Meno: Michal Korbela
�kola: Gybmn�zium J.J. B�novce nad B. Radlinsk�ho 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
�loha �.4 - Zdrojak



program tymy1;
var
pole:array[1..100,1..3] of integer;
pocet:array[1..100] of integer;
tymy,k1,k2,i,i1,i2,i3,zak1,zak2,n,m:integer;



begin

readln(n,m);
for i:=1 to m do begin					{Na��tanie vstupu kamar�tstvo pripisujeme v�dy �iakovi ktor� m� men�ie ��slo}
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

tymy:=0;						{Zatia� m�me 0 t�mov}

for i:=1 to n-2 do begin 				{otestujeme v�etk�ch okrem posledn�ch 2 - t� n�m u� nepom��u, preto�e k tomu poterebujeme e�te 3.}
if pocet[i]>1 then begin				{Ak sa s n�m kamar�tia aspo� 2 za�neme inak nem� d�vod ho testova�}
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
until (pole[zak1][i3]=zak2) or (i3=pocet[zak1]);	{Ak sa maj� navz�jom kamar�ti� 2. sa mus� kamar�ti� s 3.}

if pole[zak1][i3]=zak2 then begin			{Vieme , �e 1. sa kamar�ti s 2. a 3. a druh� sa kamar�ti s 3. - vyhrali sme}
inc(tymy);						{zv��ime po�et t�mov o 1}
pocet[zak1]:=0;						{t�to sa u� nem��u s nik�m kamar�ti�}
pocet[zak2]:=0;
end;
until (pole[zak1][i3]=zak2) or (i2=pocet[i]);
until (pole[zak1][i3]=zak2) or (i1=pocet[i]-1);
end;
end;

writeln(tymy);
readln;
end.










program domino;

var
pole:array[1..7,1..7,1..2] of integer;
cisla: array[1..7] of integer;
a,b,i,pocet,x,i1,i2,error,i3 :integer;
fronta:array[1..100,1..2] of integer;

procedure testovanie(r,s :integer);
begin

for i:=1 to 7 do begin
if i<r then begin  			{Tu sa otestujú dominá s èíslom r na domine v riadku}
if (pole[r,i,1]>0) and (pole[r,i,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=r; fronta[i2,2]:=i;  end;
pole[r,i,2]:=1;
end
else begin 				{Tu sa otestujú dominá s èíslom r na domine v ståpci}
if (pole[i,r,1]>0) and (pole[i,r,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=i; fronta[i2,2]:=r;  end;
pole[i,r,2]:=1;
end;



if i<s then begin			{Tu sa otestujú dominá s èíslom s na domine v riadku}
if (pole[s,i,1]>0) and (pole[s,i,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=s; fronta[i2,2]:=i; end;
pole[s,i,2]:=1;
end
else begin				{Tu sa otestujú dominá s èíslom s na domine vståpci}
if (pole[i,s,1]>0) and (pole[i,s,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=i; fronta[i2,2]:=s; end;
pole[i,s,2]:=1;
end;
end;


end;
{----------------------------------------------------koniec procedury testovanie--------------------------}

procedure fronta1(); 			{z nájdenıch domín testujeme, èi sa pomocou nich vieme dosta k inım - pomocou nich pripoji iiné dominá k radu}
begin
i1:=0;{}
repeat
inc(i1);
until fronta[i1,1]<>0; 			{nájdeme vo fronte domino a testujeme}
testovanie(fronta[i1,1],fronta[i1,2]);
dec(i3);				{zniime poèet domín o 1 vo fronte - domino u bolo testované}
fronta[i1,1]:=0;			{vymaeme domino z fronty}
end;

{////////////////////////////////////////////////koniec procedur//////////////////////////////////////////////////////////}

begin
readln(pocet);
for i:=1 to pocet do begin						{nacitavanie vstupu}
readln (a,b);
if a<b then
inc(pole[b+1,a+1,1])							{Ak bude a<b tak zvıšime poèet v b riadku a a ståpci a ak nie tak v b ståpci a a riadku - samozrejme v nasledujúcich riadkoch musíme a aj b zvıši o 1 aby sme nešli mimo po¾a}
else
inc(pole[a+1,b+1,1]);
if a<>b then begin							{Iba ak to nebude špeciálne domino}
inc(cisla[a+1]);								
inc(cisla[b+1]);
end;
end;


for i:=1 to 7 do
x:=x+cisla[i] mod 2;							{testovanie poctu neparnych cisel}

if (not((x=0) or (x=2))) then error:=1					{rad musí ma buï 0 koncov, alebo 2,(0 koncov - je to kruh - dá sa hocikde rozpoji) - nemoe ma inı poèet koncov}
else begin




i:=0;
repeat									{najdenie zaciatku - nejakého domina, od ktorého budeme postupova ïalej}
inc(i);
i1:=0;
Repeat
inc(i1);
until (pole[i,i1,1]>0) or (i1=7);
until pole[i,i1,1]>0;



testovanie(i,i1);							{Prvı krát spustíme testovanie - aby fronta nebola prázna - ak existujú viac ako 0 domín}

repeat									{Potom sa bude opakova procedura fronta1 to¾ko, pokım nebudú otestované všetky nájdené dominá}
fronta1();
until i3=0;

for i:=1 to 7 do begin							{Otestuje sa èi sa vieme dosta ku kadému dominu}
for i1:=1 to 7 do begin
if (pole[i1,i,2]=0) and (pole[i1,i,1]>0) then begin error:=1;end;	{Ak nie nedájú sa dominá poklada - ptretoe sa nevieme ku niektorım dosta}

end;
end;
end;




if error=1 then writeln('Neda sa')
else begin								{vypisanie ci sa da alebo nie}
writeln('Da sa');							{Ak sa dá domino poklada - pokraèujeme}

if x=2 then begin							{Prípad, keï má rad zaèiatok a koniec}


i:=0;
repeat									{zistenie neparnych cisel}
inc(i);
until cisla[i] mod 2=1;
a:=i;									{Nájdeme èíslo, ktoré musí by na zaèiatku radu}
repeat
inc(i);
until cisla[i] mod 2=1;
b:=i;									{Nájdeme èíslo, ktoré má by na konci radu}


x:=a;									{x predstavuje èíslo, s ktorım sa budú h¾ada dominá - nastaví sa zaèiatok}
i1:=0;
repeat
inc(i1);
until ((pole[i1,b,1]>0) or (pole[b,i1,1]>0)) and (i1<>b);		{nájde sa koniec - domino ktoré má by na konci okrem špeciálneho - nejaké pred ním musí by}		
if b<i1 then dec(pole[i1,b,1])						{Zníi sa poèet tıch to domín - vymae sa toto domino zo zoznamu aby nebolo vypísané skôr ako má by - rad by sa ukonèil skôr}
else dec(pole[b,i1,1]);

end
else begin







i:=0;									{Ak rad nemá zaèiatok a koniec - nájde sa nejaké domino - prvé ktoré nám príde pod ruku}
repeat
inc(i);
i1:=0;
repeat
inc(i1);
until (pole[i,i1,1]>0) or (pole[i1,i,1]>0) or (i1=6);
until (pole[i,i1,1]>0) or (pole[i1,i,1]>0);
x:=i;
if cisla[1]+cisla[2]+cisla[3]+cisla[4]+cisla[5]+cisla[6]+cisla[7]=0		{Ak existujú len špeciálne domina - hneï sa vypíšu a nemusí zbehnu ani cyklus vıpisu}
then for i:=1 to pole[x,x,1] do write(x-1,x-1,' ');				{Vdy keï budeme nieèo vypisova musíme zo zníi o 1 keïe sme pri vstupe všetko zvıšili o 1}

end;


i3:=(cisla[1]+cisla[2]+cisla[3]+cisla[4]+cisla[5]+cisla[6]+cisla[7]) div 2;	{Keïe dominá obsahujú 2 èísla - tak div 2 - nerátajú sa tu špeciálne dominá}

for i:=1 to i3 do begin


if pole[x,x,1]>0 then begin						{Tu prebehne vıpis špeciálnych domín - ak existujú}
for i1:=1 to pole[x,x,1] do write(x-1,x-1,' ');
pole[x,x,1]:=0;
end;

i1:=0;									{Nájde sa domino ktoré obsahuje x, a pre ukonèenie repeatu som musel poi i1=6 - a to v tom prípade e domino sa nenájde
 - a to len v tom prípade keï bude vymazané - a to len keï bude danı koniec domina - znamená to, e sa vypíše posledné domino}
repeat
inc(i1);
until (pole[i1,x,1]>0) or (pole[x,i1,1]>0) or (i1=6);


if (i1=6) and (i=i3) then begin						{Ak sa má vypísa posledné domino -  vypíše sa tak, e bude urèite obsahova èíslo ktoré bolo na konci radu a èíslo b - èíslo ktorım sa má rad konèi}				
write(x-1,b-1,' ');
if pole[b,b,1]>0 then 							{Ak ešte existujú špeciálne dominá vypíšu sa - nedalo sa vypísa skôr}
for i1:=1 to pole[b,b,1] do write(b-1,b-1,' ');
end
else begin


write(x-1,i1-1,' ');							{Ak to nemá by posledné domino tak sa vypíše a znii sa poèet tıchto domín - vymae sa toto domino}
if x<i1 then dec(pole[i1,x,1])
else
dec(pole[x,i1,1]);
x:=i1;






end;
end;






end;
readln;

end.

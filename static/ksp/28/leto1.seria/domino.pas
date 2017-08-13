


program domino;

var
pole:array[1..7,1..7,1..2] of integer;
cisla: array[1..7] of integer;
a,b,i,pocet,x,i1,i2,error,i3 :integer;
fronta:array[1..100,1..2] of integer;

procedure testovanie(r,s :integer);
begin

for i:=1 to 7 do begin
if i<r then begin  			{Tu sa otestuj� domin� s ��slom r na domine v riadku}
if (pole[r,i,1]>0) and (pole[r,i,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=r; fronta[i2,2]:=i;  end;
pole[r,i,2]:=1;
end
else begin 				{Tu sa otestuj� domin� s ��slom r na domine v st�pci}
if (pole[i,r,1]>0) and (pole[i,r,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=i; fronta[i2,2]:=r;  end;
pole[i,r,2]:=1;
end;



if i<s then begin			{Tu sa otestuj� domin� s ��slom s na domine v riadku}
if (pole[s,i,1]>0) and (pole[s,i,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=s; fronta[i2,2]:=i; end;
pole[s,i,2]:=1;
end
else begin				{Tu sa otestuj� domin� s ��slom s na domine vst�pci}
if (pole[i,s,1]>0) and (pole[i,s,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=i; fronta[i2,2]:=s; end;
pole[i,s,2]:=1;
end;
end;


end;
{----------------------------------------------------koniec procedury testovanie--------------------------}

procedure fronta1(); 			{z n�jden�ch dom�n testujeme, �i sa pomocou nich vieme dosta� k in�m - pomocou nich pripoji� iin� domin� k radu}
begin
i1:=0;{}
repeat
inc(i1);
until fronta[i1,1]<>0; 			{n�jdeme vo fronte domino a testujeme}
testovanie(fronta[i1,1],fronta[i1,2]);
dec(i3);				{zni�ime po�et dom�n o 1 vo fronte - domino u� bolo testovan�}
fronta[i1,1]:=0;			{vyma�eme domino z fronty}
end;

{////////////////////////////////////////////////koniec procedur//////////////////////////////////////////////////////////}

begin
readln(pocet);
for i:=1 to pocet do begin						{nacitavanie vstupu}
readln (a,b);
if a<b then
inc(pole[b+1,a+1,1])							{Ak bude a<b tak zv��ime po�et v b riadku a a st�pci a ak nie tak v b st�pci a a riadku - samozrejme v nasleduj�cich riadkoch mus�me a aj b zv��i� o 1 aby sme ne�li mimo po�a}
else
inc(pole[a+1,b+1,1]);
if a<>b then begin							{Iba ak to nebude �peci�lne domino}
inc(cisla[a+1]);								
inc(cisla[b+1]);
end;
end;


for i:=1 to 7 do
x:=x+cisla[i] mod 2;							{testovanie poctu neparnych cisel}

if (not((x=0) or (x=2))) then error:=1					{rad mus� ma� bu� 0 koncov, alebo 2,(0 koncov - je to kruh - d� sa hocikde rozpoji�) - nemo�e ma� in� po�et koncov}
else begin




i:=0;
repeat									{najdenie zaciatku - nejak�ho domina, od ktor�ho budeme postupova� �alej}
inc(i);
i1:=0;
Repeat
inc(i1);
until (pole[i,i1,1]>0) or (i1=7);
until pole[i,i1,1]>0;



testovanie(i,i1);							{Prv� kr�t spust�me testovanie - aby fronta nebola pr�zna - ak existuj� viac ako 0 dom�n}

repeat									{Potom sa bude opakova� procedura fronta1 to�ko, pok�m nebud� otestovan� v�etky n�jden� domin�}
fronta1();
until i3=0;

for i:=1 to 7 do begin							{Otestuje sa �i sa vieme dosta� ku ka�d�mu dominu}
for i1:=1 to 7 do begin
if (pole[i1,i,2]=0) and (pole[i1,i,1]>0) then begin error:=1;end;	{Ak nie ned�j� sa domin� poklada� - ptreto�e sa nevieme ku niektor�m dosta�}

end;
end;
end;




if error=1 then writeln('Neda sa')
else begin								{vypisanie ci sa da alebo nie}
writeln('Da sa');							{Ak sa d� domino poklada� - pokra�ujeme}

if x=2 then begin							{Pr�pad, ke� m� rad za�iatok a koniec}


i:=0;
repeat									{zistenie neparnych cisel}
inc(i);
until cisla[i] mod 2=1;
a:=i;									{N�jdeme ��slo, ktor� mus� by� na za�iatku radu}
repeat
inc(i);
until cisla[i] mod 2=1;
b:=i;									{N�jdeme ��slo, ktor� m� by� na konci radu}


x:=a;									{x predstavuje ��slo, s ktor�m sa bud� h�ada� domin� - nastav� sa za�iatok}
i1:=0;
repeat
inc(i1);
until ((pole[i1,b,1]>0) or (pole[b,i1,1]>0)) and (i1<>b);		{n�jde sa koniec - domino ktor� m� by� na konci okrem �peci�lneho - nejak� pred n�m mus� by�}		
if b<i1 then dec(pole[i1,b,1])						{Zn�i sa po�et t�ch to dom�n - vyma�e sa toto domino zo zoznamu aby nebolo vyp�san� sk�r ako m� by� - rad by sa ukon�il sk�r}
else dec(pole[b,i1,1]);

end
else begin







i:=0;									{Ak rad nem� za�iatok a koniec - n�jde sa nejak� domino - prv� ktor� n�m pr�de pod ruku}
repeat
inc(i);
i1:=0;
repeat
inc(i1);
until (pole[i,i1,1]>0) or (pole[i1,i,1]>0) or (i1=6);
until (pole[i,i1,1]>0) or (pole[i1,i,1]>0);
x:=i;
if cisla[1]+cisla[2]+cisla[3]+cisla[4]+cisla[5]+cisla[6]+cisla[7]=0		{Ak existuj� len �peci�lne domina - hne� sa vyp�u a nemus� zbehnu� ani cyklus v�pisu}
then for i:=1 to pole[x,x,1] do write(x-1,x-1,' ');				{V�dy ke� budeme nie�o vypisova� mus�me zo zn�i� o 1 ke�e sme pri vstupe v�etko zv��ili o 1}

end;


i3:=(cisla[1]+cisla[2]+cisla[3]+cisla[4]+cisla[5]+cisla[6]+cisla[7]) div 2;	{Ke�e domin� obsahuj� 2 ��sla - tak div 2 - ner�taj� sa tu �peci�lne domin�}

for i:=1 to i3 do begin


if pole[x,x,1]>0 then begin						{Tu prebehne v�pis �peci�lnych dom�n - ak existuj�}
for i1:=1 to pole[x,x,1] do write(x-1,x-1,' ');
pole[x,x,1]:=0;
end;

i1:=0;									{N�jde sa domino ktor� obsahuje x, a pre ukon�enie repeatu som musel po�i� i1=6 - a to v tom pr�pade �e domino sa nen�jde
 - a to len v tom pr�pade ke� bude vymazan� - a to len ke� bude dan� koniec domina - znamen� to, �e sa vyp�e posledn� domino}
repeat
inc(i1);
until (pole[i1,x,1]>0) or (pole[x,i1,1]>0) or (i1=6);


if (i1=6) and (i=i3) then begin						{Ak sa m� vyp�sa� posledn� domino -  vyp�e sa tak, �e bude ur�ite obsahova� ��slo ktor� bolo na konci radu a ��slo b - ��slo ktor�m sa m� rad kon�i�}				
write(x-1,b-1,' ');
if pole[b,b,1]>0 then 							{Ak e�te existuj� �peci�lne domin� vyp�u sa - nedalo sa vyp�sa� sk�r}
for i1:=1 to pole[b,b,1] do write(b-1,b-1,' ');
end
else begin


write(x-1,i1-1,' ');							{Ak to nem� by� posledn� domino tak sa vyp�e a zni�i sa po�et t�chto dom�n - vyma�e sa toto domino}
if x<i1 then dec(pole[i1,x,1])
else
dec(pole[x,i1,1]);
x:=i1;






end;
end;






end;
readln;

end.

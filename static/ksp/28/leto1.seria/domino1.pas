var
a,b,i,pocet,x,kon,error,i1,i2:integer;
cisla:array[1..7,1..4] of integer;
pole:array[1..100,1..2] of integer;


begin

readln(pocet);
i1:=1;
for i:=1 to pocet do begin    				{nacitavanie vstupu}
readln(a,b);
if a=b then begin					{ak s� na karti�ke rovnak� ��sla je �pecia�lna - nie je poterebn� si ju zaznamen�va� - sta�� si zaznamena� len ich po�et}
cisla[a][2]:=cisla[a][2]+1;
end
else begin
cisla[a][1]:=cisla[a][1]+1;				{ak na karti�ke s� r�zne ��sla}
cisla[b][1]:=cisla[b][1]+1;
pole[i1][1]:=a;
pole[i1][2]:=b;						{��sla sa ulo�ia}
i1:=i1+1;
end;

end;
							{na��tavanie vstupu}

for i:=1 to 6 do begin
if cisla[i][1] mod 2 = 1 then begin kon:=kon+1;		{zistovanie �i je ��sel p�rny po�et ktor� m��e by� len 0 alebo 2}
cisla[i][3]:=1;end;
end;							





if (not((kon=0) or (kon=2))) then begin error:=1;  end	{ak nieje neparnych cisel 0 alebo 2 - neda sa}

else begin
if (cisla[1][1]>0) or (cisla[2][1]>0) or (cisla[3][1]>0) or (cisla[4][1]>0) or (cisla[5][1]>0) or (cisla[6][1]>0) then begin  {potom sa testuje ci existuje aspon 1 domino ktore obsahuje rozne cisla} 

cisla[1][4]:=pole[1][1];  {ak existuje take domino ktore ma 2 rozne cisla potom sa bude nachadzat aspon 1 domino v zozname a budeme vychadzat  z prveho domina a testovat, ci sa od neho da dostat k ostatnym}
cisla[2][4]:=pole[1][2];
for i:=3 to 6 do begin    {tento cyklus zbehne 4 kr�t preto, lebo sa vieme dosta� u� k 2 (ke�e existuje tak� karti�ka ktor� obsahuje 2 r�zne ��sla) a mus�me sa dosta� u� len k ostatn�m 4(ak existuj�)}
i1:=0;
repeat
i1:=i1+1;
until (((pole[i1][1]=cisla[1][4]) or (pole[i1][1]=cisla[2][4]) or (pole[i1][1]=cisla[3][4]) or (pole[i1][1]=cisla[4][4]) or (pole[i1][1]=cisla[5][4]))
 and ((pole[i1][2]<>cisla[1][4]) and (pole[i1][2]<>cisla[2][4]) and (pole[i1][2]<>cisla[3][4]) and (pole[i1][2]<>cisla[4][4]) and (pole[i1][2]<>cisla[5][4]))) or
(((pole[i1][2]=cisla[1][4]) or (pole[i1][2]=cisla[2][4]) or (pole[i1][2]=cisla[3][4]) or (pole[i1][2]=cisla[4][4]) or (pole[i1][2]=cisla[5][4])) and
((pole[i1][1]<>cisla[1][4]) and (pole[i1][1]<>cisla[2][4]) and (pole[i1][1]<>cisla[3][4]) and (pole[i1][1]<>cisla[4][4]) and (pole[i1][1]<>cisla[5][4]))) or (i1>pocet);

{uf tro�ku zlo�itej�ia podmienka, ale zahr�a to, cyklus repeat p�jde to�ko, pok�m sa nen�jde tak� domino, ktor�ho pr�ve 1 ��slo u� bude v zozname ��sel
 ku ktor�m sa u� vieme dosta�, a s��asne druh� ��slo na karti�ke sa v zozname nach�dza� nebude}






if ((pole[i1][1]=cisla[1][4]) or (pole[i1][1]=cisla[2][4]) or (pole[i1][1]=cisla[3][4]) or (pole[i1][1]=cisla[4][4]) or (pole[i1][1]=cisla[5][4])) and (i1<=pocet) then cisla[i][4]:=pole[i1][2]
else if i1<=pocet then cisla[i][4]:=pole[i1][1];
end;

{zistenie �i sa ��slo ktor� sa nach�dza v tabu�ke nach�dza na pravej, alebo �avej strane domina}





for i:=1 to 6 do begin {zistenie, �i sa vieme dosta� ku ka�d�mu ��slu}
i1:=0;
if cisla[i][1]>0 then begin
repeat
i1:=i1+1;
until (cisla[i1][4]=i) or (i1>6);
if i1>6 then error:=1;
end;
end;
for i:=1 to 6 do 
if (cisla[i][1]=0) and (cisla[i][2]>0) then error:=1; {ak bude existova� tak� karti�ka, na ktor�j bud� 2 rovnak� ��sla, ale nebude existova� �iadna tak� karti�ka, na ktor� by ho sp�jala s ostatn�mi 
tj. nebude tak� karti�ka ktor� bude obsahova� ��slo ktor� sa nach�dza na karti�ke ktor� obsahuje 2 rovnak� ��sla a druh� na karti�ke bude in� ��slo(vieme sa pomocou tejto karti�ky dosta� ku karti�ke,
 ktor� obsahuje 2 rovnak� ��sla)}


end
else begin




i1:=0;
for i:=1 to 6 do {pokra�uje ak neexistuje �iadne tak� domino, ktor� by obsahovalo 2 r�zne ��sla, a ak sa vyskytuj� aspo� 2 domin� ktor� obsahuj� 2 rovnak� ��sla, ale tieto karti�ky nie s� rovnak�
 napr. 3 a 3, 5 a 5 - potom nie je mo�n� pouklada� rad, preto�e ich nem�me ako spoji�}

if cisla[i][2]>0 then i1:=i1+1;
if i1>1 then error:=1
else begin
i:=0;
repeat
i:=i+1;
until cisla[i][2]>0;
x:=i;
end;
end;
end;


if error=1 then writeln('Neda sa') 			{vyp�sanie �i sa d�j� zadan� domin� pouklada� alebo nie}
else begin writeln('Da sa');


if kon=2 then begin					{ak sa daj� domin� pouklada�, existuj� e�te 2 pr�pady 1. ak rad nem� za�iatok a koniec tj. prv� karti�ka sa bude v�dy rovna�
							 poslednej( to je v�dy vtedy, ke� ka�d�ho ��sla je p�rny po�et) a pr�pad ke� existuje za�iatok a koniec (ke� je pr�ve 2 ��sle nep�rny po�et)}
i:=0;							{teraz rozoberieme ke� existuje za�iatok a koniec}
repeat
i:=i+1;
until cisla[i][3]=1;					{n�jdeme si tieto ��sla a zap�eme do a a b}
a:=i;
repeat
i:=i+1;
until cisla[i][3]=1;
b:=i;




i:=0;
repeat
i:=i+1;
until (pole[i][1]=b) or (pole[i][2]=b);
pole[pocet+1][1]:=pole[i][1];
pole[pocet+1][2]:=pole[i][2];
pole[i][2]:=0;						{oznacenie konca - karti�ku z ��slom ktor� m� by� na konci presunieme na koniec, aby nebola sk�r vyp�san� ako m� by�}
pole[i][1]:=0;





if cisla[a][2]>0 then						{vypisanie prveho domina}
for i:=1 to cisla[a][2] do write(a,'',a,' ');			{najsk�r treba vyp�sa� domin� ktor� obsahuj� rovnak� karti�ky,
								 a� potom karti�ku ktor� zmen� ��slo, preto�e k tomu ��slu sa u� nemus�me dosta�}
cisla[a][2]:=0;							{potom vyp�eme zas domin� s rovnak�mi ��slami zmenen�ho ��sla}
i:=0;								{posledn� ��slo v rade si ozna�ujeme x}
repeat
i:=i+1;
until (pole[i][1]=a) or (pole[i][2]=a);
if pole[i][1]=a then begin
write(pole[i][1],'',pole[i][2],' ');
x:=pole[i][2];
end
else begin
write(pole[i][2],'',pole[i][1],' ');
x:=pole[i][1];
end;
pole[i][1]:=0;							{ak je karti�ka pou�it� - zma�e sa}
pole[i][2]:=0;

if cisla[x][2]>0 then
for i2:=1 to cisla[x][2] do
write(x,'',x,' ');
cisla[x][2]:=0;
end;


							

if x=0  then begin
x:=pole[1][1];
end;							{ak nie je udany zaciatok (kon=0) zist� sa ktor�m ��slom m��e za�a� definuje sa x}


if kon=2 then
a:=(cisla[1][1]+cisla[2][1]+cisla[3][1]+cisla[4][1]+cisla[5][1]+cisla[6][1]) div 2 -1 {ak existuje za�iatok bolo u� vyp�san� jedno domino}

else
a:=(cisla[1][1]+cisla[2][1]+cisla[3][1]+cisla[4][1]+cisla[5][1]+cisla[6][1]) div 2 ;



for i:=1 to a do begin 					{v�pis karti�iek}



i1:=0;
repeat
i1:=i1+1;
until (pole[i1][1]=x) or (pole[i1][2]=x);		{h�ad� sa karti�ka ktor� bude obsahova� ��slo x  - ��slo na konci radu}
if pole[i1][1]=x then begin
write(pole[i1][1],'',pole[i1][2],' ');     		{zist� sa �i je na pravej alebo �avej strane karti�ky a ��slo sa vyp�e}
x:=pole[i1][2];
end
else begin	
write(pole[i1][2],'',pole[i1][1],' ');
x:=pole[i1][1];
end;
pole[i1][1]:=0;	
pole[i1][2]:=0;						{karti�ka sa zma�e}

if cisla[x][2]>0 then 					{vyp�u sa karti�ky ktor� obsahuj� rovnak� ��sla}
for i2:=1 to cisla[x][2] do
write(x,'',x,' ');
cisla[x][2]:=0;
end;


if cisla[x][2]>0 then					{ak existuj� len karti�ky s rovnak�mi ��slami, tak sa vzp�u}
for i2:=1 to cisla[x][2] do
write(x,'',x,' ');
cisla[x][2]:=0;	






end;









readln;
end.


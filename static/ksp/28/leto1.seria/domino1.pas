var
a,b,i,pocet,x,kon,error,i1,i2:integer;
cisla:array[1..7,1..4] of integer;
pole:array[1..100,1..2] of integer;


begin

readln(pocet);
i1:=1;
for i:=1 to pocet do begin    				{nacitavanie vstupu}
readln(a,b);
if a=b then begin					{ak sú na kartièke rovnaké èísla je špeciaálna - nie je poterebné si ju zaznamenáva - staèí si zaznamena len ich poèet}
cisla[a][2]:=cisla[a][2]+1;
end
else begin
cisla[a][1]:=cisla[a][1]+1;				{ak na kartièke sú rôzne èísla}
cisla[b][1]:=cisla[b][1]+1;
pole[i1][1]:=a;
pole[i1][2]:=b;						{èísla sa uloia}
i1:=i1+1;
end;

end;
							{naèítavanie vstupu}

for i:=1 to 6 do begin
if cisla[i][1] mod 2 = 1 then begin kon:=kon+1;		{zistovanie èi je èísel párny poèet ktorı môe by len 0 alebo 2}
cisla[i][3]:=1;end;
end;							





if (not((kon=0) or (kon=2))) then begin error:=1;  end	{ak nieje neparnych cisel 0 alebo 2 - neda sa}

else begin
if (cisla[1][1]>0) or (cisla[2][1]>0) or (cisla[3][1]>0) or (cisla[4][1]>0) or (cisla[5][1]>0) or (cisla[6][1]>0) then begin  {potom sa testuje ci existuje aspon 1 domino ktore obsahuje rozne cisla} 

cisla[1][4]:=pole[1][1];  {ak existuje take domino ktore ma 2 rozne cisla potom sa bude nachadzat aspon 1 domino v zozname a budeme vychadzat  z prveho domina a testovat, ci sa od neho da dostat k ostatnym}
cisla[2][4]:=pole[1][2];
for i:=3 to 6 do begin    {tento cyklus zbehne 4 krát preto, lebo sa vieme dosta u k 2 (keïe existuje taká kartièka ktorá obsahuje 2 rôzne èísla) a musíme sa dosta u len k ostatnım 4(ak existujú)}
i1:=0;
repeat
i1:=i1+1;
until (((pole[i1][1]=cisla[1][4]) or (pole[i1][1]=cisla[2][4]) or (pole[i1][1]=cisla[3][4]) or (pole[i1][1]=cisla[4][4]) or (pole[i1][1]=cisla[5][4]))
 and ((pole[i1][2]<>cisla[1][4]) and (pole[i1][2]<>cisla[2][4]) and (pole[i1][2]<>cisla[3][4]) and (pole[i1][2]<>cisla[4][4]) and (pole[i1][2]<>cisla[5][4]))) or
(((pole[i1][2]=cisla[1][4]) or (pole[i1][2]=cisla[2][4]) or (pole[i1][2]=cisla[3][4]) or (pole[i1][2]=cisla[4][4]) or (pole[i1][2]=cisla[5][4])) and
((pole[i1][1]<>cisla[1][4]) and (pole[i1][1]<>cisla[2][4]) and (pole[i1][1]<>cisla[3][4]) and (pole[i1][1]<>cisla[4][4]) and (pole[i1][1]<>cisla[5][4]))) or (i1>pocet);

{uf trošku zloitejšia podmienka, ale zahròa to, cyklus repeat pôjde to¾ko, pokım sa nenájde také domino, ktorého práve 1 èíslo u bude v zozname èísel
 ku ktorım sa u vieme dosta, a súèasne druhé èíslo na kartièke sa v zozname nachádza nebude}






if ((pole[i1][1]=cisla[1][4]) or (pole[i1][1]=cisla[2][4]) or (pole[i1][1]=cisla[3][4]) or (pole[i1][1]=cisla[4][4]) or (pole[i1][1]=cisla[5][4])) and (i1<=pocet) then cisla[i][4]:=pole[i1][2]
else if i1<=pocet then cisla[i][4]:=pole[i1][1];
end;

{zistenie èi sa èíslo ktoré sa nachádza v tabu¾ke nachádza na pravej, alebo ¾avej strane domina}





for i:=1 to 6 do begin {zistenie, èi sa vieme dosta ku kadému èíslu}
i1:=0;
if cisla[i][1]>0 then begin
repeat
i1:=i1+1;
until (cisla[i1][4]=i) or (i1>6);
if i1>6 then error:=1;
end;
end;
for i:=1 to 6 do 
if (cisla[i][1]=0) and (cisla[i][2]>0) then error:=1; {ak bude existova taká kartièka, na ktoréj budú 2 rovnaké èísla, ale nebude existova iadna taká kartièka, na ktorá by ho spájala s ostatnımi 
tj. nebude taká kartièka ktorá bude obsahova èíslo ktoré sa nachádza na kartièke ktorá obsahuje 2 rovnaké èísla a druhá na kartièke bude iné èíslo(vieme sa pomocou tejto kartièky dosta ku kartièke,
 ktorá obsahuje 2 rovnaké èísla)}


end
else begin




i1:=0;
for i:=1 to 6 do {pokraèuje ak neexistuje iadne také domino, ktoré by obsahovalo 2 rôzne èísla, a ak sa vyskytujú aspoò 2 dominá ktoré obsahujú 2 rovnaké èísla, ale tieto kartièky nie sú rovnaké
 napr. 3 a 3, 5 a 5 - potom nie je moné pouklada rad, pretoe ich nemáme ako spoji}

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


if error=1 then writeln('Neda sa') 			{vypísanie èi sa dájú zadané dominá pouklada alebo nie}
else begin writeln('Da sa');


if kon=2 then begin					{ak sa dajú dominá pouklada, existujú ešte 2 prípady 1. ak rad nemá zaèiatok a koniec tj. prvá kartièka sa bude vdy rovna
							 poslednej( to je vdy vtedy, keï kadého èísla je párny poèet) a prípad keï existuje zaèiatok a koniec (keï je práve 2 èísle nepárny poèet)}
i:=0;							{teraz rozoberieme keï existuje zaèiatok a koniec}
repeat
i:=i+1;
until cisla[i][3]=1;					{nájdeme si tieto èísla a zapíšeme do a a b}
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
pole[i][2]:=0;						{oznacenie konca - kartièku z èíslom ktoré má by na konci presunieme na koniec, aby nebola skôr vypísaná ako má by}
pole[i][1]:=0;





if cisla[a][2]>0 then						{vypisanie prveho domina}
for i:=1 to cisla[a][2] do write(a,'',a,' ');			{najskôr treba vypísa dominá ktoré obsahujú rovnaké kartièky,
								 a potom kartièku ktorá zmení èíslo, pretoe k tomu èíslu sa u nemusíme dosta}
cisla[a][2]:=0;							{potom vypíšeme zas dominá s rovnakımi èíslami zmeneného èísla}
i:=0;								{posledné èíslo v rade si oznaèujeme x}
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
pole[i][1]:=0;							{ak je kartièka pouitá - zmae sa}
pole[i][2]:=0;

if cisla[x][2]>0 then
for i2:=1 to cisla[x][2] do
write(x,'',x,' ');
cisla[x][2]:=0;
end;


							

if x=0  then begin
x:=pole[1][1];
end;							{ak nie je udany zaciatok (kon=0) zistí sa ktorım èíslom môe zaèa definuje sa x}


if kon=2 then
a:=(cisla[1][1]+cisla[2][1]+cisla[3][1]+cisla[4][1]+cisla[5][1]+cisla[6][1]) div 2 -1 {ak existuje zaèiatok bolo u vypísané jedno domino}

else
a:=(cisla[1][1]+cisla[2][1]+cisla[3][1]+cisla[4][1]+cisla[5][1]+cisla[6][1]) div 2 ;



for i:=1 to a do begin 					{vıpis kartièiek}



i1:=0;
repeat
i1:=i1+1;
until (pole[i1][1]=x) or (pole[i1][2]=x);		{h¾adá sa kartièka ktorá bude obsahova èíslo x  - èíslo na konci radu}
if pole[i1][1]=x then begin
write(pole[i1][1],'',pole[i1][2],' ');     		{zistí sa èi je na pravej alebo ¾avej strane kartièky a èíslo sa vypíše}
x:=pole[i1][2];
end
else begin	
write(pole[i1][2],'',pole[i1][1],' ');
x:=pole[i1][1];
end;
pole[i1][1]:=0;	
pole[i1][2]:=0;						{kartièka sa zmae}

if cisla[x][2]>0 then 					{vypíšu sa kartièky ktoré obsahujú rovnaké èísla}
for i2:=1 to cisla[x][2] do
write(x,'',x,' ');
cisla[x][2]:=0;
end;


if cisla[x][2]>0 then					{ak existujú len kartièky s rovnakımi èíslami, tak sa vzpíšu}
for i2:=1 to cisla[x][2] do
write(x,'',x,' ');
cisla[x][2]:=0;	






end;









readln;
end.


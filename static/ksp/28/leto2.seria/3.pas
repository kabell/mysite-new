Meno: Michal Korbela
Škola: Gybmnázium J.J. Bánovce nad B. Radlinského 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
Úloha è.3 - Kód


program kombinacie;

var pole:array[1..1000] of longint;
s: array[1..1000] of longint;
i,i1,i2,x,y,n,konec,temp,max,obsadene,error,jednotky: longint;
ok,cont:boolean;


procedure kombinacie(konec:longint); {funkcia, ktorá vracia kombinácie,
 funguje na princípe n-kovej sústavy, kde n je poèet prvkov a od prvkov v kombinácii závisí poèet
 cifier tohoto èísla }
begin

i2:=0;
repeat
inc(i2);

for i:=1 to i2-1 do
s[i]:=i;
if i2=0 then
s[1]:=0
else
s[i+1]:=i;
repeat

i:=i2;

ok:=false;
	repeat

	if s[i]=n-i2+i then
	dec(i)


	else begin
	inc(s[i]);
	x:=1;
	for i1:=i+1 to i2 do begin
	s[i1]:=s[i]+x;
	inc(x);


end;
	ok:=true;
	end;


until ok=true;
temp:=0;

for i1:=1 to i2 do begin
temp:=temp+pole[s[i1]];{spoèítajú sa prvky kombinácie}
end;
y:=i2;

if temp=konec then cont:=true;{a ak vyhovujú požiadavkam, tak sa cyklus ukonèí}


until (s[1]=n-i2+1) or (temp=konec);
until (i2=n) or (temp=konec);
end;

begin
readln(n);{naèítanie vstupu}

for i:=1 to n do
read(pole[i]);


readln(max);

repeat
for i:=1 to n do
s[i]:=0;
kombinacie(obsadene+max-error);{error má hodnotu takú, ktorá vyjadruje, o ko¾ko sa má dané èíslo zmenši - ak sa nenájde maximálne, tak sa bude h¾ada o jedno menšie, ak sa nenájde, tak...}
if cont=true then begin
obsadene:=obsadene+max-error;
cont:=false;
error:=0;
if y>jednotky then jednotky:=y;
end
else begin
inc(error);
end;


until error=max;{ak sa nenašla žiadna kombinácia, ktorá by mala súèet prvkov meší ako predchádzajúca + max, tak sme skonèili}
writeln(jednotky);{výstup}








readln;
end.
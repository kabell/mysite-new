Meno: Michal Korbela
�kola: Gybmn�zium J.J. B�novce nad B. Radlinsk�ho 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
�loha �.3 - K�d


program kombinacie;

var pole:array[1..1000] of longint;
s: array[1..1000] of longint;
i,i1,i2,x,y,n,konec,temp,max,obsadene,error,jednotky: longint;
ok,cont:boolean;


procedure kombinacie(konec:longint); {funkcia, ktor� vracia kombin�cie,
 funguje na princ�pe n-kovej s�stavy, kde n je po�et prvkov a od prvkov v kombin�cii z�vis� po�et
 cifier tohoto ��sla }
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
temp:=temp+pole[s[i1]];{spo��taj� sa prvky kombin�cie}
end;
y:=i2;

if temp=konec then cont:=true;{a ak vyhovuj� po�iadavkam, tak sa cyklus ukon��}


until (s[1]=n-i2+1) or (temp=konec);
until (i2=n) or (temp=konec);
end;

begin
readln(n);{na��tanie vstupu}

for i:=1 to n do
read(pole[i]);


readln(max);

repeat
for i:=1 to n do
s[i]:=0;
kombinacie(obsadene+max-error);{error m� hodnotu tak�, ktor� vyjadruje, o ko�ko sa m� dan� ��slo zmen�i� - ak sa nen�jde maxim�lne, tak sa bude h�ada� o jedno men�ie, ak sa nen�jde, tak...}
if cont=true then begin
obsadene:=obsadene+max-error;
cont:=false;
error:=0;
if y>jednotky then jednotky:=y;
end
else begin
inc(error);
end;


until error=max;{ak sa nena�la �iadna kombin�cia, ktor� by mala s��et prvkov me�� ako predch�dzaj�ca + max, tak sme skon�ili}
writeln(jednotky);{v�stup}








readln;
end.
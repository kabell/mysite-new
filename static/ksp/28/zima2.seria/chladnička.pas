meno: Michal Korbela
�kola: gymn�zium J.J B�novce nad Bebravou
trieda: kvinta
Pr�klad �.5


program chladnicka;
uses crt;

var
rad: array[1..1000] of byte;
a,b,c,pocet,i,tah,temp,x : integer;


begin
clrscr;
writeln('zadajte pocet: ');
readln(pocet);
a:=0;
b:=0;
c:=0;
writeln('zadajte cisla: ');

for i:=1 to pocet do begin {na��tavanie vstupov a zaznamenanie po�tov 1, 2, 3}
read(rad[i]);
if rad[i]=1 then a:=a+1
else
	if rad[i]=2 then b:=b+1
	else c:=c+1;
end;

readln;
if a >= 1 then begin {Ak existuje aspo� jedna 1}
for i:=1 to a do begin

if rad[i]=2 then begin {Ak je namiesto 1 dvojka}
x:=a;{h�ad� sa medzi 2 a potom medzi 3}

repeat
x:=x+1;
until rad[x]=1;
writeln(i,' ',x);
rad[x]:=2;{n�jden� jednotka sa prep�e 2}


end;
end;

if rad[i]=3 then begin {Ak je namiesto 1 trojka}
x:=a+b;{H�ad� sa najsk�r medzi 3}
repeat
x:=x+1;
until (rad[x]=1) or (x=pocet);
if not(x=pocet) or ((x=pocet) and (rad[pocet]=1)) then begin
writeln(i,' ',x);
rad[x]:=3;
end
else begin
x:=a;{A� potom medzi 2}
repeat
x:=x+1;
until (rad[x]=1) or (x=pocet);
writeln(i,' ',x);
rad[x]:=3;
end;
end;
end;


if b >= 1 then begin {Ak existuje aspo� jedna 2}
for i:=a+1 to b+a do begin {H�adaj� sa 3 ktor� s� namiesto 2}
if rad[i]=3 then begin
x:=a+b;
repeat
x:=x+1;
until rad[x]=2;
writeln(i,' ',x);
rad[x]:=3;
end;
end;
end;
readln;
end.



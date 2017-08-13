program domino;

var
pole:array[1..6,1..6,1..2] of integer;
cisla: array[1..6] of integer;
a,b,i,pocet,x,i1,i2,error,i3 :integer;
fronta:array[1..100,1..2] of integer;

procedure testovanie(r,s :integer);
begin

for i:=1 to 6 do begin
if i<r then begin
if (pole[r,i,1]>0) and (pole[r,i,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=r; fronta[i2,2]:=i;  end;
pole[r,i,2]:=1;
end
else begin 
if (pole[i,r,1]>0) and (pole[i,r,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=i; fronta[i2,2]:=r;  end;
pole[i,r,2]:=1;
end;

if i<s then begin
if (pole[s,i,1]>0) and (pole[s,i,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=s; fronta[i2,2]:=i; end;
pole[s,i,2]:=1;
end
else begin

if (pole[i,s,1]>0) and (pole[i,s,2]=0) then begin inc(i2); inc(i3); fronta[i2,1]:=i; fronta[i2,2]:=s; end;
pole[i,s,2]:=1;
end;
end;


















end;


procedure fronta1();
begin
i1:=0;
repeat
inc(i1);
until fronta[i1,1]<>0;
testovanie(fronta[i1,1],fronta[i1,2]);
dec(i3);
fronta[i1,1]:=0;
end;

{////////////////////////////////////////////////koniec procedur//////////////////////////////////////////////////////////}

begin
readln(pocet);
for i:=1 to pocet do begin						{nacitavanie vstupu}
readln (a,b);
if a<b then
inc(pole[b,a,1])
else
inc(pole[a,b,1]);
if a<>b then begin
inc(cisla[a]);
inc(cisla[b]);
end;
end;


for i:=1 to 6 do
x:=x+cisla[i] mod 2;							{testovanie poctu neparnych cisel}

if (not((x=0) or (x=2))) then error:=1
else begin


i:=0;
repeat									{najdenie zaciatku}
inc(i);
i1:=0;
Repeat
inc(i1);
until (pole[i,i1,1]>0) or (i1=6);
until pole[i,i1,1]>0;



testovanie(i,i1);

repeat
fronta1();
until i3=0;

for i:=1 to 6 do begin
for i1:=1 to 6 do begin
if (pole[i1,i,2]=0) and (pole[i1,i,1]>0) then begin error:=1;end;

end;
end;
end;




if error=1 then writeln('Neda sa')
else begin								{vypisanie ci sa da alebo ne}
writeln('Da sa');

if x=2 then begin


i:=0;
repeat									{zistenie neparnych cisel}
inc(i);
until cisla[i] mod 2=1;
a:=i;
repeat
inc(i);
until cisla[i] mod 2=1;
b:=i;


x:=a;
i1:=0;
repeat
inc(i1);
until ((pole[i1,b,1]>0) or (pole[b,i1,1]>0)) and (i1<>b);
if b<i1 then dec(pole[i1,b,1])
else dec(pole[b,i1,1]);

end
else begin







i:=0;
repeat
inc(i);
i1:=0;
repeat
inc(i1);
until (pole[i,i1,1]>0) or (pole[i1,i,1]>0) or (i1=6);
until (pole[i,i1,1]>0) or (pole[i1,i,1]>0);
x:=i;
if cisla[1]+cisla[2]+cisla[3]+cisla[4]+cisla[5]+cisla[6]=0
then for i:=1 to pole[x,x,1] do write(x,x,' ');

end;


i3:=(cisla[1]+cisla[2]+cisla[3]+cisla[4]+cisla[5]+cisla[6]) div 2;

for i:=1 to i3 do begin


if pole[x,x,1]>0 then begin
for i1:=1 to pole[x,x,1] do write(x,x,' ');
pole[x,x,1]:=0;
end;

i1:=0;
repeat
inc(i1);
until (pole[i1,x,1]>0) or (pole[x,i1,1]>0) or (i1=6);


if (i1=6) and (i=i3) then begin
write(x,b,' ');
if pole[b,b,1]>0 then 
for i1:=1 to pole[b,b,1] do write(b,b,' ');
end
else begin


write(x,i1,' ');
if x<i1 then dec(pole[i1,x,1])
else
dec(pole[x,i1,1]);
x:=i1;






end;
end;






end;
readln;

end.

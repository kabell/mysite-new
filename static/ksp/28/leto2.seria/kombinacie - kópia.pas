program kombinacie;

var pole:array[1..1000] of longint;
s: array[1..1000] of longint;
i,i1,i2,x,y,n,konec,temp,max,obsadene,error: longint;
ok,cont:boolean;


begin
readln(n);
i2:=0;
repeat
inc(i2);

for i:=1 to i2-1 do
s[i]:=i;
if i2=0 then
s[1]:=1
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
write(s[i1],' ');

end;
writeln;


until s[1]=n-i2+1;
until i2=n;



for i:=1 to n do
s[i]:=0;




i2:=0;
repeat
inc(i2);

for i:=1 to i2-1 do
s[i]:=i;
if i2=0 then
s[1]:=1
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
write(s[i1],' ');

end;
writeln;


until s[1]=n-i2+1;
until i2=n;
readln;
end.
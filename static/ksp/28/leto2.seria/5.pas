program mena;

var kurz: array[1..100,1..4] of string;
per: array[1..100] of real;
i,x,m,pos1 :longint;
urok: real;
l,z: string;

begin
readln(l);
pos1 := Pos('%',l);
z := copy(l, 11, pos1-1);
val(Z, urok,m);


kurz[1,1]:='02.03.2009';
kurz[1,2]:='EUR USD';
kurz[1,3]:='30.11.2009';
kurz[1,4]:='USD EUR';
per[1]:=14.36;
x:=10000;

i:=1;
if per[i]>urok then begin
writeln('day ',kurz[i,1]);
writeln('transfer all ',kurz[i,2]);
writeln('day ',kurz[i,3]);
writeln('transfer all ',kurz[i,4]);
end;
readln;
end.
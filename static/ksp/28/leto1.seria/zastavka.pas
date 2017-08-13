program zastavka;

var
zastavky:array[1..10000002] of longint;
i,n,d,hranica,zas,pocet :longint;



begin


readln(n,d);


for i:=1 to n do begin
read(zas);
if zas>hranica then begin
hranica:=zas+(2*d);
pocet:=pocet+1;
zastavky[pocet]:=zas+d;
end;
end;

readln;





writeln(pocet);
for i:=1 to pocet-1 do write(zastavky[i],' ');
writeln(zastavky[pocet]);

end.




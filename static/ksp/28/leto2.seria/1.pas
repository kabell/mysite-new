Meno: Michal Korbela
�kola: Gybmn�zium J.J. B�novce nad B. Radlinsk�ho 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
�loha �.1 - K�d


program vlasy;

var x,n,d,i,naj:integer;

begin
readln(n);{na��tanie vstupu}
for i:=1 to n do begin
readln(x);
if x>0 then{ ak niekto pri�iel zv��� sa rad}
inc(d)
else dec(d);{ ak niekto i�iel dnu, tak sa otestuje, �i aktu�lny rad je v��� ako predch�dzaj�ci}
if d>naj then naj:=d;
end;
if d>naj then writeln(d) else writeln(naj);{ak v�ak nikoho nezavol� dnu, tak treba cyp�sa� aktu�lny rad}
readln;
end.


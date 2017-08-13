Meno: Michal Korbela
Škola: Gybmnázium J.J. Bánovce nad B. Radlinského 665/2, 95701
Adresa domov: Brezolupy 160, 95701
Trieda: kvinta
Úloha è.1 - Kód


program vlasy;

var x,n,d,i,naj:integer;

begin
readln(n);{naèítanie vstupu}
for i:=1 to n do begin
readln(x);
if x>0 then{ ak niekto prišiel zväèší sa rad}
inc(d)
else dec(d);{ ak niekto išiel dnu, tak sa otestuje, èi aktuálny rad je väèší ako predchádzajúci}
if d>naj then naj:=d;
end;
if d>naj then writeln(d) else writeln(naj);{ak však nikoho nezavolá dnu, tak treba cypísa aktuálny rad}
readln;
end.


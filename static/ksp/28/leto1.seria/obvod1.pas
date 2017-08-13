program obvod;

var pole:array[1..202,1..202] of string;

poz:array[1..2] of integer;
poz1:array[1..2] of integer;

start:array[1..2] of integer;
s,v: string;
x,y,i,i1,z,z1,t: integer;

procedure posun();
begin

if z1=1 then begin
if v='hore' then begin

if pole[poz[1]-3][poz[2]]='|' then begin v:='dole'; pole[poz[1]-3][poz[2]]:='.'; poz[1]:=poz[1]-3; end
else if pole[poz[1]-3][poz[2]]='+' then begin v:='vodo'; pole[poz[1]-3][poz[2]]:='.'; poz[1]:=poz[1]-3; end
else if pole[poz[1]-3][poz[2]]='o' then begin v:='dole'; pole[poz[1]-3][poz[2]]:='.'; poz[1]:=poz[1]-3; t:=1; end
else if pole[poz[1]-3][poz[2]]='V' then begin v:='dole'; pole[poz[1]-3][poz[2]]:='.'; poz[1]:=poz[1]-3; end
else if pole[poz[1]-3][poz[2]]='.' then begin v:='error'; end;
end

else if v='dole' then begin

if pole[poz[1]+3][poz[2]]='|' then begin v:='dole'; pole[poz[1]+3][poz[2]]:='.'; poz[1]:=poz[1]+3; end
else if pole[poz[1]+3][poz[2]]='+' then begin v:='vodo'; pole[poz[1]+3][poz[2]]:='.'; poz[1]:=poz[1]+3; end
else if pole[poz[1]+3][poz[2]]='o' then begin v:='dole'; pole[poz[1]+3][poz[2]]:='.'; poz[1]:=poz[1]+3; t:=1; end
else if pole[poz[1]+3][poz[2]]='^' then begin v:='dole'; pole[poz[1]+3][poz[2]]:='.'; poz[1]:=poz[1]+3; end
else if pole[poz[1]+3][poz[2]]='.' then begin v:='error'; end;
end

else if v='lavo' then begin

if pole[poz[1]][poz[2]-3]='-' then begin v:='lavo'; pole[poz[1]][poz[2]-3]:='.'; poz[2]:=poz[2]-3; end
else if pole[poz[1]][poz[2]-3]='+' then begin v:='zvis'; pole[poz[1]][poz[2]-3]:='.'; poz[2]:=poz[2]-3; end
else if pole[poz[1]][poz[2]-3]='o' then begin v:='lavo'; pole[poz[1]][poz[2]-3]:='.'; poz[2]:=poz[2]-3; t:=1; end
else if pole[poz[1]][poz[2]-3]='>' then begin v:='lavo'; pole[poz[1]][poz[2]-3]:='.'; poz[2]:=poz[2]-3; end
else if pole[poz[1]][poz[2]-3]='.' then begin v:='error'; end;
end

else if v='pravo' then begin

if pole[poz[1]][poz[2]+3]='-' then begin v:='lavo'; pole[poz[1]][poz[2]+3]:='.'; poz[2]:=poz[2]+3; end
else if pole[poz[1]][poz[2]+3]='+' then begin v:='zvis'; pole[poz[1]][poz[2]+3]:='.'; poz[2]:=poz[2]+3; end
else if pole[poz[1]][poz[2]+3]='o' then begin v:='lavo'; pole[poz[1]][poz[2]+3]:='.'; poz[2]:=poz[2]+3; t:=1; end
else if pole[poz[1]][poz[2]+3]='<' then begin v:='lavo'; pole[poz[1]][poz[2]+3]:='.'; poz[2]:=poz[2]+3; end
else if pole[poz[1]][poz[2]+3]='.' then begin v:='error'; end;
end;
z1:=0;
end


else if v='dole' then begin
if pole[poz[1]+1][poz[2]]='|' then begin v:='dole'; pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; end
else if pole[poz[1]+1][poz[2]]='+' then begin v:='vodo'; pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1;  end
else if pole[poz[1]+1][poz[2]]='o' then begin v:='dole'; pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; t:=1; end
else if pole[poz[1]+1][poz[2]]='-' then begin v:='dole'; pole[poz[1]+1][poz[2]]:='.'; z:=1; z1:=1; poz[1]:=poz[1]+1; end
else if pole[poz[1]+1][poz[2]]='^' then begin v:='dole'; pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; end
else if pole[poz[1]+1][poz[2]]='.' then begin v:='error';  end;

end


else if v='hore' then begin

if pole[poz[1]-1][poz[2]]='|' then begin v:='hore'; pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='+' then begin v:='vodo';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='o' then begin v:='hore';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; t:=1; end
else if pole[poz[1]-1][poz[2]]='-' then begin v:='hore';  pole[poz[1]-1][poz[2]]:='.'; z:=1; z1:=1; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='V' then begin v:='hore';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='.' then begin v:='error'; end;
end


else if v='vodo' then begin
if not(pole[poz[1]][poz[2]-1]='.') then begin
if pole[poz[1]][poz[2]-1]='-' then begin v:='lavo'; pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='+' then begin v:='zvis';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='o' then begin v:='lavo';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; t:=1; end
else if pole[poz[1]][poz[2]-1]='|' then begin v:='lavo';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; z:=1; z1:=1; end
else if pole[poz[1]][poz[2]-1]='>' then begin v:='lavo';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='.' then begin v:='error'; end;
end






else if not(pole[poz[1]][poz[2]+1]='.') then begin


if pole[poz[1]][poz[2]+1]='-' then begin v:='pravo'; pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='+' then begin v:='zvis';  pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='o' then begin v:='pravo';  pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; t:=1; end
else if pole[poz[1]][poz[2]+1]='|' then begin v:='pravo' ; pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; z:=1; z1:=1; end
else if pole[poz[1]][poz[2]+1]='<' then begin v:='pravo';  pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='.' then begin v:='error'; end;
end;
end





else if v='lavo' then begin

if pole[poz[1]][poz[2]-1]='-' then begin v:='lavo'; pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='+' then begin v:='zvis';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='o' then begin v:='lavo';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; t:=1; end
else if pole[poz[1]][poz[2]-1]='|' then begin v:='lavo';  pole[poz[1]][poz[2]-1]:='.'; z:=1; z1:=1; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='>' then begin v:='lavo';  pole[poz[1]][poz[2]-1]:='.'; poz[2]:=poz[2]-1; end
else if pole[poz[1]][poz[2]-1]='.' then begin v:='error'; end;
end


else if v='pravo' then begin

if pole[poz[1]][poz[2]+1]='-' then begin v:='pravo'; pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='+' then begin v:='zvis';   pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='o' then begin v:='pravo';  pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; t:=1; end
else if pole[poz[1]][poz[2]+1]='|' then begin v:='pravo';  pole[poz[1]][poz[2]+1]:='.'; z:=1; z1:=1; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='<' then begin v:='pravo';  pole[poz[1]][poz[2]+1]:='.'; poz[2]:=poz[2]+1; end
else if pole[poz[1]][poz[2]+1]='.' then begin v:='error'; end;
end



else if v='zvis' then begin

if not(pole[poz[1]-1][poz[2]]='.') then begin

if pole[poz[1]-1][poz[2]]='|' then begin v:='hore'; pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='+' then begin v:='voro';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='o' then begin v:='hore';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; t:=1; end
else if pole[poz[1]-1][poz[2]]='-' then begin v:='hore';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; z:=1; z1:=1; end
else if pole[poz[1]-1][poz[2]]='V' then begin v:='hore';  pole[poz[1]-1][poz[2]]:='.'; poz[1]:=poz[1]-1; end
else if pole[poz[1]-1][poz[2]]='.' then begin v:='error'; end;
end






else if not(pole[poz[1]+1][poz[2]]='.') then begin


if pole[poz[1]+1][poz[2]]='|' then begin v:='dole'; pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; end
else if pole[poz[1]+1][poz[2]]='+' then begin v:='vodo'; pole[poz[1]+1][poz[2]]:='.';  poz[1]:=poz[1]+1; end
else if pole[poz[1]+1][poz[2]]='o' then begin v:='dole';  pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; t:=1; end
else if pole[poz[1]+1][poz[2]]='-' then begin v:='dole';  pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; z:=1; z1:=1; end
else if pole[poz[1]+1][poz[2]]='^' then begin v:='dole';  pole[poz[1]+1][poz[2]]:='.'; poz[1]:=poz[1]+1; end
else if pole[poz[1]+1][poz[2]]='.' then begin v:='error'; end;
end;
end;



end;






begin

for i:=1 to 202 do
for i1:=1 to 202 do
pole[i][i1]:='.';
readln(x,y);

for i:=1 to x do begin
readln(s);
for i1:=1 to y do begin
pole[i+1][i1+1]:=s[i1];

end;
end;


i:=1;
repeat
i1:=1;
repeat
if pole[i][i1]='Z' then begin start[1]:=i; start[2]:=i1; end;
i1:=i1+1;
until (pole[i][i1-1]='Z') or (i1=y+1);
i:=i+1;

until pole[i-1][i1-1]='Z';



if not(pole[start[1]-2][start[2]]='.') then begin poz[1]:=start[1]+2; poz[2]:=start[2]; v:='dole'; end

else
if not(pole[start[1]][start[2]-2]='.') then begin poz[2]:=start[2]-2; poz[1]:=start[1]; v:='lavo'; end;














i:=1;

if v='hore' then begin

repeat
posun();

i:=i+1;

until ((poz[1]=start[1]+1) and (poz[2]=start[2])) or (v='error') or (i=30000);
if (v='error') or (z=0) or (t=0) then writeln('nesvieti');
if (not(v='error')) and ((z=1) and (t=1)) or (i=30000)  then writeln('svieti');
end

else if v='dole' then begin

repeat

posun();
i:=i+1;

until ((poz[1]=start[1]-1) and (poz[2]=start[2])) or (v='error') or (i=30000);
if (v='error') or (z=0) or (t=0) then writeln('nesvieti');
if (not(v='error')) and ((z=1) and (t=1)) or (i=30000)  then writeln('svieti');
end

else if v='pravo' then begin

repeat
posun();
i:=i+1;

until ((poz[1]=start[1]) and (poz[2]=start[2]-1)) or (v='error') or (i=30000);
if (v='error') or (z=0) or (t=0) then writeln('nesvieti');
if (not(v='error')) and ((z=1) and (t=1)) or (i=30000)  then writeln('svieti');
end

else if v='lavo' then begin

repeat
posun();
i:=i+1;

until ((poz[1]=start[1]) and (poz[2]=start[2]+1)) or (v='error') or (i=30000);
if (v='error') or (z=0) or (t=0) then writeln('nesvieti');
if (not(v='error')) and ((z=1) and (t=1)) or (i=30000)  then writeln('svieti');
end;














readln;
end.








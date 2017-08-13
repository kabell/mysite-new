  program kar;

  var
  pole:array [1..5] of integer;
  x,i,z,farba,znak: integer;

  begin
  pole[1]:=1;
  pole[2]:=1;
  pole[3]:=1;
  pole[4]:=1;
  pole[5]:=1;

  for i:=1 to 32 do begin
  x:=pole[1];
  z:=pole[4];
  pole[1]:=pole[2];
  pole[2]:=pole[3];

  pole[3]:=pole[4];
  pole[4]:=pole[5];
  pole[5]:=(z+x) mod 2;
  write(i,' ',pole[1],pole[2],pole[3],pole[4],pole[5]);
  farba:=pole[1]*2+pole[2];
  znak:=pole[3]*4+pole[4]*2+pole[5]+1;
  writeln(' ',farba,'_',znak)
  end;
  readln;
  end.


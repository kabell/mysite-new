var N, I, A, B, C, p: integer;
begin
Read(N);
A := 0;
B := 0;
C := 0;
for I := 1 to N do begin

Read(p);
if p = 1 then begin

if C <> 0 then WriteLn(A + B + 1, ' ' , I);

if B <> 0 then WriteLn(A + 1,  ' ', A + B + 1);

A := A + 1;
end;

if p = 2 then begin

if C <> 0 then WriteLn(A + B + 1, ' ', I);

B := B + 1;
end;
if p = 3 then begin

C := C + 1;
end;
end;
readln;
readln;
end.

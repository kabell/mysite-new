
program nahrdelnik;
uses crt;
var n: string;{nahrdelnik}
    K: integer; {jednoduch� pomocn� premenn�}

begin
 clrscr;
write('retazec');{zad�te retazec}
ReadLn(n);
write('cislo: ');{o kolko znakov sa ma posunut}
 readln(K);


Insert(Copy(n, 1, K), n, Length(n)+1); {ten tajupln� program na oto�enie :-)}
                 {skop�ruje sa po�et znakov zo za�iatku a prip�u sa na za�iatok}
Delete(n,1,K);{ po�et zakov zo za�iatku sa odstr�ni tj. zostan� znaky len na konci ako premiestnenie}
 
  WriteLn(n); {a vyp�eme v�sledok}
  readln;
end.

    
    



program nahrdelnik;
uses crt;
var n: string;{nahrdelnik}
    K: integer; {jednoduché pomocné premenné}

begin
 clrscr;
write('retazec');{zadáte retazec}
ReadLn(n);
write('cislo: ');{o kolko znakov sa ma posunut}
 readln(K);


Insert(Copy(n, 1, K), n, Length(n)+1); {ten tajuplný program na otoèenie :-)}
                 {skopíruje sa poèet znakov zo zaèiatku a pripíšu sa na zaèiatok}
Delete(n,1,K);{ poèet zakov zo zaèiatku sa odstráni tj. zostanú znaky len na konci ako premiestnenie}
 
  WriteLn(n); {a vypíšeme výsledok}
  readln;
end.

    
    


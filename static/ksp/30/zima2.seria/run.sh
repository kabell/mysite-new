#!/bin/sh


g++ server.c -o serverfilip

echo "
#!/bin/sh
./serverfilip 50000"> runafterstart.sh
chmod +x runafterstart.sh
echo "PLS nastav si script runafterstart.sh na spustanie po starte PLS"




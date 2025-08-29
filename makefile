baslat: derle calistir

derle:
	gcc -I ./include -o ./lib/buzdeviGezegen.o -c ./src/buzdeviGezegen.c
	gcc -I ./include -o ./lib/cuceGezegen.o -c ./src/cuceGezegen.c
	gcc -I ./include -o ./lib/dosyaOkuma.o -c ./src/dosyaOkuma.c
	gcc -I ./include -o ./lib/gezegen.o -c ./src/gezegen.c
	gcc -I ./include -o ./lib/GazDeviGezegen.o -c ./src/GazDeviGezegen.c
	gcc -I ./include -o ./lib/kayacGezegen.o -c ./src/kayacGezegen.c
	gcc -I ./include -o ./lib/kisi.o -c ./src/kisi.c
	gcc -I ./include -o ./lib/uzayAraci.o -c ./src/uzayAraci.c
	gcc -I ./include -o ./lib/zaman.o -c ./src/zaman.c
	gcc -I ./include -o ./bin/main.exe ./lib/buzdeviGezegen.o ./lib/cuceGezegen.o ./lib/dosyaOkuma.o ./lib/gezegen.o ./lib/GazDeviGezegen.o ./lib/kayacGezegen.o ./lib/kisi.o ./lib/uzayAraci.o ./lib/zaman.o ./src/main.c

calistir:
	./bin/main.exe

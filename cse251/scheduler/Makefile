scheduler: scheduler.o input.o display.o
	gcc -o scheduler scheduler.o input.o display.o
scheduler.o: scheduler.c scheduler.h
	gcc -c scheduler.c
input.o: input.c input.h
	gcc -c input.c
display.o: display.c display.h
	gcc -c display.c
clean:
	rm -f *.o scheduler
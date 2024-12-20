project10_guests: project10_guests.o guest.o read_line.o
	gcc -std=c99 -Wall -o project10_guests project10_guests.o guest.o read_line.o

project10_guests.o: project10_guests.c guest.h read_line.h
	gcc -std=c99 -Wall -c project10_guests.c

guest.o: guest.c guest.h
	gcc -std=c99 -Wall -c guest.c

read_line.o: read_line.c read_line.h
	gcc -std=c99 -Wall -c read_line.c

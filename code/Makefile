### 
## Makefile
## INFO0030: Projet 4
## 
### 

## Variables

# Tools & flags
CC = gcc
CFLAGS = --std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD = gcc
LDFLAGS =

# Files
EXEC_TABLEAU = gaule_tableau_test
MODULES_TABLEAU = ville.c gaule_tableau.c
OBJECTS_TABLEAU = ville.o gaule_tableau.o

EXEC_LISTE = gaule_liste_test
MODULES_LISTE = ville.c gaule_liste.c
OBJECTS_LISTE = ville.o gaule_liste.o

EXEC = $(EXEC_TABLEAU) $(EXEC_LISTE)

## Rules

#compilation

test_array: $(OBJECTS_TABLEAU)
	$(LD) -o $(EXEC_TABLEAU) $(OBJECTS_TABLEAU) $(LDFLAGS) -lm

test_list: $(OBJECTS_LISTE)
	$(LD) -o $(EXEC_LISTE) $(OBJECTS_LISTE) $(LDFLAGS) -lm


ville.o: ville.c
	$(CC) -c ville.c -o ville.o $(CFLAGS)

gaule_tableau.o: gaule_tableau.c
	$(CC) -c gaule_tableau.c -o gaule_tableau.o $(CFLAGS)

gaule_liste.o: gaule_liste.c
	$(CC) -c gaule_liste.c -o gaule_liste.o $(CFLAGS)


#rapport
rapport:all_rapport clean_log_aux

all_rapport:
	cd ../rapport && pdflatex tad-RusseCyril.tex

clean_log_aux:
	cd ../rapport && rm -f tad-RusseCyril.aux tad-RusseCyril.log tad-RusseCyril.toc

clean_rapport: clean_log_aux
	cd ../rapport && rm -f tad-RusseCyril.pdf

#création archive
archive:
	cd .. && tar -zcvf demineur_01.tar.gz source rapport doc

#supp fichiers objets + executable
clean:
	rm -f *.o $(EXEC)


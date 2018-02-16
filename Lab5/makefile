iterMS : merge.o iterMS.o runIterMS.o
	gcc merge.o iterMS.o runIterMS.o -o testIter
iterMS.o : iterMS.c ex1.h
	gcc -c iterMS.c
runIterMS.o : runIterMS.c ex1.h
	gcc -c runIterMS.c
recMS : merge.o recMS.o runRecMS.o
	gcc merge.o recMS.o runRecMS.o -o testRec
runRecMS.o : runRecMS.c ex1.h
	gcc -c runRecMS.c
recMS.o : recMS.c ex1.h
	gcc -c recMS.c
merge.o : merge.c ex1.h
	gcc -c merge.c

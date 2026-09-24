cbuff: circlebuff.o
	gcc -o $@ $<

circlebuff.o: circleBuff.c circleBuff.h
	gcc -Wall -c circleBuff.c -o $@

.PHONY: clean
clean:
	rm -f *.o cbuff

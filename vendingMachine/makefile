.PHONY: run
## test:	Runs the tests.
run:	compile
		g++ main.cpp VendingMachine.o -o test

compile: main.o VendingMachine.o

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii test.exe
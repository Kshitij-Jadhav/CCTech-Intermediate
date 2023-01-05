.PHONY: run

run:	compile
		g++ main.cpp VendingMachine.o -o VendingMachine

compile:	main.o VendingMachine.o

.PHONY: test

test:	runTest
		g++ test.cpp VendingMachine.o -o test

runTest:	test.o VendingMachine.o

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii test.exe
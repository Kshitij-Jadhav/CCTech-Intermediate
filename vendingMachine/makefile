.PHONY: run

run:	compile
		g++ main.cpp VendingMachine.o -o VendingMachine

compile:	main.o VendingMachine.o

.PHONY: test

test:	runTest
		./test

runTest:	test.o VendingMachine.o
			g++ test.cpp VendingMachine.o -o test

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii test.exe
.PHONY: run

run:	compile
		./VendingMachine
		

compile:	main.o VendingMachine.o
			g++ main.cpp VendingMachine.o -o VendingMachine

.PHONY: test

test:	runTest
		./test

runTest:	test.o VendingMachine.o
			g++ test.cpp VendingMachine.o -o test

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii test.exe
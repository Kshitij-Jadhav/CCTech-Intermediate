.PHONY: run

run:	compile
		./CurrencyConverter
		

compile:	main.o CurrencyConverter.o
			g++ main.cpp CurrencyConverter.o -o CurrencyConverter

.PHONY: test

test:	runTest
		./test

runTest:	test.o CurrencyConverter.o
			g++ test.cpp CurrencyConverter.o -o test

.PHONY: clean
## clean:	Removes all generated files.
clean:
	$(RM) *.[adios] *.ii test.exe
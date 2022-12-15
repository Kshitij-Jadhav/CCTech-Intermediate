.PHONY: all
all: test sort_by_length

.PHONY: test
test: testRunner
	./testRunner

testRunner: testRunner.o test_cases.o sort_string_by_length.o
sort_by_length: isLeapYear.o sort_string_by_length.o

.PHONY: clean
clean::
	$(RM) *.[adios] testRunner isLeapYear
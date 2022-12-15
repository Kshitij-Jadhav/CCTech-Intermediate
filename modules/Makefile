CPPFLAGS:=-MMD
CFLAGS:=-O2

.PHONY: all
all: test sort_by_length

.PHONY: test
test: testRunner
	./testRunner

testRunner: testRunner.o test_cases.a core_functions.a
sort_by_length: sort_by_length.o core_functions.a

test_cases.a: test_cases.a(test_cases.o)
core_functions.a: core_functions.a(sort_string_by_length.o)


-include *.d

.PHONY: clean
clean::
	$(RM) *.[adios] testRunner sort_by_length

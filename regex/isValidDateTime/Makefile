.PHONY: all
all: test

.PHONY : test
test : isValidDateTime
	./isValidDateTime 2022-12-26T06:55
	./isValidDateTime 2022-12-26T06:55Z
	./isValidDateTime 2022-12-26T06:55:30
	./isValidDateTime 2022-12-26T06:55:30Z
	./isValidDateTime 2022-12-26T06:55:30.741
	./isValidDateTime 2022-12-26T06:55:30.741Z
	./isValidDateTime 2022-12-26T06:55:30.741374
	./isValidDateTime 2022-12-26T06:55:30.741374Z
	./isValidDateTime 2022-12-26T06:55:30.741374147
	./isValidDateTime 2022-12-26T06:55:30.741374147Z
	./isValidDateTime 2022-12-26T12:25+05:30
	./isValidDateTime 2022-12-26T12:25:30+05:30
	./isValidDateTime 2022-12-26T12:25:30.741+05:30
	./isValidDateTime 2022-12-26T12:25:30.741374+05:30
	./isValidDateTime 2022-12-26T12:25:30.741374147+05:30
	! ./isValidDateTime 2022-12-26T12:25:30*741374147+05:30

.PHONY: clean
clean::
	$(RM) *.[adios] *.ii isValidTime
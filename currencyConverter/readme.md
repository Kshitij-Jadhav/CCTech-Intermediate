Project:

Title: Currency Converter

Total marks: 15

Duration: 4 Days

Submission: Git

Submission deadline: 2023-01-09 7:00 PM 

 

Details: 

Currency conversion is expected for some currencies (USD, GBP, INR, EUR, CHF, AUD, SGD, CNY, JPY) for one given date (date 2023-01-06).

The conversion rates should be consumed from a text file

 

It should be a command line program that displays the following

 

Welcome to CCTech Currency converter:

Select the input currency from the list
1. USD

2. GBP

3. INR

4. EUR

.

.

.

> 1

Select the output currency from the list (should not print the selected input currency at the output)

1. GBP

2. INR

3. EUR

.

.

> 1



Please enter the amount

> 500



500 USD would be 439.46 GBP on 2023-01-06

Do you wish to continue with another conversion (Y/N)

 

Error handling should be considered for the following scenarios with given messages

 

- Input / Output currency user input is not a number
Please enter a valid number
Select the input/output currency from the list

- Input / Output currency user input is a number outside the range
The number is out of range
Select the input/output currency from the list

- The currency amount entered is not a valid number
The amount entered is not valid, Please enter a valid amount
Please enter the amount

- Invalid character instead of Y/N for continuing the conversion
Invalid input, please enter Y or N (case insensitive)
Do you wish to continue with another conversion (Y/N)

Adding a new currency should involve minimum changes


Test cases: 

Conversion and failure scenarios would be tested.

 

Grading:

If the automated tests written by us pass (4 marks)
Coverage of tests that they have written (which means that they have to write tests) (2 marks)
Clean code practices followed (like naming, size, small functions etc.) (4 marks)
Scalability (ease of adding new currencies) (5 marks)
A: Above 13 marks

B: 10 to 13 marks

C: 7 to 10 marks

Fail: Below 7 marks

 

Fail action: Redo the project and implement given feedback


All the best!
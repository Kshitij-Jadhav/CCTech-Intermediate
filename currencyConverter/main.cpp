#include "CurrencyConverter.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
using namespace std;

bool allDigits(string temp) {
    bool result = true;
    for (auto c : temp) {
        if (!isdigit(c)) {
            result = false;
        }
    }
    return result;
}

int main() {
    bool runAgain = false;
    do {
        cout << "Welcome to CCTech Currency converter:" << endl;
        USD usd; INR inr; GBP gbp; EUR eur;
        vector<CurrencyConverter*> inputCurrencies = {&usd , &inr , &gbp , &eur };
        vector<string> inputCurrencyNames          = {"USD", "INR", "GBP", "EUR"};

        CurrencyConverter* inputCurrency;
        int inputCurrencyIndex;
        {
            while (1) {
                cout << "Select the input currency from the list" << endl;
                {
                    int i = 1;
                    for (auto currencyName : inputCurrencyNames) {
                        cout << i++ << "." << currencyName << endl;
                    }
                }
                cout << ".\n.\n.\n>";
                string temp;
                cin >> temp;
                if (allDigits(temp) && (stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size())) {
                    inputCurrencyIndex = stoi(temp);
                    break;
                }
                if (!allDigits(temp)) {
                    cout << "Please enter a valid number" << endl;
                }
                else if (!(stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size())) {
                    cout << "The number is out of range" << endl;
                }
            }
            inputCurrency = inputCurrencies.at(inputCurrencyIndex - 1);
        }
        vector<CurrencyConverter*> outputCurrencies;
        vector<string> outputCurrencyNames;
        {
            int it = 0;

            for (int it = 0; it < inputCurrencies.size(); it++) {
                if (inputCurrency != inputCurrencies.at(it)) {
                    outputCurrencies.emplace_back(inputCurrencies.at(it));
                    outputCurrencyNames.emplace_back(inputCurrencyNames.at(it));
                }
            }
        }
        CurrencyConverter* outputCurrency;
        int outputCurrencyIndex;

        while (1) {
            cout << "Select the output currency from the list" << endl;
            {
                int j = 1;
                for (auto currencyName : outputCurrencyNames) {
                    cout << j++ << "." << currencyName << endl;
                }
            }
            cout << ".\n.\n>";
            string temp;
            cin >> temp;
            if (allDigits(temp) && (stoi(temp) >= 0 && stoi(temp) < outputCurrencies.size())) {
                outputCurrencyIndex = stoi(temp);
                break;
            }
            if (!allDigits(temp)) {
                cout << "Please enter a valid number" << endl;
            }
            else if (!(stoi(temp) >= 0 && stoi(temp) < outputCurrencies.size())) {
                cout << "The number is out of range" << endl;
            }
        }
        outputCurrency = outputCurrencies.at(outputCurrencyIndex - 1);
        double moneyInInPutCurrency;

        while (1) {
            cout << "Please enter the amount\n>";
            string temp;
            cin >> temp;
            if (allDigits(temp)) {
                moneyInInPutCurrency = stof(temp);
                break;
            }
            cout << "The amount entered is not valid, Please enter a valid amount" << endl;
        }
        if (!inputCurrency->getExchangeRate()) {
            exit(EXIT_FAILURE);
        }
        double moneyInUSD = inputCurrency->toUSDCurrency(moneyInInPutCurrency);
        if (!outputCurrency->getExchangeRate()) {
            exit(EXIT_FAILURE);
        }
        double moneyInOutPutCurrency = outputCurrency->fromUSDCurrency(moneyInUSD);
        cout << moneyInInPutCurrency << inputCurrencyNames.at(inputCurrencyIndex - 1) << " would be "
            << moneyInOutPutCurrency << outputCurrencyNames.at(outputCurrencyIndex - 1) << " on" << " 2023-01-06" << endl;

        char Continue;
        cout << "Do you wish to continue with another conversion (Y/N)" << endl;
        cin >> Continue;
        while (true) {
            if (tolower(Continue) == 'y' || tolower(Continue) == 'n')
                break;
            cout << "Invalid input, please enter Y or N (case insensitive)" << endl;
            cin >> Continue;
        }
        if (tolower(Continue) == 'y')
            runAgain = true;
        else if (tolower(Continue) == 'n')
            runAgain = false;
    } while (runAgain);
}
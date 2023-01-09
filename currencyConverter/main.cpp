#include "CurrencyConverter.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    bool runAgain = false;
    do{        
        cout << "Welcome to CCTech Currency converter:" << endl;
        USD usd; INR inr; GBP gbp; EUR eur;
        vector<CurrencyConverter*> inputCurrencies = {&usd , &inr , &gbp , &eur};
        vector<string> inputCurrencyNames          = {"USD", "INR", "GBP", "EUR"};
        CurrencyConverter* inputCurrency;
        int inputCurrencyIndex;
        {
            
            while(1) {
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
                if(all_of(temp.begin(), temp.end(), ::isdigit) && (stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size())) {
                    inputCurrencyIndex = stoi(temp);
                    break;
                }
                if(all_of(temp.begin(), temp.end(), ::isdigit)){
                    cout << "Please enter a valid number" << endl;
                }
                else if(stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size()) {
                    cout << "The number is out of range" << endl;
                }
            }
            inputCurrency = inputCurrencies.at(inputCurrencyIndex - 1);
        }
        vector<CurrencyConverter*> outputCurrencies;
        vector<string> outputCurrencyNames ;
        {
            int it = 0;

            for(int it = 0; it < inputCurrencies.size(); it++){
                if(inputCurrency != inputCurrencies.at(it)){
                    outputCurrencies.emplace_back(inputCurrencies.at(it));
                    outputCurrencyNames.emplace_back(inputCurrencyNames.at(it));
                }
            }
        }
        CurrencyConverter* outputCurrency;
        int outputCurrencyIndex;
        {
            cout << "Select the output currency from the list" << endl;
            
            {
                int j = 1;
                for (auto currencyName : outputCurrencyNames) {
                        cout << j++ << "." << currencyName << endl;
                }
            }
            cout << ".\n.\n>";
            
            cin >> outputCurrencyIndex;
            //error handlining *is not a number *number outside the range *is not a valid number
            outputCurrency = outputCurrencies.at(outputCurrencyIndex - 1);
        }
        double moneyInInPutCurrency;
        cout << "Please enter the amount\n>";
        cin >> moneyInInPutCurrency;
        //error handlling
        inputCurrency->getExchangeRate();
        double moneyInUSD = inputCurrency->toUSDCurrency(moneyInInPutCurrency);
        outputCurrency->getExchangeRate();
        double moneyInOutPutCurrency = outputCurrency->fromUSDCurrency(moneyInUSD);
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << moneyInInPutCurrency << inputCurrencies.at(inputCurrencyIndex - 1) << " would be " 
             << moneyInOutPutCurrency << outputCurrencies.at(outputCurrencyIndex - 1) <<" on" << " 2023-01-06" << endl;


        char Continue;
        cout << "Do you wish to continue with another conversion (Y/N)" << endl;
        cin >> Continue;
        while(true){
            if(tolower(Continue) == 'y' || tolower(Continue) == 'n')
                break;
            cout << "Invalid input, please enter Y or N (case insensitive)" << endl;
            cin >> Continue;
        }
        if(tolower(Continue) == 'y')
            runAgain = true;
        else if(tolower(Continue) == 'n')
            runAgain = false;
    }while(runAgain);
}
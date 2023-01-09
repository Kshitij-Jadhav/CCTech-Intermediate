#include "CurrencyConverter.h"

bool USD::getExchangeRate() {
    currencyExchangeRate = 1;
    return true;
}

double USD::toUSDCurrency(double moneyInUSD) {
    return moneyInUSD / currencyExchangeRate;
}

double USD::fromUSDCurrency(double moneyInUSD) {
    return moneyInUSD * currencyExchangeRate;
}

bool GBP::getExchangeRate() {
    string filename = "exchangeRates.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << filename << " does not exists." << endl;
        return false;
    }
    string word, line, previousWord;
    while (file >> word) {
        if (word.compare("GBP") == 0) {
            currencyExchangeRate = stof(previousWord);
            break;
        }
        previousWord = word;
    }
    return true;
}

double GBP::toUSDCurrency(double moneyInGBP) {
    return moneyInGBP / currencyExchangeRate;
}

double GBP::fromUSDCurrency(double moneyInUSD) {
    return moneyInUSD * currencyExchangeRate;    
}

bool INR::getExchangeRate() {
    string filename = "exchangeRates.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << filename << " does not exists." << endl;
        return false;
    }
    string word, line, previousWord;
    while (file >> word) {
        if (word.compare("INR") == 0) {
            currencyExchangeRate = stof(previousWord);
            break;
        }
        previousWord = word;
    }
    return true;
}

double INR::toUSDCurrency(double moneyInINR) {
    return moneyInINR / currencyExchangeRate;
}

double INR::fromUSDCurrency(double moneyInUSD) {
    return moneyInUSD * currencyExchangeRate;
}

bool EUR::getExchangeRate() {
    string filename = "exchangeRates.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << filename << " does not exists." << endl;
        return false;
    }
    string word, line, previousWord;
    while (file >> word) {
        if (word.compare("EUR") == 0) {
            currencyExchangeRate = stof(previousWord);
            break;
        }
        previousWord = word;
    }
    return true;
}

double EUR::toUSDCurrency(double moneyInEUR) {
    return moneyInEUR / currencyExchangeRate;
}

double EUR::fromUSDCurrency(double moneyInUSD) {
    return moneyInUSD * currencyExchangeRate;   
}
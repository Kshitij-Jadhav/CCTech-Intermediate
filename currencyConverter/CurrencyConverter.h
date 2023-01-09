#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H 1

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class CurrencyConverter {
public:
    virtual bool   getExchangeRate()       = 0;
    virtual double toUSDCurrency(double)   = 0;
    virtual double fromUSDCurrency(double) = 0;
};

class USD : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toUSDCurrency(double);
    double fromUSDCurrency(double);
};

class GBP : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toUSDCurrency(double);
    double fromUSDCurrency(double);
};

class INR : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toUSDCurrency(double);
    double fromUSDCurrency(double);
};

class EUR : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toUSDCurrency(double);
    double fromUSDCurrency(double);
};
#endif
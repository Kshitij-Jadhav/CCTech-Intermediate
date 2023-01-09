#include "CurrencyConverter.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    USD usd; INR inr; GBP gbp; EUR eur;
    assert(inr.getExchangeRate());
    assert(inr.currencyExchangeRate == 98.40f);
    assert(usd.getExchangeRate());
    assert(usd.currencyExchangeRate == 1.0f);
    assert(gbp.getExchangeRate());
    assert(gbp.currencyExchangeRate == 1.19f);
    assert(eur.getExchangeRate());
    assert(eur.currencyExchangeRate == 1.13f);

    assert(inr.toUSDCurrency(98.40) - 1 < 1e-9);
    cout << inr.fromUSDCurrency(1);
    
}
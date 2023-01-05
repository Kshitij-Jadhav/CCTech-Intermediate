#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H 1

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>

#define money(dolar,cents) std::pair<int, int> 

class VendingMachine {
private:
    money(dollar, cents) totalAmount;

    const std::unordered_map<std::string, money(dollar, cents)> coins = {{"nickel" , {0,  5}},
                                                                         {"dime"   , {0, 10}}, 
                                                                         {"quarter", {0, 25}}};

    int numberOfCola;
    int numberOfChips;
    int numberOfCandy;
    const std::unordered_map<std::string, money(dollar, cents)> products = {{"cola" , {1, 00}}, 
                                                                            {"chips", {0, 50}}, 
                                                                            {"candy", {0, 65}}};

    std::vector<std::string> returnCoinsBox;

    
public:
    bool isValidCoin(std::string);
    void makeChange();
    //bool canMakeChange();
    bool isSoldOut(int);
    void exactChangeOnly();
    VendingMachine();
    void acceptCoin();
    void selectProduct();
    void returnCoins();
    void printOptions();
};
#endif
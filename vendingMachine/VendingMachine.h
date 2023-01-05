#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H 1

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <cassert>

#define money(dolar, cents) std::pair<int, int> 
#define coin(weight, diameter) std::pair<int, int> 

using namespace std;

class VendingMachine {
private:
    const std::unordered_map<std::string, coin(weight, diameter)> validCoins = {{"nickel" , {5, 21}},
                                                                                {"dime"   , {2, 18}}, 
                                                                                {"quarter", {6, 24}}};

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

    bool isValidCoin(coin(weight, diameter) givenCoin);
    void makeChange();
    //bool canMakeChange();
    bool isSoldOut(int);
    //void exactChangeOnly();
    std::string getCoin(coin(weight,diameter) givenCoin);
    void acceptCoin(coin(weight, diameter) givenCoin);
    void selectProduct();
    void returnCoins();
public:
    VendingMachine();
    void printOptions();
    void test();
};
#endif
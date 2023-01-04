#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    totalAmount   = {0, 0};
    numberOfcola  = 5;
    numberOfchips = 5;
    numberOfcandy = 5;
}

bool VendingMachine::isValidCoin(std::string insertedCoin) {
    std::transform(insertedCoin.begin(), insertedCoin.end(), insertedCoin.begin(), ::toupper);
    for(auto coin : coins) {
        if (coin.first == insertedCoin){
            return true;
        }
    }
    return false;
}

void VendingMachine::acceptCoin() {
    std::string insertedCoin;
    std::cout << "Insert Coin" << std::endl;
    std::cin >> insertedCoin;
    if (isValidCoin(insertedCoin)) {
        totalAmount.first += (coins.at(insertedCoin)).first;
        totalAmount.second += (coins.at(insertedCoin)).second;
    }
    else {
        returnCoinsBox.push_back(insertedCoin);
        std::cout << "Invalid Coin" << std::endl;
    }
}

void VendingMachine::exactChangeOnly() {
    std::string insertedCoin;
    std::cout << "Exact Change Only" << std::endl;
    std::cin >> insertedCoin;
    if (isValidCoin(insertedCoin)) {
        totalAmount.first += (coins.at(insertedCoin)).first;
        totalAmount.second += (coins.at(insertedCoin)).second;
    }
    else {
        returnCoinsBox.push_back(insertedCoin);
        std::cout << "Invalid Coin" << std::endl;
    }
}

bool VendingMachine::isSoldOut(int countOfProduct) {
    return countOfProduct > 0;
}

void VendingMachine::selectProduct() {
    int i = 1;
    for(auto product : products){
        std::cout << i << "\t. " << product.first << "\t" << (product.second).first << "." << (product.second).second << std::endl;
        i++;
    }
    std::cout << i << "\t. " << "return coins" << std::endl;
    int choice;
    std::cin>> choice;
    switch (choice)
    {
    case 1: {
        /* cola */
        if(isSoldOut(numberOfCola)){
            std::cout << "Sold Out !" << endl;
            break;
        }
        break;
    }
    case 2:{
        /* chips */
        if(isSoldOut(numberOfChips)){
            std::cout << "Sold Out !" << endl;
            break;
        }
        break;
    }
    case 3:{
        /* candy */
        if(isSoldOut(numberOfCandy)){
            std::cout << "Sold Out !" << endl;
            break;
        }
        break;
    }
    case 4:{
        acceptCoin();
        break;
    }
    case 5:{
        returnCoins();
        break;
    }
    default:
        break;
    }
}

void VendingMachine::makeChange() {
    for (auto coin : coins) {
        int numberOfcoins = ((totalAmount.first * 100) + totalAmount.second)/(((coin.second).first * 100) + (coin.second).second); 
        for(int i = 0; i < numberOfcoins; i++) {
            returnCoinsBox.push_back(coin.first);
        }
        int remAmount = ((totalAmount.first * 100) + totalAmount.second) - (((coin.second).first * 100) + (coin.second).second) * numberOfcoins;
        totalAmount.first = remAmount/100;
        totalAmount.second = remAmount%100;
    }
}

void VendingMachine::returnCoins() {
    makeChange();
    for (auto coin : returnCoinsBox) {
        std::cout << coin << std::endl;
    }
}

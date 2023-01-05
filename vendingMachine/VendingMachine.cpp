#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    totalAmount   = {0, 0};
    numberOfCola  = 5;
    numberOfChips = 5;
    numberOfCandy = 5;
}

bool VendingMachine::isValidCoin(std::string insertedCoin) {
    std::transform(insertedCoin.begin(), insertedCoin.end(), insertedCoin.begin(), ::tolower);
    for(auto coin : coins) {
        if (coin.first == insertedCoin){
            return true;
        }
    }
    return false;
}

void VendingMachine::acceptCoin() {
    std::string insertedCoin;
    std::cin >> insertedCoin;
    if (isValidCoin(insertedCoin)) {
        int insertedAmountCents = (((coins.at(insertedCoin)).first) * 100) + ((coins.at(insertedCoin)).second);
        int totalAmountCents = ((totalAmount.first * 100) + totalAmount.second);
        totalAmountCents += insertedAmountCents; 
        totalAmount.first = totalAmountCents/100;
        totalAmount.second = totalAmountCents%100;
    }
    else {
        returnCoinsBox.push_back(insertedCoin);
        std::cout << "Invalid Coin" << std::endl;
    }
    std::cout<< std::endl;
    printOptions();
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
    return countOfProduct <= 0;
}

void VendingMachine::selectProduct() {
    int i = 1;
    std::cout << "Amount : $" << totalAmount.first << "." << totalAmount.second << std::endl;
    for(auto product : products){
        std::cout << i++ << ". " << product.first << "  \t$" << (product.second).first << "." << (product.second).second << std::endl;
    }
    std::cout << "any other key to go back" << std::endl;
    int choice;
    std::cin>> choice;
    switch (choice)
    {
        case 1:{
            /* candy */
            if(isSoldOut(numberOfCandy)){
                std::cout << "Sold Out !" << std::endl;
                break;
            }
            if((((totalAmount).first *100) + (totalAmount).second) < (((products.at("candy")).first *100) + (products.at("candy")).second)) {
                std::cout << "PRICE\t$" <<  (products.at("candy")).first << "." << (products.at("candy")).second << std::endl;
            }
            else {
                int remAmount = (((totalAmount).first *100) + (totalAmount).second) - (((products.at("candy")).first *100) + (products.at("candy")).second);
                totalAmount.first = remAmount/100;
                totalAmount.second = remAmount%100;
                makeChange();
                numberOfCandy--;
                std::cout << "THANK YOU" << std::endl;
            }
            std::cout<< std::endl;
            printOptions();
            break;
        }
        case 2:{
            /* chips */
            if(isSoldOut(numberOfChips)){
                std::cout << "Sold Out !" << std::endl;
                break;
            }
            if((((totalAmount).first *100) + (totalAmount).second) < (((products.at("chips")).first *100) + (products.at("chips")).second)) {
                std::cout << "PRICE\t$" <<  (products.at("chips")).first << "." << (products.at("chips")).second << std::endl;
            }else {
                int remAmount = (((totalAmount).first *100) + (totalAmount).second) - (((products.at("chips")).first *100) + (products.at("chips")).second);
                totalAmount.first = remAmount/100;
                totalAmount.second = remAmount%100;
                makeChange();
                numberOfChips--;
                std::cout << "THANK YOU" << std::endl;
            }
            std::cout<< std::endl;
            printOptions();
             break;
        }
        case 3: {
            /* cola */
            if(isSoldOut(numberOfCola)){
                std::cout << "Sold Out !" << std::endl;
                break;
            }
            if((((totalAmount).first *100) + (totalAmount).second) < (((products.at("cola")).first *100) + (products.at("cola")).second)) {
                std::cout << "PRICE\t$" <<  (products.at("cola")).first << "." << (products.at("cola")).second << std::endl;
            }
            else {
                int remAmount = (((totalAmount).first *100) + (totalAmount).second) - (((products.at("cola")).first *100) + (products.at("cola")).second);
                totalAmount.first = remAmount/100;
                totalAmount.second = remAmount%100;
                makeChange();
                numberOfCola--;
                std::cout << "THANK YOU" << std::endl;
            }
            std::cout<< std::endl;
            printOptions();
             break;
        }
        default: std::cout<< std::endl; printOptions();
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
    std::cout<< std::endl;
    returnCoinsBox.clear();
    printOptions();
}

void VendingMachine::printOptions() {
    int i = 1;
    if(((totalAmount.first * 100) + totalAmount.second) <= 0) {
        std::cout << "INSERT COIN" << std::endl;
    }
    else {
        std::cout << "Amount : $" << totalAmount.first << "." << totalAmount.second << std::endl;
    }
    std::cout << i++ << ". " << "insert coins" << std::endl;
    std::cout << i++ << ". " << "select product" << std::endl;
    for(auto product : products){
        std::cout << "\t"<< product.first << "  \t$" << (product.second).first << "." << (product.second).second << std::endl;
    }
    std::cout << i++ << ". " << "return coins" << std::endl;
    std::cout << "any other key to exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice)
    {
        case 1: acceptCoin();    break;
        case 2: selectProduct(); break;
        case 3: returnCoins();   break;
        default: {exit(EXIT_SUCCESS);}
    }
}

void VendingMachine::test() {
    assert(isValidCoin("dime"));
    assert(isValidCoin("quarter"));
    assert(isValidCoin("nickel"));
    assert(!isValidCoin("penny"));
    assert(isSoldOut(1));
    assert(isSoldOut(0));
}
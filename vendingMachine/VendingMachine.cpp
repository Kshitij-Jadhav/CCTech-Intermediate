#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    totalAmount   = {0, 0};
    numberOfCola  = 5;
    numberOfChips = 5;
    numberOfCandy = 5;
}

bool VendingMachine::isValidCoin(coin(weight,diameter) givenCoin)
{
    bool result = false;
    for(auto coin : validCoins) {
        if (((coin.second).first == givenCoin.first) && ((coin.second).second == givenCoin.second)){
            result =  true;
        }
    }
    return result;
}

string VendingMachine::getCoin(coin(weight,diameter) givenCoin) {
    string insertedCoin;
    for(auto coin : validCoins) {
        if (((coin.second).first == givenCoin.first) && ((coin.second).second == givenCoin.second)){
            insertedCoin = coin.first;
        }
    }
    return insertedCoin;
}

void VendingMachine::acceptCoin(coin(weight, diameter) givenCoin) {
    string insertedCoin = getCoin(givenCoin);
    if (isValidCoin(givenCoin)) {
        int insertedAmountCents = (((coins.at(insertedCoin)).first) * 100) + ((coins.at(insertedCoin)).second);
        int totalAmountCents = ((totalAmount.first * 100) + totalAmount.second);
        totalAmountCents += insertedAmountCents; 
        totalAmount.first = totalAmountCents/100;
        totalAmount.second = totalAmountCents%100;
        cout << "Inserted " << insertedCoin << endl;
    }
    else {
        returnCoinsBox.push_back(insertedCoin);
        cout << "Invalid Coin" << endl;
    }
    cout<< endl;
}

// void VendingMachine::exactChangeOnly() {
//     string insertedCoin;
//     cout << "Exact Change Only" << endl;
//     cin >> insertedCoin;
//     if (isValidCoin(insertedCoin)) {
//         totalAmount.first += (coins.at(insertedCoin)).first;
//         totalAmount.second += (coins.at(insertedCoin)).second;
//     }
//     else {
//         returnCoinsBox.push_back(insertedCoin);
//         cout << "Invalid Coin" << endl;
//     }
// }

bool VendingMachine::isSoldOut(int countOfProduct) {
    return countOfProduct <= 0;
}

void VendingMachine::selectProduct() {
    int i = 1;
    cout << "Amount : $" << totalAmount.first << "." << totalAmount.second << endl;
    for(auto product : products){
        cout << i++ << ". " << product.first << "  \t$" << (product.second).first << "." << (product.second).second << endl;
    }
    cout << "any other key to go back" << endl;
    int choice;
    cin>> choice;
    switch (choice)
    {
        case 1:{
            /* candy */
            if(isSoldOut(numberOfCandy)){
                cout << "Sold Out !" << endl;
                break;
            }
            if((((totalAmount).first *100) + (totalAmount).second) < (((products.at("candy")).first *100) + (products.at("candy")).second)) {
                cout << "PRICE\t$" <<  (products.at("candy")).first << "." << (products.at("candy")).second << endl;
            }
            else {
                int remAmount = (((totalAmount).first *100) + (totalAmount).second) - (((products.at("candy")).first *100) + (products.at("candy")).second);
                totalAmount.first = remAmount/100;
                totalAmount.second = remAmount%100;
                makeChange();
                numberOfCandy--;
                cout << "THANK YOU" << endl;
            }
            cout<< endl;
            
            break;
        }
        case 2:{
            /* chips */
            if(isSoldOut(numberOfChips)){
                cout << "Sold Out !" << endl;
                break;
            }
            if((((totalAmount).first *100) + (totalAmount).second) < (((products.at("chips")).first *100) + (products.at("chips")).second)) {
                cout << "PRICE\t$" <<  (products.at("chips")).first << "." << (products.at("chips")).second << endl;
            }else {
                int remAmount = (((totalAmount).first *100) + (totalAmount).second) - (((products.at("chips")).first *100) + (products.at("chips")).second);
                totalAmount.first = remAmount/100;
                totalAmount.second = remAmount%100;
                makeChange();
                numberOfChips--;
                cout << "THANK YOU" << endl;
            }
            cout<< endl;
            
             break;
        }
        case 3: {
            /* cola */
            if(isSoldOut(numberOfCola)){
                cout << "Sold Out !" << endl;
                break;
            }
            if((((totalAmount).first *100) + (totalAmount).second) < (((products.at("cola")).first *100) + (products.at("cola")).second)) {
                cout << "PRICE\t$" <<  (products.at("cola")).first << "." << (products.at("cola")).second << endl;
            }
            else {
                int remAmount = (((totalAmount).first *100) + (totalAmount).second) - (((products.at("cola")).first *100) + (products.at("cola")).second);
                totalAmount.first = remAmount/100;
                totalAmount.second = remAmount%100;
                makeChange();
                numberOfCola--;
                cout << "THANK YOU" << endl;
            }
            cout<< endl;
            
             break;
        }
        default: cout<< endl; 
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
        cout << coin << endl;
    }
    cout<< endl;
    returnCoinsBox.clear();
    
}

void VendingMachine::printOptions() {
    while(true) {
        int i = 1;
        if(((totalAmount.first * 100) + totalAmount.second) <= 0) {
            cout << "INSERT COIN" << endl;
        }
        else {
            cout << "Amount : $" << totalAmount.first << "." << totalAmount.second << endl;
        }
        cout << i++ << ". " << "insert coins" << endl;
        cout << i++ << ". " << "select product" << endl;
        for(auto product : products){
            cout << "\t"<< product.first << "  \t$" << (product.second).first << "." << (product.second).second << endl;
        }
        cout << i++ << ". " << "return coins" << endl;
        cout << "any other key to exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1: {
                coin(weight, diameter) insertedCoin;
                cout << "Enter weight of coin = " << endl;
                cin >> insertedCoin.first;
                cout << "Enter diameter of coin = " << endl;
                cin >> insertedCoin.second;
                acceptCoin(insertedCoin);    
                break;
            } 
            case 2: selectProduct(); break;
            case 3: returnCoins();   break;
            default: {exit(EXIT_SUCCESS);}
        }
    }
}

void VendingMachine::test() {
    assert(isValidCoin({5, 21}));
    assert(isValidCoin({2, 18}));
    assert(isValidCoin({6, 24}));
    assert(!isValidCoin({5, 24}));

    assert(!isSoldOut(1));
    assert(isSoldOut(0));
    {
        totalAmount ={1, 55};
        assert((totalAmount.first == 1) && (totalAmount.second == 55));
        makeChange();
        assert((totalAmount.first == 0) && (totalAmount.second == 0));
    }
}
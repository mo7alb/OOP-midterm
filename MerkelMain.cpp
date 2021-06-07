#include <iostream>
#include <vector>

#include "MerkelMain.hpp"
#include "CSVReader.hpp"

using namespace std;

MerkelMain::MerkelMain(){}

void MerkelMain::init() {
    bool runProgram = true;
    int input;
    currentTime = orderBook.getEarliestTime();

    while (runProgram) {
        printMenu();
        input = getUserOption();
        runProgram = processUserOption(input);
    }
}

void MerkelMain::printMenu() {
    // 1 print help
    cout << "1: Print Help" << endl;
    
    // 2 print exchange stats
    cout << "2: Print Exchange Stats" << endl;
    
    // 3 make an offer - sell something
    cout << "3: Make an offer" << endl;
    
    // 4 make a bid - buy something
    cout << "4: Make a bid" << endl;
    
    // 5 print wallet
    cout << "5: Print Wallet" << endl;
    
    // 6 next time step / continue
    cout << "6: Continue" << endl;
    
    // 7 exit from the application
    cout << "7: Exit" << endl;
    cout << "---------------------" << endl;

    cout << "Current time is: " << currentTime << endl;
}

int MerkelMain::getUserOption() {
    int userOption;
    cout << "Type in an option 1-7" << endl;
    cin >> userOption;
    cout << "You chose " << userOption << endl;
    cout << endl;

    return userOption;
}

void MerkelMain::printHelp() {
    cout << "Help - your aim is to make money." << endl;
    cout << "Analyse the market and make bids" << endl;
    cout << "and offers. " << endl;
}

void MerkelMain::printMarketStats() {
    
    for (string const& p : orderBook.getKnownProducts()) {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        
        cout << "Asks seen: " << entries.size() << endl;
        cout << "Highest price: " << OrderBook::getHighPrice(entries) << endl;
        cout << "Lowest price: " << OrderBook::getLowPrice(entries) << endl;
        cout << "Average price: " << OrderBook::getAveragePrice(entries) << endl;
        cout << "Price spread: " << OrderBook::getPriceSpread(entries) << endl;

        cout << endl;
    }
}
void MerkelMain::makeOffer() {
    cout << "Lets sell some stufff, ohhh yeah" << endl;
}

void MerkelMain::makeBid() {
    cout << "Lets get some stuff, yeah" << endl;
}

void MerkelMain::printWallet() {
    cout << "Here is your wallet" << endl;
}

void MerkelMain::nextTimeFrame() {
    cout << "Going to next time frame." << endl;
    currentTime = orderBook.getNextTime(currentTime);
}

bool MerkelMain::exitMenu() {
    cout << "We are sorry to see you leave :(" << endl;
    cout << "Exiting...." << endl;
    return false;
}

bool MerkelMain::processUserOption(int userOption) {
    bool runProgram = true;
    if (userOption == 0 || userOption > 7) { // bad input
        cout << "Invalid Input, choose a number between 1-7" << endl;
    }
    
    if (userOption == 1) { // input for help
        printHelp();
    }
    
    if (userOption == 2) { // input for market stats
        printMarketStats();
    }
    
    if (userOption == 3) { // make an offer
        makeOffer();
    }
    
    if (userOption == 4) { // make a bid
        makeBid();
    }
    
    if (userOption == 5) { // print wallet
        printWallet();
    }
    
    if (userOption == 6) { // continue
        nextTimeFrame();
    }
    
    if (userOption == 7) { // exit from program
        runProgram = exitMenu();
    }
    return runProgram;
}

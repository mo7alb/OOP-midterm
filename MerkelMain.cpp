#include <iostream>
#include <vector>

#include "MerkelMain.hpp"
#include "CSVReader.hpp"

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
    std::cout << "1: Print Help" << std::endl;
    
    // 2 print exchange stats
    std::cout << "2: Print Exchange Stats" << std::endl;
    
    // 3 make an offer - sell something
    std::cout << "3: Make an offer" << std::endl;
    
    // 4 make a bid - buy something
    std::cout << "4: Make a bid" << std::endl;
    
    // 5 print wallet
    std::cout << "5: Print Wallet" << std::endl;
    
    // 6 next time step / continue
    std::cout << "6: Continue" << std::endl;
    
    // 7 exit from the application
    std::cout << "7: Exit" << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
}

int MerkelMain::getUserOption() {
    int userOption;
    std::cout << "Type in an option 1-7" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose " << userOption << std::endl;
    std::cout << std::endl;

    return userOption;
}

void MerkelMain::printHelp() {
    std::cout << "Help - your aim is to make money." << std::endl;
    std::cout << "Analyse the market and make bids" << std::endl;
    std::cout << "and offers. " << std::endl;
}

void MerkelMain::printMarketStats() {
    
    for (std::string const& p : orderBook.getKnownProducts()) {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, "2020/03/17 17:01:40.107326");
        
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Highest price: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Lowest price: " << OrderBook::getLowPrice(entries) << std::endl;
        std::cout << "Average price: " << OrderBook::getAveragePrice(entries) << std::endl;
        std::cout << "Price spread: " << OrderBook::getPriceSpread(entries) << std::endl;

        std::cout << std::endl;
    }
}
void MerkelMain::makeOffer() {
    std::cout << "Lets sell some stufff, ohhh yeah" << std::endl;
}

void MerkelMain::makeBid() {
    std::cout << "Lets get some stuff, yeah" << std::endl;
}

void MerkelMain::printWallet() {
    std::cout << "Here is your wallet" << std::endl;
}

void MerkelMain::nextTimeFrame() {
    std::cout << "Going to next time frame." << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

bool MerkelMain::exitMenu() {
    std::cout << "We are sorry to see you leave :(" << std::endl;
    std::cout << "Exiting...." << std::endl;
    return false;
}

bool MerkelMain::processUserOption(int userOption) {
    bool runProgram = true;
    if (userOption == 0 || userOption > 7) { // bad input
        std::cout << "Invalid Input, choose a number between 1-7" << std::endl;
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

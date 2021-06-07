#pragma once

#include <vector>
#include <string>

#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"

using namespace std;

class MerkelMain {
    public:
    MerkelMain();
    /** Call this to start the simulation */
    void init();

    private:
    void printMenu();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void makeOffer();
    void makeBid();
    void printWallet();
    void nextTimeFrame();
    bool exitMenu();
    bool processUserOption(int userOption);
    
    string currentTime;

    OrderBook orderBook{"20200317.csv"};
};

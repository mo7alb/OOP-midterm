#pragma once

#include <vector>

#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"

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
    
    OrderBook orderBook{"20200317.csv"};
};

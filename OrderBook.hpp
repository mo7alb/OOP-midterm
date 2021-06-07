#pragma once

#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"

#include <string>
#include <vector>

using namespace std;

class OrderBook {
    public:
    /** Constructor, Reading a csv file */
    OrderBook(string filename);
    /** return vector of all known products in the dataset */
    vector<string> getKnownProducts();
    /** return vector of Orders according to the sent filters */
    vector<OrderBookEntry> getOrders(OrderBookType type, string product, string timestamp);
    
    /** return the price of the highest bid in the sent set */
    static double getHighPrice(vector<OrderBookEntry>& orders);
    /** return the price of the lowest bid sent */
    static double getLowPrice(vector<OrderBookEntry>& orders);
    /** return the average price of all the bids sent */
    static double getAveragePrice(vector<OrderBookEntry>& orders);
    /** return the price spread of all the bids sent */
    static double getPriceSpread(vector<OrderBookEntry>& orders);
    /** returns the earliest time in the orderbook */
    string getEarliestTime();
    /** returns the next time after the sent time 
     * in the orderbook. if there is no next timestamp,
     * wraps around to the start */
    string getNextTime(string timestamp);

    private:
    vector<OrderBookEntry> orders;
};

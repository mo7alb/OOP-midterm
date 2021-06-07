#pragma once

#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"

#include <string>
#include <vector>

class OrderBook {
    public:
    /** Constructor, Reading a csv file */
    OrderBook(std::string filename);
    /** return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();
    /** return vector of Orders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);
    
    /** return the price of the highest bid in the sent set */
    static double getHighPrice(std::vector<OrderBookEntry>& orders);
    /** return the price of the lowest bid sent */
    static double getLowPrice(std::vector<OrderBookEntry>& orders);
    /** return the average price of all the bids sent */
    static double getAveragePrice(std::vector<OrderBookEntry>& orders);
    /** return the price spread of all the bids sent */
    static double getPriceSpread(std::vector<OrderBookEntry>& orders);
    /** returns the earliest time in the orderbook */
    std::string getEarliestTime();
    /** returns the next time after the sent time 
     * in the orderbook. if there is no next timestamp,
     * wraps around to the start */
    std::string getNextTime(std::string timestamp);

    private:
    std::vector<OrderBookEntry> orders;
};

#include "OrderBook.hpp"
#include "CSVReader.hpp"

#include <iostream>
#include <map>

OrderBook::OrderBook(std::string filename) {
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> products;
    
    std::map<std::string, bool> productMap;
    
    for (OrderBookEntry& e : orders) {
        productMap[e.product] = true;
    }
    
    // now flatten the map to a vector of strings
    for (auto const& e : productMap) {
        products.push_back(e.first);
    }
    
    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp) {
    std::vector<OrderBookEntry> orders_sub;
    
    for (OrderBookEntry& e : orders) {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }
    
    return orders_sub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders) {
    double Highest = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (Highest < e.price) Highest = e.price;
    }
    return Highest;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders) {
    double lowest = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (lowest > e.price) lowest = e.price;     
    }
    return lowest;
}

double OrderBook::getAveragePrice(std::vector<OrderBookEntry>& orders) {
    double sum = 0;
    for (OrderBookEntry& e : orders)
    {
        sum += e.price;
    }
    return sum/orders.size();
}

double OrderBook::getPriceSpread(std::vector<OrderBookEntry>& orders) {
    double lowest = getLowPrice(orders);
    double highest = getHighPrice(orders);

    return highest - lowest;
}

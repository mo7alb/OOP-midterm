#include "OrderBook.hpp"
#include "CSVReader.hpp"

#include <iostream>
#include <map>

using namespace std;

OrderBook::OrderBook(string filename) {
    orders = CSVReader::readCSV(filename);
}

vector<string> OrderBook::getKnownProducts() {
    vector<string> products;
    
    map<string, bool> productMap;
    
    for (OrderBookEntry& e : orders) {
        productMap[e.product] = true;
    }
    
    // now flatten the map to a vector of strings
    for (auto const& e : productMap) {
        products.push_back(e.first);
    }
    
    return products;
}

vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, string product, string timestamp) {
    vector<OrderBookEntry> orders_sub;
    
    for (OrderBookEntry& e : orders) {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }
    
    return orders_sub;
}

double OrderBook::getHighPrice(vector<OrderBookEntry>& orders) {
    double Highest = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (Highest < e.price) Highest = e.price;
    }
    return Highest;
}

double OrderBook::getLowPrice(vector<OrderBookEntry>& orders) {
    double lowest = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (lowest > e.price) lowest = e.price;     
    }
    return lowest;
}

double OrderBook::getAveragePrice(vector<OrderBookEntry>& orders) {
    double sum = 0;
    for (OrderBookEntry& e : orders)
    {
        sum += e.price;
    }
    return sum/orders.size();
}

double OrderBook::getPriceSpread(vector<OrderBookEntry>& orders) {
    double lowest = getLowPrice(orders);
    double highest = getHighPrice(orders);

    return highest - lowest;
}

string OrderBook::getEarliestTime() {
    return orders[0].timestamp;
}

string OrderBook::getNextTime(string timestamp) {
    string next_timestamp = "";
    for (OrderBookEntry& e : orders) {
        if (e.timestamp > timestamp) {
            next_timestamp = e.timestamp;
            break;
        }
    }

    if (next_timestamp == "") next_timestamp = orders[0].timestamp;

    return next_timestamp;
}
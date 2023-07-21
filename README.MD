# Merkel

### Overview

A basic CryptoCurrency trading platform built with C++. It is a commandline application that reads data from a csv file to set the rates for different cryptocurrencies. It then takes user input to make trades and moves further in time changing the rates of cryptocurrencies. This was a part of a midterm solution for the module Object Oriented Programming.

### Getting Started

1. Prerequisistes: A c++ compiler called g++
2. In a terminal run the following command

   ```console
   g++ -std=c++11 main.cpp MerkelMain.cpp OrderBook.cpp OrderBookEntry.cpp CSVReader.cpp
   ```

3. run the application using the following command in a terminal

   ```console
   ./a.out
   ```

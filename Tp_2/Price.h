#pragma once
#include <iostream>
#include <string>

class Price {
private:
    std::string productName;
    std::string storeName;
    double productCost;

public:
    Price() : productName("-"), storeName("-"), productCost(0) {}

    Price(const std::string& name, const std::string& store, double cost)
        : productName(name), storeName(store), productCost(cost) {}

    std::string getProductName() const {
        return productName;
    }

    std::string getStoreName() const {
        return storeName;
    }

    double getProductCost() const {
        return productCost;
    }

    friend std::ostream& operator<<(std::ostream& os, const Price& price);
    friend std::istream& operator>>(std::istream& is, Price& price);
};
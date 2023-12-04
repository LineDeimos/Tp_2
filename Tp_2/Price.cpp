#include "Price.h"

// Перегруженная операция вставки для вывода информации о товаре
std::ostream& operator<<(std::ostream& os, const Price& price) {
    os << "Product: " << price.productName << "\n";
    os << "Store: " << price.storeName << "\n";
    os << "Cost: " << price.productCost << " rubles\n";
    return os;
}

// Перегруженная операция извлечения для ввода информации о товаре
std::istream& operator>>(std::istream& is, Price& price) {
    std::cout << "Enter product name: ";
    std::getline(is >> std::ws, price.productName);

    std::cout << "Enter store name: ";
    std::getline(is >> std::ws, price.storeName);

    std::cout << "Enter product cost: ";
    is >> price.productCost;

    return is;
}
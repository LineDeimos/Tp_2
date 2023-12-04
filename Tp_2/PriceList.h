#pragma once
#include "Price.h"

class Node {
public:
    Price data;
    Node* next;

    Node(const Price& value) : data(value), next(nullptr) {}
};

class PriceList {
private:
    Node* head;

    Node* partition(Node* low, Node* high);

    void quickSort(Node* low, Node* high);

public:
    PriceList() : head(nullptr) {}

    ~PriceList();

    // Метод для вставки элемента в список
    void insert(const Price& value);

    void remove(const std::string& productName);

    Price* find(const std::string& productName) const;

    void displayAll() const;

    // Метод для вывода информации о товарах в магазине
    void displayByStore(const std::string& searchStore) const;

    void sort();
};


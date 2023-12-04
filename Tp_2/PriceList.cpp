#include "PriceList.h"

Node* PriceList::partition(Node* low, Node* high)
{
    Price pivot = high->data;
    Node* i = low->next;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data.getStoreName() < pivot.getStoreName()) {
            std::swap(i->data, j->data);
            i = i->next;
        }
    }

    std::swap(i->data, high->data);
    return i;
}

void PriceList::quickSort(Node* low, Node* high)
{
    if (low != nullptr && high != nullptr && low != high && low->next != high) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}

PriceList::~PriceList()
{
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void PriceList::insert(const Price& value)
{
    Node* newNode = new Node(value);

    if (head == nullptr || value.getStoreName() < head->data.getStoreName()) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data.getStoreName() <= value.getStoreName()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void PriceList::remove(const std::string& productName)
{
    if (head == nullptr) {
        std::cout << "Price list is empty.\n";
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data.getProductName() == productName) {
            if (prev == nullptr) {
                // Элемент находится в начале списка
                head = current->next;
            }
            else {
                // Элемент находится в середине или в конце списка
                prev->next = current->next;
            }

            // Удаляем текущий элемент
            delete current;
            std::cout << "Product removed from the price list.\n";
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cout << "Product with the specified name not found.\n";
}

Price* PriceList::find(const std::string& productName) const
{
    Node* current = head;

    while (current != nullptr) {
        if (current->data.getProductName() == productName) {
            return &current->data;
        }

        current = current->next;
    }

    return nullptr;
}

void PriceList::displayAll() const
{
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << "\n";
        current = current->next;
    }
}

void PriceList::displayByStore(const std::string& searchStore) const
{
    Node* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data.getStoreName() == searchStore) {
            std::cout << current->data << "\n";
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        std::cout << "No products found in the specified store.\n";
    }
}

void PriceList::sort()
{
    quickSort(head, nullptr);
}

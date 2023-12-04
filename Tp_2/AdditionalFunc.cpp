#include "AdditionalFunc.h"

void clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void startMainMenu()
{
	char choice;

	do {
		system("cls");
		std::cout << "-----Main-Menu-----\n\n";
		std::cout << "1 - Task #1\n";
		std::cout << "2 - Task #2\n";
		std::cout << "0 - Exit\n\n";
		std::cout << ">> ";

		std::cin >> choice;

		switch (choice) {
		case '1': {
			startFirstTask();
		}
		case '2': {
			startSecondTask();
		}
		case '0': {
			std::cout << "Program terminated.\n";
			break;
		}
		default:
			std::cout << "Invalid choice. Please choose from 0 to 2.\n";
			clearInputBuffer();
			break;
		}
	} while (choice != '0');
}

void startFirstTask()
{
	PriceList priceList;
	char choice;

	do {
		system("cls");
		std::cout << "-------------------Task-#1-------------------\n\n";
		std::cout << "1 - Add a product to the price list\n";
		std::cout << "2 - Remove a product from the price list\n";
		std::cout << "3 - Modify information of a product\n";
		std::cout << "4 - Display products in a specific store\n";
		std::cout << "5 - Display all products in the price list\n";
		std::cout << "0 - Exit\n\n";
		std::cout << ">> ";

		std::cin >> choice;

		switch (choice) {
		case '1': {
			Price newProduct;
			std::cin >> newProduct;
			priceList.insert(newProduct);
			std::cout << "Product added to the price list.\n";
			system("Pause");
			break;
		}
		case '2': {
			std::string productName;
			std::cout << "Enter the product name to remove: ";
			std::cin >> productName;
			priceList.remove(productName);
			system("Pause");
			break;
		}
		case '3': {
			std::string productName;
			std::cout << "Enter the product name to modify product information: ";
			std::cin >> productName;

			Price* productToUpdate = priceList.find(productName);
			if (productToUpdate) {
				std::cout << "Current product information:\n" << *productToUpdate << '\n';
				std::cin >> *productToUpdate;
				std::cout << "Product information updated.\n";
			}
			else {
				std::cout << "Product with the specified product name not found.\n";
			}
			system("Pause");
			break;
		}
		case '4': {
			std::cout << "Enter the store name to display products: ";
			std::string searchStore;
			std::cin >> searchStore;
			std::cout << '\n';
			priceList.displayByStore(searchStore);
			system("Pause");
			break;
		}
		case '5': {
			std::cout << '\n';
			priceList.displayAll();
			system("Pause");
			break;
		}
		case '0':
			break;

		default:
			std::cout << "Invalid choice. Please choose from 0 to 5.\n";
			system("Pause");
			clearInputBuffer();
			break;
		}
	} while (choice != '0');
}

void startSecondTask()
{
	system("cls");
	std::cout << "----------------Task-#2----------------\n\n";
	std::string filename;
	std::cout << "Enter the filename: ";
	std::cin >> filename;
	processSentences(filename);
}

bool isOneLetterWord(const std::string& word)
{
	return word.length() == 1;
}

void processSentences(const std::string& filename)
{
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		throw FileOpenException(filename);
	}

	std::vector<std::string> oneLetterSentence;
	std::vector<std::string> otherSentences;

	std::string line;
	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string word;

		iss >> word;
		if (isOneLetterWord(word)) {
			oneLetterSentence.push_back(line);
			continue;
		}

		if (otherSentences.empty() || otherSentences.back() != line) {
			otherSentences.push_back(line);
		}
	}

	std::cout << "Sentences starting with one-letter words:" << std::endl;
	for (const auto& sentence : oneLetterSentence) {
		std::cout << sentence << std::endl;
	}

	std::cout << "\nOther sentences:" << std::endl;
	for (const auto& sentence : otherSentences) {
		std::cout << sentence << std::endl;
	}

	inputFile.close();
	
	system("Pause");
}

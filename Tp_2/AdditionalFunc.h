#pragma once
#include "PriceList.h"
#include "FileExeption.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

void clearInputBuffer();

void startMainMenu();

void startFirstTask();

void startSecondTask();

bool isOneLetterWord(const std::string& word);

void processSentences(const std::string& filename);

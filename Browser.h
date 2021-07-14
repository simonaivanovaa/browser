#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
class Browser
{
	struct Tab
	{
		time_t timestamp;
		char* URL;

		Tab* next;
		Tab* prev;
		Tab()
		{
			timestamp = time(0);
			next = nullptr;
			prev = nullptr;
			URL = new char[11];
			strcpy(URL, "about blank");
		}
		Tab(char* URL)
		{
			this->timestamp = time(0);
			next = nullptr;
			prev = nullptr;
			this->URL = new char[(strlen(URL)) + 1];
			strcpy(this->URL, URL);
		}

	};
	Tab* head;
	Tab* tail;
	Tab* current;
	size_t count = 1;

	void Free();
	void CopyFrom(const Browser& other);
public:
	Browser();
	Browser(const Browser& other);
	Browser& operator=(const Browser& other);
	~Browser();

	void Insert(char* URL);
	void Back();
	void Forward();
	void Remove();
	void Go(char* URL);
	void Print();
	void UpgradeTimestamp(Tab* toUpdate);

	void getAtIndex(size_t index, Tab*& ptr);
	size_t getSize() const;

	void Sort();



};

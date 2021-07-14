#include "Browser.h"
Browser::Browser() : count(1)
{
	Tab* defaultOne = new Tab();
	head = tail = current = defaultOne;
}
Browser::Browser(const Browser& other)
{
	CopyFrom(other);
}
void Browser::CopyFrom(const Browser& other)
{
	Tab* otherIter = other.head;
	while (otherIter != nullptr)
	{
		Insert(otherIter->URL);
		otherIter = otherIter->next;
	}
}
void Browser::Free()
{
	Tab* iter = head;
	while (iter != nullptr)
	{
		Tab* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
}
Browser& Browser::operator=(const Browser& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Browser::~Browser()
{
	Free();
}
size_t Browser::getSize() const
{
	return count;
}
void Browser::Print()
{
	Tab* iter = head;
	while (iter != nullptr)
	{
		if (iter == current)
			std::cout << ">";
		cout << iter->URL << " " << iter->timestamp << endl;
		iter = iter->next;
	}


}
void Browser::getAtIndex(size_t index, Tab*& ptr)
{
	Tab* iter = head;
	for (size_t i = 0; i < index; i++)
		iter = iter->next;
	ptr = iter;
}


void Browser::Insert(char* URL) {
	Tab* added = new Tab(URL);
	if (head == current && current == tail) {
		head->next = added;
		added->next = nullptr;
		added->prev = head;
		tail = current = added;
		current->timestamp = time(nullptr);
	}
	else if (head == current) {

		head->next = added;
		added->prev = head;
		added->next = head->next;
		head->next->prev = added;
		current = added;
		current->timestamp = time(nullptr);
	}
	else if (tail == current) {
		tail->next = added;
		added->prev = tail;
		added->next = nullptr;
		tail = current = added;
		current->timestamp = time(nullptr);

	}
	else {
		Tab* curnext = current->next;
		Tab* curprev = current->prev;
		curnext->prev = added;
		added->next = curnext;
		current->next = added;
		added->prev = current;
		current = added;
		current->timestamp = time(nullptr);


	}

	count++;
	//UpgradeTimestamp(current);

}
void Browser::Back() {
	if (head == current) {

	}
	else {
		Tab* curprev = current->prev;
		current = curprev;
	}
}
void Browser::Forward() {
	if (tail == current) {

	}
	else {
		Tab* curnext = current->next;
		current = curnext;
	}

}
void Browser::Remove() {
	Tab* toRemove = current;
	if (head == current && tail == current) {
		Tab* newOne = new Tab();
		head = tail = current = newOne;

	}
	else if (current == tail) {
		tail->prev->next = nullptr;
		tail = current = toRemove->prev;
		count--;
	}
	else {
		Tab* curnext = toRemove->next;
		curnext->prev = toRemove->prev;
		toRemove->prev->next = toRemove->next;
		current = curnext;
		count--;
	}

}
void Browser::Go(char* URL) {
	Tab* refresh = new Tab(URL);

	if (head == current && tail == current) {

		head = tail = current = refresh;
		current->timestamp = time(nullptr);
	}
	else if (tail == current) {

		tail->prev->next = refresh;
		refresh->prev = tail->prev;
		refresh->next = nullptr;
		tail = current = refresh;
		current->timestamp = time(nullptr);

	}
	else {
		current->next->prev = refresh;
		current->prev->next = refresh;
		refresh->next = current->next;
		refresh->prev = current->prev;
		current = refresh;
		current->timestamp = time(nullptr);
	}


	//UpgradeTimestamp(current);
}
void Browser::UpgradeTimestamp(Tab* toUpdate) {
	Tab* newOne = new Tab(toUpdate->URL);
	toUpdate->timestamp = time(0);
}
void  Browser::Sort()
{
	Tab* iter = head;
	Tab* lexMin = head;


	while (iter != nullptr)
	{

	}
	Print();

}
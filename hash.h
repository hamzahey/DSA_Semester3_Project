#include <iostream>
using namespace std;



template <typename o>
class ListNode
{
public:
	o data;
	ListNode* next;
};


template <typename o>
class LinkedList
{
public:
	ListNode<o>* start;
	ListNode<o>* last;
	ListNode<o>* ploc;
	ListNode<o>* loc;
	int listSize;

	LinkedList();
	ListNode<o>* getStart();
	ListNode<o>* getLast();
	ListNode<o>* getLoc();
	ListNode<o>* getPloc();
	int size();
	bool isEmpty();
	void insertAtFront(o value);
	void insertAtEnd(o value);
	void printList();
	void search(int value, bool sorted = false);
	void insertSorted(o value);
	void Delete(o value);
	void destroy();
};

template <typename o>
LinkedList<o>::LinkedList() {
	start = NULL;
	last = NULL;
	loc = NULL;
	ploc = NULL;
	listSize = 0;
}
template <typename o>
ListNode<o>* LinkedList<o>::getStart() {
	return start;
}
template <typename o>
ListNode<o>* LinkedList<o>::getLast() {
	return last;
}
template <typename o>
ListNode<o>* LinkedList<o>::getLoc() {
	return loc;
}
template <typename o>
ListNode<o>* LinkedList<o>::getPloc() {
	return ploc;
}
template <typename o>
int LinkedList<o>::size() {
	return listSize;
}
template <typename o>
bool LinkedList<o>::isEmpty() {
	return (start == NULL);
}
template <typename o>
void LinkedList<o>::printList() {
	ListNode<o>* temp = start;
	if (isEmpty()) {
		return;
	}
	while (temp != NULL) {
		cout << temp->data.complete<<endl;
		temp = temp->next;
	}
	// cout << "NULL" << endl;
}
template <typename o>
void LinkedList<o>::insertAtFront(o value) {
	ListNode<o>* newnode = new ListNode<o>();
	newnode->data = value;

	if (!isEmpty()) {
		newnode->next = start;
	}
	else {
		newnode->next = NULL;
		last = newnode;
	}
	start = newnode;
	listSize++;
}
template <typename o>
void LinkedList<o>::insertAtEnd(o value) {
	ListNode<o>* newnode = new ListNode<o>();
	newnode->data = value;
	newnode->next = NULL;

	if (!isEmpty()) {
		last->next = newnode;
	}
	else {
		start = newnode;
	}
	last = newnode;
	listSize++;
}
template <typename o>
void LinkedList<o>::search(int value, bool sorted) {
	ploc = NULL;
	loc = start;

	if (sorted) {
		while (loc != NULL && loc->data < value) {
			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL && loc->data != value) {
			loc = NULL;
		}
	}
	else {
		while (loc != NULL && loc->data != value) {
			ploc = loc;
			loc = loc->next;
		}
	}
}
template <typename o>
void LinkedList<o>::insertSorted(o value) {
	search(value, true);

	//If value exists.
	if (loc != NULL) {
		return;
	}

	//If position is as head node.
	if (ploc == NULL) {
		insertAtFront(value);
	}
	//If position is at tail end.
	else if (ploc->next == NULL) {
		insertAtEnd(value);
	}
	//Position is after ploc in the middle.
	else {
		ListNode<o>* newnode = new ListNode<o>();
		newnode->data = value;
		newnode->next = ploc->next;
		ploc->next = newnode;
		listSize++;
	}
}
template <typename o>
void LinkedList<o>::Delete(o value) {
	if (isEmpty()) {
		return;
	}

	search(value);
	//If value is found.
	if (loc != NULL) {
		//If value is in the first node.
		if (ploc == NULL) {
			start = start->next;
			delete loc;
		}
		//If value is in the last node.
		else if (loc->next == NULL) {
			last = ploc;
			last->next = NULL;
			delete loc;
		}
		else {
			ploc->next = loc->next;
			delete loc;
		}
		listSize--;
	}
}
template <typename o>
void LinkedList<o>::destroy() {
	ListNode<o>* temp;
	while (start != NULL) {
		temp = start;
		start = start->next;
		delete temp;
	}
	last = NULL;
	listSize = 0;
}





template <typename o>
//Using chaining.
class HashTable1
{
private:
	LinkedList<o>* pArray;
    int arraySize;
	int nodesCount;

public:
    HashTable1<o>();
    HashTable1<o>(int size);
	void createHashTable(int size);
	bool isEmpty();
    void insert(o data,int item);
    void Delete(int item);
	ListNode<o>* search(int item);
    int hashFunction(int key);
    void printHashTable();
    void destroy();
	// this function is used for printing data greater than given value
	void searchByQuantity(int quantity);
	// this function is used for printing data smaller than given value
	void searchByQuantitymax(int quantity);
};

template <typename o>
HashTable1<o>::HashTable1() {
	nodesCount = 0;
    arraySize = 11;
    pArray = new LinkedList<o>[arraySize];
}

template <typename o>
HashTable1<o>::HashTable1(int size) {
	nodesCount = 0;
    arraySize = size;
    pArray = new LinkedList<o>[arraySize];
}

template <typename o>
void HashTable1<o>::createHashTable(int size) {
	if (!isEmpty()) {
		destroy();
	}
	nodesCount = 0;
	arraySize = size;
	pArray = new LinkedList<o>[arraySize];
}

template <typename o>
bool HashTable1<o>::isEmpty() {
	return (nodesCount == 0);
}

template <typename o>
int HashTable1<o>::hashFunction(int key) {
    return (key % arraySize);
}

template <typename o>
void HashTable1<o>::insert(o data,int item) {
    int index = hashFunction(item);
    pArray[index].insertAtEnd(data);
	nodesCount++;
}

template <typename o>
void HashTable1<o>::Delete(int item) {
    int index = hashFunction(item);
    pArray[index].Delete(item);
	nodesCount--;
}

template <typename o>
ListNode<o>* HashTable1<o>::search(int item) {
	int index = hashFunction(item);
	pArray[index].search(item);
	return pArray[index].getLoc();
}

template <typename o>
void HashTable1<o>::printHashTable() {
    for (int i = 0; i < arraySize; i++) {
		cout << i << ": ";
		if (!pArray[i].isEmpty()) {
			pArray[i].printList();
		}
		else {
			cout << "\n";
		}
    }
}
  template<typename o>
    void HashTable1<o>::searchByQuantity(int quantity){
      for (int i = quantity; i <=534; i++) {
		if (!pArray[i].isEmpty()) {
			pArray[i].printList();
		}
		else
		cout<<"";
	}
	}
  template<typename o>
    void HashTable1<o>::searchByQuantitymax(int quantity){
      for (int i = 0; i <=quantity; i++) {
		if (!pArray[i].isEmpty()) {
			pArray[i].printList();
		}
		else
		cout<<"";
	}
	}
template <typename o>
void HashTable1<o>::destroy() {
    for (int i = 0; i < arraySize; i++) {
        pArray[i].destroy();
    }
    delete pArray;
    arraySize = 0;
}
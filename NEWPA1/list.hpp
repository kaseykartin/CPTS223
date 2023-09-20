#pragma once

#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

class linkedList {
public:
	linkedList();

	~linkedList() {};

	Node* getHeadPtr();

	void setHeadPtr(Node* mpHead);

	void insertAtFront(string command, string description);

	void deleteNode(string cmd);

	void deleteList(Node* mpHead);

	int displayMenu(void);

	Node* loadCommandList(void);


private:

	Node* mpHead;
};

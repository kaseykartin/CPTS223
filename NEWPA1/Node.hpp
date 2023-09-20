#pragma once

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Node {
public:

	Node(string cmd, string desc, Node* mpNext = nullptr);  // constructor

	~Node(); // destructor 


	// getters
	string getCommand() const;
	string getDescription() const;
	Node* getNextPtr() const;      // used to retrieve a copy of the node's next pointer

	// setters
	void setCommand(string cmd);
	void setDescription(string desc);
	void setNextPtr(Node* mpNext); // used to modify the node's next pointer

private:
	string command;
	string description;
	Node* mpNext;    // should be set to NULL in the constructor
};
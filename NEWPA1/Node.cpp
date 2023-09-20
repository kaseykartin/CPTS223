#include "Node.hpp"

Node::Node(string cmd, string desc, Node* mpNext)
{
	this->command = cmd;
	this->description = desc;
}

Node::~Node()
{
	//implicit destructor
}


string Node::getCommand() const
{
	return this->command;
}

string Node::getDescription() const
{
	return this->description;
}

Node* Node::getNextPtr() const
{
	return this->mpNext;
}

void Node::setCommand(string cmd)
{
	this->command = cmd;
}

void Node::setDescription(string desc)
{
	this->description = desc;
}

void Node::setNextPtr(Node* mpNext)
{
	this->mpNext = mpNext;
}
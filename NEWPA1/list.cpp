#include "list.hpp"

linkedList::linkedList()
{
	mpHead = nullptr;
}

Node* linkedList::getHeadPtr()
{
	return this->mpHead;
}

void linkedList::setHeadPtr(Node* mpHead)
{
	this->mpHead = mpHead;
}

//insertAtFront function, takes created new node as input, puts it at front of list
void linkedList::insertAtFront(string command, string description)
{
	Node* newNode = new Node(command, description);

	if (mpHead == nullptr)
	{
		mpHead = newNode;
	}
	else
	{
		Node* pMem = newNode;
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}
}

//deleteNode command, takes cmd as input variable in order to search for correct node to delete
void linkedList::deleteNode(string cmd)
{
	Node* pTemp = nullptr, * pCur = mpHead;
	while (pCur->getCommand() != cmd)
	{
		pTemp = pCur;
		pCur = pCur->getNextPtr();
	}
}

void linkedList::deleteList(Node* mpHead)
{

}


Node* linkedList::loadCommandList(void)
{
	fstream commandListFile;
	linkedList commandList;
	string cmdTemp = "", descTemp = "";
	commandListFile.open("commands.csv");


	if (commandListFile.is_open())
	{
		while (!commandListFile.eof())
		{
			getline(commandListFile, cmdTemp, ',');
			getline(commandListFile, descTemp, ',');

			Node* pTemp = new Node(cmdTemp, descTemp);
			commandList.insertAtFront(cmdTemp, descTemp);
		}
	}

	else
	{
		cout << "Error opening file!!!" << endl;
	}

	commandListFile.close();

	return this->mpHead;

}

//displaymenu function, returns an integer selection
int linkedList::displayMenu(void)
{
	int selection = 0;

	cout << "Welcome to the Linux Command Matching Game! Please make a selection:" << endl;
	cout << "1: Game Rules" << endl;
	cout << "2. Play Game" << endl;
	cout << "3. Load Previous Game" << endl;
	cout << "4. Add Command" << endl;
	cout << "5. Remove Command" << endl;
	cout << "6. Exit" << endl;

	cin >> selection;

	return selection;
}
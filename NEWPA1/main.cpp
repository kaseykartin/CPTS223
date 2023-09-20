#include "list.hpp"


int main()
{
	linkedList commandList;
	fstream commandListFile;
	string cmdTemp = "", descTemp = "", newLine = "";
	commandListFile.open("commands.csv");

	//construct the linked list, each node is made of two stings, a command and its statement
	if (commandListFile.is_open())
	{
		while (!commandListFile.eof())
		{
			getline(commandListFile, cmdTemp, ',');
			getline(commandListFile, descTemp, '\n');

			commandList.insertAtFront(cmdTemp, descTemp);
		}
	}

	else
	{
		cout << "Error opening file!!!" << endl;
	}

	//the actual game starts now

	int selection = commandList.displayMenu();

	while (selection != 6)
	{
		if (selection == 1) //game rules
		{
			cout << "A linux command will be displayed to the player, three different descriptions" << endl;
			cout << "will then be shown, with only one being the correct description for the displayed" << endl;
			cout << "command. If the player selects the correct description, a point will be added to" << endl;
			cout << "their profile." << endl;
			system("pause");
			system("cls");
		}
		else if (selection == 2) //play game
		{

		}
		else if (selection == 3) //load previous game
		{

		}
		else if (selection == 4) //add command
		{

		}
		else if (selection == 5) //remove command
		{

		}
		else if (selection == 6) //exit boiiiii
		{
			return 0;
		}
		else // in place if player makes an invalid selection
		{
			while (selection < 0 || selection > 6)
			{
				cout << "Please enter an integer between 1-6" << endl;
			}
		}
		
		selection = commandList.displayMenu();
	}


	commandListFile.close();

	return 0;
}
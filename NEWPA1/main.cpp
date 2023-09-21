#include "list.hpp"
#include "Profiles.hpp"

//ADVANTAGES/DISADVANTAGES LINKED LIST
//Advantage - A linked list doesnt not need to be created with a specific length, items can be added infinitely
//Disadvantage - Must start from an end of the list in order to traverse its elements, cannot go straight to a value in the middle

//ADVANTAGES/DISADVANTAGES ARRAY
//Advantage - Can look up values at any point within the array at any time, ie can find a value in the middle of an array without starting at the first element
//Disadvantage - must be created with a set size, cannot vary in size once initialized


int main()
{
	linkedList commandList;
	fstream commandListFile;
	fstream profilesFile;
	Profile profileList[20];
	string cmdTemp = "", descTemp = "", newLine = "", player = "", playerTemp = "";
	int playerScore = 0, questions = 0;

	srand(time(nullptr)); //initialize random number generator

	commandListFile.open("commands.csv");
	profilesFile.open("profiles.csv");

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

	//do the same but for the profile list
	if (profilesFile.is_open())
	{
		int k = 0;
		while (!profilesFile.eof())
		{
			getline(profilesFile, playerTemp, ',');
			getline(profilesFile, descTemp, '\n');

			int scoreTemp = stoi(descTemp);
			profileList[k].setName(playerTemp);
			profileList[k].setScore(scoreTemp);
			k++;
		}
	}

	else
	{
		cout << "Error opening file!!!" << endl;
	}

	//the actual game starts now

	int selection = commandList.displayMenu();
	Node* pCur = commandList.getHeadPtr();

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
			if (player == "") //no profile has been loaded, starting new game
			{

				Profile profileTemp;
				profileTemp.setScore(0);
				
				cout << "Please enter your name: " << endl;
				cin >> player;

				profileTemp.setName(player);
				for (int i = 0; i < 20; i++)
				{
					if (profileList[i].getName() == "")
					{
						profileList[i] = profileTemp;
						i = 100;
					}
				}
			}

			cout << "How many questions? (integer between 5-30)" << endl;
			cin >> questions;

			while (questions < 5 || questions > 30) //make sure a valid number is given
			{
				cout << "Invalid question count, please enter an integer between 5 and 30: " << endl;
				cin >> questions;
			}

			for (int i = 0; i < questions; i++) //meat and potatoes of the game
			{
				int randomList[30], rl = 0, playerAnswer = 0;
				int random1 = rand() % questions, random2 = rand() % questions, random3 = rand() % questions;
				string cmd, desc, rd2, rd3;


				for (int k = 0; k < 30; k++) //check to make sure number hasnt been selected before
				{
					while (randomList[k] == random1)
					{
						random1 = rand() % questions;
					}
				}

				while (random2 == random1 || random2 == random3) //sameness check for random2
				{
					random2 = rand() % questions;
				}
				while (random3 == random1 || random3 == random2) //sameness check for random3
				{
					random3 = rand() % questions;
				}


				randomList[i] = random1;

				pCur = commandList.getHeadPtr(); //make sure were starting from head pointer

				for (int j = 0; j < random1; j++) //getting the correct command and description
				{
					pCur = pCur->getNextPtr();
				}
				cmd = pCur->getCommand();
				desc = pCur->getDescription();

				pCur = commandList.getHeadPtr(); //must reset pCur each time its manipulated

				for (int j = 0; j < random2; j++) //getting the first random description
				{
					pCur = pCur->getNextPtr();
				}
				rd2 = pCur->getDescription();

				pCur = commandList.getHeadPtr();

				for (int j = 0; j < random3; j++) //getting the second random description
				{
					pCur = pCur->getNextPtr();
				}
				rd3 = pCur->getDescription();



				//can now display cmd to user and three descriptions in varying order
				//doenst matter what order the random descriptions go in so only three cases are needed
				cout << "Your command is " << cmd << ", what is the correct description? (1-3)" << endl;
				
				int order = (rand() % 3) + 1; //determine the order that descriptions are displayed

				if (order == 1)
				{
					int answer = 1;
					cout << "1. " << desc << "\n2. " << rd2 << "\n3. " << rd3 << endl;
				}

				if (order == 2)
				{
					int answer = 2;
					cout << "1. " << rd2 << "\n2. " << desc << "\n3. " << rd3 << endl;
				}

				if (order == 3)
				{
					int answer = 3;
					cout << "1. " << rd3 << "\n2. " << rd2 << "\n3. " << desc << endl;
				}

				cin >> playerAnswer;

				if (playerAnswer == order)
				{
					cout << "Correct! One point added" << endl;
					playerScore++;
				}
				else
				{
					cout << "False, the correct answer was " << order << ". Minus one point" << endl;
					playerScore--;
				}

			}

			cout << "Thats Game! Your total score is " << playerScore << ". Play Again!" << endl;
			system("pause");
			system("cls");


		}
		else if (selection == 3) //load previous game
		{
			cout << "Please enter your profile name" << endl;
			cin >> playerTemp;
			int check = 0;

			for (int f = 0; f < 20; f++)
			{
				if (profileList[f].getName() == playerTemp)
				{
					player = playerTemp;
					playerScore = profileList[f].getScore();
					check = 1;
				}
			}
			if (check == 0)
			{
				cout << "Profile not found" << endl;
			}
			if (check == 1)
			{
				cout << "Welcome " << player << "!\nYour current score is " << playerScore << endl;
			}
		}
		else if (selection == 4) //add command
		{
			string cmdTemp = "", descTemp = "";
			pCur = commandList.getHeadPtr(); //reset pcur just in case
			system("cls");
			cout << "Please enter the name of the command you would like to add (N to quit): ";
			cin >> cmdTemp;

			if (cmdTemp == "N")
			{
				selection = 0;
			}
			else 
			{
				cout << "\nPlease enter the description of the command you're adding:" << endl;
				getline(cin >> ws, descTemp); //can get multiple words using getline()
				commandList.insertAtFront(cmdTemp, descTemp);
			}
			while (pCur != nullptr)
			{
				if (pCur->getCommand() == cmdTemp)
				{
					cout << "Command already in list, please try again" << endl;
					system("pause");
					system("cls");
					main();
				}
				else
				{
					pCur = pCur->getNextPtr();
				}
			}


		}
		else if (selection == 5) //remove command
		{
			string cmdTemp = "";
			pCur = commandList.getHeadPtr(); //reset pCur just in case
			int k = 0;

			system("cls");
			cout << "Please enter the command you would like to remove (N to quit)" << endl;
			cin >> cmdTemp;

			if (cmdTemp == "N")
			{
				system("pause");
				system("cls");

				pCur = nullptr;
				k = 1;
			}

			while (pCur != nullptr)
			{
				if (pCur->getCommand() == cmdTemp)
				{
					k = 1;
					commandList.deleteNode(cmdTemp);
					cout << "Command " << cmdTemp << " Removed" << endl;
					system("pause");
					system("cls");
				}
				pCur = pCur->getNextPtr();
			}

			if (k == 0)
			{

				cout << "Command Not Found" << endl;
				system("pause");
				system("cls");

			}
			
		}
		else if (selection == 6) //exit boiiiii
		{
			pCur = commandList.getHeadPtr();

			while (pCur != nullptr)
			{
				commandListFile << pCur->getCommand() << ", " << pCur->getDescription() << "\n";
				pCur = pCur->getNextPtr();
			}
			commandListFile.close();

			for (int i = 0; i < 20; i++)
			{
				profilesFile << profileList[i].getName() << ", " << profileList->getScore() << "\n";
			}
			profilesFile.close();

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


	return 0;
}
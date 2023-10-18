#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //Scenario 1

    //Create a new std::map
    std::map<string, TwitterData> Usernames; //using usernames as key to find savage1 later

    //Insert all data into the std::map
    for (int i = 0; i < 5; i++)
    {
        Usernames[twitter_data[i].getUserName()] = twitter_data[i];
    }

    //iterate through the map and print the key-value pairs
    //https://stackoverflow.com/questions/1443793/iterate-keys-in-a-c-map/21436440#21436440 used as reference
    for (const auto& myPair : Usernames) 
    {
        std::cout << myPair.first << " : " << myPair.second.print() << "\n";
    }

    //Find savage1 and print out his record
    //https://www.geeksforgeeks.org/map-find-function-in-c-stl/ used as reference
    string target = "savage1";
    auto userTemp = Usernames.find(target);
    if (userTemp != Usernames.end()) 
    {
        cout << userTemp->first <<" : found : Value : " << userTemp->second.print() << endl;
    }
    else cout << target <<" : Not found" << endl;

    //Remove this person from the map
    Usernames.erase(target);
    cout << "\n\n" << endl; //get some space between scenario 1 and 2

    //-----------------------------------------------------------------------------------------------
    
    //Scenario 2
    //Create a new std::map
    std::map<string, TwitterData> Emails; //Using emails as key to find kat@gmail.com later

    //Insert the data using Email as key
    for (int i = 0; i < 5; i++)
    {
        Emails[twitter_data[i].getEmail()] = twitter_data[i];
    }

    //Iterate and print
    for (const auto& myPair : Emails)
    {
        std::cout << myPair.first << " : " << myPair.second.print() << "\n";
    }

    //find kat@gmail.com and print the record
    string target2 = "kat@gmail.com";
    auto emailTemp = Emails.find(target2);
    if (emailTemp != Emails.end())
    {
        cout << emailTemp->first << " : found : Value : " << emailTemp->second.print() << endl;
    }
    else cout << target2 << " : Not found" << endl;

    //Remove this person from the map
    Emails.erase(target2);


    return 0;
}
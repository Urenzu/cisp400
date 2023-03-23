#include "SemanticDictionary.h"
using namespace std;

//include SemanticDictionary header file

void printMenu()
{
    cout << "1.  Read the semantic dictionary from storage" << endl;
    cout << "2.  Write the semantic dictionary to storage" << endl;
    cout << "3.  Read and process a text file (get smarter!)" << endl;
    cout << "4.  Solve a TOEFL question" << endl;
    cout << "5.  Quit" << endl;
    cout << "> ";
}

int main()
{
    //declare SemanticDictionary object
    SemanticDictionary d;

    //declare string for menu choice
    string choice;

    //declare and assign a string for the dictionary file name
    string dictionaryFileName = "SemanticDictionary.txt";

    //output some kind of welcome message
    cout << "Yo, let's check out some words." << endl;
    //print the menu
    printMenu();
    //input the menu choice
    cin >> choice;

    while(choice != "5")
    {
        if(choice == "1")
        {
            //output that you are reading the dictionary file
            cout << "Reading dictionary from file..." << endl;
            //construct ifstream object and open the file
            ifstream ifs(dictionaryFileName);
            if(!ifs)
            {
                cout << "Dictionary file failed to open..." << endl;
            }
            else
            {
                //extract from ifstream object into your dictionary object
                ifs >> d;
                //output that you are done reading
                cout << "Done reading." << endl;
            }
        }
        else if(choice == "2")
        {
            //warn the user that this will overwrite the previous file, ask if they want to proceed
            //if proceed
            cout << "Previous dictionary file will be overwritten. Proceed? (y or no):" << endl;
            string proceedChoice;
            cin >> proceedChoice;
            if(proceedChoice == "y")
            {
                //output that you are writing the dictionary to a file
                cout << "Writing dictionary to a file..." << endl;
                //declare and open ofstream object
                ofstream ofs(dictionaryFileName);
                //insert from the dictionary object into the ofstream object
                ofs << d;
                //output that you are done writing
                cout << "Done writing." << endl;
            }
        }
        else if(choice == "3")
        {
            //declare variable for file name
            string userFileName;
            //prompt and input file name
            cout << "Name of file to read: ";
            cin >> userFileName;
            //construct ifstream object and open the file
            ifstream ifs(userFileName);

            if(!ifs)
            {
                cout << "Couldn't open file." << endl;
            }
            else
            {
                cout << "File opened, reading..." << endl;
                auto start = high_resolution_clock::now(); //code to record time elapsed
                //declare a variable to hold all of the text
                string giantText;
                //loop to read every word in the file.  Concatenate each word onto text, separated by " "
                string s;
                while(ifs >> s) giantText += s + " ";
                //pass text into getSentenceLists.  (This is a copy paste from the last project)
                vector<vector<string>> sentenceLists = getSentenceLists(giantText);
                //Create a double for loop to loop through each word of each sentenceList in sentenceLists and 
                //    process the target word.  (This is also a copy paste from the last project)
                for(vector<string> sentenceList : sentenceLists)
                for(string targetWord : sentenceList) d.processTargetWord(targetWord, sentenceList);
                auto stop = high_resolution_clock::now();  //code to record time elapsed
                auto duration = duration_cast<milliseconds>(stop - start);
                cout << "Done.  Time elapsed: " << duration.count() << " milliseconds" << endl;
            }
        }
        else if(choice == "4")
        {
            cout << "Enter a TOEFL question as <word> <answer> <choice1> <choice2> <choice3>:" << endl;
            string word, answer, choice1, choice2, choice3;
            cin >> word >> answer >> choice1 >> choice2 >> choice3;

            try
            {
                string s = d.mostSimilarWord(word, vector<string>{choice1, choice2, choice3});
                cout << "Most similar: " << s << endl;
                cout << "Index: " << d.getSimilarity(word, s) << endl;
                if(s == answer) cout << "Correct answer." << endl;
                else cout << "Incorrect answer." << endl;
            }
            catch(runtime_error& e)
            {
                cout << e.what() << endl;
            }
        }
        else
        {
            cout << "Invalid menu choice" << endl;
        }

        printMenu();
        cin >> choice;
    }

    return 0;
}

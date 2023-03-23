#include "SemanticDictionary.h"
using namespace std;

int main()
{
    SemanticDictionary d;

    string text;
    cout << "Type a paragraph followed by a newline to build semantic descriptors:" << endl;
    getline(cin, text);

    vector<vector<string>> sentenceLists = getSentenceLists(text);

    cout << sentenceLists << endl;

    for(vector<string> sentenceList : sentenceLists)
        for(string targetWord : sentenceList) d.processTargetWord(targetWord, sentenceList);

    cout << d << endl;
    
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
    return 0;
}
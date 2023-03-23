#include "SemanticDictionary.h"

vector<vector<string>> getSentenceLists(string text)           // I like lost ark.
{                                                              // I'm almost tier three.
    vector<vector<string>> sentenceLists; ///multidimensional vector
    vector<string> sentenceList;
    string word = "";

    for(size_t i = 0; i < text.size(); i++)
    {
        if(isalpha(text.at(i))) // Within ctype.h header file. // if we see letters at text.at(i) // text.at(i) for connecting to the ith character
        {                                                      // keep going through the letters 
            word += text.at(i);                                // till end of word and add it to
        }                                                      // word string
        else                                                   // while word exists basically
        {                                                      // push word into our sentenceList
            if((word.size() > 0))                              // vector then clear word.
            {                                                  // once text.at(i) encounters a sentence 
                sentenceList.push_back(word);                  // ender and it exists add all words within
                word = "";                                     // sentenceList to our list of sentences.
            }                                                  // then clear our sentenceList to restart
            if((text.at(i) == '?' || text.at(i) == '.' || text.at(i) == '!') && sentenceList.size() > 0)
            {                                                  
                sentenceLists.push_back(sentenceList);
                sentenceList.clear();
            }
        }
    }

    return sentenceLists;
}

ostream& operator<<(ostream& os, const vector<vector<string>>& sentenceLists)
{
    os << "Sentence Lists: " << endl; //Start output proper format
    os << "[" << endl;                

    for(size_t i = 0; i < sentenceLists.size(); i++) // use size_t to be safe for allowing maximum size of vector.
    {                                                // because I guess it's useful for "array indexing and loop counting"
        os<< "[ ";                             
        for(size_t j = 0; j < sentenceLists.at(i).size(); j++) //Our sentenceLists vector is multidimensional...
        {                                                      // It didn't work properly with just i loop so added j loop tried with couts as well. The usual debugging methods weren't working for me since the program compiled.
            os << sentenceLists.at(i).at(j).size() << " ";
        }
        os << "]" << endl;
    }

    return os;
}
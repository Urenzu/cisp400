#include "SemanticDictionary.h"

vector<vector<string>> getSentenceLists(string text)
{
    vector<vector<string>> sentenceLists;
    vector<string> sentenceList;
    string word = "";

    for(size_t i = 0; i < text.size(); i++)
    {
        char c = text.at(i);
        ///if the ith char is alphabetical, concatenate it onto word
        if(isalpha(c)) word += tolower(c);
        ///else
        ///  if the size of word > 0, push it back into sentenceList and make the word empty
        ///  if the ith char is '?', '.', or '!', AND the size of sentenceList > 0, 
        ///    then push back sentenceList into sentenceLists and clear sentenceList
        else
        {
            if(word.size() > 0)
            {
                if(!isStopWord(word)) sentenceList.push_back(word);
                word = "";
            }
            if((c == '?' || c == '.' || c == '!') && sentenceList.size() > 0)
            {
                sentenceLists.push_back(sentenceList);
                sentenceList.clear();
            }
        }
    }

    ///if the size of word > 0, push it back into sentenceList
    ///if the size of sentenceList > 0, push it back into sentenceLists
    if(word.size() > 0)
    {
        if(!isStopWord(word)) sentenceList.push_back(word);
        word = "";
    }
    if(sentenceList.size() > 0)
    {
        sentenceLists.push_back(sentenceList);
    }
    return sentenceLists;
}

/*
Sentence Lists:
[
[ she was vexed irritated and angry with his actions ]
[ he was annoyed and irritated as well wishing he could explain to her how angry he was ]
[ the dog was amused gleefully tearing the couch apart and sprinting around the room ]
[ the cat was frightened trying to hide under the couch that the dog was destroying ]
]
*/

ostream& operator<<(ostream& os, const vector<vector<string>>& sentenceLists)
{
    cout << "Sentence Lists:" << endl;
    cout << "[" << endl;
    for(size_t i = 0; i < sentenceLists.size(); i++)
    {
        cout << "[ ";
        for(size_t j = 0; j < sentenceLists[i].size(); j++)
        {
            cout << sentenceLists[i][j] << " ";
        }
        os << "]" << endl;
    }
    os << "]" << endl;
    return os;
}

int SemanticDictionary::searchTargetWord(string targetWord)
{
    for(size_t i = 0; i < semanticDescriptors.size(); i++)
    {
        if(targetWord == semanticDescriptors[i].getTargetWord()) return i;
    }
    return -1;
}

void SemanticDictionary::processTargetWord(string targetWord, vector<string> sentenceList)
{
    int n = searchTargetWord(targetWord);
    if(n == -1)
    {
        semanticDescriptors.push_back(SemanticDescriptor(targetWord));
        n = semanticDescriptors.size() - 1;
    }
    for(size_t i = 0; i < sentenceList.size(); i++)
    {
        if(sentenceList[i] != targetWord) semanticDescriptors[n].processContextWord(sentenceList[i]);
    }
}

ostream& operator<<(ostream& os, const SemanticDictionary& d)
{
    os << "Semantic Descriptors" << endl << "{" << endl;
    for(size_t i = 0; i < d.semanticDescriptors.size(); i++)
    {
        os << d.semanticDescriptors[i] << endl;
    }
    os << "}" << endl;
    return os;
}

double SemanticDictionary::getSimilarity(string targetWord1, string targetWord2)
{
    int n1 = searchTargetWord(targetWord1);
    int n2 = searchTargetWord(targetWord2);
    if(n1 == -1 || n2 == -1) throw runtime_error("Target words(s) unknown");
    SemanticDescriptor a = semanticDescriptors[n1];
    SemanticDescriptor b = semanticDescriptors[n2];
    return (a*b*1.0) / (sqrt(a*a) * sqrt(b*b));
}

string SemanticDictionary::mostSimilarWord(string word, vector<string> choices)
{
    double bestScore = getSimilarity(word, choices.at(0));
    size_t bestIndex = 0;
    for(size_t i = 1; i < choices.size(); i++)
    {
        double score = getSimilarity(word, choices.at(i));
        if(score > bestScore)
        {
            bestScore = score;
            bestIndex = i;
        }
    }
    return choices.at(bestIndex);
}

bool isStopWord(string s)
{
    for(string word : stopWordList)
    {
        if(s == word) return true;
    }
    return false;

}

istream& operator>>(istream& is, SemanticDictionary& d)
{
    d.semanticDescriptors.clear();
    SemanticDescriptor desc{""};
    char c;
    while(is >> c)
    {
        if(c == '{') break;
    }
    if(is.fail()) return is;

    while(is >> desc)
    {
        d.semanticDescriptors.push_back(desc);
    }
    is.clear();
    is >> c;
    if(c != '}')
    {
        is.clear(ios::failbit);
    }
    return is;
}
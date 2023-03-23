#ifndef SEMANTICDICTIONARY_H_INCLUDED
#define SEMANTICDICTIONARY_H_INCLUDED

#include "SemanticDescriptor.h"
#include <sstream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

vector<vector<string>> getSentenceLists(string text);

bool isStopWord(string s);

const vector<string> stopWordList = {"i","a","about","an","are","as","at","be","by","for","from","how","in","is","it","of","on","or","that","the",
"this","to","was", "what","when","where","who","will","with"};

class SemanticDictionary
{
    private:
        vector<SemanticDescriptor> semanticDescriptors;
        int searchTargetWord(string targetWord);

    public:
        void processTargetWord(string targetWord, vector<string> sentenceList);
        double getSimilarity(string targetWord1, string targetWord2);
        string mostSimilarWord(string word, vector<string> choices);
        friend ostream& operator<<(ostream& os, const SemanticDictionary& d);
        //friend istream& operator>>(istream& is, SemanticDictionary& d);
};

ostream& operator<<(ostream& os, const vector<vector<string>>& sentenceLists);

#endif // SEMANTICDICTIONARY_H_INCLUDED
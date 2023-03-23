#include "SemanticDescriptor.h"


void SemanticDescriptor::processContextWord(string s)
{
    for(size_t i = 0; i < contextWords.size(); i++)
    {
        if(contextWords.at(i).word == s)
        {
            contextWords.at(i).count++;
            return;
        }
    }
    contextWords.push_back(ContextWord{s, 1});
}

int SemanticDescriptor::operator*(const SemanticDescriptor& desc)
{
    int sum = 0;
    for(size_t i = 0; i < this->contextWords.size(); i++)
    {
        for(size_t j = 0; j < desc.contextWords.size(); j++)
        {
            if(this->contextWords[i].word == desc.contextWords[j].word)
            {
                sum += this->contextWords[i].count * desc.contextWords[j].count;
                break;
            }
        }
    }
    return sum;
}

ostream& operator<<(ostream& os, const SemanticDescriptor& desc)
{
    os << desc.targetWord << " {";
    for(size_t i = 0; i < desc.contextWords.size(); i++)
    {
        os << desc.contextWords[i].word << " " << desc.contextWords[i].count << " ";
    }
    os << "}" << endl;
    return os;
}

istream& operator>>(istream& is, SemanticDescriptor& desc)
{
    desc.targetWord = "";
    desc.contextWords.clear();
    /*
    char c;
    is >> c;
    if(c == '}')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    */

    string targetWord;
    is >> targetWord;
    desc.targetWord = targetWord;


    char c;
    is >> c;
    if(c != '{')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    while(is)
    {
        is >> c;
        if(c == '}') return is;
        is.unget();
        string word;
        int count;
        is >> word >> count;
        desc.contextWords.push_back(ContextWord{word, count});
    }

    return is;
}
#include "String.h"

namespace String{
    string::string()
    {
        sz = 0;
        pChars = nullptr;
        space = 0;
    }

    string::string(const char* s)
    { 
        sz = strlen(s);
        pChars = new char[strlen(s) + 1];
        space = sz + 1;
        strcpy(pChars, s);
        pChars[strlen(s)] = '\0';
    }

    string::string(const string& s)
    {          
        sz = s.sz;
        pChars = new char[s.sz];
        space = s.sz;
        strcpy(pChars, s.pChars);
        pChars[s.sz] = '\0';
    }

    string& string::operator=(const string& s)
    {
        if(s.sz <= space){
            strcpy(pChars, s.pChars);
            sz = s.sz;
            return *this;
        }
        char *p = new char[s.sz + 1];
        strcpy(p, s.pChars);
        delete[] pChars;
        sz = s.sz;
        space = s.space;
        pChars = p;
        return *this;
    }

    string& string::operator=(const char* s)
    {
        char *p = new char[strlen(s) + 1];
        for(size_t i = 0; s[i] != '\0'; i++)
        {
            p[i] = s[i];
        }
        p[sz] = '\0';
        delete[] pChars;
        sz = strlen(s);
        space = strlen(s);
        pChars = p;
        return *this;
    }

    string& string::operator=(string&& s)
    {
        delete[] pChars;
        pChars = s.pChars;
        sz = s.sz;
        space = s.space;
        s.pChars = nullptr;
        s.sz = 0;
        cout << "Move" << endl;
        return *this;
    }

    string::~string(){
        delete [] pChars;
    }

    char& string::operator[](size_t pos)
    {
        return pChars[pos];
    }

    const char& string::operator[](size_t pos) const
    {
        return pChars[pos];
    }

    void string::reserve(size_t n)
    {
        if (n <= space)
        {
            return;
        }
        char *p = new char[n];
        for (size_t i = 0; i < n; i++)
        {
            p[i] = pChars[i];
        }
        delete[] pChars;
        pChars = p;
        space = n;
    }

    void string::push_back(const char c)
    {        
        int newSize = sz + 1;
        char *p = new char[newSize + 1];
        for(size_t i = 0; i < sz; i++)
        {
            p[i] = pChars[i];
        }
        p[newSize] = c;
        delete[] pChars;
        sz = strlen(p);
        space = strlen(p);
        pChars = p;
    }

  



size_t string::find(const char* s, size_t pos) const
{
    return 0;
} 
      
bool operator==(const string& lhs, const string& rhs)
{
    if(lhs.size() == rhs.size()){
        for(size_t i = 0; i < lhs.size(); i++){
            if(lhs[i] != rhs[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

    bool operator==(const string& lhs, const char* rhs)
    {
        if(lhs.size() == strlen(rhs))
        {
            for (size_t i = 0; i< lhs.size(); i++)
            {
                if(lhs[i] == rhs[i]) return true;
            }
        }
        return false;
    }

    bool operator>(const string& lhs, const string& rhs)
    {
        for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
        {
            if(lhs[i] > rhs[i])
            {
                return true;
            }
            else if(lhs[i] < rhs[i])
            {
                return false;
            }
        }
        if(lhs.size() > rhs.size())
        {
            return true;
        }
        return false;
    }

    string operator+(const string& lhs, const string& rhs)
    {
        string result = "";
        for(size_t i = 0; i < lhs.size(); i++)
        {
            result.push_back(lhs[i]);
            
        }
        for(size_t j = 0; j < rhs.size(); j++)
        {
            result.push_back(rhs[j]);
            
        }
        return result;
    }


    ostream& operator<<(ostream& os, const string& s){
        for(size_t i = 0; i < s.size(); i++){
            os << s[i];
        }
        return os;
    }

    istream& operator>>(istream& is, string& s){
        char c;
        while(is.get(c)){
            if(c != ' '){
                s.push_back(c);
            }
        }
        return is;
    }
}
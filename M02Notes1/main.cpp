#include "../std_lib_facilities.h"

int main()
{
    vector<string> words;
    for(string s; cin >> s && s != "quit";)
        words.push_back(s);

    sort(words);

    vector<string>w2;
    if(0<words.size())
    {
        w2.push_back(words[0]);
        for(size_t i = 1; i < words.size(); ++i)
            if(words[i-1] == words[i])
                w2.push_back(words[i]);
    }

    cout << "found " << words.size()-w2.size() << " duplicates\n";
    for(string s : words)
        cout << s << '\n';
}
#include <iostream>

#include <string>

using namespace std;

int main()
{
    string word = "";
    
    cout << "Enter words to be translated:" << endl;
    getline(cin, word);

    while (word != "quit!")
    {
        if (word.size() <= 4)
            cout << word << endl;
        else
        {
            int pos = word.rfind("o");
            
            if (word[pos + 1] == 'r' && pos + 1 == word.size() - 1)
                cout << word.substr(0, pos) << "our" << endl;
            else
                cout << word << endl;
        }

        getline(cin, word);
    }

    return 0;
}
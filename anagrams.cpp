#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  while(true)
  {
    int buf = -1;
    string word1, word2, word3;
    map<int, string> map1;
    map<int, string> map2;
    map<int, string>::iterator it;

    cout << "Input 1 word: "; getline(cin, word1);
    if(word1 == "q") break;
    cout << "Input 2 word: "; getline(cin, word2);

    for (int i = 0; i < word1.length(); ++i)
      map1.insert(pair<int, string>(i, word1.substr(i,1)));
    for (int i = 0; i < word2.length(); ++i)
      map2.insert(pair<int, string>(i, word2.substr(i,1)));

    if(word1.length() == word2.length())
    {
      for (int i = 0; i < word2.length(); ++i)
      {
        for (it = map1.begin(); it != map1.end(); ++it)
        {
          if(it->second == word2.substr(i,1))
          {
            if (i != buf) word3 += map2[i];
            buf = i;
          }
        }
      }
    }

    if (word3 == word2) cout << boolalpha << true << endl;
    else cout << boolalpha << false << endl;
  }
}

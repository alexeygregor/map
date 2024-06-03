#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  int cnt = 0;
  string input, output, buf;
  map<string, int> reg;
  map<string, int>::iterator it;
  while (input != "q")
  {
    cout << "->";
    cin >> input;
    if (input == "Next")
    {
      if (cnt < 1) { cout << "#Queue empty" << endl; continue; }
      cnt--;
      it = reg.begin();
      buf = it->first;
      while (buf.length() <= 15) buf += " ";
      output = buf + "#" + to_string(cnt) + " people in queue";
      cout << "<-" << output << endl;
      reg.erase(it);
    }
    else if (input != "Next")
    { reg.insert(pair<string, int> (input, cnt)); cnt++; }
  }
}

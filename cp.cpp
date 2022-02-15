#include <iostream>
#include <string>

using namespace std;

char vowels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

string GetRuler(const string& kingdom) {
    if(kingdom[kingdom.size() - 1] == 'y' || kingdom[kingdom.size() - 1] == 'Y')
        return "nobody";

    for(int i=0; i<10; ++i) {
        if(kingdom[kingdom.size() - 1] == vowels[i])
            return "Alice";
    }

    return "Bob";
}

int main() {
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}

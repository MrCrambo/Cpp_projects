#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    size_t old_size = dict.size();
    for (const auto& word : words) {
      dict.insert(word);
    }
    return dict.size() - old_size;
  }

  vector<string> KnownWords() const {
    return {dict.begin(), dict.end()};
  }
};

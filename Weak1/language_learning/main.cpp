#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
//#include "../../profile.h"
//#include "../../test_runner.h"

using namespace std;

class Learner {
 private:
	set<string> dict;

 public:
	int Learn(const vector<string>& words) {
		int newWords = 0;
		size_t oldsize = dict.size();
		dict.insert(words.begin(), words.end());
		newWords = static_cast<int>(dict.size() - oldsize);
		return newWords;
	}

	vector<string> KnownWords() {
		return vector<string>(dict.begin(), dict.end());
	}
};

//void BanchMark()
//{
//	vector<string> words{"wtf" "mzf" "sgsfg" "sfdgsg" "sf" "fsd" "dwer" "dsfd"
//											"wtfa" "mzfa" "sgsfga" "sfdgsga" "sfa" "fsda" "dwera" "dsfda"
//											"wtfb" "mzfb" "sgsfgb" "sfdgsgb" "sfb" "fsdb" "dwerb" "dsfdb"
//											"wtfc" "mzfc" "sgsfgc" "sfdgsgc" "sfc" "fsdc" "dwerc" "dsfdcc"
//											};
//	{
//		LOG_DURATION("Learn time 50000 times");
//		for (int i = 0; i < 50000; i++){
//			Learner learner;
//			learner.Learn(words);
//		}
//	}
//	{
//		LOG_DURATION("learn and check learned 50000 times");
//		for (int i = 0; i < 50000; i++){
//			Learner learner;
//			learner.Learn(words);
//			learner.KnownWords();
//		}
//	}
//}
//before
//Learn time 50000 times: 29 ms
//learn and check learned 50000 times: 57 ms
//after
//Learn time 50000 times: 23 ms
//learn and check learned 50000 times: 43 ms


int main() {
//	TestRunner tr;
//	RUN_TEST(tr, BanchMark);
	Learner learner;
	string line;
	while (getline(cin, line)) {
		vector<string> words;
		stringstream ss(line);
		string word;
		while (ss >> word) {
			words.push_back(word);
		}
		cout << learner.Learn(words) << "\n";
	}
	cout << "=== known words ===\n";
	for (auto word : learner.KnownWords()) {
		cout << word << "\n";
	}
}

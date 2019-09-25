#include "test_runner.h"

#include <numeric>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Реализуйте шаблон класса Paginator

template <typename Iterator>
class Page{
public:
	Page(Iterator begin, Iterator end):
		_begin(begin), _end(end)
	{}
	Iterator begin() { return _begin; }
	Iterator end() { return _end; }
	size_t size() { return _size; }
private:
	Iterator _begin, _end;
	size_t _size;
};


template <typename Iterator>
class Paginator{
public:
	Paginator(Iterator begin, Iterator end, size_t page_size):
	_page_size(page_size)
	{
		size_t duration = end - begin;
		size_t page_number = duration/page_size;
		pages.reserve(page_number);
		for ( size_t i = 0; i < page_number; i++){
			pages.push_back(Page<Iterator>(begin, end));
		}
		_begin = pages.begin();
		_end = pages.end();
	}
	Iterator begin() { return _begin; }
	Iterator end() { return  _end; }
	size_t size() const { return pages.size(); }
private:
	vector<Page<Iterator>> pages;
	typename vector<Page<Iterator>>::iterator _begin, _end;
	size_t _page_size;
};

//template <typename C>
//Paginator<typename C::iterator> Paginate(C& c, size_t page_size) {
//  // Реализуйте этот шаблон функции
//}

//void TestPageCounts() {
//  vector<int> v(15);

//  ASSERT_EQUAL(Paginate(v, 1).size(), v.size());
//  ASSERT_EQUAL(Paginate(v, 3).size(), 5u);
//  ASSERT_EQUAL(Paginate(v, 5).size(), 3u);
//  ASSERT_EQUAL(Paginate(v, 4).size(), 4u);
//  ASSERT_EQUAL(Paginate(v, 15).size(), 1u);
//  ASSERT_EQUAL(Paginate(v, 150).size(), 1u);
//  ASSERT_EQUAL(Paginate(v, 14).size(), 2u);
//}

//void TestLooping() {
//  vector<int> v(15);
//  iota(begin(v), end(v), 1);

//  Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
//  ostringstream os;
//  for (const auto& page : paginate_v) {
//    for (int x : page) {
//      os << x << ' ';
//    }
//    os << '\n';
//  }

//  ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
//}

//void TestModification() {
//  vector<string> vs = {"one", "two", "three", "four", "five"};
//  for (auto page : Paginate(vs, 2)) {
//    for (auto& word : page) {
//      word[0] = toupper(word[0]);
//    }
//  }

//  const vector<string> expected = {"One", "Two", "Three", "Four", "Five"};
//  ASSERT_EQUAL(vs, expected);
//}

//void TestPageSizes() {
//  string letters(26, ' ');

//  Paginator letters_pagination(letters.begin(), letters.end(), 11);
//  vector<size_t> page_sizes;
//  for (const auto& page : letters_pagination) {
//    page_sizes.push_back(page.size());
//  }

//  const vector<size_t> expected = {11, 11, 4};
//  ASSERT_EQUAL(page_sizes, expected);
//}

//void TestConstContainer() {
//  const string letters = "abcdefghijklmnopqrstuvwxyz";

//  vector<string> pages;
//  for (const auto& page : Paginate(letters, 10)) {
//    pages.push_back(string(page.begin(), page.end()));
//  }

//  const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
//  ASSERT_EQUAL(pages, expected);
//}

//void TestPagePagination() {
//  vector<int> v(22);
//  iota(begin(v), end(v), 1);

//  vector<vector<int>> lines;
//  for (const auto& split_by_9 : Paginate(v, 9)) {
//    for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
//      lines.push_back({});
//      for (int item : split_by_4) {
//        lines.back().push_back(item);
//      }
//    }
//  }

//  const vector<vector<int>> expected = {
//      {1, 2, 3, 4},
//      {5, 6, 7, 8},
//      {9},
//      {10, 11, 12, 13},
//      {14, 15, 16, 17},
//      {18},
//      {19, 20, 21, 22}
//  };
//  ASSERT_EQUAL(lines, expected);
//}

int main() {
	vector<int> v{1, 2, 3, 4, 5, 6};
	for (auto value: Page<vector<int>::iterator>(v.begin(), v.end())){
		cout << value << endl;
	}
//  TestRunner tr;
//  RUN_TEST(tr, TestPageCounts);
//  RUN_TEST(tr, TestLooping);
//  RUN_TEST(tr, TestModification);
//  RUN_TEST(tr, TestPageSizes);
//  RUN_TEST(tr, TestConstContainer);
//  RUN_TEST(tr, TestPagePagination);
	return 0;
}

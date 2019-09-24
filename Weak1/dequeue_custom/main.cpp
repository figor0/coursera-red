#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class Deque{
public:
	Deque(): back(), front()
	{}
	bool Empty() const{ return back.empty() && front.empty(); }
	size_t Size() const { return back.size() + front.size(); }
	const T& operator[](size_t index) const{
		if ( Empty() )
			return back[index];
		if ( front.size() > index ){
			return front[front.size() - 1 - index];
		} else{
			return back[index - front.size()];
		}
	}
	T& operator[](size_t index){
		return const_cast<T&>( static_cast<const T&>(*this[index]) );
	}
	const T& At(size_t index) const{
		if ( front.size() > index ){
			return front.at(front.size() - 1 - index);
		} else{
			return back.at(index - front.size());
		}
	}
	T& At(size_t index){
		const T& t = operator[](index);
		return const_cast<T&>(t);
	}

	T& Front(){
		return front.back();
	}
	const T& Front() const{
		return front.back();
	}
	T& Back(){
		return back.back();
	}
	const T& Back() const{
		return back.back();
	}
	void PushFront(const T& value){
		front.push_back(value);
	}
	void PushBack(const T& value){
		back.push_back(value);
	}
private:
	vector<T> back, front;
};

template <typename T>
ostream& operator<<(ostream& reader, const Deque<T>& deq){
	for ( size_t i = 0; i < deq.Size(); i ++){
		reader << deq.At(i) << ' ';
	}
}

int main()
{
	try {


	Deque<int> deq;
	for (int i = 0 ; i < 5; i++){
		deq.PushBack(i);
		deq.PushFront(i);
	}
	cout << deq.Size() << endl;
	cout << deq.Back() << endl;
	cout << deq.Front() << endl;
	cout << deq[0] << endl;
	} catch ( std::exception& value) {
		cout << value.what() << endl;
	}
	return 0;
}

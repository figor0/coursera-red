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
		return const_cast<T&>( static_cast<const Deque<T>&>(*this)[index] );
	}
	const T& At(size_t index) const{
		if ( front.size() > index ){
			return front.at(front.size() - 1 - index);
		} else{
			return back.at(index - front.size());
		}
	}
	T& At(size_t index){
		return const_cast<T&>( static_cast<const Deque<T>&>(*this).At(index) );
	}

	const T& Front() const{
		if (front.empty() ){
			return back[0];
		} else {
			return front[front.size() - 1];
		}
	}

	T& Front(){
		return const_cast<T&>( static_cast<const Deque<T>&>(*this).Front() );
	}
	const T& Back() const{
		if ( back.empty())
			return front[0];
		else{
			return back[back.size() - 1];
		}
	}

	T& Back(){
		return const_cast<T&>( static_cast<const Deque<T>&>(*this).Back() );
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
	for ( size_t i = 0; i < deq.Size(); i++){
		reader << deq.At(i) << ' ';
	}
	return reader;
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
	cout << deq << endl;
	} catch ( std::exception& value) {
		cout << value.what() << endl;
	}
	return 0;
}

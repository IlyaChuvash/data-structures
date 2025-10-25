#include <vector>
#include <stdexcept>


template <typename T>
class Stack {

protected:
	std::vector<T> arr;

public:

	void push(const T& val) {
		arr.push_back(val);
	}
	void pop() {
		if (arr.empty()) {
			throw std::out_of_range("Stack is empty");
		}
		arr.pop_back();
	}
	T top() const {
		if (arr.empty()) {
			throw std::out_of_range("Stack is empty");
		}
		return arr.back();
	}
	size_t size() const {
		return arr.size();
	}
	void clear() {
		arr.clear();
	}
	bool empty() const {
		return arr.empty();
	}
};

template <typename T>
class StackMm : public Stack<T>
{
private:
	std::vector<T> minArr;
	std::vector<T> maxArr;
public:
	void push(const T& val) {
		Stack<T>::push(val);
		if (minArr.empty() || val <= minArr.back()) {
			minArr.push_back(val);
		}
		else {
			minArr.push_back(minArr.back());
		}
		if (maxArr.empty() || val >= maxArr.back()) {
			maxArr.push_back(val);
		}
		else {
			maxArr.push_back(maxArr.back());
		}
	}
	void pop() {
		if (Stack<T>::empty()) {
			throw std::out_of_range("Stack is empty");
		}

		Stack<T>::pop();

		minArr.pop_back();
		maxArr.pop_back();

	}
	T getMin() const {
		if (minArr.empty()) {
			throw std::out_of_range("Stack is empty");
		}
		return minArr.back();
	}
	T getMax() const {
		if (maxArr.empty()) {
			throw std::out_of_range("Stack is empty");
		}
		return maxArr.back();
	}
};
#include <stdexcept>
#include <vector>


template <typename T>
class Queue {
private:
	std::vector<T> arr;
	size_t start = 0;
	size_t end = 0;
public:
	void add(T val) {
		if (arr.size() == end) {
			std::vector<T> newArr((arr.size()+1)*2);
			for (size_t i = start; i < end; i++) {
				newArr[i - start] = arr[i];
			}
			arr = std::move(newArr);
			end = end - start;
			start = 0;
		}
		arr[end] = val;
		end++;

	}
	void remove() {
		if (start == end) {
			throw std::out_of_range("Queue is empty");
		}
		start++;
		if (start == end) {
			start = 0;
			end = 0;
			arr.clear();
		}
	}
	void clear() {
		arr.clear();
		start = 0;
		end = 0;
	}
	T& first() {
		if (start == end) {
			throw std::out_of_range("Queue is empty");
		}
		return arr[start];
	}
	bool empty() const{
		return start == end;
	}
	size_t size() const{
		return end - start;
	}
};
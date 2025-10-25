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

		size_t current_size = end - start;
		if (arr.size() > 16 && current_size < arr.size() / 4) {
			size_t new_size = std::max(size_t(8), arr.size() / 2);
			std::vector<T> newArr(new_size);
			for (size_t i = 0; i < current_size; i++) {
				newArr[i] = arr[start + i];
			}
			arr = std::move(newArr);
			end = current_size;
			start = 0;
		}

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
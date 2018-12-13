//============================================================================
// Name        : Insertion_Sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

void insertion_sort(double array[], int const size){
	for (std::size_t i = 0 ; i < size - 1; ++i){
		if (array[i] > array[i + 1]){
			double temp{array[i+1]};
			array[i+1] = array[i];
			array[i] = temp;
			for (std::size_t j = i - 1; j >= 0; --j){
				if (array[j] > array [j+1]){
					double temp{array[j]};
					array[j] = array[j+1];
					array[j+1] = temp;
				}else{
					break;
				}
			}
		}
	}
}
void binary_search(double const array[], int const capacity, double const num){
	bool found{false};
	int search = std::ceil(capacity/2);
	int prev = 0;
	int max = capacity;
	for(int i = 0; i <= std::ceil(std::log2(capacity)); ++i){
		if (array[search] == num){
			std::cout << "Number: " << num << ", Position: " << search + 1 << std::endl;
			found = true;
			break;
		}else if (array[search] < num){
			prev = search;
			search = std::ceil((search + max)/2);
		}else{
			max = search;
			search = std::ceil((search + prev)/2);
		}

	}
	if (!found){
		std::cout << "The number you are looking for isn't in the array." << std::endl;
	}
}
void print_array(double const array[], int const capacity){
	for (std::size_t i = 0; i < capacity; ++i){
		std::cout << array[i] << std::endl;
	}
}

int main() {
	double input;
	int capacity{0};
	while (input != -1){
		std::cout << "How many entries do you want in your array: ";
		std::cin >> capacity;
		double *sort= new double[capacity];
		for (std::size_t i = 0; i < capacity; ++i){
			std::cout << "Entry #" << i + 1 << ": ";
			std::cin >> input;
			sort[i] = input;
		}
		insertion_sort(sort, capacity);
		print_array(sort, capacity);
		double search{};
		std::cout << "Enter a number to search for: ";
		std::cin >> search;
		binary_search(sort, capacity, search);
		delete sort;
		sort = nullptr;
	}
	return 0;
}

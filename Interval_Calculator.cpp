//============================================================================
// Name        : Pject.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : An interval calculator built for a school project
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
void interval_calculator();
int main();
void interval_calculator(){
	double a = 0.0, b = 0.0, limit[2], temp{0}, mem_stored[2], scalar, interval[2], comp;
		bool initial = false, mem_initial = false;
		std::string command;
		do{
			std::cout << "input :> ";
			//std::cin << command << a << b
			std::cin >> command;
			if (command == "exit"){
				std::cout << "Bye bye: Terminating interval calculator program.";
				return;
				//takes two doubles and stores them in the immediate interval
				//If the interval is not valid, immediate is uninitialized and an error is printed
			}else if (command == "enter"){
				std::cin >> a >> b;
				if (a > b){
					std::cout << "Error: invalid interval as " << a << " > " << b << std::endl;
					initial = false;
				}else{
					initial = true;
					limit[0] = a;
					limit[1] = b;
				}
				//takes the immediate interval and makes it negative and flips the order
			}else if (command == "negate"){
				if (initial){
					temp = limit[1];
					limit[1] = -limit[0];
					limit[0] = -temp;
				}
				//takes the inverse of the limit (1/a) and flips the order of the interval
				//outputs an error if the interval includes zero
			}else if (command == "invert"){
				if (limit[0] <= 0 && limit[1] >= 0){
					std::cout << "Error: division by zero" << std::endl;
					initial = false;
				}else if (initial){
					temp = limit[1];
					limit[1] = 1/limit[0];
					limit[0] = 1/temp;
				}
				//takes the immediate interval and saves it to memory, initializes memory
			}else if (command == "ms"){
				if (initial){
					mem_stored[0] = limit[0];
					mem_stored[1] = limit[1];
					mem_initial = true;
				}
				//returns memory interval to immediate interval
				//if no memory outputs immediate interval
			}else if( command == "mr"){
				if (mem_initial){
					limit[0] = mem_stored[0];
					limit[1] = mem_stored[1];
				}
				//uninitializes memory
			}else if (command == "mc"){
				mem_initial = false;
				//adds immediate interval to memory
			}else if (command == "m+"){
				if (mem_initial){
					mem_stored[0] += limit[0];
					mem_stored[1] += limit[1];
				}
				//subtracts immediate interval from memory
			}else if (command == "m-"){
				if (mem_initial){
					mem_stored[0] -= limit[1];
					mem_stored[1] -= limit[0];
				}
				//adds a scalar to the immediate interval
			}else if (command == "scalar_add"){
				std::cin >> scalar;
				if (initial){
					limit[0] += scalar;
					limit[1] += scalar;

				}
				//subtracts a scalar from the immediate interval
			}else if (command == "scalar_subtract"){
				std::cin >> scalar;
				if (initial){
					limit[0] -= scalar;
					limit[1] -= scalar;
				}
				//multiplies immediate interval my a scalar
			}else if (command == "scalar_multiply"){
				std::cin >> scalar;
				if (initial){
					if (scalar >= 0){
						limit[0] *= scalar;
						limit[1] *= scalar;
					}else{
						temp = limit[0];
						limit[0] = scalar * limit[1];
						limit[1] = scalar * temp;
					}
				}
				//divides the immediate interval by a scalar
				//if the scalar is less than 0 the interval is flipped
			}else if (command == "scalar_divide"){
				std::cin >> scalar;
				if (initial){
					if (scalar == 0){
						std::cout << "Error: division by zero"<< std::endl;
						initial = false;
					}else if (scalar > 0){
						limit[0] /= scalar;
						limit[1] /= scalar;
					}else{
						temp = limit[0];
						limit[0] = limit[1]/scalar;
						limit[1] = temp/scalar;
					}
				}
				//divides a scalar by the immediate interval, if the scalar is less than 0 the interval is reversed
				//interval cannot include 0 in its range
			}else if (command == "scalar_divided_by"){
				std::cin >> scalar;

				if (initial){
					if ((limit[0] <= 0 && limit [1] >= 0)){
						std::cout << "Error: division by zero" << std::endl;
						initial = false;
					}else if (scalar > 0){
						limit[0] = scalar/limit[0];
						limit[1] = scalar/limit[1];
					}else{
						temp = limit[0];
						limit[0] = scalar/limit[1];
						limit[1] = scalar/temp;
					}
				}
				//adds a valid new interval to the immediate interval
			}else if(command == "interval_add"){
				std::cin >> interval[0] >> interval[1];
				if (initial){
					if (interval[0] > interval[1]){
						std::cout << "Error: invalid interval as " << interval[0] << " > " << interval[1] << std::endl;
					}else{
						limit[0] += interval[0];
						limit[1] += interval[1];
					}
				}
				//subtracts a valid interval from the immediate interval
			}else if(command == "interval_subtract"){
				std::cin >> interval[0] >> interval[1];
				if (initial){
					if (interval[0] > interval[1]){
						std::cout << "Error: invalid interval as " << interval[0] << " > " << interval[1] << std::endl;
					}else{
						limit[0] -= interval[1];
						limit[1] -= interval[0];
					}
				}
				//Takes in a valid interval and takes the maximum value of all the multiplications and the minimum
				//the max and min are assigned to the immediate interval
			}else if(command == "interval_multiply"){
				std::cin >> interval[0] >> interval[1];
				if (interval[0] > interval[1]){
					std::cout << "Error: invalid interval as " << interval[0] << " > "<< interval[1] << std::endl;
					initial = false;
				}
				if (initial){
					temp = limit[0];
					limit[0] = std::min(limit[0]*interval[0], limit[0]*interval[1]);
					comp = std::min(limit[1]*interval[0], limit[1]*interval[1]);
					if (limit[0] > comp){
						limit[0] = comp;
					}
					limit[1] = std::max(limit[1]*interval[0], limit[1]*interval[1]);
					comp = std::max(temp*interval[0], temp*interval[1]);
					if (limit[1] < comp){
						limit[1] = comp;
					}

				}
				//Takes in a valid interval and takes the maximum value of all the divisions and the minimum
				//the max and min are assigned to the immediate interval
				//outputs an error if a zero is included in the inputted interval
			}else if(command == "interval_divide"){
				std::cin >> interval[0] >> interval[1];
				if (initial){
					if (interval[0] > interval[1]){
						std::cout << "Error: invalid interval as " << interval[0] << " > "<< interval[1] << std::endl;
					}else if (interval[0] <= 0 && interval[1] >= 0){
						std::cout << "Error: division by zero" << std::endl;
						initial = false;
					}else{
						temp = limit[0];
						limit[0] = std::min(limit[0]/interval[0], limit[0]/interval[1]);
						comp = std::min(limit[1]/interval[0], limit[1]/interval[1]);
						if (limit[0] > comp){
							limit[0] = comp;
						}
						limit[1] = std::max(limit[1]/interval[0], limit[1]/interval[1]);
						comp = std::max(temp/interval[0], temp/interval[1]);
						if (limit[1] < comp){
							limit[1] = comp;
						}
					}
				}
				//takes the lowest value and the highest value that exist within both of the valid intervals
				//sets this to be the immediate interval
			}else if(command == "intersect"){
				std::cin >> interval[0] >> interval[1];
				if (interval[0] > interval[1]){
					std::cout << "Error: invalid interval as " << interval[0] << " > "<< interval[1] << std::endl;
					initial = false;
				}
				if (initial){
					if (interval[0] > limit[1] || interval[1] < limit[0]){
						initial = false;
					}if (interval[0] < limit[1] && interval[0] > limit[0]){
						limit[0] = interval[0];
						if (interval[1] < limit[1]){
							limit[1] = interval[1];
						}
					}else if (interval[1] < limit[1] && interval[1] > limit[0]){
						limit[1] = interval[1];
						if (interval[0] > limit[0]){
							limit[0] = interval[0];
						}
					}
				}
				//outputs all integers between the lower and upper limit of the interval
			}else if(command == "integers"){
				if (initial){
					for (int i = std::ceil(limit[0]); i <= std::floor(limit[1]); ++i){
						std::cout << i;
						if (i < std::floor(limit[1])){
							std::cout << ", ";
						}
					}
					std::cout << std::endl;
				}
				//does a cartesian multiplication of all integer values between a valid inputted range and thr immediate interval
			}else if(command == "cartesian_integers"){
				std::cin >> interval[0] >> interval[1];
				if (interval[0] > interval[1]){
					std::cout << "Error: invalid interval as " << interval[0] << " > "<< interval[1] << std::endl;
					initial = false;
				}
				if (initial){
					interval[0] = std::ceil(interval[0]);
					interval[1] = std::floor(interval[1]);
					for (int i = std::ceil(limit[0]); i <= std::floor(limit[1]); ++i){
						for (int j = interval[0]; j <= interval[1]; ++j){
							std::cout << "(" << i << "," << j << ")";
							if (!(i == limit[1] && j == interval[1])){
								std::cout << ", ";
							}
						}
					}
					std::cout << std::endl;
				}
			}else{
				std::cout << "Error: illegal command" << std::endl;
			}

			if (initial){
				std::cout << "[" << limit[0] << ", " << limit[1] << "]";
				std::cout << std::endl;
			}else{
				std::cout << "--" << std::endl;
			}

		} while(true);
}
int main(){
	interval_calculator();
	return 0;
}


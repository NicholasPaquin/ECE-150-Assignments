//============================================================================
// Name        : Polynomial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "Polynomial.h"

#ifndef MARMOSET_TESTING
int main();
#endif

void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree){
	if (p.a_coeffs != nullptr){
		destroy_poly(p);
	}
	p.a_coeffs = new double[init_degree + 1];
	for(std::size_t j = 0; j < init_degree + 1; j++){
		p.a_coeffs[j] = init_coeffs[j];
	}
	p.degree = init_degree;
}
void destroy_poly(poly_t &p ){
	delete[] p.a_coeffs;
	p.a_coeffs = nullptr;
	p.degree = 0;
}
unsigned int poly_degree( poly_t const &p){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		return p.degree;
	}
}
double poly_coeff( poly_t const &p, unsigned int n){
	if (p.a_coeffs == nullptr){
		throw 0;
	}else{
		return p.a_coeffs[n];
	}
}
double poly_val(poly_t const &p, double const x ){
	if (p.a_coeffs == nullptr){
		throw 0;
	}else{
		double sum{p.a_coeffs[0]};
		for(size_t k = 1; k <= p.degree; k++ ){
			sum = sum +  p.a_coeffs[k] * std::pow(x, k);
		}
		return sum;
	}
}
void poly_add(poly_t &p, poly_t const &q ){
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}else{
		poly_t temp{nullptr, 0};
		if (p.degree == q.degree){
			temp.degree = p.degree;
			std::size_t deg = temp.degree + 1;
			for(std::size_t i = p.degree; i > 0; --i ){
				if (p.a_coeffs[i] + q.a_coeffs[i] == 0){
					temp.degree -= 1;

				}else{
					break;
				}
			}
			temp.a_coeffs = new double[deg];
			for (std::size_t i = 0; i <= temp.degree; ++ i){
				temp.a_coeffs[i] = p.a_coeffs[i] + q.a_coeffs[i];
			}
		}else if(q.degree > p.degree){
			temp.degree = q.degree;
			std::size_t deg = temp.degree + 1;
			temp.a_coeffs = new double[deg];
			for (std::size_t i = 0; i <= p.degree; ++ i){
				temp.a_coeffs[i] = p.a_coeffs[i] + q.a_coeffs[i];
			}
			for (std::size_t j = p.degree + 1; j <= q.degree; ++j){
				temp.a_coeffs[j] = q.a_coeffs[j];
			}
		}else if(p.degree > q.degree){
			temp.degree = p.degree;
			std::size_t deg = temp.degree + 1;
			temp.a_coeffs = new double[deg];
			for (std::size_t i = 0; i <= q.degree; ++ i){
				temp.a_coeffs[i] = p.a_coeffs[i] + q.a_coeffs[i];
			}
			for (std::size_t j = q.degree + 1; j <= p.degree; ++j){
				temp.a_coeffs[j] = p.a_coeffs[j];
			}
		}
		destroy_poly(p);
		init_poly(p, temp.a_coeffs, temp.degree);
		destroy_poly(temp);
	}

}
void poly_subtract(poly_t &p, poly_t const &q ){
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
			throw 0;
		}
		else{
			if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
					throw 0;
				}else{
					poly_t temp{nullptr, 0};
					if (p.degree == q.degree){
						temp.degree = p.degree;
						std::size_t deg = temp.degree + 1;
						for(std::size_t i = p.degree; i > 0; --i ){
							if (p.a_coeffs[i] - q.a_coeffs[i] == 0){
								temp.degree -= 1;

							}else{
								break;
							}
						}
						temp.a_coeffs = new double[deg];
						for (std::size_t i = 0; i <= temp.degree; ++ i){
							temp.a_coeffs[i] = p.a_coeffs[i] - q.a_coeffs[i];
						}
					}else if(q.degree > p.degree){
						temp.degree = q.degree;
						std::size_t deg = temp.degree + 1;
						temp.a_coeffs = new double[deg];
						for (std::size_t i = 0; i <= p.degree; ++ i){
							temp.a_coeffs[i] = p.a_coeffs[i] - q.a_coeffs[i];
						}
						for (std::size_t j = p.degree + 1; j <= q.degree; ++j){
							temp.a_coeffs[j] = - q.a_coeffs[j];
						}
					}else if(p.degree > q.degree){
						temp.degree = p.degree;
						std::size_t deg = temp.degree + 1;
						temp.a_coeffs = new double[deg];
						for (std::size_t i = 0; i <= q.degree; ++ i){
							temp.a_coeffs[i] = p.a_coeffs[i] - q.a_coeffs[i];
						}
						for (std::size_t j = q.degree + 1; j <= p.degree; ++j){
							temp.a_coeffs[j] = p.a_coeffs[j];
						}
					}
					destroy_poly(p);
					init_poly(p, temp.a_coeffs, temp.degree);
					destroy_poly(temp);
				}
		}
}
void poly_multiply(poly_t &p, poly_t const &q ){
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}else{
		poly_t temp;
		temp.a_coeffs = new double[q.degree + p.degree + 1]{0};
		temp.degree = p.degree + q.degree;
		if((q.degree == 0 && q.a_coeffs[0] == 0) || (p.degree == 0 && p.a_coeffs[0] == 0)){
			destroy_poly(temp);
			double array[1]{0};
			init_poly(temp, array, 0);
		}else{
			for (std::size_t k = 0; k <= p.degree; ++k){
				for (std::size_t j = 0; j <= q.degree; ++j){
						temp.a_coeffs[j + k] += p.a_coeffs[k] * q.a_coeffs[j];
				}
			}
			for (size_t i = q.degree + p.degree; i > 0; --i){
				if (temp.a_coeffs[i] == 0){
					temp.degree = temp.degree - 1;
				}else{
					break;
				}
			}
		}
		destroy_poly(p);
		init_poly(p, temp.a_coeffs, temp.degree);
		destroy_poly(temp);
	}
}
double poly_divide(poly_t &p, double r){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		double remainder = 0;
		if(p.degree == 0){
			remainder = p.a_coeffs[0];
			poly_t temp{nullptr, 0};
			temp.degree = 0;
			temp.a_coeffs = new double[1];
			temp.a_coeffs[0] = 0;
			destroy_poly(p);
			init_poly(p, temp.a_coeffs, temp.degree);
			destroy_poly(temp);
		}else{
			poly_t temp{nullptr,0};
			temp.a_coeffs = new double[p.degree];
			temp.degree = p.degree - 1;
			for (std::size_t j = p.degree; j >= 0; --j){
				remainder = p.a_coeffs[j] + r * remainder;
				if(j != 0){
					temp.a_coeffs[j-1] = remainder;
				}else{
					break;
				}

			}
			destroy_poly(p);
			init_poly(p, temp.a_coeffs, temp.degree);
			destroy_poly(temp);
		}
		return remainder;
	}
}
void poly_diff(poly_t &p){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		poly_t temp{nullptr,0};
		temp.a_coeffs = new double[p.degree];
		temp.degree = p.degree -1;
		for (std::size_t i = 1; i <= p.degree; ++i){
			temp.a_coeffs[i-1] = p.a_coeffs[i] * i;
		}
		destroy_poly(p);
		init_poly(p, temp.a_coeffs, temp.degree);
		destroy_poly(temp);
	}
}
double poly_approx_int(poly_t const &p, double a, double b, unsigned int n){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		double h = (b - a)/n;
		double integral = h/2 * poly_val(p, a) + h/2 * poly_val(p, b);;
		for (unsigned int k = 1; k < n; ++k){
			double x = a + k * h;
			integral += h * poly_val(p, x);
		}
		return integral;
	}
}
#ifndef MARMOSET_TESTING
int main() {
		poly_t p {nullptr, 0};
		poly_t q {nullptr, 0};
		double coeffs[1]{870};
		double coeffs2[2]{0, 1};
		init_poly(p, coeffs, 0);
		init_poly(q, coeffs2, 1);
		std::cout << poly_approx_int(q, 0, 4, 100) << std::endl;
		for (std::size_t i = 0; i <= q.degree; ++ i){
			std::cout << q.a_coeffs[i] << std::endl;
		}
		std::cout <<"degree " << q.degree << std::endl;
	return 0;
}
#endif

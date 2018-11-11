//============================================================================
// Name        : Polynomial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <Polynomial.h>
struct poly_t{
	double *a_coeffs;// array of coefficients
	unsigned int degree;// the degree of the polynomial};
};
void init_poly(poly_t &p, double const init_coeffs[],unsigned int const init_degree );
void destroy_poly(poly_t &p );
unsigned int poly_degree( poly_t const &p );
double poly_coeff( poly_t const &p, unsigned int n);
double poly_val(poly_t const &p, double const x );
void poly_add( poly_t &p,poly_t const &q );
void poly_subtract(poly_t &p, poly_t const &q );
void poly_multiply(poly_t &p, poly_t const &q );

void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree){
	if (p.a_coeffs != nullptr){
		delete p.a_coeffs;
	}
	p.a_coeffs = new double[init_degree + 1];
	for(std::size_t j = 0; j < init_degree + 1; j++){
		p.a_coeffs[j] = init_coeffs[j];
	}
}
void destroy_poly(poly_t &p ){
	delete p.a_coeffs;
	p.a_coeffs = nullptr;
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
		return p.a_coeffs[n - 1];
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
	}
	else{
		double *temp = new double[std::max(q.degree, p.degree) + 1];
		double *temp_2 = nullptr;
		for(size_t k = 0;k < std::min(q.degree, p.degree); k++){
			temp[k] = p.a_coeffs[k] + q.a_coeffs[k];
		}
		if (q.degree > p.degree){
			for (size_t j = p.degree; j < q.degree; j++){
				temp[j] = q.a_coeffs[j];
			}
		}else{
			for (size_t j = q.degree; j < p.degree; j++){
				temp[j] = p.a_coeffs[j];
			}
		}
		for (size_t i = std::max(q.degree, p.degree) +1; i >= 0; i++){
			if (temp[i] != 0){
				temp_2 = new double[i];
				p.degree = i - 1;
				break;
			}
		}
		for (size_t i = 0; i <= p.degree + 1; i++){
			temp_2[i] = temp[i];
		}
		delete temp;
		delete p.a_coeffs;
		p.a_coeffs = temp_2;
	}
}
void poly_subtract(poly_t &p, poly_t const &q ){
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
			throw 0;
		}
		else{
			double *temp = new double[std::max(q.degree, p.degree) + 1];
			double *temp_2 = nullptr;
			for(size_t k = 0;k < std::min(q.degree, p.degree) + 1; k++){
				temp[k] = p.a_coeffs[k] - q.a_coeffs[k];
			}
			if (q.degree > p.degree){
				for (size_t j = p.degree + 1; j < q.degree + 1; j++){
					temp[j] = - q.a_coeffs[j];
				}
			}else{
				for (size_t j = q.degree + 1; j < p.degree + 1; j++){
					temp[j] = p.a_coeffs[j];
				}
			}
			for (size_t i = std::max(q.degree, p.degree) +1; i >= 0; i++){
				if (temp[i] != 0){
					temp_2 = new double[i];
					p.degree = i - 1;
					break;
				}
			}
			for (size_t i = 0; i <= p.degree + 1; i++){
				temp_2[i] = temp[i];
			}
			delete temp;
			delete p.a_coeffs;
			p.a_coeffs = temp_2;
		}
}
void poly_multiply(poly_t &p, poly_t const &q ){
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}else{
		for (std::size_t i = q.a_coeffs + 1; i >= 0; --i){
			if (q.a_coeffs[i] != 0){
				q.degree = i - 1;
				break;
			}
		}
	}
}
int main() {

	return 0;
}

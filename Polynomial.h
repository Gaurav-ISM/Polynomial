#ifndef POLY_H
#define POLY_H

#include<vector>
using std::vector;

#include<string>
using std::string;

class Polynomial {
public:
	Polynomial();
	Polynomial(const vector<float>& c);
	Polynomial operator+(const Polynomial &rhs) const;
	Polynomial operator-(const Polynomial &rhs) const;
	Polynomial operator*(const Polynomial &rhs) const;
	Polynomial Derivative() const;
	Polynomial Antiderivative() const;
	float operator()(float x) const;
	string to_string(char var) const;
	vector<float> coefficients() const;
	~Polynomial();
private:
	int degree;
	vector<float> coeff;
	
	Polynomial(int deg, float init = 0.0f);
};

#endif

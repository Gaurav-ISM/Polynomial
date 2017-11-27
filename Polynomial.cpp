#include<vector>
using std::vector;

#include<string>
using std::string;

#include "Polynomial.h"

Polynomial :: Polynomial() : degree(-1), coeff()
{
	
}

Polynomial :: Polynomial(const vector<float>& c) : degree(c.size()-1), coeff(degree + 1)
{
	std::copy(c.begin(), c.end(), coeff.begin());
}

Polynomial Polynomial :: operator + (const Polynomial &rhs) const
{
	Polynomial sum(std::max(this->degree, rhs.degree));
	int index, common = std::min(this->degree, rhs.degree);
	for (index = 0; index <= common; ++index)
	{
		sum.coeff[index] = this->coeff[index] + rhs.coeff[index];
	}
	
	if (rhs.degree < this->degree)
	{
		sum.coeff[index] = this->coeff[index];
		++index;
	}
	else
	if (this->degree < rhs.degree)
	{
		sum.coeff[index] = rhs.coeff[index];
		++index;
	}
	
	while (sum.coeff[sum.degree] == 0)
	{
		sum.coeff.resize(sum.degree);
		--sum.degree;
	}
	
	return sum;
}

Polynomial Polynomial :: operator - (const Polynomial &rhs) const
{
	Polynomial dif(std::max(this->degree, rhs.degree));
	int index, common = std::min(this->degree, rhs.degree);
	for (index = 0; index <= common; ++index)
	{
		dif.coeff[index] = this->coeff[index] - rhs.coeff[index];
	}
	
	if (rhs.degree < this->degree)
	{
		dif.coeff[index] = this->coeff[index];
		++index;
	}
	else
	if (this->degree < rhs.degree)
	{
		dif.coeff[index] = -rhs.coeff[index];
		++index;
	}
	
	while (dif.coeff[dif.degree] == 0)
	{
		dif.coeff.resize(dif.degree);
		--dif.degree;
	}
	return dif;
}

Polynomial Polynomial :: operator * (const Polynomial &rhs) const
{
	Polynomial prod(this->degree + rhs.degree);

	for (int i = 0; i <= this->degree; i++)
	{
		for (int j = 0; j <= rhs.degree; j++)
			prod.coeff[i+j] += this->coeff[i] * rhs.coeff[j];
	}
	return prod;
}

Polynomial Polynomial :: Derivative() const
{
	Polynomial derivative(this->degree - 1);
	int index;
	
	for (index = 0; index <= derivative.degree; ++index)
		derivative.coeff[index] = (index+1) * this->coeff[index+1];
		
	return derivative;
}

Polynomial Polynomial :: Antiderivative() const
{
	Polynomial antiderivative(this->degree + 1);
	int index;

	for (index = 1; index <= antiderivative.degree; ++index)
		antiderivative.coeff[index] = this->coeff[index-1] / index;
		
	return antiderivative;
}

float Polynomial :: operator () (float x) const
{
	int value = 0, index, varPow = 1;
	for (index = 0; index <= this->degree; ++index)
	{
		value += this->coeff[index] * varPow;
		varPow *= x;
	}
	return value;
}

string Polynomial :: to_string(char var) const
{
	string output;
	output = "(" + std::to_string(this->coeff[0]) + ")*(" + var + "^0)";
	
	int index;
	for (index = 1; index <= this->degree; ++index)
		output +=  " + (" + std::to_string(this->coeff[index]) + ")*(" + var + "^" + std::to_string(index) + ")";
	
	return output;
}

vector<float> Polynomial :: coefficients() const
{
	vector<float> c (this->degree + 1);
	std::copy(coeff.begin(), coeff.end(), c.begin());
	return c;
}

Polynomial :: ~Polynomial()
{
	
}

Polynomial :: Polynomial(int deg, float init) : degree(deg), coeff(deg+1, init)
{
	
}

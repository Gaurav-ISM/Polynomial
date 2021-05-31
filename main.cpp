#include<iostream>
#include<vector>
using namespace std;

#include "Polynomial.h"

int main()
{
	Polynomial p1(vector<float>{2.0f, 0.0f, 1.0f, -1.0f});
	cout << p1.to_string('x') << endl;
	Polynomial p2(vector<float>{3.0f, 2.0f});
	Polynomial p3 = p1 + p2;
	
	Polynomial p4 = p1.Antiderivative();
	cout << p4.to_string('x') << endl;
	return 0;
}

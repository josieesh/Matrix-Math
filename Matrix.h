#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

class Matrix
{
	public:
		//Default Constructor
		Matrix();
		Matrix(const int newrow, const int newcol);
		//Copy Constructor
		Matrix (const Matrix &matrix);
		//Default Destructor
		~Matrix ();
		
		//Overloaded functions
		Matrix operator + (const Matrix & matrix2) const;
		Matrix operator - (const Matrix & matrix2) const;
		Matrix operator * (const Matrix & matrix2) const;
		
		bool canadd (const Matrix & matrix2) const;
		bool canmultiply (const Matrix & matrix2) const;
		void print() const;
		void input (ifstream &in, Matrix & matrix2);
		
		//Overloaded assignment operator to help with dynamic memory allocation 
		void operator=(const Matrix & matrix);
		
		//Overloaded friend functions
		//Friend function used to overload extraction operator <<
		friend ostream& operator <<(ostream &out, const Matrix &matrix);
		//Friend function used to overload >> insertion operator >>
		friend istream& operator >>(istream &in, Matrix &matrix);
		
	private:
		int row;
		int col; 
		int **ptr; //points to an int array in the memory
};

#endif


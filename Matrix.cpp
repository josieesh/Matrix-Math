#include "Matrix.h"

/* Matrix::Matrix()
{
	row = 0; 
	col = 0;
} */

Matrix::Matrix(const int newrow, const int newcol)
{
	row = (newrow > 0? newrow : 100);
	col = (newcol > 0? newcol : 100);
	
	ptr = new int*[row];
	for(int i = 0; i < row; i++) 
	{
    	ptr[i] = new int[col];
	}
	
	if (ptr == NULL)
	{
		cout << "Error, out of memory." << endl;
		exit(1);
	}
}

Matrix::Matrix(const Matrix & matrix)
{
	row = matrix.row;
	col = matrix.col;
	
	ptr = new int*[row];
	for(int i = 0; i < row; i++) 
	{
    	ptr[i] = new int[col];
	}
	
	if (ptr == NULL)
	{
		cout << "Error, out of memory." << endl;
		exit (1);
	}
	
	//Set new matrix array equal to initial matrix using two for-loops
	for ( int i = 0; i < row; i ++)
	{
		for (int j = 0; j < col; j++)
		{
			ptr[i][j] = matrix.ptr[i][j];
		}
	}
} 

Matrix::~Matrix()
{
	for(int i = 0; i < row; i++) 
	{
    	delete [] ptr[i];
	}
	delete [] ptr;
}

//Overloaded assignment operator
void Matrix::operator = (const Matrix & matrix)
{
	if (matrix.row > row || matrix.col > col)
	{
		for(int i = 0; i < row; i++) 
		{
    		delete [] ptr[i];
		}
		delete [] ptr;
	}
	row = matrix.row;
	col = matrix.col;
	
	ptr = new int*[row];
	for(int i = 0; i < row; i++) 
	{
   		ptr[i] = new int[col];
	}
	
	for (int i = 0; i < row; i ++)
	{
		for (int j = 0; j < col; j ++)
		{
			ptr [i][j] = matrix.ptr [i][j];
		}
	}
}

void Matrix::input (ifstream &in, Matrix & matrix2)
{
	in >> row;
	in >> col;
	
	cout << "Matrix 1 row: " << row << endl;
	cout << "Matrix 1 col: " << col << endl;
	
	ptr = new int*[row];
	
	for (int i = 0; i < row; i ++)
	{
		ptr[i] = new int[col];
	}
	
	for (int i = 0; i < row; i ++)
	{
		for (int j = 0; j < col; j ++)
		{
			in >> ptr[i][j];
		}
	}
				
	in >> matrix2.row;
	in >> matrix2.col;
	
	cout << "Matrix 2 row: " << matrix2.row << endl;
	cout << "Matrix 2 col: " << matrix2.col << endl;
	
	matrix2.ptr = new int*[matrix2.row];
	
	for (int i = 0; i < matrix2.row; i ++)
	{
		matrix2.ptr[i] = new int[matrix2.col];
	}
	
	for (int i = 0; i < matrix2.row; i ++)
	{
		for (int j = 0; j < matrix2.col; j ++)
		{
			in >> matrix2.ptr[i][j];
		}
	}
}

//Function to check if two matrices can be added together
bool Matrix::canadd (const Matrix & matrix2) const
{
	return (row == matrix2.row && col== matrix2.col);
}

//Function to check if two matrices can be multiplied
bool Matrix::canmultiply (const Matrix & matrix2) const
{
	return (col == matrix2.row);
}

Matrix Matrix::operator + (const Matrix & matrix2) const
{
	if (!canadd(matrix2))
	{
		cout << "Addition cannot be carried out because matrices are not the same size." << endl;
		exit (1);
	}
	else
	{
		int newrow = row;
		int newcol = col;
		
		Matrix sum(newrow, newcol);
		
		for (int i = 0; i < newrow; i ++)
		{
			for (int j = 0; j < newcol; j ++)
			{
				sum.ptr[i][j] = ptr[i][j] + matrix2.ptr[i][j];
			}
		}
		
		return sum;
	}
}

Matrix Matrix::operator - (const Matrix & matrix2) const
{
	if (!canadd(matrix2))
	{
		cout << "Addition cannot be carried out because matrices are not the same size." << endl;
		exit (1);
	}
	else
	{
		int newrow = row;
		int newcol = col;
		
		Matrix difference(newrow, newcol);
		
		for (int i = 0; i < newrow; i ++)
		{
			for (int j = 0; j < newcol; j ++)
			{
				difference.ptr[i][j] = ptr[i][j] - matrix2.ptr[i][j];
			}
		}
		return difference;
	}
} 

Matrix Matrix::operator *(const Matrix & matrix2) const
{
	if (!canmultiply(matrix2))
	{
		cout << "Multiplication cannot be carried out because matrices are not the same size. " << endl;
		exit (1);
	}
	else
	{
		int newrow = matrix2.row;
		int newcol = col;
 		
		Matrix product(newrow, newcol);
				
		for (int i = 0; i < product.row; i++)
	    {
	        for(int j = 0; j < product.col; j++)
	        {
	            for (int k = 0; k < col; k++)
	            {
	                product.ptr[i][j] += (ptr[i][k]*matrix2.ptr[k][j]);
	            }
	        }
	    }
	    return product;
	}
}

void Matrix::print() const
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j ++)
        {
        	cout << ptr[i][j] << "  ";
		}
		cout << endl;
    }
}

ostream& operator <<(ostream &out, const Matrix &matrix)
{
	for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j ++)
        {
        	out << matrix.ptr[i][j] << "  ";
		}
		out << endl;
    }
    return out;
}

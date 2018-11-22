#pragma once
class matrix
{
private:
	double ** data;
	unsigned int rows, cols;
	int m, n, g, i, j;
	double **mat;
public:
	matrix();
	matrix(unsigned int rows, unsigned int cols);
	~matrix();
	friend matrix operator*(const matrix &ob1, const matrix &ob2);
	friend matrix operator+(const matrix &ob1, const matrix &ob2);
	matrix operator*=(const matrix &ob);
	matrix operator+=(const matrix &ob);
	void print();
	void set();
};

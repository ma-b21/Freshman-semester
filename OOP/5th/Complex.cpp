#include"Complex.h"


ostream& operator <<(ostream& out, C_complex& c)
{
	if (c.real == INT_MAX)
	{
		out << "None!" << endl;
		return out;
	}
	if (c.real == -0)
		c.real = 0;
	if (c.imaginary == 0)
		out << c.real << endl;
	else
	{
		if (c.real != 0)
			out << c.real;
		if (c.imaginary > 0 && c.real != 0)cout << '+';
		if (abs(c.imaginary) != 1)
			out << c.imaginary << 'i' << endl;
		if (c.imaginary == 1)
			out << 'i' << endl;
		if (c.imaginary == -1)
			cout << "-i" << endl;
	}
	return out;
}
istream& operator >>(istream& in, C_complex& c)
{
	in >> c.real >> c.imaginary;
	return in;
}

C_complex& operator ++(C_complex& c)
{
	c.real++;
	return c;
}
C_complex operator ++ (C_complex& c, int)
{
	C_complex a = c;
	c.real++;
	return a;
}
C_complex& operator -- (C_complex& c)
{
	c.real--;
	return c;
}
C_complex operator -- (C_complex& c, int)
{
	C_complex a = c;
	c.real--;
	return a;
}
C_complex operator +(C_complex& a, C_complex& b)
{
	C_complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return c;
}
C_complex operator -(C_complex& a, C_complex& b)
{
	C_complex c;
	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;
	return c;
}
C_complex operator *(C_complex& a, C_complex& b)
{
	C_complex c;
	c.real = a.real * b.real - a.imaginary * b.imaginary;
	c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return c;
}
C_complex operator /(C_complex& a, C_complex& b)
{
	if (a.real == 0 && a.imaginary == 0) return 0;
	if (b.real == 0 && b.imaginary == 0)
	{
		cout << "操作无意义! ";
		return INT_MAX;
	}
	C_complex c;
	c.real = b.real;
	c.imaginary = -1 * b.imaginary;
	C_complex d = a * c;
	C_complex e = b * c;
	d.real /= e.real;
	d.imaginary /= e.real;
	return d;
}
C_complex operator +=(C_complex& a, C_complex& b)
{
	a.real += b.real;
	a.imaginary += b.imaginary;
	return a;
}
C_complex operator -=(C_complex& a, C_complex& b)
{
	a.real -= b.real;
	a.imaginary -= b.imaginary;
	return a;
}
C_complex operator *=(C_complex& a, C_complex& b)
{
	C_complex c;
	c.real = a.real * b.real - a.imaginary * b.imaginary;
	c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	a.real = c.real;
	a.imaginary = c.imaginary;
	return a;
}
C_complex operator /=(C_complex& a, C_complex& b)
{
	C_complex c;
	c = a / b;
	a.real = c.real;
	a.imaginary = c.imaginary;
	return a;
}
bool operator ==(C_complex& a, C_complex& b)
{
	if (a.real == b.real && a.imaginary == b.imaginary)
		return true;
	return false;
}

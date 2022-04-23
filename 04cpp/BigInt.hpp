#pragma once
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include <stdint.h>

int i = std::move(1);

class BigInt
{
public:
	BigInt() { length = 0; ptr = nullptr; }
	BigInt(int x);
	const static int base = 10;
	BigInt(const BigInt& other);
	BigInt(const std::string& str);


	const BigInt operator -() const;
	BigInt& operator =(const BigInt& other);
	BigInt& operator +=(const BigInt& x);
	BigInt& operator *=(const BigInt& x);
	BigInt& operator -=(const BigInt& x);
	BigInt operator +(const BigInt& x) const;
	//BigInt operator +(const BigInt& x) const{
	//BigInt(x);
//}
	BigInt operator -(const BigInt& x) const;
	BigInt operator *(const BigInt& x) const;

	BigInt extend_sign(int digits) const;

	void extend_sign_inline(int digits);
	void invert_sign_inline();

	bool operator==(const BigInt& x) const;
	bool operator!=(const BigInt& x) const;

	bool operator<(const BigInt& x) const;
	bool operator>(const BigInt& x) const;

	bool operator<=(const BigInt& x) const;
	bool operator>=(const BigInt& x) const;



	short int get_digit(int i) const;
	int get_length() const;

	~BigInt();

	friend std::ostream& operator<<(std::ostream& os, const BigInt& a);

private:
	short int* ptr;
	int length; //LITTLE ENDIAN
};


// std move â 
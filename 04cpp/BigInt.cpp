#include "pch.h"
#include <string>
#include "BigInt.hpp"

//const BigInt& BigInt::operator-() const
using std::string;

BigInt::BigInt(const std::string& str) {
	int sign = 1;
	string str_abs;
	if (str[0] == '-') {
		sign = -1;
		str_abs = str.substr(1);
	}
	else { str_abs = str; }
	length = str_abs.length();
	ptr = new short[length];
	for (int i = str_abs.length() - 1, j = 0; i >= 0; i--, j++) {
		ptr[j] = int(str_abs[i] - '0');
	}
	if (sign < 0) { invert_sign_inline(); }
}

BigInt::BigInt(const BigInt& other) {
	length = other.length;
	ptr = new short int[other.length];
	memcpy(ptr, other.ptr, length*(sizeof(short)));
}

BigInt& BigInt::operator =(const BigInt& other) {
	if (&other == this) return *this;
	delete[] ptr;
	length = other.length;
	ptr = new short int[other.length];
	memcpy(ptr, other.ptr, length*(sizeof(short)));
	return *this;
}

//delaem
BigInt& BigInt::operator +=(const BigInt& x) {
	int result_length = std::max(length, x.length) + 1;
	short* buffer = new short[result_length];

	int carry = 0;
	for (int i = 0; i < result_length; i++) {
		int tmp = int(get_digit(i)) + int(x.get_digit(i)) + carry;
		buffer[i] = tmp % 10;
		carry = tmp / 10;
	}
	//assert((carry == 0)|| (carry == 9));//нет переполнения
	length = result_length;
	delete[] ptr;
	ptr = buffer;
	return *this;
}

BigInt& BigInt::operator*=(const BigInt& x)
{
	int result_length = length + x.length;
	short* buffer = new short[result_length];

	for (int i = 0; i < result_length; i++) {
		buffer[i] = 0;
	}

	for (int i = 0; i < result_length; i++) {
		int carry = 0;
		for (int j = 0; j < result_length; j++) {
			int tmp = x.get_digit(i) * get_digit(j) + carry;
			int d1 = x.get_digit(i);
			int d2 = x.get_digit(j);
			if (i+j < result_length){
				int tmp2 = buffer[i + j] + tmp;
				buffer[i + j] = tmp2 % 10;
				carry = tmp2 / 10;
			}
		}
	}
	length = result_length;
	delete[] ptr;
	ptr = buffer;
	return *this;
}

BigInt::BigInt(int x)
{
	length = 10;
	ptr = new short[length];
	int32_t y = abs(x);
	for (int i = 0; i < length; i++) {
		ptr[i] = y % base;
		y /= base;
	}
	if (x < 0) invert_sign_inline();
}

BigInt& BigInt::operator-=(const BigInt& x) {
	*this += -x;
	return *this;
}


BigInt BigInt::operator +(const BigInt& x) const {
	BigInt tmp(*this);
	tmp += x;
	return tmp;
}

BigInt BigInt::operator *(const BigInt& x) const {
	BigInt tmp(*this);
	tmp *= x;
	return tmp;
}

BigInt BigInt::operator -(const BigInt& x) const {
	BigInt tmp(*this);
	tmp -= x;
	return tmp;
}

short int BigInt::get_digit(int i) const {
	if (i < length) return ptr[i];
	short int sign = (ptr[length-1] < 5) ? 0 : 9;
	return sign;
}

int BigInt::get_length() const {
	return length;
}


BigInt::~BigInt() {
	delete[] ptr;
}


const BigInt BigInt::operator-() const
{
	BigInt x_copy = *this;
	x_copy.invert_sign_inline();
	return x_copy;
	// // O: insert return statement here
}

bool BigInt::operator==(const BigInt& x) const {
	int max_length = std::max(length, x.length);
	for (int i = 0; i < max_length; i++) {
		if (get_digit(i) != x.get_digit(i)) return false;
	}
	return true;
}
void BigInt::invert_sign_inline()
{	
	for (int i = 0; i < length; i++) {
		ptr[i] = (base - 1) - ptr[i];
	}

	int carry = 1;
	for (int i = 0; i < length; i++) {
		int tmp = int(get_digit(i)) + carry;
		ptr[i] = tmp % 10;
		carry = tmp / 10;
	}
	//*this += 1;
}
//to do пустой конструктор
BigInt BigInt::extend_sign(int digits) const
{	
	short int sign = (ptr[length - 1] < 5) ? 0 : 9;
	BigInt result;
	result.length = length + digits;
	result.ptr = new short int[result.length];
	memcpy(result.ptr, ptr, length*sizeof(short int));
	for (int i = length; i < result.length; i++) {
		result.ptr[i] = sign;
	}
	return result;
}

void BigInt::extend_sign_inline(int digits)
{
	short int sign = (ptr[length - 1] < 5) ? 0 : 9;
	BigInt result;
	int length2 = length + digits;
	short * ptr2 = new short int[length2];

	memcpy(ptr2, ptr, length * sizeof(short int));
	for (int i = length; i < length2; i++) {
		ptr2[i] = sign;
	}
	delete[] ptr;
	ptr = ptr2;
	length = length2;
}

bool BigInt::operator!=(const BigInt& x) const {
	return (!(*this == x));
}

bool BigInt::operator<(const BigInt& x) const {
	return true;
}

bool BigInt::operator>(const BigInt& x) const {
	if (*this == x) return false;
	if (*this < x) return false;
	return true;
}

bool BigInt::operator<=(const BigInt& x) const {
	if ((*this == x) || (*this < x)) return true;
	return false;
}

bool BigInt::operator>=(const BigInt& x) const {
	if ((*this == x) || (*this > x)) return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const BigInt& a) {
	for (int i = 0; i < a.get_length(); i++) {
		os << a.get_digit(i);
		std::cout << a.get_digit(i) << " ";
	}
	return os;
}
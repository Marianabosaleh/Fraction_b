#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

namespace ariel
{
	class Fraction
	{
		int Numerator;
		int Denominator;

	public:
		// constructors
		Fraction();
		Fraction(int Numerator, int Denominator);
		Fraction(float flo);
		Fraction(const Fraction &other);
		Fraction &operator=(const Fraction &other);
		Fraction(Fraction &&other) noexcept;
		Fraction &operator=(Fraction &&other) noexcept;

		// destructor
		~Fraction(void);

		// Getter and Setter
		int getNumerator() const;
		int getDenominator() const;
		void setNumerator(int Numerator);
		void setDenominator(int Denominator);

		// Fraction functions
		void reduce();
		void float_To_Fraction(float flo);
		float Fraction_To_float(int Numerator, int Denominator);

		// Operator overloading functions
		friend Fraction operator+(const Fraction &fraction1, const Fraction &fraction2);
		friend Fraction operator+(const Fraction &frac, const float &num);
		friend Fraction operator+(const float &num, const Fraction &frac);
		friend Fraction operator-(const Fraction &fraction1, const Fraction &fraction2);
		friend Fraction operator-(const Fraction &frac, const float &num);
		friend Fraction operator-(const float &num, const Fraction &frac);
		friend Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
		friend Fraction operator*(const Fraction &frac, const float &num);
		friend Fraction operator*(const float &num, const Fraction &frac);
		friend Fraction operator/(const Fraction &fraction1, const Fraction &fraction2);
		friend Fraction operator/(const Fraction &frac, const float &num);
		friend Fraction operator/(const float &num, const Fraction &frac);

		const Fraction operator++();
		const Fraction operator++(int);
		const Fraction operator--();
		const Fraction operator--(int);

		friend bool operator>(const Fraction &fraction1, const Fraction &fraction2);
		friend bool operator>(const Fraction &frac, float num);
		friend bool operator>(float num, const Fraction &frac);
		friend bool operator<(const Fraction &fraction1, const Fraction &fraction2);
		friend bool operator<(const Fraction &frac, float num);
		friend bool operator<(float num, const Fraction &frac);
		friend bool operator>=(const Fraction &fraction1, const Fraction &fraction2);
		friend bool operator>=(const Fraction &frac, float num);
		friend bool operator>=(float num, const Fraction &frac);
		friend bool operator<=(const Fraction &fraction1, const Fraction &fraction2);
		friend bool operator<=(const Fraction &frac, float num);
		friend bool operator<=(float num, const Fraction &frac);
		friend bool operator==(const Fraction &fraction1, const Fraction &fraction2);
		friend bool operator==(const Fraction &frac, float num);
		friend bool operator==(float num, const Fraction &frac);
		friend bool operator!=(const Fraction &fraction1, const Fraction &fraction2);
		friend bool operator!=(const Fraction &frac, float num);
		friend bool operator!=(float num, const Fraction &frac);

		friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);
		friend std::istream &operator>>(std::istream &inn, Fraction &fraction);
	};

}
#include "Fraction.hpp"
using namespace std;
namespace ariel
{

    // constructors
    Fraction::Fraction()
    {
        this->Numerator = 0;
        this->Denominator = 1;
    }
    Fraction::Fraction(int Numerator, int Denominator)
    {
        if (Denominator == 0)
        {
            throw std::invalid_argument("Denominatorou can't divide by Denominator 0 ");
        }

        this->Numerator = Numerator;
        this->Denominator = Denominator;
        reduce();
    }

    Fraction::Fraction(float flo)
    {
        const int dig = 1000;
        int num = flo * dig;
        int den = dig;
        Fraction frac(num, den);
        Numerator = frac.getNumerator();
        Denominator = frac.getDenominator();
        reduce();
    }
    Fraction::Fraction(const Fraction &other)
        : Numerator(other.Numerator), Denominator(other.Denominator)
    {
    }

    Fraction &Fraction::operator=(const Fraction &other)
    {
        if (this != &other)
        {
            Numerator = other.Numerator;
            Denominator = other.Denominator;
        }
        return *this;
    }

    Fraction::Fraction(Fraction &&other) noexcept
        : Numerator(std::exchange(other.Numerator, 0)),
          Denominator(std::exchange(other.Denominator, 0))
    {
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept
    {
        if (this != &other)
        {
            Numerator = std::exchange(other.Numerator, 0);
            Denominator = std::exchange(other.Denominator, 0);
        }
        return *this;
    }
    // destructor
    Fraction::~Fraction() {}

    // Getter and Setter
    int Fraction::getNumerator() const
    {
        return this->Numerator;
    }

    int Fraction::getDenominator() const
    {
        return this->Denominator;
    }

    void Fraction::setNumerator(int Numerator)
    {
        this->Numerator = Numerator;
    }

    void Fraction::setDenominator(int Denominator)
    {
        if (Denominator == 0)
        { // checking if the denominator is valid (!= 0) first
            throw std::invalid_argument("denominator cant be zero !!");
        }
        this->Denominator = Denominator;
    }

    void Fraction::reduce()
    {
        int gcd = std::__gcd(Numerator, Denominator);
        if (Denominator == 0)
        {
            throw("denominator cant be 0");
        }
        Numerator /= gcd;
        Denominator /= gcd;
        if (Denominator < 0)
        {
            Numerator = -Numerator;
            Denominator = -Denominator;
        }
    }

    void Fraction::float_To_Fraction(float flo)
    {
        const int dig = 1000;
        int num = flo * dig;
        int den = dig;
        Fraction frac(num, den);
        Numerator = frac.getNumerator();
        Denominator = frac.getDenominator();
        reduce();
    }
    float Fraction::Fraction_To_float(int Numerator, int Denominator)
    {
        float to_f = static_cast<float>(Numerator) / Denominator;
        float round = roundf(to_f * 1000) / 1000; // round to first 3 digits
        return round;
    }
    // Operator overloading functions
    Fraction operator+(const Fraction &fraction1, const Fraction &fraction2)
    {
        long long num = (long long)fraction1.getNumerator() * (long long)fraction2.getDenominator() + (long long)fraction1.getDenominator() * (long long)fraction2.getNumerator();
        long long den = (long long)fraction1.getDenominator() * (long long)fraction2.getDenominator();
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
        {
            throw std::overflow_error("Fraction overflow or underflow");
        }
        Fraction result = Fraction(num, den);
        result.reduce();
        return result;
    }
    Fraction operator+(const Fraction &frac, const float &num)
    {
        Fraction temp = Fraction(num);
        Fraction result = frac + temp;
        result.reduce();
        return result;
    }
    Fraction operator+(const float &num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        Fraction result = temp + frac;
        result.reduce();
        return result;
    }
    Fraction operator-(const Fraction &fraction1, const Fraction &fraction2)
    {
        long long num = (long long)fraction1.getNumerator() * (long long)fraction2.getDenominator() - (long long)fraction1.getDenominator() * (long long)fraction2.getNumerator();
        long long den = (long long)fraction1.getDenominator() * (long long)fraction2.getDenominator();
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
        {
            throw std::overflow_error("Fraction overflow or underflow");
        }
        Fraction result = Fraction(num, den);
        result.reduce();
        return result;
    }
    Fraction operator-(const Fraction &frac, const float &num)
    {
        Fraction temp = Fraction(num);
        Fraction result = frac - temp;
        result.reduce();
        return result;
    }
    Fraction operator-(const float &num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        Fraction result = temp - frac;
        result.reduce();
        return result;
    }
    Fraction operator*(const Fraction &fraction1, const Fraction &fraction2)
    {
        long long num = (long long)fraction1.getNumerator() * (long long)fraction2.getNumerator();
        long long den = (long long)fraction1.getDenominator() * (long long)fraction2.getDenominator();
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
        {
            throw std::overflow_error("Fraction overflow or underflow");
        }
        Fraction result = Fraction(num, den);
        result.reduce();
        return result;
    }
    Fraction operator*(const Fraction &frac, const float &num)
    {
        Fraction temp = Fraction(num);
        Fraction result = frac * temp;
        result.reduce();
        return result;
    }
    Fraction operator*(const float &num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        Fraction result = temp * frac;
        result.reduce();
        return result;
    }
    Fraction operator/(const Fraction &fraction1, const Fraction &fraction2)
    {
        long long num = (long long)fraction1.getNumerator() * (long long)fraction2.getDenominator();
        long long den = (long long)fraction1.getDenominator() * (long long)fraction2.getNumerator();
        if (den == 0)
        {
            throw std::runtime_error("divide by 0");
        }
        if (num > INT_MAX || num < INT_MIN || den > INT_MAX || den < INT_MIN)
        {
            throw std::overflow_error("Fraction overflow or underflow");
        }
        Fraction result = Fraction(num, den);
        result.reduce();
        return result;
    }
    Fraction operator/(const Fraction &frac, const float &num)
    {
        Fraction temp = Fraction(num);
        Fraction result = frac / temp;
        return result;
    }
    Fraction operator/(const float &num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        Fraction result = temp / frac;
        result.reduce();
        return result;
    }

    const Fraction Fraction::operator++()
    {
        Numerator += Denominator;
        return *this;
    }
    const Fraction Fraction::operator++(int)
    {
        Fraction temp(*this);
        Numerator += Denominator;
        return temp;
    }
    const Fraction Fraction::operator--()
    {
        Numerator -= Denominator;
        return *this;
    }
    const Fraction Fraction::operator--(int)
    {
        Fraction temp(*this);
        Numerator -= Denominator;
        return temp;
    }

    bool operator>(const Fraction &fraction1, const Fraction &fraction2)
    {
        int num1 = fraction1.getNumerator() * fraction2.getDenominator();
        int num2 = fraction2.getNumerator() * fraction1.getDenominator();

        return (num1 > num2);
    }
    bool operator>(const Fraction &frac, float num)
    {
        Fraction temp = Fraction(num);
        return (frac > temp);
    }
    bool operator>(float num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        return (temp > frac);
    }
    bool operator<(const Fraction &fraction1, const Fraction &fraction2)
    {
        int num1 = fraction1.getNumerator() * fraction2.getDenominator();
        int num2 = fraction2.getNumerator() * fraction1.getDenominator();
        return (num1 < num2);
    }
    bool operator<(const Fraction &frac, float num)
    {
        Fraction temp = Fraction(num);
        return (frac < temp);
    }
    bool operator<(float num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        return (temp < frac);
    }
    bool operator>=(const Fraction &fraction1, const Fraction &fraction2)
    {
        int num1 = fraction1.getNumerator() * fraction2.getDenominator();
        int num2 = fraction2.getNumerator() * fraction1.getDenominator();
        return (num1 > num2 || num1 == num2);
    }
    bool operator>=(const Fraction &frac, float num)
    {
        Fraction temp = Fraction(num);
        return (frac >= temp);
    }
    bool operator>=(float num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        return (temp >= frac);
    }
    bool operator<=(const Fraction &fraction1, const Fraction &fraction2)
    {
        int num1 = fraction1.getNumerator() * fraction2.getDenominator();
        int num2 = fraction2.getNumerator() * fraction1.getDenominator();
        return (num1 < num2 || num1 == num2);
    }
    bool operator<=(const Fraction &frac, float num)
    {
        Fraction temp = Fraction(num);
        return (frac <= temp);
    }
    bool operator<=(float num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        return (temp <= frac);
    }
    bool operator==(const Fraction &fraction1, const Fraction &fraction2)
    {
        int num1 = fraction1.getNumerator() * fraction2.getDenominator();
        int num2 = fraction2.getNumerator() * fraction1.getDenominator();

        return (num1 == num2);
    }
    bool operator==(const Fraction &frac, float num)
    {
        Fraction temp = Fraction(num);
        return (frac == temp);
    }
    bool operator==(float num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        return (temp == frac);
    }
    bool operator!=(const Fraction &fraction1, const Fraction &fraction2)
    {
        int num1 = fraction1.getNumerator() * fraction2.getDenominator();
        int num2 = fraction2.getNumerator() * fraction1.getDenominator();
        return (num1 != num2);
    }
    bool operator!=(const Fraction &frac, float num)
    {
        Fraction temp = Fraction(num);
        return (frac != temp);
    }
    bool operator!=(float num, const Fraction &frac)
    {
        Fraction temp = Fraction(num);
        return (temp != frac);
    }

    std::ostream &operator<<(std::ostream &out, const Fraction &fraction)
    {
        out << fraction.getNumerator() << '/' << fraction.getDenominator();
        return out;
    }

    std::istream &operator>>(std::istream &inn, Fraction &fraction)
    {
        int numerator, denominator;
        if (denominator == 0)
        {
            throw std::runtime_error("denominator cant be zero");
        }
        if ((inn >> numerator >> denominator) && denominator != 0)
        {
            int gcd = __gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            fraction.setNumerator(numerator);
            fraction.setDenominator(denominator);
        }
        else
        {
            throw std::runtime_error("input is one number");
        }
        return inn;
    }

}
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

int NOD(int a, int b)
{
    while (max(a, b) % min(a, b) != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return min(a, b);
}

class Rational 
{
    public:
        Rational()
        {
            n= 0;
            d = 1;
        }
        
        Rational(int numerator, int denominator)
        {
            if (numerator == 0)
                d = 1;
            else if (numerator * denominator > 0 && numerator > 0)
            {
                n = numerator / NOD(numerator, denominator);
                d = denominator / NOD(numerator, denominator);
            }
            else if (numerator * denominator > 0)
            {
                n = -numerator / NOD(-numerator, -denominator);
                d = -denominator / NOD(-numerator, -denominator);
            }
            else if (numerator < 0)
            {
                n = numerator / NOD(-numerator, denominator);
                d = denominator / NOD(-numerator, denominator);
            }
            else
            {
                n = -numerator / NOD(numerator, -denominator);
                d = -denominator / NOD(numerator, -denominator);
            }
        }

        int Numerator() const
        {
            return n;
        }

        int Denominator() const
        {
            return d;
        }
    
    private:
        int n, d;
};

bool operator==(const Rational& l,  const Rational& r)
{
    return l.Numerator() == r.Numerator() && l.Denominator() == r.Denominator();
}

bool operator<(Rational lhs, Rational rhs) 
{
	return (lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator());
}

Rational operator+(const Rational& l,  const Rational& r)
{
    int n = l.Numerator() * r.Denominator() + l.Denominator() * r.Numerator();
    int d = l.Denominator() * r.Denominator();
    return Rational(n, d);
}

Rational operator-(const Rational& l,  const Rational& r)
{
    int n = l.Numerator() * r.Denominator() - l.Denominator() * r.Numerator();
    int d = l.Denominator() * r.Denominator();
    return Rational(n, d);
}

Rational operator*(const Rational& l,  const Rational& r)
{
    return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/(const Rational& l,  const Rational& r)
{
    return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

ostream& operator << (ostream& s, Rational& r) {
	s << r.Numerator() << "/" << r.Denominator();
	return s;
}

istream& operator >> (istream& s, Rational& r) {
	int numerator = 0;
	int denominator = 1;

	s >> numerator;
	s.ignore(1);
	s >> denominator;

	r = Rational(numerator, denominator);

	return s;
}

int main() {
    return 0;
}

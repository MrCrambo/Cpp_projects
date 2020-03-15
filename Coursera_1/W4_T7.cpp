#include <iostream>
#include <exception>
using namespace std;

class Rational 
{
    public:
        Rational() 
        {
            n = 0;
            d = 1;
        }

        Rational(const int& numerator, const int& denominator) 
        {
            if (denominator == 0)
                throw invalid_argument("zero denominator");

            n = numerator;
            d = denominator;

            int first = abs(n);
            int second = abs(d);
            while (first != 0 && second != 0) 
            {
                if (first > second)
                    first -= second;
                else
                    second -= first;
            }
            
            n /= (first + second);
            d /= (first + second);

            if (n < 0 && d < 0) 
            {
                n = abs(n);
                d = abs(d);
            } 
            else if (d < 0) 
            {
                d = abs(d);
                n *= -1;
            }

            if (n == 0)
                d = 1;
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
        int n;
        int d;
};

bool operator==(const Rational& a, const Rational& b) {
    return a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator();
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

Rational operator*(const Rational& a, const Rational& b) {
    return {a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator()};
}

Rational operator/(const Rational& a, const Rational& b) 
{
    if (b == Rational(0, 1))
        throw domain_error("zero division");
    return {a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator()};
}

ostream& operator<<(ostream& output, const Rational& data) 
{
    output << data.Numerator() << "/" << data.Denominator();
    return output;
}

istream& operator>>(istream& input, Rational& data) 
{
    int n = 0;
    int d = 1;
    if (input) {
        input >> n;
        input.ignore(1);
        input >> d;
        data = {n, d};    
    }
    return input;
}


bool operator<(const Rational& lhs, const Rational& rhs) 
{
    return (lhs.Numerator() * rhs.Denominator() < lhs.Denominator() * rhs.Numerator());
}

int main() 
{
    try 
    {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {}

    try 
    {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {}

    cout << "OK" << endl;
    return 0;
}

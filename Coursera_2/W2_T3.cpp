#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) 
{
    os << "{";
    bool first = true;
    for (const auto& x : s) 
    {
        if (!first)
            os << ", ";
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) 
{
    os << "{";
    bool first = true;
    for (const auto& x : s) 
    {
        if (!first)
            os << ", ";
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) 
{
    os << "{";
    bool first = true;
    for (const auto& kv : m)
    {
        if (!first)
            os << ", ";
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) 
{
    if (t != u) 
    {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty())
            os << " hint: " << hint;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) 
{
    AssertEqual(b, true, hint);
}

class TestRunner {
    public:
        template <class TestFunc>
        void RunTest(TestFunc func, const string& test_name) 
        {
            try 
            {
                func();
                cerr << test_name << " OK" << endl;
            } 
            catch (exception& e) 
            {
                ++fail_count;
                cerr << test_name << " fail: " << e.what() << endl;
            } 
            catch (...) 
            {
                ++fail_count;
                cerr << "Unknown exception caught" << endl;
            }
        }

        ~TestRunner() 
        {
            if (fail_count > 0) 
            {
                cerr << fail_count << " unit tests failed. Terminate" << endl;
                exit(1);
            }
        }

    private:
        int fail_count = 0;
};

bool IsPalindrom(const string &str) 
{
   if(str.size() < 2)
   {
       return true;
   }
   size_t start = 0, end = str.size() - 1;
   while (start <= end) 
   {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
   }
   return true;
}

void TestIsPalindrom(){
    string str="";
    {
        // Пустая строка - палиндром
        Assert(IsPalindrom(str), str + " Empty string is palindrome");

        str = "a";
        Assert(IsPalindrom(str), str + " One char string is palindrome");
        
        str = "1";
        Assert(IsPalindrom(str), str + " One char string is palindrome");
        
        str = "!";
        Assert(IsPalindrom(str), str + " One char string is palindrome");
        
        str = "ABBA";
        Assert(IsPalindrom(str), str + " Uppercase");
        
        str = " ";
        Assert(IsPalindrom(str), str + " One white-space string is palindrome");
        
        str = "ABcBA";
        Assert(IsPalindrom(str), str + " Odd numbers of chars");
        
        str = "####";
        Assert(IsPalindrom(str), str + " Even numbers of chars");
        
        str = "12345678987654321";
        Assert(IsPalindrom(str), "String " + str + "is numeric palindrom");
        
        str = "!@#$%^&*()_++_)(*&^%$#@!";
        Assert(IsPalindrom(str), "String " + str + " is symbols palindrom");

        str = "-madam-";
        Assert(IsPalindrom(str), "String" + str + " is a palindrom.");

        str = "|m a d a m|";
        Assert(IsPalindrom(str), "String" + str + " is a palindrom.");

        str = "\" \"";
        Assert(IsPalindrom(str), "String" + str + " is a palindrom.");

        str = "\tab\nba\t";
        Assert(IsPalindrom(str), "String" + str + " is a palindrom.");
    }
}

void TestIsNotPalindrom(){
    string str;
    
    str = "a ba";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Ignore symbol int the middle of string");
    
    str = " aba";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Ignore symbol in the start of  string");
    
    str = "aba!";
    Assert(!IsPalindrom(str), "String" + str + " is not a palindrom. Ignore ! in the end of string");
    
    str = " m  ada m   ";
    Assert(!IsPalindrom(str), "String" + str + " is not a palindrom. Skipping white-space characters");
    
    str = "ABc ab cBA";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Did not compare symbol in the middle of string");

    str = "AbcBa";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Case sensetive");

    str = "\tabba ";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Tab in the start");

    str = " abba\t";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Tab in the end");

    str = "ab\t ba";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. Tab in the middle");

    str = "\nabcba";
    Assert(!IsPalindrom(str), "String " + str + " is not a palindrom. \n in the start");
}

int main() 
{
    TestRunner runner;
    runner.RunTest(TestIsPalindrom, "TestIsPalindrom");
    runner.RunTest(TestIsNotPalindrom, "TestIsNotPalindrom");
    return 0;
}

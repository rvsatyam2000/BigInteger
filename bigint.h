#include<bits/stdc++.h>
using namespace std;
#define POS 1
#define NEG 0
class BigInt
{
    string digits;
    int sign;

public:
    // Constructors:
    /*
        Storing numbers in the form of string in reverse order
        for easy calculations.
    */
    BigInt(long long int n = 0)
    {
        if (n < 0)
        {
            sign = NEG;
        }
        else
        {
            sign = POS;
        }
        if (sign == NEG)
        {
            n *= -1;
        }
        digits = to_string(n);
        reverse(digits.begin(), digits.end());
        trim((*this));
    }
    BigInt(string &s)
    {
        int n = s.size();
        int end = 0;
        if (n != 0 and s[0] == '-')
        {
            sign = NEG;
            end = 1;
        }
        else
        {
            sign = POS;
        }

        for (int i = n - 1; i >= end; i--)
        {
            if (!isdigit(s[i]))
            {
                cout << "Invalid number\n";
                exit(1);
            }
            digits.push_back(s[i]);
        }
        if (!digits.size())
        {
            cout << "Number can't be empty\n";
            exit(1);
        }
        if (digits == "0")
        {
            sign = POS;
        }
        trim((*this));
    }
    BigInt(const char *s)
    {
        int n = strlen(s);
        int end = 0;
        if (n != 0 and s[0] == '-')
        {
            sign = NEG;
            end = 1;
        }
        else
        {
            sign = POS;
        }
        for (int i = n - 1; i >= end; i--)
        {
            if (!isdigit(s[i]))
            {
                cout << "Invalid number\n";
                exit(1);
            }
            digits.push_back(s[i]);
        }
        if (!digits.size())
        {
            cout << "Number can't be empty\n";
            exit(1);
        }
        if (digits == "0")
        {
            sign = POS;
        }
        trim((*this));
    }
    BigInt(BigInt &num)
    {
        digits = num.digits;
        sign = num.sign;
        trim((*this));
    }
    BigInt(const BigInt &num)
    {
        digits = num.digits;
        sign = num.sign;
        trim((*this));
    }
    // Helper functions

    // To find the length of number
    friend int Length(const BigInt &num)
    {
        return num.digits.size();
    }

    // To check if number is 0 or not
    friend bool Null(const BigInt &num)
    {
        return num.digits == "0";
    }

    // To divide number by 2
    friend void divide_by_2(BigInt &num)
    {
        int add = 0;
        for (int i = num.digits.size() - 1; i >= 0; i--)
        {
            int digit = ((num.digits[i] - '0') >> 1) + add;
            add = (((num.digits[i] - '0') & 1) * 5);
            num.digits[i] = digit + '0';
        }
        trim(num);
    }

    // To remove 0's from front side of number
    friend void trim(BigInt &num)
    {
        int n = Length(num);
        for (int i = n - 1; i >= 0 and num.digits[i] == '0'; i--)
        {
            num.digits.pop_back();
        }
        if (num.digits.size() == 0)
        {
            num.digits = "0";
            num.sign = POS;
        }
    }

    // To return absolute number
    friend BigInt abs(const BigInt &num)
    {
        BigInt temp;
        temp.digits = num.digits;
        temp.sign = num.sign;
        if (temp.sign == NEG)
        {
            temp.sign = POS;
        }
        return temp;
    }

    // Comparison operators
    bool operator==(const BigInt &num)
    {
        return (*this).digits == num.digits and (*this).sign == num.sign;
    }
    bool operator!=(const BigInt &num)
    {
        return !((*this) == num);
    }
    bool operator>(const BigInt &num)
    {
        int a = (*this).sign;
        int b = (num).sign;
        if (a == POS and b == NEG)
        {
            return true;
        }
        else if (a == NEG and b == POS)
        {
            return false;
        }
        else
        {
            int l1 = (*this).digits.size();
            int l2 = num.digits.size();
            if (l1 > l2)
            {
                if (a == POS)
                    return true;
                return false;
            }
            else if (l1 < l2)
            {
                if (a == POS)
                    return false;
                return true;
            }
            else
            {
                for (int i = l1 - 1; i >= 0; i--)
                {
                    if ((*this).digits[i] > num.digits[i])
                    {
                        return true;
                    }
                    else if ((*this).digits[i] < num.digits[i])
                    {
                        return false;
                    }
                }
            }
        }
        return false;
    }
    bool operator>=(const BigInt &num)
    {
        bool flag = (*this) > num;
        flag = flag || ((*this) == num);
        return flag;
    }
    bool operator<(const BigInt &num)
    {
        BigInt temp(num);
        return (temp > (*this));
    }
    bool operator<=(const BigInt &num)
    {
        BigInt temp(num);
        return (temp >= (*this));
    }
    /* * * * Operator Overloading * * * */

    // Direct assignment
    BigInt &operator=(const BigInt &num)
    {
        digits = num.digits;
        sign = num.sign;
        return (*this);
    }

    BigInt &operator+=(const BigInt &num)
    {
        if ((*this).sign == num.sign)
        {
            int t = 0, s, i;
            int n = Length((*this)), m = Length(num);
            if (m > n)
                (*this).digits.append(m - n, '0');
            n = Length(*this);
            for (i = 0; i < n; i++)
            {
                if (i < m)
                    s = ((*this).digits[i] - '0' + num.digits[i] - '0') + t;
                else
                    s = (*this).digits[i] - '0' + t;
                t = s / 10;
                (*this).digits[i] = (s % 10) + '0';
            }
            if (t)
                (*this).digits.push_back(t + '0');
        }
        else if ((*this).sign == POS and num.sign == NEG)
        {
            BigInt a = abs(*this);
            BigInt b = abs(num);
            if (a > b)
            {
                BigInt temp = num;
                temp.sign = POS;
                (*this) -= temp;
            }
            else if (b > a)
            {
                BigInt temp = num;
                temp.sign = POS;
                temp -= (*this);
                (*this) = temp;
                (*this).sign = NEG;
            }
            else
            {
                (*this).digits.erase();
                (*this).digits.push_back('0');
                (*this).sign = POS;
            }
        }
        else if ((*this).sign == NEG and num.sign == POS)
        {
            BigInt a = abs(*this);
            BigInt b = abs(num);
            if (a > b)
            {
                BigInt temp = num;
                (*this).sign = POS;
                (*this) -= temp;
                (*this).sign = NEG;
            }
            else if (b > a)
            {
                BigInt temp = num;
                (*this).sign = POS;
                temp -= (*this);
                (*this) = temp;
            }
            else
            {
                (*this).digits.erase();
                (*this).digits.push_back('0');
                (*this).sign = POS;
            }
        }
        return (*this);
    }
    BigInt operator+(const BigInt &num)
    {
        BigInt tmp(*this);
        tmp += num;
        return tmp;
    }
    BigInt operator-(const BigInt &num)
    {
        BigInt tmp(*this);
        tmp -= num;
        return tmp;
    }
    BigInt &operator-=(const BigInt &num)
    {
        if ((*this).sign == num.sign)
        {
            BigInt a = abs(*this);
            BigInt b = abs(num);
            if (a > b)
            {
                int n = Length(*this), m = Length(num);
                int i, t = 0, s;
                for (i = 0; i < n; i++)
                {
                    if (i < m)
                        s = (*this).digits[i] - '0' - (num.digits[i] - '0') + t;
                    else
                        s = (*this).digits[i] - '0' + t;
                    if (s < 0)
                        s += 10,
                            t = -1;
                    else
                        t = 0;
                    (*this).digits[i] = s + '0';
                }
                while (n > 1 && (*this).digits[n - 1] == '0')
                    (*this).digits.pop_back(),
                        n--;
            }
            else if (a < b)
            {
                BigInt temp = num;
                temp -= (*this);
                (*this) = temp;
                (*this).sign = NEG;
            }
            else
            {
                (*this).digits.erase();
                (*this).digits.push_back('0');
                (*this).sign = POS;
            }
        }
        else if ((*this).sign == POS and num.sign == NEG)
        {
            BigInt temp = num;
            temp.sign = POS;
            (*this) += temp;
        }
        else if ((*this).sign == NEG and num.sign == POS)
        {
            BigInt temp = (*this);
            temp.sign = POS;
            temp += num;
            (*this) = temp;
            (*this).sign = NEG;
        }
        return (*this);
    }

    // Post/Pre - Incrementation
    BigInt &operator++()
    {
        (*this) = (*this) + BigInt("1");
        return (*this);
    }
    BigInt operator++(int temp)
    {
        BigInt tmp = (*this);
        ++(*this);
        return tmp;
    }
    BigInt &operator--()
    {
        (*this) = (*this) - BigInt("1");
        return (*this);
    }
    BigInt operator--(int temp)
    {
        BigInt tmp = (*this);
        --(*this);
        return tmp;
    }

    // Read and Write
    friend ostream &operator<<(ostream &cout, const BigInt &num)
    {
        if (num.sign == NEG)
        {
            cout << "-";
        }
        int n = Length(num);
        for (int j = n - 1; j >= 0; j--)
        {
            cout << num.digits[j];
        }
        return cout;
    }
    friend istream &operator>>(istream &cin, BigInt &num)
    {
        cin >> num.digits;
        int n = Length(num);
        if (n == 0 || (n == 1 and num.digits[0] == '-'))
        {
            cout << "Number can't be empty" << endl;
            exit(1);
        }
        if (num.digits[0] == '-')
        {
            num.digits.erase(0, 1);
            num.sign = NEG;
        }
        else
        {
            num.sign = POS;
        }
        reverse(num.digits.begin(), num.digits.end());
        trim((num));
        return cin;
    }

    // Multiplication and Division
    BigInt &operator*=(const BigInt &num)
    {
        if (Null((*this)) || Null(num))
        {
            (*this) = BigInt();
            return (*this);
        }
        int n = (*this).digits.size(), m = num.digits.size();
        vector<int> v(n + m, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                v[i + j] += ((*this).digits[i] - '0') * (num.digits[j] - '0');
            }
        n += m;
        (*this).digits.resize(v.size());
        for (int s, i = 0, t = 0; i < n; i++)
        {
            s = t + v[i];
            v[i] = s % 10;
            t = s / 10;
            (*this).digits[i] = v[i] + '0';
        }
        for (int i = n - 1; i >= 1 && !v[i]; i--)
            (*this).digits.pop_back();
        if ((*this).sign == num.sign)
        {
            (*this).sign = POS;
        }
        else
        {
            (*this).sign = NEG;
        }
        return (*this);
    }
    BigInt operator*(const BigInt &num)
    {
        BigInt temp = (*this);
        temp *= num;
        return temp;
    }
    BigInt &operator/=(const BigInt &num)
    {
        if (Null(num))
        {
            cout << "Arithmetic Error: Division By 0";
            exit(1);
        }
        BigInt a = abs(*this);
        BigInt b = abs(num);
        if (a < b)
        {
            (*this) = BigInt();
            return (*this);
        }
        int i, lgcat = 0;
        int n = Length((*this)), m = Length(num);
        vector<int> cat(n, 0);
        BigInt t, cc;
        for (i = n - 1; t * 10 + (*this).digits[i] - '0' < b; i--)
        {
            t *= 10;
            t += (*this).digits[i] - '0';
        }
        for (; i >= 0; i--)
        {
            t = t * 10 + (*this).digits[i] - '0';
            for (cc = 9; cc * b > t; cc--)
                ;
            t -= cc * b;
            cat[lgcat++] = cc.digits[0] - '0';
        }

        (*this).digits.erase();

        for (i = lgcat - 1; i >= 0; i--)
            (*this).digits.push_back(cat[i] + '0');

        if ((*this).sign == num.sign)
        {
            (*this).sign = POS;
        }
        else
        {
            (*this).sign = NEG;
        }
        return (*this);
    }
    BigInt operator/(const BigInt &num)
    {
        BigInt temp(*this);
        temp /= num;
        return temp;
    }
    // Modulo
    BigInt operator%(const BigInt &num)
    {
        BigInt temp = (*this);
        temp %= num;
        return temp;
    }
    BigInt &operator%=(const BigInt &num)
    {
        if (Null(num))
        {
            cout << "Arithmetic Error: Division By 0";
            exit(1);
        }
        BigInt a = abs(*this);
        BigInt b = abs(num);
        if (a < b)
        {
            return (*this);
        }
        int i, lgcat = 0;
        int n = Length((*this)), m = Length(num);
        vector<int> cat(n, 0);
        BigInt t, cc;
        for (i = n - 1; t * 10 + (*this).digits[i] - '0' < b; i--)
        {
            t *= 10;
            t += (*this).digits[i] - '0';
        }
        for (; i >= 0; i--)
        {
            t = t * 10 + (*this).digits[i] - '0';
            for (cc = 9; cc * b > t; cc--)
                ;
            t -= cc * b;
        }

        (*this).digits.erase();
        (*this).digits = t.digits;
        if (t.digits[0] == '0')
        {
            (*this).sign = POS;
        }
        return (*this);
    }
    // Power Function
    BigInt &operator^=(const BigInt &num)
    {
        if (num.sign == NEG)
        {
            cout << "Power should be positive\n";
            exit(0);
        }
        BigInt Exponent(num), Base(*this);
        (*this) = 1;
        while (!Null(Exponent))
        {
            if ((Exponent.digits[0] - '0') & 1)
                (*this) *= Base;
            Base *= Base;
            divide_by_2(Exponent);
        }
        return (*this);
    }
    BigInt operator^(const BigInt &num)
    {
        BigInt temp = (*this);
        temp ^= num;
        return temp;
    }
    friend BigInt sqrt(BigInt &num)
    {
        if(num.sign == NEG){
            cout << "Number can't be negative\n";
            exit(1);
        }
        BigInt left, right(num), v(1), mid, prod;
        divide_by_2(right);
        while (left <= right)
        {
            mid += left;
            mid += right;
            divide_by_2(mid);
            prod = (mid * mid);
            if (prod <= num)
            {
                v = mid;
                ++mid;
                left = mid;
            }
            else
            {
                --mid;
                right = mid;
            }
            mid = BigInt();
        }
        return v;
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isResultNegative = false;

    string trimZero(const vector<int>& result) {
        string resultString;
        auto it = find_if(result.begin(), result.end(), [](int i) { return i != 0; });
        if (it == result.end()) {
            return "0";
        }
        for (; it != result.end(); ++it) {
            resultString += to_string(*it);
        }
        return resultString;
    }

    bool compare(const BigInteger& other) const {
        if (other.digits.size() > this->digits.size()) {
            return true;
        } else if (other.digits.size() < this->digits.size()) {
            return false;
        } else {
            return lexicographical_compare(this->digits.begin(), this->digits.end(),
                                          other.digits.begin(), other.digits.end());
        }
    }

    string subtractHelper(const BigInteger& num1, const BigInteger& num2) {
        int borrow = 0;
        int n = num1.digits.size();
        vector<int> result(n + 1);
        for (int i = 0; i < n; i++) {
            int a = i < num1.digits.size() ? num1.digits[num1.digits.size() - 1 - i] : 0;
            int b = i < num2.digits.size() ? num2.digits[num2.digits.size() - 1 - i] : 0;
            int sum = a - b - borrow;
            if (sum < 0) {
                sum += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result[n - i] = sum;
        }

        string resultString = trimZero(result);
        return resultString.empty() ? "0" : resultString;
    }

public:
    BigInteger(const string& s) {
        auto it = find_if(s.begin(), s.end(), [](char c) { return c != '0'; });
        string st(it, s.end());
        for (char c : st) {
            digits.push_back(c - '0');
        }
    }

    string toString() const {
        string s;
        if (isResultNegative) {
            s += '-';
        }
        for (int digit : digits) {
            s += to_string(digit);
        }
        return s.empty() ? "0" : s;
    }

    BigInteger add(const BigInteger& other) const {
        int n = max(other.digits.size(), this->digits.size());
        vector<int> result(n + 1);
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int a = i < this->digits.size() ? this->digits[this->digits.size() - 1 - i] : 0;
            int b = i < other.digits.size() ? other.digits[other.digits.size() - 1 - i] : 0;
            int sum = a + b + carry;
            result[n - i] = sum % 10;
            carry = sum / 10;
        }
        result[0] = carry;

        string resultString = trimZero(result);
        return BigInteger(resultString);
    }

    BigInteger subtract(const BigInteger& other) const {
        bool checkGreater = compare(other);

        BigInteger result(checkGreater ? subtractHelper(other, *this) : subtractHelper(*this, other));
        result.isResultNegative = checkGreater;
        return result;
    }

    BigInteger multiply(const BigInteger& other) const {
        int n = this->digits.size() + other.digits.size();
        vector<int> result(n);
        for (int i = this->digits.size() - 1; i >= 0; i--) {
            for (int j = other.digits.size() - 1; j >= 0; j--) {
                int mul = this->digits[i] * other.digits[j];
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + result[p2];
                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }
        string resultString = trimZero(result);
        return BigInteger(resultString);
    }
};

int main() {
    BigInteger num1("636");
    cout << num1.toString() << endl;
    BigInteger num2("36");
    cout << num2.toString() << endl;
    BigInteger num3 = num1.add(num2);
    BigInteger num4 = num1.subtract(num2);
    cout << num3.toString() << endl;
    cout << num1.subtract(num2).toString() << endl;
    cout << num4.toString() << endl;
    cout << num1.multiply(num2).toString() << endl;

    return 0;
}
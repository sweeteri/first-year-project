#include "long_number.hpp"

namespace IBusko {
    LongNumber::LongNumber() : numbers(new int[1]), length(1), sign(0) {
        numbers[0] = 0;
    }


    LongNumber::LongNumber(const char *const str) : length(get_length(str)), sign(0) {
        int i = 0;
        if (str[0] == LongNumber::MINUS) {
            sign = 1;
            length--;
            i = 1;
        }
        numbers = new int[length];
        for (int j = i; j < length + sign; j++) {
            numbers[j - i] = str[j] - ZERO;
        }
    }


    LongNumber::LongNumber(const LongNumber &x) : numbers(new int[x.length]), length(x.length), sign(x.sign) {
        for (int i = 0; i < length; i++) {
            numbers[i] = x.numbers[i];
        }

    }

    LongNumber::LongNumber(LongNumber &&x) : numbers(x.numbers), length(x.length), sign(0) {
        length = x.length;
        sign = x.sign;
        numbers = x.numbers;
        x.numbers = nullptr;
        /*x.numbers = new int[1];
        x.length = 1;
        x.sign = 0;
        x.numbers[0] = 0;*/
    }

    LongNumber::~LongNumber() {
        length = 0;
        delete[] numbers;
        numbers = nullptr;
    }

    LongNumber &LongNumber::operator=(const char *const str) {
        delete[] numbers;
        length = get_length(str);
        sign = 0;
        int i = 0;
        if (str[0] == MINUS) {
            sign = 1;
            length--;
            i = 1;
        }
        numbers = new int[length];
        for (int j = i; j < length + i; j++) {
            numbers[j - i] = str[j] - int('0');
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(const LongNumber &x) {
        if (&x != this) {
            delete[] numbers;
            length = x.length;
            sign = x.sign;
            numbers = new int[length];
            for (int i = 0; i < length; i++) {
                numbers[i] = x.numbers[i];
            }
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(LongNumber &&x) {
        length = x.length;
        sign = x.sign;
        delete[] numbers;
        numbers = x.numbers;
        x.numbers = nullptr;
        /*if (&x != this) {
            delete[] numbers;
            length = x.length;
            sign = x.sign;
            numbers = x.numbers;
            x.numbers = new int[1];
            x.sign = 0;
            x.length = 1;
            x.numbers[0] = 0;
        }*/
        return *this;
    }

    bool LongNumber::operator==(const LongNumber &x) const {
        if (this==&x) return true;
        if (sign != x.sign || length != x.length) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (x.numbers[i] != numbers[i]) {
                return false;
            }
        }
        return true;
    }

    bool LongNumber::operator>(const LongNumber &x) const {
        if (sign != x.sign) {
            return !sign;
        }
        if (length != x.length) {
            if (length > x.length) {
                return true;
            } else {
                return false;
            }
        }
        for (int i = 0; i < length; i++) {
            if (numbers[i] < x.numbers[i]) {
                return false;
            } else {
                return true;
            }
        }
    }

    bool LongNumber::operator<(const LongNumber &x) const {
        return !(*this > x);
    }

    LongNumber LongNumber::operator-() const {
        LongNumber copy(*this);
        copy.sign = !copy.sign;
        return copy;
    }

    LongNumber LongNumber::operator+(const LongNumber &x) const {
        LongNumber result;
        if (sign == 1) {
            if (x.sign == 1) return -(-*this + (-x));
            else return x - (-*this);
        } else if (x.sign == 1) return *this - (-x);

        int max_length = (length < x.length) ? x.length : length;
        result.length = max_length + 1;
        result.numbers = new int[result.length];

        int last_carry = 0;
        int i = length - 1;
        int j = x.length - 1;
        int ind = result.length - 1;

        while (i >= 0 || j >= 0) {
            int s = last_carry;
            if (i >= 0) {
                s = s + numbers[i--];
            }
            if (j >= 0) {
                s = s + x.numbers[j--];
            }
            result.numbers[ind--] = s % 10;
            last_carry = s / 10;
        }
        if (last_carry > 0) {
            result.numbers[ind--] = last_carry;
        } else {
            int *new_result = new int[max_length];
            for (int i = 0; i < max_length; i++) {
                new_result[i] = result.numbers[i + 1];
            }
            delete[] result.numbers;
            result.numbers = new_result;
            result.length = max_length;
        }
        return result;
    }

    LongNumber LongNumber::operator-(const LongNumber &x) const {
        LongNumber result;
        if (*this == x) return LongNumber("0");
        if (x.sign) return *this + (-x);
        else if (sign) return -((-*this) + x);
        else if (*this < x) return -(x - *this);
        else {
            result.sign = sign;
            int last_carry = 0;
            result.length = length;
            result.numbers = new int[result.length];

            int i = length - 1;
            int j = x.length - 1;
            int ind = result.length - 1;

            while (i >= 0 || j >= 0) {
                if (i >= 0 && j >= 0) {
                    if ((numbers[i] - x.numbers[j]) < 0) {
                        if (last_carry) {
                            result.numbers[ind--] = numbers[i--] - 1 - x.numbers[j--];
                        } else {
                            last_carry = 1;
                            result.numbers[ind--] = 10 + numbers[i--] - x.numbers[j--];
                        }
                    } else {
                        result.numbers[ind--] = numbers[i--] - last_carry - x.numbers[j--];
                        if (last_carry) {
                            last_carry = 0;
                        }
                    }
                } else if (i >= 0) {
                    if (last_carry) {
                        result.numbers[ind--] = numbers[i--] - last_carry;
                        last_carry = 0;
                    } else {
                        result.numbers[ind--] = numbers[i--];
                    }
                }
            }
            ind = 0;
            for (int k = 0; k < result.length; k++) {
                if (result.numbers[k] == 0) {
                    ind++;
                } else {
                    break;
                }
            }

            if (ind != 0) {
                int *new_result = new int[result.length - ind];
                for (int k = 0; k < result.length - ind; k++) {
                    new_result[k] = result.numbers[ind + k];
                }
                delete[] result.numbers;
                result.numbers = new_result;
                result.length = result.length - ind;
            }
        }
        return result;
    }

    LongNumber LongNumber::operator*(const LongNumber &x) const {
        if ((LongNumber) *this == LongNumber("0") || ((LongNumber) x == LongNumber("0"))) {
            return LongNumber("0");
        }
        LongNumber result;
        result.sign = 0;
        if (sign != x.sign) {
            result.sign = 1;
        }

        result.length = length + x.length;
        result.numbers = new int[result.length];
        for (int i = 0; i < result.length; i++) {
            result.numbers[i] = 0;
        }

        int curr;
        for (int i = length - 1; i >= 0; i--) {
            int last_carry = 0;
            for (int j = x.length - 1; j >= 0; j--) {
                curr = numbers[i] * x.numbers[j] + result.numbers[i + j + 1] + last_carry;
                result.numbers[i + j + 1] = curr % 10;
                last_carry = curr / 10;
            }
            result.numbers[i] = result.numbers[i] + last_carry;
        }
        int ind = 0;
        for (int k = 0; k < result.length; k++) {
            if (result.numbers[k] == 0) {
                ind++;
            } else {
                break;
            }
        }

        if (ind != 0) {
            int *new_result = new int[result.length - ind];
            for (int k = 0; k < result.length - ind; k++) {
                new_result[k] = result.numbers[ind + k];
            }
            delete[] result.numbers;
            result.numbers = new_result;
            result.length = result.length - ind;
        }
        return result;
    }

    LongNumber LongNumber::operator/(const LongNumber &x) const {
        if ((LongNumber) x == LongNumber("0")) {
            throw std::runtime_error("Division by zero");
        }
        if ((LongNumber) *this == LongNumber("0")) {
            return LongNumber("0");
        }
        LongNumber result;
        result.sign = 0;
        LongNumber a(*this);
        if (a.sign) {
            a.sign = 0;
        }
        LongNumber b(x);
        if (b.sign) {
            b.sign = 0;
        }
        while (a > b || a == b) {
            a = a - b;
            result = result + LongNumber("1");
        }
        if (sign != x.sign) {
            result.sign = 1;
        }
        return result;
    }

    LongNumber LongNumber::operator%(const LongNumber &x) const {
        if ((LongNumber) x == LongNumber("0")) {
            throw std::runtime_error("Division by zero");
        }
        if ((LongNumber) *this == LongNumber("0")) {
            return LongNumber("0");
        }
        LongNumber a(*this);
        a.sign = 0;
        LongNumber b(x);
        b.sign = 0;
        while (a > b || a == b) {
            a = a - b;
        }
        if (x.sign != sign) {
            a.sign = 1;
        }
        return a;
    }

    int LongNumber::get_digits_number() const {
        return length;
    }

    bool LongNumber::is_positive() const {
        return sign == POSITIVE;
    }

    int LongNumber::get_length(const char *const str) const {
        const char *temp = str;
        int length = 0;

        while (*temp) {
            length++;
            temp++;
        }
        return length;
    }

    std::ostream &operator<<(std::ostream &os, const LongNumber &x) {
        if (!x.is_positive()) os << LongNumber::MINUS;

        for (int i = 0; i < x.length; i++) {
            os << x.numbers[i];
        }
        return os;
    }
}


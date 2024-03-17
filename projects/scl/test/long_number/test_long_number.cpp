#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
    IBusko::LongNumber x("12345");
    ASSERT_EQ(5, x.get_digits_number())
                                << "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
    IBusko::LongNumber x("-1");
    ASSERT_EQ(1, x.get_digits_number())
                                << "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
public:
    IBusko::LongNumber zero = IBusko::LongNumber("0");
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber five = IBusko::LongNumber("5");
    IBusko::LongNumber eight = IBusko::LongNumber("8");
    IBusko::LongNumber eleven = IBusko::LongNumber("11");
    IBusko::LongNumber negative_eleven = IBusko::LongNumber("-11");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
    IBusko::LongNumber thirteen = IBusko::LongNumber("13");
    IBusko::LongNumber negative_thirteen = IBusko::LongNumber("-13");
    IBusko::LongNumber ninety_nine = IBusko::LongNumber("99");
    IBusko::LongNumber one_hundred = IBusko::LongNumber("100");
    IBusko::LongNumber one_hundred_thirteen = IBusko::LongNumber("113");
    IBusko::LongNumber big_num = IBusko::LongNumber("1469");
};

TEST_F(EqualityFixture, equal) {
    ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
    ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
    ASSERT_FALSE(one_v1 == negative_one)
                                << "Проверка " << one_v1 << " == " << negative_one;
}

TEST_F(EqualityFixture, greater_pos) {
    ASSERT_TRUE(one_v1 < twelve) << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(EqualityFixture, smaller_neg) {
    ASSERT_FALSE(twelve < negative_one) << "Проверка " << twelve << " > " << negative_one;
}

TEST_F(EqualityFixture, zero_pos) {
    ASSERT_TRUE((twelve + zero) == twelve) << "Проверка " << twelve << " + " << zero << " = " << twelve;
    ASSERT_TRUE((twelve - zero) == twelve) << "Проверка " << twelve << " - " << zero << " = " << twelve;
    ASSERT_TRUE((twelve * zero) == zero) << "Проверка " << twelve << " * " << zero << " = " << zero;
    ASSERT_TRUE((zero / twelve) == zero) << "Проверка " << zero << " / " << twelve << " = " << zero;
}

TEST_F(EqualityFixture, sum_pos) {
    ASSERT_TRUE((twelve + one_v1) == thirteen) << "Проверка " << twelve << " + " << one_v1 << " = " << thirteen;
    ASSERT_TRUE((ninety_nine + one_v1) == one_hundred)
                                << "Проверка " << ninety_nine << " + " << one_v1 << " = " << one_hundred;
}

TEST_F(EqualityFixture, sum_negative_one_pos) {
    ASSERT_TRUE((twelve + negative_one) == eleven) << "Проверка " << twelve << " + " << negative_one << " = " << eleven;
    ASSERT_TRUE((negative_twelve + one_v1) == negative_eleven)
                                << "Проверка " << negative_twelve << " + " << one_v2 << " = " << negative_eleven;
    ASSERT_TRUE((negative_twelve + negative_one) == negative_thirteen)
                                << "Проверка " << negative_twelve << " + " << negative_one << " = "
                                << negative_thirteen;
}

TEST_F(EqualityFixture, subtraction_pos) {
    ASSERT_TRUE((twelve - one_v1) == eleven) << "Проверка " << twelve << " - " << one_v1 << " = " << eleven;
    ASSERT_TRUE((one_hundred_thirteen - thirteen) == one_hundred)
                                << "Проверка " << one_hundred_thirteen << " - " << thirteen << " = " << one_hundred;
}

TEST_F(EqualityFixture, subtraction_negative_one_pos) {
    ASSERT_TRUE((twelve - negative_one) == thirteen)
                                << "Проверка " << twelve << " - " << negative_one << " = " << thirteen;
    ASSERT_TRUE((negative_twelve - one_v1) == negative_thirteen)
                                << "Проверка " << negative_twelve << " - " << one_v2 << " = " << negative_thirteen;
    ASSERT_TRUE((negative_twelve - negative_one) == negative_eleven)
                                << "Проверка " << negative_twelve << " - " << negative_one << " = " << negative_eleven;
}

TEST_F(EqualityFixture, multiplication_pos) {
    ASSERT_TRUE((twelve * one_v1) == twelve) << "Проверка " << twelve << " * " << one_v1 << " = " << twelve;
    ASSERT_TRUE((one_hundred_thirteen * thirteen) == big_num)
                                << "Проверка " << one_hundred_thirteen << " * " << thirteen << " = " << big_num;
}

TEST_F(EqualityFixture, division_pos) {
    ASSERT_TRUE((twelve / one_v1) == twelve) << "Проверка " << twelve << " / " << one_v1 << " = " << twelve;
    ASSERT_TRUE((one_v1 / twelve) == zero) << "Проверка " << one_v1 << " / " << twelve << " = " << zero;
    ASSERT_TRUE((ninety_nine / twelve) == eight) << "Проверка " << ninety_nine << " / " << twelve << " = " << eight;
}

TEST_F(EqualityFixture, division_remainder_pos) {
    ASSERT_TRUE((twelve % one_v1) == zero) << "Проверка " << twelve << " % " << one_v1 << " = " << zero;
    ASSERT_TRUE((thirteen % eight) == five) << "Проверка " << thirteen << " % " << eight << " = " << five;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

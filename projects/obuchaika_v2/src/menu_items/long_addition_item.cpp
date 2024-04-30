#include <iostream>
#include <random>

#include "long_addition_item.hpp"
#include "long_number.hpp"

namespace {
	static const char END = '\0';
	static const char ZERO = '0';

	short MIN_LENGTH = 1;
	short MAX_LENGTH = 18;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<short> lenght_dist(MIN_LENGTH, MAX_LENGTH);

	IBusko::LongNumber get_random_unsigned_long_number();
	void my_getline(char* buffer, int size);
}

namespace IBusko {
	LongAdditionItem::LongAdditionItem(
		const char* const title,
		const MenuItem* parent
	) : MenuItem(title, parent) {}

	const MenuItem* LongAdditionItem::execute() const {
		LongNumber first_value = get_random_unsigned_long_number();
		LongNumber second_value = get_random_unsigned_long_number();
		LongNumber result_value = first_value + second_value;

		bool ansver_is_true;
		char user_input[MAX_LENGTH + 2];
		do {
			std::cout << "q - Назад" << std::endl;
			std::cout << first_value << " + " << second_value << " = ";

			my_getline(user_input, sizeof(user_input));
			ansver_is_true = LongNumber(user_input) == result_value;

			if (user_input[0] == 'q') {
				std::cout << std::endl;
				return parent;
			}

			std::cout << ((ansver_is_true) ? "Верно" : "Неверно") << std::endl << std::endl;
		} while (!ansver_is_true);
		return this;
	}
}

namespace {
	IBusko::LongNumber get_random_unsigned_long_number() {
		short length = lenght_dist(gen);
		char buffer[MAX_LENGTH + 1];
		if (length == 1) {
			buffer[0] = ZERO + rand() % 10;
		} else {
			buffer[0] = ZERO + 1 + rand() % 9;
			for (int i = 1; i < length; ++i) {
				buffer[i] = ZERO + rand() % 10;
			}
		}
		buffer[length] = END;

		return IBusko::LongNumber(buffer);
	}

	void my_getline(char* buffer, int size) {
		int i = 0;
		char c;
		while (i < size - 1) {
			std::cin.get(c);
			if (i == 0 && (c == '\n' || c == ' '))
				continue;
			if (c == '\n' || c == ' ' || std::cin.eof())
				break;
			buffer[i++] = c;
		}
		buffer[i] = '\0';
	}
}

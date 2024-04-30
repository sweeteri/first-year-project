#include "school_division_item.hpp"

namespace IBusko {
    SchoolDevisionItem::SchoolDevisionItem(
            const char* const title,
            const MenuItem* parent
    ) : MenuItem(title, parent) {}

    const MenuItem* SchoolDevisionItem::execute() const {
        int n;
        do{

            std::cout << "\033[1;31mДеление — возможно, самое сложное действие для ученика начальной школы\033[0m\n";
            std::cout << "\033[1;32mРассмотрим базовые термины:\033[0m\n";
            std::cout << "\t \033[1;34mДелимое\033[0m" << "  - это число, которое подвергают делению. \n";
            std::cout << "\t \033[1;34mДелитель\033[0m" << " - это число, которым делят: оно указывает, на сколько равных частей нужно разделить делимое. \n";
            std::cout << "\t \033[1;34mЧастное\033[0m" << "  - это результат деления. Если умножить частное на делитель, получится делимое. \n";

            std::cout << "Введи через пробел 2 числа - делимое и делитель, и посмотри на результат: \n";
            int dividend,divisor;
            std::cin >> dividend >> divisor;
            int quotient = 0;    // Частное
            int remainder = dividend;  // Остаток

            // Выполнение деления пошагово
            while (remainder >= divisor) {
                // Вычисляем количество раз, которое делитель "вмещается" в остаток
                int multiplier = remainder / divisor;

                // Добавляем кратное к частному
                quotient += multiplier;

                // Вычисляем новый остаток
                remainder = remainder % divisor;

                // Выводим информацию о текущем шаге
                std::cout << "\t" << multiplier << " * " << divisor << " = " << multiplier * divisor << "\n";
                std::cout << "\tОстаток: " << remainder << "\n";
            }

            // Выводим итоговый результат
            std::cout << "\n\tФинальный результат: " << dividend << " / " << divisor <<  " = " << quotient << " (остаток: " << remainder << ")\n";

            // Сброс цветовой схемы
            std::cout << "\033[0m";


            std::cout << std::endl << "0 - Вернуться на уровень выше:";
            std::cout << std::endl << "Любая другая клавиша - попробовать еще!: \n";
            std::cin >> n;
        }while(n != 0);

        return parent->get_parent();
    }
}

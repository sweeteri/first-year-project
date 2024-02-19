#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_items.hpp"

int main() {
    std::system("chcp 65001 > log");
    std::cout << "Искусство России приветствует тебя!" << std::endl;
    const KPetrova::MenuItem* current = &KPetrova::MAIN;
    do {
        current = current->func(current);
    } while (true);
    return 0;
}

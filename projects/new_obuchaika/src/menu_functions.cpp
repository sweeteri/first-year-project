#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"

const KPetrova::MenuItem *KPetrova::show_menu(const MenuItem *current) {
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Исскуство > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const KPetrova::MenuItem *KPetrova::exit(const MenuItem *current) {
    std::exit(0);
}

const KPetrova::MenuItem *KPetrova::go_back(const MenuItem *current) {
    return current->parent->parent;
}

const KPetrova::MenuItem *KPetrova::show_study_artists(const MenuItem *current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const KPetrova::MenuItem *KPetrova::show_study_musicians(const MenuItem *current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

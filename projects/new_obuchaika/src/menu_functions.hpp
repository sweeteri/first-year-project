#pragma once

#include "menu.hpp"

namespace KPetrova {
    const MenuItem *show_menu(const MenuItem *current);

    const MenuItem *exit(const MenuItem *current);

    const MenuItem *show_study_artists(const MenuItem *current);
    const MenuItem *show_study_musicians(const MenuItem *current);

    const MenuItem *go_back(const MenuItem *current);

}

#include "menu_items.hpp"

#include "menu_functions.hpp"

const KPetrova::MenuItem KPetrova::ARTISTS_RUBLEV = {
        "1 - Андрей Иванов сын Рублев", KPetrova::show_study_artists, &KPetrova::STUDY_ARTISTS
};
const KPetrova::MenuItem KPetrova::ARTISTS_POLENOV = {
        "2 - Василий Дмитриевич Поленов", KPetrova::show_study_artists, &KPetrova::STUDY_ARTISTS
};
const KPetrova::MenuItem KPetrova::ARTISTS_AIVAZONSKIY = {
        "3 - Иван Константинович Айвазовский", KPetrova::show_study_artists, &KPetrova::STUDY_ARTISTS
};
const KPetrova::MenuItem KPetrova::ARTISTS_GO_BACK = {
        "0 - Выйти в предыдущее меню", KPetrova::go_back, &KPetrova::STUDY_ARTISTS
};
namespace {
    const KPetrova::MenuItem *const russian_artists_children[] = {
            &KPetrova::ARTISTS_GO_BACK,
            &KPetrova::ARTISTS_RUBLEV,
            &KPetrova::ARTISTS_POLENOV,
            &KPetrova::ARTISTS_AIVAZONSKIY,
    };
    const int russian_artists_size = sizeof(russian_artists_children) / sizeof(russian_artists_children[0]);
}


const KPetrova::MenuItem KPetrova::STUDY_ARTISTS = {
        "1 - Русские художники", KPetrova::show_menu, &KPetrova::STUDY, russian_artists_children, russian_artists_size
};
const KPetrova::MenuItem KPetrova::STUDY_MUSICIANS = {
        "2 - Русские музыканты", KPetrova::show_study_musicians, &KPetrova::STUDY
};
const KPetrova::MenuItem KPetrova::STUDY_GO_BACK = {
        "0 - Выйти в главное меню", KPetrova::go_back, &KPetrova::STUDY
};
namespace {
    const KPetrova::MenuItem *const study_children[] = {
            &KPetrova::STUDY_GO_BACK,
            &KPetrova::STUDY_ARTISTS,
            &KPetrova::STUDY_MUSICIANS,
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}


const KPetrova::MenuItem KPetrova::STUDY = {
        "1 - Искусство России", KPetrova::show_menu, &KPetrova::MAIN, study_children, study_size
};
const KPetrova::MenuItem KPetrova::EXIT = {
        "0 - Выйти", KPetrova::exit, &KPetrova::MAIN
};

namespace {
    const KPetrova::MenuItem *const main_children[] = {
            &KPetrova::EXIT,
            &KPetrova::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const KPetrova::MenuItem KPetrova::MAIN = {
        nullptr, KPetrova::show_menu, nullptr, main_children, main_size
};
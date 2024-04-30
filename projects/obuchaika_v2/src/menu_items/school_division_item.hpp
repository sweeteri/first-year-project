#pragma once

#include "menu_item.hpp"

namespace IBusko {
    class SchoolDevisionItem : public MenuItem {
    public:
        SchoolDevisionItem(const char* const title, const MenuItem* parent);
        const MenuItem* execute() const;
    };
}

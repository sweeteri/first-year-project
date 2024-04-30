#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class LongDivisionItem : public MenuItem {
		public:
			LongDivisionItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}

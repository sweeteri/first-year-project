#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class LongAdditionItem : public MenuItem {
		public:
			LongAdditionItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}

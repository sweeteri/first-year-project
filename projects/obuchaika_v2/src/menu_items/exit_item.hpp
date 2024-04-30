#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class ExitItem : public MenuItem {
		public:
			ExitItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}

#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class GoBackItem : public MenuItem {
		public:
			GoBackItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}

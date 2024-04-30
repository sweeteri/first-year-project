#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class LongMultiplicationItem : public MenuItem {
	public:
		LongMultiplicationItem(const char* const title, const MenuItem* parent);
		const MenuItem* execute() const;
	};
}

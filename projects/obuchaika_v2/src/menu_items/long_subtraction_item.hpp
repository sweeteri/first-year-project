#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class LongSubtractionItem : public MenuItem {
		public:
			LongSubtractionItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}

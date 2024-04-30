#include "goback_item.hpp"

namespace IBusko {
	GoBackItem::GoBackItem(const char* const title, const MenuItem* parent)
		: MenuItem(title, parent) {}
		
	const MenuItem* GoBackItem::execute() const {
		return parent->get_parent();
	}
}

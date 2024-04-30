#include "long_division_item.hpp"

namespace IBusko {
	LongDivisionItem::LongDivisionItem(
		const char* const title, 
		const MenuItem* parent
	) : MenuItem(title, parent) {}
		
	const MenuItem* LongDivisionItem::execute() const {
		// TODO
		return parent->get_parent();
	}
}

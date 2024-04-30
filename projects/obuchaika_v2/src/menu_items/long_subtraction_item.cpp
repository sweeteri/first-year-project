#include "long_subtraction_item.hpp"

namespace IBusko {
	LongSubtractionItem::LongSubtractionItem(
		const char* const title, 
		const MenuItem* parent
	) : MenuItem(title, parent) {}
		
	const MenuItem* LongSubtractionItem::execute() const {
		// TODO
		return parent->get_parent();
	}
}

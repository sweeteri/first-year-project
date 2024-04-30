#include "long_multiplication_item.hpp"

namespace IBusko {
	LongMultiplicationItem::LongMultiplicationItem(
		const char* const title,
		const MenuItem* parent
	) : MenuItem(title, parent) {}

	const MenuItem* LongMultiplicationItem::execute() const {
		// TODO
		return parent->get_parent();
	}
}

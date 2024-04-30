#include "exit_item.hpp"

#include <cstdlib>

namespace IBusko {
	ExitItem::ExitItem(const char* const title, const MenuItem* parent)
		: MenuItem(title, parent) {}
		
	const MenuItem* ExitItem::execute() const {
		std::exit(0);
	}
}

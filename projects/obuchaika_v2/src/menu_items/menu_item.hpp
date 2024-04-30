#pragma once

#include "text.hpp"

namespace IBusko {
	class MenuItem {
		protected:
			Text title;
			const MenuItem* parent;
			const MenuItem* const * children;
			int children_count;
		public:
			MenuItem(const char* const title);
			MenuItem(const char* const title, const MenuItem* parent);
			MenuItem(const MenuItem* const * children, const int children_count);
			MenuItem(
				const char* const title,
				const MenuItem* parent,
				const MenuItem* const * children,
				const int children_count
			);
			
			const MenuItem* get_parent() const { return parent; }
			virtual const MenuItem* execute() const;
	};
}

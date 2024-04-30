#include "menu_item.hpp"

namespace IBusko {
	MenuItem::MenuItem(const char* const title) : title(title) {}
	
	MenuItem::MenuItem(const char* const title, const MenuItem* parent) 
		: title(title), parent(parent) {}
	
	MenuItem::MenuItem(const MenuItem* const * children, const int children_count) 
		: children(children), children_count(children_count) {}
	
	MenuItem::MenuItem(
		const char* const title,
		const MenuItem* parent,
		const MenuItem* const * children,
		const int children_count
	) :
		title(title),
		parent(parent),
		children(children),
		children_count(children_count)
	{}
			
	const MenuItem* MenuItem::execute() const {
		std::cout << "Обучайка приветствует тебя, студент!" << std::endl;
		for (int i = 1; i < children_count; i++) {
			std::cout << children[i]->title << std::endl;
		}
		std::cout << children[0]->title << std::endl;
		std::cout << "Обучайка > ";

		int user_input;
		std::cin >> user_input;
		std::cout << std::endl;
        if(children_count <= user_input){
            throw "Wrong Choice!";
        }else{
            return children[user_input];
        }
	}
}

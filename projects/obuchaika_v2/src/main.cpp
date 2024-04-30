#include "menu_items.hpp"

int main() {
	const IBusko::MenuItem* current = &IBusko::MAIN;
	do {
        try{
            current = current->execute();
        }
        catch (const char* error_message)
        {
            std::cout << error_message << std::endl;
            std::cout << "Try again!" << std::endl << std::endl;
        }

    } while (true);
		
    return 0;
}

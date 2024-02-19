target_sources(new_obuchaika_lib 
	PRIVATE
		main.cpp
		menu_functions.cpp
		menu_items.cpp
	PUBLIC
		menu.hpp
		menu_functions.hpp
		menu_items.hpp
)

target_include_directories(new_obuchaika_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)

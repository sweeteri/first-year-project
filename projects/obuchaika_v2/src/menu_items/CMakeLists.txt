set(HEADERS 
	exit_item.hpp
	goback_item.hpp
	
	long_addition_item.hpp
	long_division_item.hpp
	long_multiplication_item.hpp
	long_subtraction_item.hpp
	
	menu_item.hpp
  
  school_division_item.hpp
)

set(SOURCES 
	exit_item.cpp
	goback_item.cpp
	
	long_addition_item.cpp
	long_division_item.cpp
	long_multiplication_item.cpp
	long_subtraction_item.cpp
	
	menu_item.cpp
  
  school_division_item.cpp
)

target_sources(${PROJECT_NAME}
        PRIVATE
        ${HEADERS}
        ${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${PROJECT_SOURCE_DIR}/src/menu_items"
)

set(HEADERS 
	menu_items.hpp
)

set(SOURCES 
	menu_items.cpp
)

target_sources(${PROJECT_NAME} 
	PRIVATE
		${HEADERS}
		${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${PROJECT_SOURCE_DIR}/src/data"
)

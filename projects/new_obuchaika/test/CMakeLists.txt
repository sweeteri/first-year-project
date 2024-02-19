set(SOURCES
	test_new_obuchaika.cpp
)

add_executable(test_new_obuchaika ${SOURCES})
target_link_libraries(test_new_obuchaika
	gtest_main
	gmock_main
	new_obuchaika_lib
)

add_test(test_new_obuchaika test_new_obuchaika)

project(obuchaika_v2)

add_executable(${PROJECT_NAME} "")
target_link_libraries(${PROJECT_NAME} ${SCL_LIB})

add_subdirectory(src)

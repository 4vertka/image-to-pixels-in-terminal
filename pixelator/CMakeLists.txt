
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(pixelator_lib
	pixelated_image.cpp
	pixelated_image.hpp
	generic.hpp
	stb_image_data_view.hpp
	stb_image_data_view.cpp
	image.hpp
	drawer.hpp
)

target_include_directories(pixelator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(pixelator_lib PUBLIC stb ftxui::screen ftxui::dom ftxui::component)

enable_testing()
add_executable(pixelator_tests pixelated_image_test.cpp)
target_link_libraries(pixelator_tests PRIVATE pixelator_lib gtest_main)
add_test(NAME PixelatorTests COMMAND pixelator_tests)

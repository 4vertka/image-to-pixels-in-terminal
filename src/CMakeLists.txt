add_executable(pixelated_app pixelated.cpp)

target_link_libraries(pixelated_app
	PRIVATE
		pixelator_lib
		ftxui::screen
		ftxui::dom
		ftxui::component
)

#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <stb_image_data_view.hpp>
#include <image.hpp>
#include <pixelated_image.hpp>
#include <drawer.hpp>
#include <iostream>
#include <filesystem>


int main() {
	pixelator::StbImageDataView view("../pixelator/test_data/image.png");
    	if (view.empty()) {
        	std::cerr << "Check failed: Image not loaded." << std::endl;
        	return 1;
    	}

	pixelator::Drawer drawer{ftxui::Dimension::Fixed(42)};
	pixelator::PixelateImage scaler(view, drawer.size());

    	const pixelator::Image& myImage = scaler.GetImage();

	drawer.Draw(myImage);
    
}

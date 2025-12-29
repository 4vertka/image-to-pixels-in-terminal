#pragma once
#include <generic.hpp>
#include <image.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>


namespace pixelator {

class Drawer {
	public:
		Drawer(ftxui::Dimensions dimensions) {
			int base_row = dimensions.dimy;

        		_size.rows = base_row;
        		_size.cols = base_row * 2;
		}

		void Draw(const Image& image) {
			ftxui::Screen screen = ftxui::Screen::Create(
				ftxui::Dimension::Fixed(_size.cols),
				ftxui::Dimension::Fixed(_size.rows)
			);

			for (int y = 0; y < image.rows(); ++y) {
				for (int x = 0; x < image.cols(); ++x) {
					if (x < _size.cols && y < _size.rows) {
						auto& pixel = screen.PixelAt(x, y);
						pixel.background_color = image.at(y, x);
						pixel.character = ' ';
					}
				}
			}
			screen.Print();
		} 
		
		int rows() const {return _size.rows;}
		int cols() const {return _size.cols;}
		Size size() const {return _size;}
		
	
	private:
		Size _size{};
};

};



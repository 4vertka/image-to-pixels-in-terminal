#pragma once
#include <generic.hpp>
#include <iostream>
#include <ftxui/screen/color.hpp>
#include <vector>

namespace pixelator {

class Image {
	public:
		Image() : imageSize{0,0} {}
		
		Image(int rows, int cols) : imageSize{rows, cols}, 
			pixels(static_cast<size_t>(rows * cols), ftxui::Color::Black)
		{
		}

		int rows() const {return imageSize.rows;}
		int cols() const {return imageSize.cols;}
		Size size() const {return imageSize;}

		ftxui::Color at(int row, int col) const {
			return pixels[row * imageSize.cols + col]; 
		}

		ftxui::Color& at(int row, int col) {
			return pixels[row * imageSize.cols + col];
		}

		~Image() {}
	private:
		Size imageSize{};
		std::vector<ftxui::Color> pixels;

};

};

#pragma once
#include <stb/stb_image.h>
#include <ftxui/screen/color.hpp>
#include <generic.hpp>

#include <filesystem>
#include <iostream>

namespace pixelator {
	
	class StbImageDataView{
		public:
			StbImageDataView(const std::filesystem::path &image_path);
				
			//copy constructor and assigment operator deleted
			StbImageDataView(const StbImageDataView&) = delete;
			StbImageDataView& operator=(const StbImageDataView&) = delete;

			~StbImageDataView();

			Size size() const {return _imageSize;}
			int rows() const {return _imageSize.rows;}
			int cols() const {return _imageSize.cols;}

			bool empty() const {return image_data == nullptr;}

			ftxui::Color const at(int row, int col) const;

		private:
			unsigned char *image_data{};
			static constexpr auto kLoadAllChannels{0};
			Size _imageSize{};
			int _imageChannels{};
	};

};


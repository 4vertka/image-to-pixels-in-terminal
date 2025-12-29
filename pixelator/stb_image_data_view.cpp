#define STB_IMAGE_IMPLEMENTATION
#include <stb_image_data_view.hpp>
#include <iostream>
#include <filesystem>

namespace pixelator {
	
	StbImageDataView::StbImageDataView(const std::filesystem::path &image_path) {
				if (!std::filesystem::exists(image_path)) {
					std::cerr <<
						"Error: file does not found " 
						<< image_path
						<< std::endl;
					return;
				}

				image_data = stbi_load(image_path.c_str(),
							&_imageSize.cols,
							&_imageSize.rows,
							&_imageChannels,
							4);

				if (image_data == nullptr) {
					std::cerr << "Error: stb_image failed to load "
						<< image_path
						<< "\n Reason "
						<< stbi_failure_reason()
						<< std::endl;
				}

			}

	StbImageDataView::~StbImageDataView() {
				if (image_data) {
					stbi_image_free(image_data);
				}
			}

	ftxui::Color const StbImageDataView::at(int row, int col) const {
				if (!image_data) return {0,0,0};
				
				const int channels = 4;

				const auto index{channels * (row * _imageSize.cols + col)};
				
				Color myPixel = {
					static_cast<int>(image_data[index]),
					static_cast<int>(image_data[index+1]),
					static_cast<int>(image_data[index+2])
				};

				ftxui::Color ftxuiColor = ftxui::Color::RGB(
						static_cast<unsigned char>(myPixel.red),
						static_cast<unsigned char>(myPixel.green),
						static_cast<unsigned char>(myPixel.blue)
						);

				return ftxuiColor;

			}
};

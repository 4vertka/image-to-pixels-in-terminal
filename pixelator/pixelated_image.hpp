#pragma once
#include <stb_image_data_view.hpp>
#include <generic.hpp>
#include <algorithm>
#include <image.hpp>

namespace pixelator {

class PixelateImage {
	public:
		PixelateImage(const StbImageDataView& view, Size size);

		const Image& GetImage() const {return pixelated_image;}

		int Scale(int number, float factor);


	private:
		Image pixelated_image;

};

};

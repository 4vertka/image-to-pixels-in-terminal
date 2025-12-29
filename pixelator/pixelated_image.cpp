#include <pixelated_image.hpp>


namespace pixelator{

	PixelateImage::PixelateImage(const StbImageDataView& view, Size size) {

			const float factor_cols =
				size.cols / static_cast<float>(view.cols());
			const float factor_rows = 
				size.rows / static_cast<float>(view.rows());
			const float scale = std::min(factor_cols, factor_rows);

			int final_cols = static_cast<int>(view.cols() * scale);
			int final_rows = static_cast<int>(view.rows() * scale);

			pixelated_image = Image(final_rows, final_cols);

			for (int r = 0; r < final_rows; ++r) {
				for (int c = 0; c < final_cols; ++c) {
					int source_r = static_cast<int>(r / scale);
					int source_c = static_cast<int>(c / scale);

					pixelated_image.at(r,c) = view.at(source_r, source_c);
				}
			}
	}
		
	int PixelateImage::Scale(int number, float factor) {
			return static_cast<int>(number * factor);
		}
}

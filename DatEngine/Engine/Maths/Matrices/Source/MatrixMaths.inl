template <typename MatType>
Mat<4, 4, MatType> translate(Mat<4, 4, MatType> Matrix, Vec<3, MatType> TranslationVector) {
	Mat<4, 4, MatType> temp(Matrix);

	temp[3][0] = Matrix[0][0] * TranslationVector.x + Matrix[1][0] * TranslationVector.y + Matrix[2][0] * TranslationVector.z + Matrix[3][0] * 1;
	temp[3][1] = Matrix[0][1] * TranslationVector.x + Matrix[1][1] * TranslationVector.y + Matrix[2][1] * TranslationVector.z + Matrix[3][1] * 1;
	temp[3][2] = Matrix[0][2] * TranslationVector.x + Matrix[1][2] * TranslationVector.y + Matrix[2][2] * TranslationVector.z + Matrix[3][2] * 1;
	temp[3][3] = Matrix[0][3] * TranslationVector.x + Matrix[1][3] * TranslationVector.y + Matrix[2][3] * TranslationVector.z + Matrix[3][3] * 1;

	return temp;
}
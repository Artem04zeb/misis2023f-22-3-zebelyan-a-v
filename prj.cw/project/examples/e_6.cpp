#include <morph.hpp>

int main() {
	Eigen::MatrixXd V_input;
	Eigen::MatrixXi F_input;
	std::string source_output;

	Morph six;
	six.write_obj(V_input, F_input, source_output);
}
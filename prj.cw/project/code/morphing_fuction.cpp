#include <igl/readOBJ.h>     
#include <igl/opengl/glfw/Viewer.h>
#include <iostream>

Eigen::MatrixXd V, Union;
Eigen::MatrixXd
d_nose,
d_chin,
d_cheeks,
d_jawls,
d_lips,
d_horns;
Eigen::MatrixXi F, F1, F2, F3, F4, F5, F6;

bool key_down(igl::opengl::glfw::Viewer viewer_temp, unsigned char key, int mods) {
	switch (key) {
	case '1':
		Union = Union + (d_nose - V);
		return true;
	case '2':
		Union = Union - (d_nose - V);
		return true;
		// ----
	case '3':
		Union = Union + (d_chin - V);
		return true;
	case '4':
		Union = Union - (d_chin - V);
		return true;
		// ----
	case '5':
		Union = Union + (d_cheeks - V);
		return true;
	case '6':
		Union = Union - (d_cheeks - V);
		return true;
		// ----
	case '7':
		Union = Union + (d_jawls - V);
		return true;
	case '8':
		Union = Union - (d_jawls - V);
		return true;
		// ----
	case 'q':
		Union = Union + (d_lips - V);
		return true;
	case 'w':
		Union = Union - (d_lips - V);
		return true;
		// ----
	case 'e':
		Union = Union + (d_horns - V);
		return true;
	case 'r':
		Union = Union - (d_horns - V);
		return true;
		// ---- Обнуление всех изменений
	case '0':
		Union = V;
		return true;
		// ---- SAVE0
	case ' ':
		igl::writeOBJ("C:\\Users\\user\\Desktop\\models\\RESULT.obj", Union, F);
		return true;
	}

	return false;
}

bool pre_draw(igl::opengl::glfw::Viewer& viewer_temp) {
	viewer_temp.data().set_vertices(Union);
	viewer_temp.data().compute_normals();
	return false;
}

int main(int argc, char* argv[]) {
	std::cout << "Check the file paths";

	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\face.obj", V, F);
	Union = V;

	// inits:
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\cheeks.obj", d_cheeks, F1);
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\chin.obj", d_chin, F2);
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\horns.obj", d_horns, F3);
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\jawls.obj", d_jawls, F4);
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\lips.obj", d_lips, F5);
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\nose.obj", d_nose, F6);


	igl::opengl::glfw::Viewer viewer; // Здесь в консоль выводится инструкция взаиодействия
	viewer.data().set_mesh(Union, F);
	viewer.callback_key_down = &key_down;
	viewer.callback_pre_draw = &pre_draw;
	viewer.launch();
}

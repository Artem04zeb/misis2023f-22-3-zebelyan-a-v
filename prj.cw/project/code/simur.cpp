#include <iostream>

// std
#include <string>
#include <fstream>
#include <sstream>
#include <functional>

// readers
#include <igl/readOBJ.h>
#include <igl/readOFF.h>
#include <igl/readDMAT.h>

// writers
#include <igl/writeOBJ.h>
#include <igl/writeOFF.h>

// other
#include <igl/harmonic.h>
#include <igl/opengl/glfw/Viewer.h>
#include <igl/colon.h>


Eigen::MatrixXd V, Union;
Eigen::MatrixXd
d_nose,
d_chin,
d_cheeks,
d_jawls,
d_lips,
d_horns;
Eigen::MatrixXi F, F1;


//
void save_file() {
	igl::writeOBJ("C:\\Users\\user\\Desktop\\models\\RESULT.obj", Union, F);
}


//
void rounder(std::string source_input, std::string source_output) {
	Eigen::MatrixXd V_spec_for_rounder;
	Eigen::MatrixXi F_spec_for_rounder;

	if (source_input.substr(source_input.size() - 3, 3) == "obj") {
		if (igl::readOBJ(source_input, V_spec_for_rounder, F_spec_for_rounder))
		{
			for (int i = 0; i < V_spec_for_rounder.rows(); i++) {
				for (int j = 0; j < 3; j++) {
					V_spec_for_rounder(i, j) = std::round(V_spec_for_rounder(i, j) * 10000) / 10000;
				}
			}
			if (igl::writeOBJ(source_output, V_spec_for_rounder, F_spec_for_rounder))
			{
				std::cout << "\nRounder result: SUCCESS\n";
			}
			else std::cout << "\nRounder result: ERROR due writing obj\n";
		}
		else std::cout << "\nRounder result: ERROR due reading obj\n";
	}
	else if (source_input.substr(source_input.size() - 3, 3) == "off")
	{
		if (igl::readOFF(source_input, V_spec_for_rounder, F_spec_for_rounder))
		{
			for (int i = 0; i < V_spec_for_rounder.rows(); i++) {
				for (int j = 0; j < 3; j++) {
					V_spec_for_rounder(i, j) = std::round(V_spec_for_rounder(i, j) * 10000) / 10000;
				}
			}
			if (igl::writeOBJ(source_output, V_spec_for_rounder, F_spec_for_rounder))
			{
				std::cout << "\nRounder result: SUCCESS\n";
			}
			else std::cout << "\nRounder result: ERROR due writing obj\n";
		}
		else std::cout << "\nRounder result: ERROR due reading off\n";
	}
	else
	{
		std::cout << "ERROR: Input file type should be .obj or .off.";
	}
}


//
void convert_off_to_obj(std::string source_input, std::string source_output) {
	Eigen::MatrixXd V_spec_for_conv;
	Eigen::MatrixXi F_spec_for_conv;

	if (igl::readOFF(source_input, V_spec_for_conv, F_spec_for_conv))
	{
		if (igl::writeOBJ(source_output, V_spec_for_conv, F_spec_for_conv))
		{
			std::cout << "\nConvert result: SUCCESS\n";
		}
		else std::cout << "\nConvert result: ERROR due writing\n";
	}
	else std::cout << "\nConvert result: ERROR due reading\n";
}
void convert_obj_to_off(std::string source_input, std::string source_output) {
	Eigen::MatrixXd V_spec_for_conv;
	Eigen::MatrixXi F_spec_for_conv;

	if (igl::readOBJ(source_input, V_spec_for_conv, F_spec_for_conv))
	{
		if (igl::writeOFF(source_output, V_spec_for_conv, F_spec_for_conv))
		{
			std::cout << "\nConvert result: SUCCESS\n";
		}
		else std::cout << "\nConvert result: ERROR due writing\n";
	}
	else std::cout << "\nConvert result: ERROR due reading\n";
}


//
void wriste_obj(Eigen::MatrixXd V_input, Eigen::MatrixXi F_input, std::string source_output) {
	std::ofstream out;
	// "C:\\Users\\user\\Desktop\\test\\V3.txt"
	out.open(source_output);
	if (out.is_open())
	{
		out << V_input;
		out << "\n";
		out << F_input;
	}
	out.close();
	std::cout << "File has been written" << std::endl;
}


bool key_down(igl::opengl::glfw::Viewer& viewer_temp, unsigned char key, int mods) {
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
	case ' ':
		save_file();
		return true;
	}

	return false;
}

bool pre_draw(igl::opengl::glfw::Viewer& viewer_temp) {
	viewer_temp.data().set_vertices(Union);
	viewer_temp.data().compute_normals();
	return false;
}


//
void init_bones()
{
	// main face
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\face.obj", V, F);
	// cheeks
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\cheeks.obj", d_cheeks, F1);
	// chin
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\chin.obj", d_chin, F1);
	// horns
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\horns.obj", d_horns, F1);
	// jawls
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\jawls.obj", d_jawls, F1);
	// lips
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\lips.obj", d_lips, F1);
	// nose
	igl::readOBJ("C:\\Users\\user\\Desktop\\models\\nose.obj", d_nose, F1);
}


// 
void fast_draw(std::string source_to_file) {

	igl::readOBJ(source_to_file, V, F);

	igl::opengl::glfw::Viewer viewer;
	viewer.data().set_mesh(V, F);
	viewer.launch();
}


//
void draw_mesh() {
	Union = V;
	igl::opengl::glfw::Viewer viewer;
	viewer.data().set_mesh(Union, F);

	viewer.callback_key_down = &key_down;
	viewer.callback_pre_draw = &pre_draw;

	viewer.launch();
}


// TODO
void set_texture();
void start_gui();
void set_color();


int main() {
	// INTRO
	std::cout << "--- Introduction message ---" << std::endl;
	std::cout << "--- Info about all functions --- " << std::endl;


	// ASK MODE
	std::cout << "--- Choose mode, you would like to continue ---" << std::endl;
	

	if (false)
	{
		// VIEWER MODE
		std::cout << "--- Write file name, you want see ---" << std::endl;
		// Main face - base
		fast_draw("C:\\Users\\user\\Desktop\\models\\face.obj");
	}
	else
	{
		// EDITING MODE
		init_bones();
		draw_mesh();
	}
	

	return 0;
}

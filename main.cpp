// main.cpp

#include "Art_Student.h"
#include "Physics_Student.h"

#include <vector>
#include <fstream>

// ALLOCATE SPACE IN MEMORY FOR TEMPORARY STUDENT DECLARATIONS
Student *temp_student;
Art_Student *temp_artstudent;
Physics_Student *temp_physicsstudent;

// WRITE-FILE FUNCTIONS
void write_outputfile(std::string output_filename, std::vector<Student *> students);	// declare function to output file
void write_asoutputfile(std::string output_filename, std::vector<Art_Student *> art_students);
void write_psoutputfile(std::string output_filename, std::vector<Physics_Student *>);

// VECTORS FOR STUDENT LISTS
std::vector<Student *> undeclared_students;
std::vector<Art_Student *> art_students;
std::vector<Physics_Student *> physics_students;


int main() {
	// ****** ART STUDENTS ****** 
	
	// Establish (Art) student directly into the list
	art_students.push_back(new Art_Student);
	art_students[0]->setName("Some","Name");	// changed professor's -> to . 	???
	art_students[0]->setGpa(3.9);				// ''
	art_students[0]->setEnrollSemYear('S',2024);
	art_students[0]->setGradSemYear('F',2026);
	art_students[0]->setGu('g');
	art_students[0]->set_artconcentra("Art History");

	// Establish individual (Art) students, declare concentration, then put them into the list
	temp_artstudent = new Art_Student("Taiko", "Nakayama", 3.31, 2028, 'S', 2024, 'F', 'u');
	std::cout << "Current GPA: " << temp_artstudent->getGpa() << std::endl;
	std::cout << "This student got a 4.0 GPA this semester, so let's adjust the overall GPA." << std::endl;
	temp_artstudent->calculateGpa(4.00);
	std::cout << "New GPA: "<< temp_artstudent->getGpa() << std::endl;
	art_students.push_back(temp_artstudent);	
	
	temp_artstudent = new Art_Student("Jose", "Ramiro", 3.69, 2029, 'S', 2025, 'F', 'u');
	temp_artstudent->set_artconcentra("Art History");
	art_students.push_back(temp_artstudent);
		
	temp_artstudent = new Art_Student("Jinxing", "Zhou", 3.37, 2028, 'S', 2024, 'F', 'u');
	art_students.push_back(temp_artstudent);
	
	temp_artstudent = new Art_Student("Katalin", "Toth", 3.69, 2029, 'S', 2027, 'F', 'g');
	temp_artstudent->set_artconcentra("Art Education");
	art_students.push_back(temp_artstudent);
	
	// Output art students to .dat file
	write_asoutputfile("art_students.dat",art_students);
		
	
	
	// ****** PHYSICS STUDENTS ****** 
	temp_physicsstudent = new Physics_Student("Kelechi", "Iheanacho", 3.05, 2028, 'S', 2024, 'F', 'u');
	temp_physicsstudent->set_physicsconcentra("Earth and Planetary Sciences");
	physics_students.push_back(temp_physicsstudent);	
	temp_physicsstudent = new Physics_Student("Jane", "Pearson", 3.91, 2028, 'S', 2024, 'F', 'u');
	temp_physicsstudent->set_physicsconcentra("Biophysics");
	physics_students.push_back(temp_physicsstudent);
	temp_physicsstudent = new Physics_Student();
	temp_physicsstudent->set_physicsconcentra("Biophysics");
	temp_physicsstudent->set_physicsconcentra("Earth and Planetary Sciences");
	physics_students.push_back(temp_physicsstudent);
	temp_physicsstudent = new Physics_Student("Mel", "Godwin", 3.71, 2028, 'S', 2026, 'F', 'g');
	temp_physicsstudent->set_physicsconcentra("Biophysics");
	physics_students.push_back(temp_physicsstudent);
	temp_physicsstudent = new Physics_Student("Atul", "Kumar", 3.29, 2028, 'S', 2026, 'F', 'g');
	temp_physicsstudent->set_physicsconcentra("Biophysics");
	physics_students.push_back(temp_physicsstudent);
	
	// Call function to output physics students to a list in a .dat file
	write_psoutputfile("physics_students.dat",physics_students);



		
	temp_student = new Student("Mary", "Oliver", 3.22, 2026, 'S', 2022, 'F', 'u');
	undeclared_students.push_back(temp_student);	
	temp_student = new Student("Jose", "Ramiro", 3.77, 2028, 'S', 2024, 'F', 'u');
	undeclared_students.push_back(temp_student);
	temp_student = new Student("Jinxing", "Zhou", 3.41, 2027, 'S', 2023, 'F', 'u');
	undeclared_students.push_back(temp_student);
	temp_student = new Student("Katalin", "Toth", 3.28, 2028, 'S', 2027, 'F', 'g');
	undeclared_students.push_back(temp_student);
	temp_student = new Student();
	undeclared_students.push_back(temp_student);
	
	// Call function to write .dat file
	write_outputfile("undeclared_students.dat",undeclared_students);	
	
	std::cout << "Now check the output files and make sure the three lists are accurate!" << std::endl;

	return 0;
}



void write_outputfile(std::string output_filename, std::vector<Student *> students) {
	std::ofstream outfile(output_filename);
	if(!outfile.is_open()) { 										// error handling if the file didn't open
		std::cerr << "Error: could not open " << output_filename << ".";
		//return 1;		void function		
	}
	
	outfile << "LAST NAME" << "," << "FIRST NAME" << "," << "GPA" << "," << "GRADUATION YEAR" << ",";
	outfile << "GRADUATION SEMESTER" << "," << "YEAR ENROLLED" << "," << "SEMESTER ENROLLED" << "," << "GRAD/UNDERGRAD" << std::endl;
	for(int i = 0; i < students.size(); i++){
		outfile << students[i]->getLastname() << "," << students[i]->getFirstname() << "," << students[i]->getGpa() << "," << students[i]->getGradYear() << "," << students[i]->getGradSem() << "," << students[i]->getEnrollYear() << "," << students[i]->getEnrollSem() << "," << students[i]->getGu() << std::endl;
	}
}

void write_asoutputfile(std::string output_filename, std::vector<Art_Student *> art_students){
	std::ofstream outfile(output_filename);
	if(!outfile.is_open()) { 										// error handling if the file didn't open
		std::cerr << "Error: could not open " << output_filename << ".";
		//return 1;		void function		
	}
	
	outfile << "LAST NAME" << "," << "FIRST NAME" << "," << "GPA" << "," << "GRADUATION YEAR" << ",";
	outfile << "GRADUATION SEMESTER" << "," << "YEAR ENROLLED" << "," << "SEMESTER ENROLLED" << ",";
	outfile << "GRAD/UNDERGRAD" << "," << "CONCENTRATION" << std::endl;
	for(int i = 0; i < art_students.size(); i++){
		outfile << art_students[i]->getLastname() << "," << art_students[i]->getFirstname() << "," << art_students[i]->getGpa() << ",";
		outfile << art_students[i]->getGradYear() << "," << art_students[i]->getGradSem() << "," << art_students[i]->getEnrollYear() << ",";
		outfile << art_students[i]->getEnrollSem() << "," << art_students[i]->getGu() << "," << art_students[i]->Art_concentra() << std::endl;
	}
}

void write_psoutputfile(std::string output_filename, std::vector<Physics_Student *> physics_students){
	std::ofstream outfile(output_filename);
	if(!outfile.is_open()) { 										// error handling if the file didn't open
		std::cerr << "Error: could not open " << output_filename << ".";
		//return 1;		void function		
	}
	
	outfile << "LAST NAME" << "," << "FIRST NAME" << "," << "GPA" << "," << "GRADUATION YEAR" << ",";
	outfile << "GRADUATION SEMESTER" << "," << "YEAR ENROLLED" << "," << "SEMESTER ENROLLED" << ",";
	outfile << "GRAD/UNDERGRAD" << "," << "CONCENTRATION" << std::endl;
	for(int i = 0; i < physics_students.size(); i++){
		outfile << physics_students[i]->getLastname() << "," << physics_students[i]->getFirstname() << ",";
		outfile << physics_students[i]->getGpa() << "," << physics_students[i]->getGradYear() << ",";
		outfile << physics_students[i]->getGradSem() << "," << physics_students[i]->getEnrollYear() << ",";
		outfile << physics_students[i]->getEnrollSem() << "," << physics_students[i]->getGu() << "," << physics_students[i]->physics_concentra() << std::endl;
	}
}


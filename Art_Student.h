// Art_Student.h

#ifndef ART_STUDENT_H // header guard
#define ART_STUDENT_H // ensures class is not re-declared

#include "Student.h"


class Art_Student: public Student{
  public:  	
	std::string a_concentra;
	
	Art_Student() : Student() {
		a_concentra = "Art Studio";		
		std::cout << "Concentration in Studio Art by default! You can change with a setter." << std::endl;
	}
	
	Art_Student(std::string f_n, std::string l_n, double g, int g_y, char g_s, int enr_year, char enr_sem, char u_g) : Student(f_n, l_n, g, g_y, g_s, enr_year, enr_sem, u_g) {		
		a_concentra = "Art Studio";		
		std::cout << "Concentration in Studio Art by default! You can change with a setter." << std::endl;
	}
	
	~Art_Student() {}
	
	// getter
	std::string Art_concentra() const {
		return a_concentra;
	}
	
	// setter
	void set_artconcentra(std::string chosen_concentra){
		if(chosen_concentra == "Art Education" || chosen_concentra == "Art History" || chosen_concentra == "Art Studio"){
			a_concentra = chosen_concentra;
		}
		else{
			std::cout << "Invalid concentration for an Art major. Try again." << std::endl;
		}
	}
};

#endif


// Physics_Student.h

#ifndef PHYSICS_STUDENT_H // header guard
#define PHYSICS_STUDENT_H // ensures class is not re-declared

#include "Student.h"

/*
enum PhysicsEmphasis {
	BIOPHYSICS,
	EARTH_AND_PLANETARY_SCIENCES
};*/

class Physics_Student: public Student{
  public:	
	std::string p_concentra;
	
	Physics_Student() : Student() {}
	
	Physics_Student(std::string f_n, std::string l_n, double g, int g_y, char g_s, int enr_year, char enr_sem, char u_g) : Student(f_n, l_n, g, g_y, g_s, enr_year, enr_sem, u_g) {		}
	
	~Physics_Student() {}
	
	// getter
	std::string physics_concentra() const {
		return p_concentra;
	}
	
	// setter
	void set_physicsconcentra(std::string chosen_concentra){
		if(chosen_concentra == "Biophysics" || chosen_concentra == "Earth and Planetary Sciences"){
			p_concentra = chosen_concentra;
		}
		else{
			std::cout << "Invalid concentration for a Physics major. Try again." << std::endl;
		}
	}
	
	/*
	// getter
	std::string Physics_p_concentra() const {
		std::string get_p_concentra = "";
		if(p_concentra == BIOPHYSICS){
			get_p_concentra = "Biophysics";
		}
		else if(p_concentra == EARTH_AND_PLANETARY_SCIENCES){
			get_p_concentra = "EARTH and Planetary Sciences";
		}
		else{
			std::cout << "(Physics) concentra not chosen. Use the setter." <<std::endl;
		}
		
		//std::cout << "This student's p_concentra is "+get_p_concentra+"." << std::endl;
		
		return get_p_concentra;
	}
	
	// setter
	void set_concentra(std::string chosen_p_concentra){
		if(chosen_p_concentra == "Biophysics"){
			p_concentra = BIOPHYSICS;
		}
		else{
			p_concentra = EARTH_AND_PLANETARY_SCIENCES;
		}
	}*/
};

#endif


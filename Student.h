// Student.h

#ifndef STUDENT_H // header guard
#define STUDENT_H // ensures class is not re-declared

#include "individual_data.h"

#include <iostream>
#include <string>

class Student{
  protected:
	Individual_Data* S; // = new Individual_Data; // S = new Individual_Data	???
  public:  
	Student() {
		S = new Individual_Data;
		S->last_name = "Smith";
		S->first_name = "John";
		S->gpa = 4.00;
		S->graduation_year = 2029;
		S->graduation_semester = 'S';
		S->enrolled_year = 2025;		// enrolled Fall 2025
		S->enrolled_semester = 'F';		// by default		
		S->undergrad_grad = 'u';
		std::cout << "Student created:\t" << S->first_name << " " << S->last_name << ".  ";
		std::cout << "(No info provided; Values are auto-populated.)" << std::endl;		
	}
	
	Student(std::string f_n, std::string l_n, double g, int grad_year, char grad_sem, int enr_year, char enr_sem, char u_g) {
		S = new Individual_Data;
		S->last_name = l_n;
		S->first_name = f_n;
		S->gpa = g;
		S->graduation_year = grad_year;
		S->graduation_semester = grad_sem;
		S->enrolled_year = enr_year;
		S->enrolled_semester = enr_sem;
		S->undergrad_grad = u_g;		
		std::cout << "Student created:\t" << f_n << " " << l_n << std::endl;
	}
	
	~Student() {
		delete S;
	}
	
	// setters
	void setName(std::string f_n, std::string l_n) {
		S->first_name = f_n;
		S->last_name = l_n;
		std::cout << "Student Name changed to \"" << f_n << " " << l_n << "\"!\n" << std::endl;
	}
	
	void setEnrollSemYear(char enr_sem, int enr_year) {		
		S->enrolled_year = enr_year;
		S->enrolled_semester = enr_sem;
		std::cout << "New effective enrollment semester is " << enr_sem << " " << enr_year << "." << std::endl;
	}
	
	void setGradSemYear(char grad_sem, int grad_year) {
		S->graduation_year = grad_year;
		S->graduation_semester = grad_sem;
	}
	
	void setGpa(double new_gpa) {
		S->gpa = new_gpa;
	}
	
	void calculateGpa(double new_gradeaverage) {
		int semesters_enrolled = 0;
		if(S->enrolled_semester == 'F' && S->enrolled_year == 2025) {
			std::cout << "New grade average is the new GPA." << std::endl;
			S->gpa = new_gradeaverage;
		}
		else{			
			semesters_enrolled = (2025 - S->enrolled_year)*2;	// Logic explanation:
			if(S->enrolled_semester == 'F') {						// We assume current semester is Fall 2025 (and include it).
				semesters_enrolled += 1;							// E.g. student enrolled Fall 24, total semesters: (2025-2024)*2 + 1 = 3
			}														// E.g. student enrolled Spring 24, total semesters: (2025-2024)*2 = 2
		}
		double temp_gpa = (((S->gpa)*(semesters_enrolled-1)) + new_gradeaverage)/(semesters_enrolled);
		S->gpa = temp_gpa;
	}
	
	void setGu(double ug) {
		S->undergrad_grad = ug;
	}
	
	// getters
	// CONSTANT - good practice to mark getter functions as const since they do not modify object
	std::string getFirstname() {
		return S->first_name;
	}
	
	std::string getLastname() {
		return S->last_name;
	}
	
	char getEnrollSem() const {				
		return S->enrolled_semester;
	}
	
	int getEnrollYear() const {
		return S->enrolled_year;
	}
	
	char getGradSem() const {
		return S->graduation_semester;
	}
	
	int getGradYear() const {
		return S->graduation_year;		
	}
	
	double getGpa() const {
		return S->gpa;
	}
	
	char getGu() const {
		return S->undergrad_grad;
	}
};

#endif


// individual_data.h
// struct contains all data for each student.

#include <string>

#ifndef INDIVIDUAL_DATA_H
#define INDIVIDUAL_DATA_H


struct _individual_data
{
	std::string last_name;
	std::string first_name;
	double gpa;
	int graduation_year;
	char graduation_semester;	// formatted like 'S' for Spring or 'F' for Fall
	int enrolled_year;
	char enrolled_semester;		// formatted like 'S' for Spring or 'F' for Fall
	char undergrad_grad;		// formatted 'U' for undergrad, 'G' for grad	
};
typedef struct _individual_data Individual_Data;

#endif


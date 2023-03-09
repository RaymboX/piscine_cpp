#ifndef DUMMY_HPP
# define DUMMY_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class Dummy: public ATarget
{
public:
						Dummy();
						Dummy(const std::string& type);
						Dummy(const Dummy& rhs);
	Dummy&				operator=(const Dummy& rhs);
	virtual				~Dummy();

	Dummy*				clone() const;
};

#endif
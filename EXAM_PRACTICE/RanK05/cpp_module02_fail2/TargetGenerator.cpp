#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
	for (targets_t::iterator it = _targets.begin(); it != _targets.end(); it++)
		delete it->second;
}


void	TargetGenerator::learntarget(ATarget* target_ptr)
{
	this->_targets.insert(std::pair<std::string, ATarget*>(target_ptr->getName(), target_ptr->clone()));
}

void	TargetGenerator::forgettarget(const std::string& targetType)
{
	if (this->_targets.find(targetName) != this->_targets.end())
	{
		delete _targets.find(targetName)->second;
		this->_targets.erase(this->_targets.find(targetName));
	}
}

ATarget*	createtarget(const std::string& targetName)
{
	return new Dummy(targetName);
}



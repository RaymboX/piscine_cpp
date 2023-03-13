#include "TargetGenerator.hpp"
#include "Dummy.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType(ATarget* targetPtr)
{
	this->_targets.insert(std::pair<std::string, ATarget*>(targetPtr->getType(), targetPtr));
}

void	TargetGenerator::forgetTargetType(const std::string& targetType)
{
	if (this->_targets.find(targetType) != this->_targets.end())
		this->_targets.erase(this->_targets.find(targetType));
}

ATarget* 	TargetGenerator::createTarget(const std::string& targetType)
{
	return (new Dummy(targetType));
}
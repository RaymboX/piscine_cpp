#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>

# include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
private:
	std::map<std::string, ATarget*> _targets;
public:
						TargetGenerator();
	virtual				~TargetGenerator();

	void				learnTargetType(ATarget* targetPtr);

	void				forgetTargetType(const std::string& targetType);

	ATarget* 			createTarget(const std::string& targetType);
};

#endif
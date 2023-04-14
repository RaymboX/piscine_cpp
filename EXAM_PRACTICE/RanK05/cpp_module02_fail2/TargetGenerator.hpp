#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>

# include "ATarget.hpp"

class ATarget;

typedef std::map<std::string, ATarget*> targets_t;

class TargetGenerator
{
private:
	targets_t			_targets;
public:
						TargetGenerator();
//						TargetGenerator(const TargetGenerator& rhs);
//	TargetGenerator&			operator=(const TargetGenerator& rhs);
	virtual				~TargetGenerator();

	void				learnTargetType(ATarget* Target_ptr);
	void				forgetTargetType(const std::string& targetType);
	ATarget*			createTarget(const std::string& targetType);
};


#endif

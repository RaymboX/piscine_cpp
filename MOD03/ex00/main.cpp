#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	ragnar("Ragnar");
	ClapTrap	rollo("Rollo");
	ClapTrap	priest(ragnar);

	srand(time(0));

	ragnar.setRandAttack();
	rollo.setRandAttack();
	while (ragnar.isDead() == false && rollo.isDead() == false
			&& (ragnar.getEnergyPoint() > 0 && rollo.getEnergyPoint() > 0))
	{
		ragnar.actionAttack(rollo);
		rollo.actionStatus();
		if (rollo.isDead() == false)
		{
			rollo.actionAttack(ragnar);
			ragnar.actionStatus();
		}
	}

	std::cout << CYAN;
	if (ragnar.isDead() == true)
		std::cout << "Rollo defeat ragnar!" << std::endl;
	else if (rollo.isDead() == true)
		std::cout << "Ragnar defeat rollo!" << std::endl;
	else
		std::cout << "Both stop fighting because they have no energy left" << std::endl;
	std::cout << COLORDEF;
	
	return 0;
}

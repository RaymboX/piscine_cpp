#include "ClapTrap.hpp"

int main(void)
{
	//CONSTRUCTION
	ClapTrap	ragnar;
	ClapTrap	rollo("Rollo");
	ClapTrap	priest(ragnar);

	//RANDOMIZING
	srand(time(0));

	//SETTING NAME MANUALLY
	ragnar.setName("Ragnar");
	priest.setName("Priest");
	
	//SETTING RANDOM MAX ATTACK (WEAPON)
	ragnar.setRandAttack();
	rollo.setRandAttack();
	
	//COMBAT
	while (ragnar.isDead() == false && rollo.isDead() == false
			&& (ragnar.getEnergyPoint() > 0 && rollo.getEnergyPoint() > 0))
	{
		std::cout << std::endl;
		//CHOICE WHO HIT FIRST
		if (rand() % 2 == 0)
		{
			std::cout << CYAN << "Ragnar win the turn" << std::endl;
			ragnar.actionAttack(rollo);
			rollo.actionStatus();
			if (rollo.isDead() == false)
			{
				rollo.actionAttack(ragnar);
				ragnar.actionStatus();
			}
		}
		else
		{
			std::cout << CYAN << "Rollo win the turn" << std::endl;
			rollo.actionAttack(ragnar);
			ragnar.actionStatus();
			if (ragnar.isDead() == false)
			{
				ragnar.actionAttack(rollo);
				rollo.actionStatus();
			}
		}
	}

	//END STATUS
	std::cout << CYAN;
	if (ragnar.isDead() == true)
		std::cout << "Rollo defeat ragnar!" << std::endl;
	else if (rollo.isDead() == true)
		std::cout << "Ragnar defeat rollo!" << std::endl;
	else
		std::cout << "Both stop fighting because they have no energy left" << std::endl;
	std::cout << COLORDEF << std::endl;
	
	return 0;
}

#include "ScavTrap.hpp"

void	clapTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik);

int main(void)
{
	std::cout << BLUE << "-----CONSTRUCTING CLAPTRAP-----" << std::endl;
	
	ClapTrap	ragnar;

	ragnar.setName("Ragnar");

	ClapTrap	rollo("Rollo");
	ClapTrap	priest(ragnar);

	priest.setName("Priest");

	std::cout << RED << "\n-----CONSTRUCTING SCAVTRAP-----" << std::endl;

	ScavTrap	horik("Horik");

	{
		ScavTrap	soldier1;
		ScavTrap	soldier2(soldier1);

		std::cout << YELLOW << "\nSoldiers was afraid and run away!" << std::endl;
	}
	
	srand(time(0));

	ragnar.setHitPoint(20);
	rollo.setHitPoint(20);
	priest.setHitPoint(10);
	ragnar.setEnergyPoint(10);
	rollo.setEnergyPoint(10);
	priest.setEnergyPoint(20);
	ragnar.setWeaponMaxDamage(10);
	rollo.setWeaponMaxDamage(10);
	priest.setWeaponMaxDamage(10);

	while (horik.isDead() == false
			&& (ragnar.isDead() == false && rollo.isDead() == false
			&& priest.isDead() == false))
	{
		if (rand() % 2 == 0)
		{
			std::cout << "The ClapTraps hit first!" << std::endl;
			

			
		}
		else
		{
			std::cout << "The ScavTrap hit first!" << std::endl;

		}
	}





	std::cout << COLORDEF << "\n-----DESTRUCTING-----" << std::endl;

	
	return 0;
}

void	clapTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik)
{
	if (priest.isDead() == false)
	{
		if (ragnar.getHitPoint() <= rollo.getHitPoint())
			priest.heal(ragnar);
		else
			priest.heal(rollo);
	}
	if (ragnar.isDead() == false)
		ragnar.actionAttack(horik);
	if (ragnar.isDead() == false)
		ragnar.actionAttack(horik);
}

void	scavTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik)
{
	if (horik.isDead() == false)
	{
		int	target = rand() % 10;

		horik.setGuardMode(false);
		switch (target)
		{
			case 0:
				horik.actionAttack(ragnar);
				break;
			case 1:
				horik.actionAttack(rollo);
				break;
			case 2:
				horik.actionAttack(priest);
				break;
			default:
				horik.setGuardMode(true);
				horik.guardGate();
		}
	}
}

void	statusList(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik)
{

}
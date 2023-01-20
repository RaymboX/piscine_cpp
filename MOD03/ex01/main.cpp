#include "ScavTrap.hpp"

void	clapTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik);

void	scavTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik);

void	statusList(ClapTrap & ragnar, ClapTrap & rollo,
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
	
	int	round = 0;

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
			&& (ragnar.isDead() == false || rollo.isDead() == false || priest.isDead() == false)
			&& (ragnar.getEnergyPoint() > 0 || rollo.getEnergyPoint() > 0
			|| horik.getEnergyPoint() > 0))
	{
		std::cout << WHITE << "\nTurn " << ++round << std::endl;

		if (rand() % 2 == 0)
		{
			std::cout << "The ClapTraps hit first!" << std::endl;
			clapTrapTurn(ragnar, rollo, priest, horik);
			scavTrapTurn(ragnar, rollo, priest, horik);
		}
		else
		{
			std::cout << "The ScavTrap hit first!" << std::endl;
			scavTrapTurn(ragnar, rollo, priest, horik);
			clapTrapTurn(ragnar, rollo, priest, horik);
		}
		statusList(ragnar, rollo, priest, horik);
	}

	if (horik.isDead() == true)
		std::cout << CYAN << "\nClapTrap win the battle" << std::endl;
	else 
		std::cout << RED << "\nScavTrap win the battle" << std::endl;

	std::cout << COLORDEF << "\n-----DESTRUCTING-----" << std::endl;

	return 0;
}

void	clapTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik)
{
	if (priest.isDead() == false)
	{
		if (ragnar.getHitPoint() <= rollo.getHitPoint() && ragnar.isDead() == false)
			priest.heal(ragnar);
		else if (rollo.isDead() == false)
			priest.heal(rollo);
	}
	if (ragnar.isDead() == false)
	{
		ragnar.actionAttack(horik);
		if (ragnar.getAttackDamage() > 0)
			horik.takeDamage(ragnar.getAttackDamage());
	}
	if (rollo.isDead() == false && horik.isDead() == false)
	{
		rollo.actionAttack(horik);
		if (rollo.getAttackDamage() > 0)
			horik.takeDamage(rollo.getAttackDamage());
	}
}

void	scavTrapTurn(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik)
{
	int	target = rand() % 10;
	
	if (horik.isDead() == false)
	{
		if (ragnar.getEnergyPoint() > 0 && rollo.getEnergyPoint() > 0)
			target = rand() % 10;
		else
			target = rand() % 3;
		while (target <= 2 
			&& ((target == 0 && ragnar.isDead() == true)
			|| (target == 1 && rollo.isDead() == true)
			|| (target == 2 && priest.isDead() == true)))
			target = rand() % 3;

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
				horik.guardGate();
		}
	}
}

void	statusList(ClapTrap & ragnar, ClapTrap & rollo,
					ClapTrap & priest, ScavTrap & horik)
{
	ragnar.coutStatus();
	rollo.coutStatus();
	priest.coutStatus();
	horik.coutStatus();
}
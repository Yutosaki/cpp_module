#include "ClapTrap.hpp"

void printSeparator(const std::string& title)
{
	std::cout << "\n==================== " << title << " ====================\n" << std::endl;
}

int main()
{
	printSeparator("Construction");
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");

	printSeparator("Initial Attacks");
	a.attack("Bravo");
	b.attack("Alpha");

	printSeparator("Damage and Repair Test");
	a.takeDamage(5);
	a.beRepaired(3);
	b.takeDamage(9);
	b.beRepaired(2);

	printSeparator("Exhausting Energy Points");
	for (int i = 0; i < 11; ++i)
	{
		a.attack("Training Dummy");
	}

	printSeparator("Edge Case: Zero HP");
	b.takeDamage(100);   // b should now be at 0 HP
	b.beRepaired(5);     // should fail
	b.attack("Alpha");   // should fail

	printSeparator("Assignment and Copy Test");
	ClapTrap c = a;       // copy constructor
	ClapTrap d("Delta");
	d = b;                // copy assignment

	printSeparator("Final Interactions");
	c.attack("TestTarget");
	d.beRepaired(1);

	printSeparator("Destruction");
	return 0;
}
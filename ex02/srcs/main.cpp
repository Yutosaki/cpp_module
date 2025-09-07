#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		delete j;
		delete i;
	}

	std::cout << "\n-----------------------------------------\n" << std::endl;

	{
		std::cout << "1. Creating Original Dog on the stack." << std::endl;
		Dog original_dog;

		{
			std::cout << "\n2. Creating Copied Dog in a new scope." << std::endl;
			Dog copied_dog(original_dog);
			std::cout << "3. Copied Dog is about to go out of scope." << std::endl;
		}

		std::cout << "\n4. Original Dog is still alive." << std::endl;
		std::cout << "5. Original Dog is about to go out of scope." << std::endl;
	}

	std::cout << "\n-----------------------------------------\n" << std::endl;

	{
		const int numAnimals = 6;
		AAnimal *animals[numAnimals];

		for (int i = 0; i < numAnimals / 2; ++i)
		{
			animals[i] = new Dog();
		}
		for (int i = numAnimals / 2; i < numAnimals; ++i)
		{
			animals[i] = new Cat();
		}

		std::cout << "\n--- Deleting all animals in the array ---\n" << std::endl;
		for (int i = 0; i < numAnimals; ++i)
		{
			delete animals[i];
		}
	}

	return (0);
}
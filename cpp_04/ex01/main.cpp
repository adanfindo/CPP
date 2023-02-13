/*
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define ANIMALS 8

int	main(void)
{
	Animal	*animals[ANIMALS];
	Brain	*brain1;

	for (int i = 0; i < ANIMALS; i++)
	{
		if (i < ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	brain1 = animals[7]->getBrain();
	brain1->ideas[0] = "I'm hungry";
	brain1->ideas[1] = "That's a strange idea I'm having";
	brain1->ideas[2] = "Ball!!!!!";
	brain1->ideas[3] = "Mum";
	std::cout << animals[7]->getBrain()->ideas[0] << std::endl;

	*(animals[5]) = *(animals[7]);
	std::cout << animals[5]->getBrain()->ideas[2] << std::endl;

	for (int i = 0; i < ANIMALS; i++)
		delete animals[i];
}*/

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

#define RED "\033[31m"
#define NONE "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

int main()
{
	std::cout << RED << "**** Constructor ****" << NONE << std::endl;
	Animal* meta = new Animal();
	Dog *j = new Dog();
	Cat *cat = new Cat();
	WrongAnimal* evilAldo = new WrongAnimal();
	WrongAnimal* evilCat = new WrongCat();
	int n = 10;
	Animal *array[n];
	std::cout << std::endl << "**** Constructor ****" << std::endl << std::endl;
	for(int k = 0; k < n; k++)
	{
		if(k < n / 2)
			array[k] = new Dog();
		else
			array[k] = new Cat();
	}

	std::cout << RED << "**** Testing ****  " << NONE << std::endl;
	std::cout << GREEN << "**** Types ****  " << NONE << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
	std::cout << GREEN << "**** Sounds ****  " << NONE << std::endl;
	cat->makeSound();
	j->makeSound();
	meta->makeSound();
	evilAldo->makeSound();
	evilCat->makeSound();

	std::cout << GREEN << "**** Ideas ****  " << NONE << std::endl;
	
	Brain *brain1;

	brain1 = cat->getBrain();
	brain1->ideas[0] = "I'm hungry";
	brain1->ideas[1] = "That's a strange idea I'm having";
	brain1->ideas[2] = "Ball!!!!!";
	brain1->ideas[3] = "Mum";
	std::cout << cat->getBrain()->ideas[0] << std::endl;
	std::cout << cat->getBrain()->ideas[1] << std::endl;
	std::cout << cat->getBrain()->ideas[2] << std::endl;
	std::cout << cat->getBrain()->ideas[3] << std::endl;


	std::cout << NONE << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << RED << "**** Destructor ****" << NONE << std::endl;
	for (int i = 0; i < n; i++)
		delete array[n];
	
	delete meta;
	delete j;
	delete cat;
	delete evilAldo;
	delete evilCat;
}

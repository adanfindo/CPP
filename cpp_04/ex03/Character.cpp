#include "Character.hpp"

Character::Character(void): _name(""), _number_equipped(0)
{
	for (int i = 0; i < Character::_inventory_size; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default Character\n";
}

Character::Character(const std::string &name)
{
	*this = Character();
	this->_name = name;
	std::cout << "Name Character\n";
	return;
}

Character::Character(Character const &src)
{
	std::cout << "Copy Character\n";
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Destructor Character\n";
}

Character &	Character::operator=(Character const &other)
{
	this->_number_equipped = 0;
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = other._inventory[i];
		if (other._inventory[i])
			this->_number_equipped++;
	}
	this->_name = other.getName();
	std::cout << "Assignement Character\n";
	return *this;
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (this->_number_equipped < Character::_inventory_size)
	{
		this->_inventory[this->_number_equipped] = m;
		this->_number_equipped++;
		std::cout << "Equipped a " << m->getType() << std::endl;
	}
	else
		std::cout << "Couldn't equip a " << m->getType() << ", no more space"
			<< std::endl;
}

void	Character::unequip(int idx)
{
	int i;

	i = idx + 1;
	while (i < Character::_inventory_size && this->_inventory[i])
	{
		this->_inventory[i - 1] = this->_inventory[i];
		i++;
	}
	this->_inventory[i] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	this->_inventory[idx]->use(target);
	this->unequip(idx);
}

void	Character::printInventory(void) const
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (this->_inventory[i])
			std::cout << i << ": " << this->_inventory[i] << std::endl;
		else
			std::cout << i << ": Empty\n";
	}
}
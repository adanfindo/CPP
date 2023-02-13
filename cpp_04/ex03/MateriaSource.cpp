#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): _number_learned(0)
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
		this->_materias[i] = NULL;
	std::cout << "Default MateriaSource\n";
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "Copy MateriaSource\n";
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	std::cout << "Destructor MateriaSource\n";
}

MateriaSource &	MateriaSource::operator=(MateriaSource const &other)
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (other._materias[i])
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	std::cout << "Assignement MateriaSource\n";
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia_to_learn)
{
	if (this->_number_learned >= MateriaSource::_materias_size)
		std::cout << "Can't learn any more materias\n";
	else
	{
		this->_materias[this->_number_learned] = materia_to_learn;
		this->_number_learned++;
		std::cout << "Learned " << materia_to_learn->getType() << " Materia\n";
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MateriaSource::_materias_size && this->_materias[i]; i++)
	{
		if (type == this->_materias[i]->getType())
			return this->_materias[i]->clone();
	}
	return NULL;
}

void	MateriaSource::printMaterias(void) const
{
	for (int i = 0; i < MateriaSource::_materias_size; i++)
	{
		if (this->_materias[i])
			std::cout << i << ": " << this->_materias[i]->getType() << std::endl;
		else
			std::cout << i << ": Empty\n";
	}
}

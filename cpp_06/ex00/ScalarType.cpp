#include "ScalarType.hpp"

ScalarType::ScalarType(void)
{
	this->resetValues();
	std::cout << "Default constructor\n";
}

ScalarType::ScalarType(char *input)
{
	this->analyseNewInput(input);
	std::cout << "Char* constructor\n";
}

ScalarType::ScalarType(ScalarType const &src)
{
	std::cout << "Copy constructor\n";
	*this = src;
}

ScalarType::~ScalarType(void)
{
	std::cout << "Destructor\n";
}

ScalarType	&ScalarType::operator=(ScalarType const &other)
{
	std::cout << "Assignement operator\n";
	this->_selectedType = other._selectedType;
	this->_charScalar = other._charScalar;
	this->_intScalar = other._intScalar;
	this->_floatScalar = other._floatScalar;
	this->_doubleScalar = other._doubleScalar;
	return *this;
}

void	ScalarType::analyseNewInput(char *input)
{
	this->resetValues();
	if (input[0] == 0)
		throw ScalarType::EmptyInput();
	if (!this->getType(input))
		throw ScalarType::CannotAnalyse();
	this->setVariable(input);
}

void	ScalarType::printTypes(void)
{
	if (this->_selectedType == ScalarType::noType)
		std::cout << "No type set\n";
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

void	ScalarType::resetValues(void)
{
	this->_selectedType = ScalarType::noType;
	this->_charScalar = 0;
	this->_intScalar = 0;
	this->_floatScalar = 0;
	this->_doubleScalar = 0;
}

bool	ScalarType::getType(char* input)
{
	this->_selectedType = handle_special_cases(input);
	if (this->_selectedType != ScalarType::noType)
		return true;
	if ((input[0] >= '0' && input[0] <= '9') || input[0] == '-'
			|| input[0] == '.')
	{
		this->_selectedType = handle_numeric_values(input);
		if (this->_selectedType != ScalarType::noType)
			return true;
	}
	if (input[1])
		return false;
	this->_selectedType = ScalarType::charType;
	return true;
}

void	ScalarType::setVariable(char *input)
{
	if (this->_selectedType == ScalarType::charType)
	{
			std::cout << "Selected char type\n";
		this->_charScalar = input[0];
	}
	else if (this->_selectedType == ScalarType::intType)
	{
			std::cout << "Selected int type\n";
		this->_intScalar = atoi(input);
	}
	else if (this->_selectedType == ScalarType::floatType)
	{
			std::cout << "Selected float type\n";
		this->_floatScalar = atof(input);
	}
	else if (this->_selectedType == ScalarType::doubleType)
	{
			std::cout << "Selected double type\n";
		this->_doubleScalar = atof(input);
	}
}

int		ScalarType::handle_special_cases(char *input) const
{
	const std::string	special_doubles[] =
	{
		"inf", "+inf", "-inf", "nan"
	};
	const std::string	special_floats[] =
	{
		"inff", "+inff", "-inff", "nanf"
	};

	for (int i = 0; i < 4; i++)
	{
		if (special_doubles[i] == input)
			return ScalarType::doubleType;
		else if (special_floats[i] == input)
			return ScalarType::floatType;
	}
	return ScalarType::noType;
}

int		ScalarType::handle_numeric_values(char *input) const
{
	int	i = 0;
	int	dotCount = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] == 'f' || input[i + 1] == 0))
		return (ScalarType::noType);
	while (input[i] == '.' || ft_isdigit(input[i]))
	{
		if (input[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return ScalarType::noType;
		i++;
	}
	if (!input[i])
	{
		if (dotCount == 1)
			return ScalarType::doubleType;
		return ScalarType::intType;
	}
	else if (input[i] == 'f' && !input[i + 1] && dotCount == 1)
		return ScalarType::floatType;
	return ScalarType::noType;
}

void	ScalarType::printChar(void)
{
	if (this->_selectedType == ScalarType::intType)
	{
		if (this->canConvertToChar(this->_intScalar))
			std::cout << "char: " << static_cast<char>(this->_intScalar) << std::endl;
	}
	else if (this->_selectedType == ScalarType::floatType)
	{
		if (this->canConvertToChar(this->_floatScalar))
			std::cout << "char: " << static_cast<char>(this->_floatScalar) << std::endl;
	}
	else if (this->_selectedType == ScalarType::doubleType)
	{
		if (this->canConvertToChar(this->_doubleScalar))
			std::cout << "char: " << static_cast<char>(this->_doubleScalar) << std::endl;
	}
	else
		std::cout << "char: " << this->_charScalar << std::endl;
}

bool	ScalarType::canConvertToChar(double number)
{
	if (number - static_cast<int>(number) != 0 || number > 127 || number < 0)
		std::cout << "char: impossible\n";
	else if (number <= 31 || number == 127)
		std::cout << "char: Non displayable\n";
	else
		return true;
	return false;
}

void	ScalarType::printInt(void)
{
	if (this->_selectedType == ScalarType::charType)
		std::cout << "int: " << static_cast<int>(this->_charScalar)
			<< std::endl;
	else if (this->_selectedType == ScalarType::intType)
		std::cout << "int: " << this->_intScalar << std::endl;
	else if (this->_selectedType == ScalarType::floatType)
	{
		if (canConvertToInt(this->_floatScalar))
			std::cout << "int: " << static_cast<int>(this->_floatScalar) << std::endl;
		else
			std::cout << "int: impossible\n";
	}
	else if (this->_selectedType == ScalarType::doubleType)
	{
		if (canConvertToInt(this->_doubleScalar))
			std::cout << "int: " << static_cast<int>(this->_doubleScalar) << std::endl;
		else
			std::cout << "int: impossible\n";
	}
}

void	ScalarType::printFloat(void)
{
	if (this->_selectedType == ScalarType::charType)
		std::cout << "float: " << static_cast<float>(this->_charScalar) << ".0f\n";
	else if (this->_selectedType == ScalarType::intType)
		std::cout << "float: " << static_cast<float>(this->_intScalar) << ".0f\n";
	else if (this->_selectedType == ScalarType::floatType)
		std::cout << "float: " << this->_floatScalar
			<< printDotZero(static_cast<float>(this->_floatScalar)) << "f\n";
	else if (this->_selectedType == ScalarType::doubleType)
	{
		if (canConvertToFloat(this->_doubleScalar))
			std::cout << "float: " << static_cast<float>(this->_doubleScalar)
				<< printDotZero(static_cast<float>(this->_doubleScalar)) << "f\n";
		else
			std::cout << "float: impossible\n";
	}
}

void	ScalarType::printDouble(void)
{
	if (this->_selectedType == ScalarType::charType)
		std::cout << "double: " << static_cast<double>(this->_charScalar)
			 << ".0\n";
	else if (this->_selectedType == ScalarType::intType)
		std::cout << "double: " << static_cast<double>(this->_intScalar)
			<< ".0\n";
	else if (this->_selectedType == ScalarType::floatType)
		std::cout << "double: " << static_cast<double>(this->_floatScalar)
			<< printDotZero(static_cast<double>(this->_floatScalar)) << std::endl;
	else if (this->_selectedType == ScalarType::doubleType)
		std::cout << "double: " << this->_doubleScalar
			<< printDotZero(static_cast<double>(this->_doubleScalar)) << std::endl;
}

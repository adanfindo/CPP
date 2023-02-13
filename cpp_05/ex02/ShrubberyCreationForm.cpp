#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Standard ShrubberyCreationForm\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "Default ShrubberyCreationForm\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
	Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm\n";
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor ShrubberyCreationForm\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	other.getTarget();
	std::cout << "Assignement ShrubberyCreationForm\n";
	return *this;
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	f;
	std::string		file_name = this->_target + "_shrubbery";

	this->checkExecutability(executor);
	f.open(file_name.c_str(), std::ios::out);


	f << "                                                 .\n";
	f << "                                      .         ;\n";
	f << "         .              .              ;%     ;;\n";
	f << "           ,           ,                :;%  %;\n";
	f << "            :         ;                   :;%;'     .,\n";
	f << "   ,.        %;     %;            ;        %;'    ,;\n";
	f << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	f << "      %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
	f << "       ;%;      %;        ;%;        % ;%;  ,%;'\n";
	f << "        `%;.     ;%;     %;'         `;%%;.%;'\n";
	f << "         `:;%.    ;%%. %@;        %; ;@%;%'\n";
	f << "            `:%;.  :;bd%;          %;@%;'\n";
	f << "              `@%:.  :;%.         ;@@%;'\n";
	f << "                `@%.  `;@%.      ;@@%;\n";
	f << "                  `@%%. `@%%    ;@@%;\n";
	f << "                    ;@%. :@%%  %@@%;\n";
	f << "                      %@bd%%%bd%%:;\n";
	f << "                        #@%%%%%:;;\n";
	f << "                        %@@%%%::;\n";
	f << "                        %@@@%(o);  . '\n";
	f << "                        %@@@o%;:(.,'\n";
	f << "                    `.. %@@@o%::;\n";
	f << "                       `)@@@o%::;\n";
	f << "                        %@@(o)::;\n";
	f << "                       .%@@@@%::;\n";
	f << "                       ;%@@@@%::;.\n";
	f << "                      ;%@@@@%%:;;;.\n";
	f << "                  ...;%@@@@@%%:;;;;,..\n";
	f.close();
	std::cout << "A tree grown: " << this->_target << "_shrubbery\n";
}

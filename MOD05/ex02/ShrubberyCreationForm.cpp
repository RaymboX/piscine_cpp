#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():	
						AForm("DefaultShrub", signGradeDefault, execGradeDefault),
						_target("DefaultTarget")
{
	std::cout << BLUE << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target):
										AForm(name, signGradeDefault, execGradeDefault), _target(target)
{
	std::cout << BLUE << "ShrubberyCreationForm param constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
						AForm(src.getName(), signGradeDefault, execGradeDefault),
						_target(src.getTarget())
{
	std::cout << BLUE << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << PURPLE << "ShrubberyCreationForm copy constructor called" << std::endl;
	this->setTarget(src.getTarget());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << std::endl;
}

//ACCESSOR

std::string	ShrubberyCreationForm::getTarget() const {return this->_target;}
void		ShrubberyCreationForm::setTarget(const std::string target) {this->_target = target;}

//MEMBER FUNCTION

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	try
	{
		if (this->getIsSigned() == false)
			throw ShrubberyCreationForm::ExecutionFormException();
		if (this->getExecGrade() < executor.getGrade())
			throw ShrubberyCreationForm::GradeTooHighException();
		std::ofstream	ofs("file_shrubbery");
		ofs << this->shrubArt;
		ofs.close();
		std::cout << PURPLE << "A shrubbery file has been created" << std::endl;
	}
	catch (const ShrubberyCreationForm::ExecutionFormException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch (const ShrubberyCreationForm::GradeTooHighException& e)
	{
		std::cerr << YELLOW << "The form " << e.what() << " to be execute by " << executor.getName() << std::endl;
	}
}

const int			ShrubberyCreationForm::signGradeDefault = 145;
const int			ShrubberyCreationForm::execGradeDefault = 137;
const std::string	ShrubberyCreationForm::shrubArt =
"                     .o00o \n"
"                   o000000oo \n"
"                  00000000000o \n"
"                 00000000000000 \n"
"              oooooo  00000000  o88o \n"
"           ooOOOOOOOoo  ```''  888888 \n"
"         OOOOOOOOOOOO'.qQQQQq. `8888' \n"
"        oOOOOOOOOOO'.QQQQQQQQQQ/.88' \n"
"        OOOOOOOOOO'.QQQQQQQQQQ/ /q \n"
"         OOOOOOOOO QQQQQQQQQQ/ /QQ \n"
"           OOOOOOOOO `QQQQQQ/ /QQ' \n"
"             OO:F_P:O `QQQ/  /Q' \n"
"                \\\\. \\ |  // | \n"
"                d\\ \\\\\\|_//// \n"
"                qP| \\\\ _' `|Ob \n"
"                   \\  / \\  \\Op \n"
"                   |  | O| | \n"
"           _       /\\. \\_/ /\\ \n"
"            `---__/|_\\\\   //|  __ \n"
"                  `-'  `-'`-'-' ";

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    //TEST 1
    std::cout << BRED "TEST 1: Make Form with Inter \n" CLEAR << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
   
   try
   {
        Form        *dossier;
        Bureaucrat  superviseur("Jack", 5);    
        Intern      merde;
        
        //Shrubbery Test 
        std::cout << std::endl << BRED " - ShrubberyForm Creation by Intern \n" CLEAR << std::endl;
        dossier = merde.makeForm("shrubbery creation", "bouquet-de-fleurs2");
        superviseur.signForm(*dossier);
        superviseur.executeForm(*dossier);
        delete dossier;

        //Robotomy test
        std::cout << std::endl << BRED " - RobotomyForm Creation by Intern \n" CLEAR << std::endl;
        dossier = merde.makeForm("robotomy request", "Éric Duhaime");
        superviseur.signForm(*dossier);
        superviseur.executeForm(*dossier);
        delete dossier;

        //Presidential Pardon test
        std::cout << std::endl << BRED " - PresidentialPardonForm Creation by Intern \n" CLEAR << std::endl;
        dossier = merde.makeForm("presidential pardon", "Jesus");
        superviseur.signForm(*dossier);
        superviseur.executeForm(*dossier);
        delete dossier;

        //Unexisting form type
        std::cout << BRED "TEST 2: Wrong Form name\n" CLEAR << std::endl;
        dossier = merde.makeForm("NonExistingForm", "Nonexisting target");
        std::cout << "Non exiting form" << std::endl;
        delete dossier;
   }
    catch(Intern::NOFException & e)
    {
        std::cerr << std::endl << e.whate() << std::endl;
        std::cerr << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }


   return(0);
} 
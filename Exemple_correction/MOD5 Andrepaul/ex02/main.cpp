#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    //TEST 1

   try
   {
        std::cout << BRED "TEST 1: INVALID BUREAUCRAT\n" CLEAR << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    
        Bureaucrat  instance("Poulpe", 151);

        Form    *Mani = new ShrubberyCreationForm("Forêt");
        delete Mani;
   }
    catch(Bureaucrat::GTLException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }
    catch(Bureaucrat::GTHException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }

    //TEST 2
    try
    {
        std::cout << BRED "\nTEST 2: SIGN/EXECUTE SHRUBBERY \n" CLEAR << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        Form    *Calamar = new ShrubberyCreationForm("bouquet");
        Bureaucrat Pedo;
        Bureaucrat instance1("AP", 100);
        Bureaucrat  instance2("Max", 140);

        Pedo.signForm(*Calamar);
        instance1.signForm(*Calamar);
        instance1.signForm(*Calamar);
        instance1.executeForm(*Calamar);
        Pedo.executeForm(*Calamar);
        instance2.executeForm(*Calamar);
        delete Calamar;
    }
    catch(Bureaucrat::GTLException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }
    catch(Bureaucrat::GTHException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }

    //TEST 3
    try
    {
        std::cout << BRED "\nTEST 3: SIGN/EXECUTE ROBOTOMY\n" CLEAR << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));

        Form *robo = new RobotomyRequestForm("Éric Duhaime");
        Bureaucrat  player1("Bistro-Pub", 100);
        Bureaucrat  player2("Machine", 45);

        player1.executeForm(*robo);
        player1.signForm(*robo);
        player2.executeForm(*robo);
        player2.signForm(*robo);
        player1.executeForm(*robo);
        player2.executeForm(*robo);
        player2.executeForm(*robo);
        player2.executeForm(*robo);
        player2.executeForm(*robo);
        delete robo;
    }
    catch(Bureaucrat::GTLException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }
    catch(Bureaucrat::GTHException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }

    //TEST 4
    try
    {
        std::cout << BRED "\nTEST 4: SIGN/EXECUTE PRESIDENTIAL PARDON\n" CLEAR << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Form *important = new PresidentialPardonForm("Gollum");
        Bureaucrat  instance("Andre", 1);
        Bureaucrat  instance2("Edo", 24);
        std::cout << BHRED << "<< OVERLOAD :   " YEL << instance << instance2 << *important << CLEAR << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        instance.signForm(*important);
        instance2.executeForm(*important);
        instance.executeForm(*important);
        delete important; 
    }
    catch(Bureaucrat::GTLException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }
    catch(Bureaucrat::GTHException & e)
    {
        std::cerr << e.whate() << std::endl;
        std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    }



   return(0);
} 
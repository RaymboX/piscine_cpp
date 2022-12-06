#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>
#include "colours.hpp"

int main(void)
{

    try
    {
        //CREATE BUREAUCRATS

        std::cout << BRED "Test the Bureaucrats " CLEAR << std::endl;

        Bureaucrat  instance1("Edo", 120);
        std::cout << instance1 << std::endl;
        Bureaucrat  instance("Andre", 1);
        std::cout << instance << std::endl;
        instance1.getPromotion();
        std::cout << instance1 << std::endl;
        instance1.getDemoted();
        std::cout << instance1 << std::endl;

        //WHERE ERROR OCCURS
        std::cout << BRED "Try to promote over the limit " CLEAR<< std::endl;

        Bureaucrat  instance2("Max", 151);

        instance.getPromotion();
        
        //THIS CODE IS NOT PROCESSED
        std::cout << instance << std::endl;
        Bureaucrat  instance3("Alex", 0);
        //Bureaucrat  instance2("Max", 151);
        std::cout << "anthony est un génie!" << std::endl;
    }
    
    //EXCEPTION CAUGHT HERE
    catch(Bureaucrat::GTHException & e)
    {
        std::cout << e.whate() << std::endl;
    }
    catch(Bureaucrat::GTLException & e)
    {
        std::cout << e.whate() << std::endl;
    }
    std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
    return(0);
} 
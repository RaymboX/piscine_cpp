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
        Form form1("Mini project", 150, 150);
        Form form2("Mega project", 5, 5);
        Bureaucrat  instance("Andre", 1);
        Bureaucrat  instance1("Edo", 120);

        std::cout << form1 << form2 << std::endl;
        std::cout << instance1 << std::endl;
        std::cout << instance << std::endl;
        instance1.getPromotion();
        std::cout << instance1 << std::endl;
        instance1.getDemoted();
        std::cout << instance1 << std::endl;


        instance1.signForm(form1);
        instance1.signForm(form2);

        //WHERE ERROR OCCURS
        std::cout << BRED "Try to promote over the limit " CLEAR<< std::endl;
        instance.getPromotion();
        
        //THIS CODE IS NOT PROCESSED
        std::cout << instance << std::endl;
        Bureaucrat  instance3("Alex", 0);
        Bureaucrat  instance2("Max", 151);
        std::cout << "anthony est un génie!" << std::endl;
    }
    
    //EXCEPTION CAUGHT HERE
    catch(Bureaucrat::GTHException & e)
    {
        std::cerr << e.whate() << std::endl;
    }
    catch(Bureaucrat::GTLException & e)
    {
        std::cerr << e.whate() << std::endl;
    }
   std::cout << BRED "Exception has been CAUGHT " CLEAR<< std::endl;
     std::cout << std::endl << BRED "Test FORMS " CLEAR<< std::endl;
    //FORM tests
    try
    {
        Form mini("Mini project", 123, 115);
        std::cout << mini << std::endl; 
        Form wrong("Mini project", 154, 115);
        
        //IS NOT PROCESSED
        std::cout << "This code will not process" << std::endl;

    }
    catch(const Form::GTHException& e)
    {
        std::cerr << e.whate() << std::endl;
    }
    catch(const Form::GTLException& e)
    {
         std::cerr << e.whate() << std::endl;
    }
    


    std::cout << BRED "Exception has been CAUGHT once again" CLEAR<< std::endl;
    return(0);
} 
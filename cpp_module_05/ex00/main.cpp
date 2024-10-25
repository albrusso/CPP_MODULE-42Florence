#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat a("Aldo", 0);
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat p("Pippo", 151);
			std::cout << p << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{	
		try 
		{
			Bureaucrat d("Duccio", 2);
			std::cout << d << std::endl;
			d.up();
			std::cout << d << std::endl;
			d.up();
			std::cout << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{	
		try 
		{
			Bureaucrat f("Fabio", 149);
			std::cout << f << std::endl;
			f.down();
			std::cout << f << std::endl;
			f.down();
			std::cout << f << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
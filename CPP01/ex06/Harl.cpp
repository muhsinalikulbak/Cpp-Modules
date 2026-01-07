#include "Harl.hpp"


Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void (Harl::*func)(void);
    func 	funcs[4];
	int		intLevel = -1;
 
	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			intLevel = (int)i;
			break;
		}
	}

	switch (intLevel)
	{
	case 0:
		std::cout << "[DEBUG]" << std::endl;
		(this->*funcs[0])();
		/* fall through */
	case 1:
		std::cout << "[INFO]" << std::endl;
		(this->*funcs[1])();
		/* fall through */
	case 2:
		std::cout << "[WARNING]" << std::endl;
		(this->*funcs[2])();
		/* fall through */
	case 3:
		std::cout << "[ERROR]" << std::endl;
		(this->*funcs[3])();
		break;
	default :
		std::cout << "Invalid section" << std::endl;
		break;
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you just started working here last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

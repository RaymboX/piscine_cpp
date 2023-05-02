#include "RPN.hpp"

RPN::RPN(const char* command): _command(command) {routine();}

RPN::~RPN(){clearStack();}

const char	RPN::_operatorList[4] = {'+', '-', '*', '/'};

void	RPN::routine()
{
	try	
	{
		iterCommand();
		validEndCommandStackSize();
		coutAnswer();
	}
	catch(const std::exception& e){
		if (DEMARCHE == 1)
			std::cout << std::endl;
		std::cerr << RED << e.what() << COLORDEF << '\n';}
}

void	RPN::iterCommand()
{
	for	(size_t	index = 0; index < _command.length(); index++)
		detectNext(index);
}

void	RPN::detectNext(const size_t& index)
{
	if (index % 2 != 0)
		validSpace(index);
	else if (!isNumber(index) && !isOperator(index))
		throw	genericException("command format error at command position " 
									+ std::to_string(index));
}

void	RPN::validSpace(const size_t& index) const
{
	if (_command.at(index) != ' ')
		throw genericException("should be a space at command position "
									+ std::to_string(index));
}

bool	RPN::isNumber(const size_t& index)
{
	if (!isdigit(_command.at(index)))
		return false;
	_numbers.push(std::stoi(_command.substr(index, 1)));
	return true;
}

bool	RPN::isOperator(const size_t& index)
{
	if (!isInOperatorList(index))
		return false;
	doOperation(index);
	return true;
}

bool	RPN::isInOperatorList(const size_t& index) const
{
	for (int i = 0; i < 4; i++)
	{
		if (_command.at(index) == _operatorList[i])
			return true;
	}
	return false;
}

void	RPN::doOperation(const size_t& index)
{
	extractOperationValues(index);
	coutDemarcheCalcul();
	switch (_operator)
	{
		case OP_ADD:
			_numbers.push(_lhs + _rhs);
			break;
		case OP_SUB:
			_numbers.push(_lhs - _rhs);
			break;
		case OP_MUL:
			_numbers.push(_lhs * _rhs);
			break;
		case OP_DIV:
			validDivide0();
			_numbers.push(_lhs / _rhs);
			break;
	}
	coutDemarcheResult();
}

void	RPN::extractOperationValues(const size_t& index)
{
	popNumbers();
	recordOperation(index);
}

void	RPN::popNumbers()
{
	validOperationStackSize();
	_rhs = _numbers.top();
	_numbers.pop();
	_lhs = _numbers.top();
	_numbers.pop();
}

void	RPN::validOperationStackSize() const
{
	if (_numbers.size() < 2)
		throw genericException("Not enough number to do the operation");
}

void	RPN::recordOperation(const size_t& index)
{
	int i = -1;
	while (_command.at(index) != _operatorList[++i]);
	_operator = i;
}

void	RPN::validDivide0() const
{
	if (_operator == OP_DIV && _rhs == 0)
		throw genericException("division by 0 impossible");
}

void	RPN::validEndCommandStackSize() const
{
	if (_numbers.size() == 0)
		throw genericException("Empty command");
	if (_numbers.size() > 1)
		throw genericException("Not enough operator for number");
}

void	RPN::coutAnswer() const
{
	std::cout << GREEN << _numbers.top() << COLORDEF << std::endl;
}

void	RPN::clearStack()
{
	while (_numbers.size() > 0)
		_numbers.pop();
}

void	RPN::coutDemarcheCalcul() const
{
	if (DEMARCHE == 1)
		std::cout << _lhs << " " << _operatorList[_operator] << " " << _rhs;
}

void	RPN::coutDemarcheResult() const
{
	if (DEMARCHE == 1)
		std::cout << " = " << _numbers.top() << std::endl;
}

RPN::genericException::genericException(const std::string& exception_str):
		_errorMessage("ERROR: " + exception_str){}
RPN::genericException::~genericException() throw() {}
const char*	RPN::genericException::what() const throw() {
	return _errorMessage.c_str();}
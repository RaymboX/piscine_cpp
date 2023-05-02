#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdexcept>

# include "colors.hpp"

enum	operator_e
{
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV
};

# ifndef DEMARCHE
#  define DEMARCHE 0
# endif

class RPN
{
private:
	int					_lhs;
	int					_rhs;
	int					_operator;
	std::string			_command;
	std::stack<int>		_numbers;
	static const char	_operatorList[4];

	void				routine();
	void				iterCommand();
	void				detectNext(const size_t& index);
	void				validSpace(const size_t& index) const;
	bool				isOperator(const size_t& index);
	bool				isInOperatorList(const size_t& index) const;
	void				doOperation(const size_t& index);
	void				validOperationStackSize() const;
	void				extractOperationValues(const size_t& index);
	void				popNumbers();
	void				recordOperation(const size_t& index);
	void				validDivide0() const;
	bool				isNumber(const size_t& index);
	void				validEndCommandStackSize() const;
	void				coutAnswer() const;
	void				clearStack();
	void				coutDemarcheCalcul() const;
	void				coutDemarcheResult() const;

						RPN();
						RPN(const RPN& rhs);
	RPN&				operator=(const RPN& rhs);
public:
						RPN(const char* command);
	virtual				~RPN();

	class	genericException: public std::exception
	{
		public:
			genericException(const std::string& exception_str);
			virtual	~genericException() throw();
			virtual const char* what() const throw();
		private:
			std::string	_errorMessage;
	};

};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:37 by msolinsk          #+#    #+#             */
/*   Updated: 2025/01/31 17:28:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits;
}

/*
	For example:
	float value = 12.34f;
	int	ret = 12 * (1 << 8) + 0.34 * (1 << 8) ==>> 12.34 * (1 << 8)
	1 << 8 == 256
*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator = ( const Fixed& fixed_op)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed_op)
		this->setRawBits(fixed_op.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum)
{
	os << fixedNum.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


float Fixed::toFloat( void ) const
{
	return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_value >> _fractionalBits;
}


int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

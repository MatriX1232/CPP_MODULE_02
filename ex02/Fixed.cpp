/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:37 by msolinsk          #+#    #+#             */
/*   Updated: 2024/11/07 22:10:03 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value) : _value ( value << this->_fractionalBits )
{
}

/*
	For example:
	float value = 12.34f;
	int	ret = 12 * (1 << 8) + 0.34 * (1 << 8) ==>> 12.34 * (1 << 8)
	1 << 8 == 256
*/
Fixed::Fixed(const float value) : _value ( roundf(value * (1 << this->_fractionalBits)) )
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}


Fixed& Fixed::operator = ( const Fixed& fixed_op)
{
	if (this != &fixed_op)
		this->setRawBits(fixed_op.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum)
{
	os << fixedNum.toFloat();
	return os;
}

bool	operator>(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() > b.getRawBits();
}

bool	operator<(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() < b.getRawBits();
}

bool	operator>=(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() >= b.getRawBits();
}

bool	operator<=(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() <= b.getRawBits();
}

bool	operator==(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() == b.getRawBits();
}

bool	operator!=(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() != b.getRawBits();
}

Fixed	operator+(const Fixed &a, const Fixed &b)
{
	return Fixed(a.toFloat() + b.toFloat());
}

Fixed	operator-(const Fixed &a, const Fixed &b)
{
	return Fixed(a.toFloat() - b.toFloat());
}

Fixed	operator*(const Fixed &a, const Fixed &b)
{
	return Fixed(a.toFloat() * b.toFloat());
}

Fixed	operator/(const Fixed &a, const Fixed &b)
{
	if (b.toFloat() == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(a.toFloat() / b.toFloat());
}

Fixed& Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator ++ (int)
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return tmp;
}



float Fixed::toFloat( void ) const
{
	return (float)(this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractionalBits);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}


int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

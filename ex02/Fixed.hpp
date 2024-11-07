/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:41:00 by msolinsk          #+#    #+#             */
/*   Updated: 2024/11/07 12:54:42 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();									// Default constructor
		Fixed(const int value);						// Int constructor
		Fixed(const float value);					// Float constructor
		Fixed(const Fixed &copy);					// Copy constructor
		Fixed &operator=(const Fixed &fixed_op);	// Assignation operator overload
		~Fixed(); 									// Destructor

		friend std::ostream&	operator << (std::ostream& os, const Fixed& fixedNum);
		friend bool				operator >  (const Fixed &a, const Fixed &b);
		friend bool				operator <  (const Fixed &a, const Fixed &b);
		friend bool				operator >= (const Fixed &a, const Fixed &b);
		friend bool				operator <= (const Fixed &a, const Fixed &b);
		friend bool				operator == (const Fixed &a, const Fixed &b);
		friend bool				operator != (const Fixed &a, const Fixed &b);
		friend Fixed			operator +  (const Fixed &a, const Fixed &b);
		friend Fixed			operator -  (const Fixed &a, const Fixed &b);
		friend Fixed			operator *  (const Fixed &a, const Fixed &b);
		friend Fixed			operator /  (const Fixed &a, const Fixed &b);
		Fixed&					operator ++ ();
		Fixed					operator ++ (int);
		Fixed&					operator -- ();
		Fixed					operator -- (int);

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	min(Fixed const &a, Fixed const &b);
		static const Fixed&	max(Fixed const &a, Fixed const &b);

	private:
		int					_value;
		static const int	_fractionalBits =	8;
};

#endif // FIXED_HPP

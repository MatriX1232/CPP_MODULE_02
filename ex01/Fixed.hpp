/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:41:00 by msolinsk          #+#    #+#             */
/*   Updated: 2024/11/04 16:04:27 by msolinsk         ###   ########.fr       */
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

		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

#endif // FIXED_HPP

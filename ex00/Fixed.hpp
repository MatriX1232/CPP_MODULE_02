/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:19:57 by msolinsk          #+#    #+#             */
/*   Updated: 2024/11/03 22:58:06 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	public:
		Fixed();									// Default constructor
		Fixed(const Fixed &copy);					// Copy constructor
		Fixed &operator=(const Fixed &fixed_op);	// Assignation operator overload
		~Fixed(); 									// Destructor

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _value;
		int _fractionalBits;
};

#endif // FIXED_HPP

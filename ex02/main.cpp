/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:59:11 by msolinsk          #+#    #+#             */
/*   Updated: 2025/01/31 17:31:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int main( void )
{
	Fixed a;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed c( Fixed( 5.05f ) / Fixed( 0 ) );
	// std::cout << c << std::endl;

	return (0);
}

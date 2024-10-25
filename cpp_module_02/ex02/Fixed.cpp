/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:16:11 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 16:27:24 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//costructor && destructor
Fixed::Fixed(void): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int param): _value(param << _fractBit) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float param): _value(static_cast<int>(roundf(param * (1 << _fractBit)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

//copy assignement
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

//compare operator
bool Fixed::operator<(const Fixed &other) {
	return this->_value < other._value;
}

bool Fixed::operator>(const Fixed &other) {
	return this->_value > other._value;
}

bool Fixed::operator<=(const Fixed &other) {
	return this->_value <= other._value;
}

bool Fixed::operator>=(const Fixed &other) {
	return this->_value >= other._value;
}

bool Fixed::operator==(const Fixed &other) {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) {
	return this->_value != other._value;
}

//math symbol
Fixed Fixed::operator+(const Fixed &other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
	return Fixed(this->toFloat() / other.toFloat());
}

//incremen && decrement operator
Fixed &Fixed::operator++(void) {
	(this->_value)++;
	return *this;
}

Fixed &Fixed::operator--(void) {
	(this->_value)--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed f(*this);
	++(*this);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed f(*this);
	--(*this);
	return f;
}

//other function
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_value) / (1 << this->_fractBit);
}

int Fixed::toInt(void) const {
	return roundf(this->toFloat());
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1.toFloat() < f2.toFloat())
		return f1;
	else
		return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.toFloat() < f2.toFloat())
		return f1;
	else
		return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1.toFloat() < f2.toFloat())
		return f2;
	else
		return f1;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.toFloat() < f2.toFloat())
		return f2;
	else
		return f1;
}

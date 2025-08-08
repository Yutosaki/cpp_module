#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    this->_rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other) {
    // std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_rawBits + other._rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_rawBits - other._rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other._rawBits == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result.setRawBits((this->_rawBits << _fractionalBits) / other._rawBits);
    return result;
}

Fixed &Fixed::operator++() {
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

int Fixed::getRawBits() const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

int Fixed::toInt() const {
    return this->_rawBits >> _fractionalBits;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
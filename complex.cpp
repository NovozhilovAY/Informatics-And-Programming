#include "complex.h"
#include <iostream>

Complex::Complex() : re(0.0), im(0.0) {}

// указанное написание конструктора по умолчанию эквивалентно написанию с занятия:
/*
Complex::Complex() {
  re = 0.0;
  im = 0.0;
}
*/

Complex::Complex(const Complex &c) : re(c.re), im(c.im) {}

// указанное написание конструктора копирования эквивалентно написанию с занятия:
/*
Complex::Complex(const Complex &c) {
  re = c.re;
  im = c.im;
}
*/

Complex::Complex(double _re, double _im) : re(_re), im(_im) {}

// указанное написание конструктора инициализации эквивалентно написанию с занятия:
/*
Complex::Complex(double _re, double _im) {
  re = re_;
  im = im_;
}
*/

Complex::Complex(double _re) : re(_re), im(0.0) {}

// указанное написание конструктора преобразования типа эквивалентно написанию с занятия:
/*
Complex::Complex(double _re) {
  re = _re;
  im = 0.0;
}
*/

Complex::~Complex() {
  re = 0.0;
  im = 0.0;
}

Complex& Complex::operator=(const Complex& c) {
  (*this).re = c.re;
  im = c.im;
  return *this;
}

bool Complex::operator==(const Complex& c) {
  if (c.re == re && c.im == im) return true;
  else return false;
}

bool Complex::operator!=(const Complex& c) {
  if (c.re != re || c.im != im) return true;
  else return false;
}

void Complex::output() {
  std::cout << re;
  if (im > 0) { std::cout << " + " << im << "i"; }
  else if (im < 0) { std::cout << " - " << -im << "i"; }
  std::cout << std::endl;
}

Complex Complex::Add(const Complex& c) {
  Complex res;
  res.re = re + c.re;
  res.im = im + c.im;
  return res;
}

Complex Complex::operator+(const Complex& c) {
  Complex res;
  res.re = re + c.re;
  res.im = im + c.im;
  return res;
}

Complex Complex::operator-(const Complex& c) {
  Complex res;
  res.re = re - c.re;
  res.im = im - c.im;
  return res;
}

Complex Complex::operator*(const Complex& c) {
  Complex res;
  res.re = re * c.re - im * c.im;
  res.im = re * c.im + im * c.re;
  /* тут ваш код */
  return res;
}

Complex Complex::operator/(const Complex& c) {
  Complex res;
  if (c.re == 0 && c.im == 0) {
	  std::cout << "Error: division by 0" << std::endl;
	  res = -1;
  }
  else
  {
	  res.re = (re * c.re + im * c.im) / (pow(c.re, 2) + pow(c.im, 2));
	  res.im = (c.re * im - re * c.im) / (pow(c.re, 2) + pow(c.im, 2));
  }
  return res;
}

Complex operator+(double d, const Complex& c) {
  Complex res;
  res.re = d + c.re;
  res.im = c.im;
  return res;
}

Complex operator-(double d, const Complex& c) {
  Complex res;
  res.re = d - c.re;
  res.im = - c.im;
  return res;
}

Complex operator*(double d, const Complex& c) {
  Complex res;
  res.re = d * c.re;
  res.im = d * c.im;
  return res;
}

Complex operator/(double d, const Complex& c) {
  Complex res;
  if (c.re == 0 && c.im == 0) {
  std::cout << "Error: division by 0" << std::endl;
    res = -1;
  } else {
    res.re = (d * c.re) / (pow(c.re, 2) + pow(c.im, 2));
    res.im = -(d * c.im) / (pow(c.re, 2) + pow(c.im, 2));
  }
  return res;
}

std::ostream& operator<<(std::ostream& stream, const Complex& c) {
  stream << c.re;
  if (c.im > 0) { stream << " + " << c.im << "i"; }
  else if (c.im < 0) { stream << " - " << -c.im << "i"; }
  return stream;
}

std::istream& operator>>(std::istream& stream, Complex& c) {
  stream >> c.re >> c.im;
  return stream;
}

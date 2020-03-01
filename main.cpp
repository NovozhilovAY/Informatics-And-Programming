#include <iostream>
#include <fstream>
#include <clocale>
#include "complex.h"

int main() {
  setlocale(LC_CTYPE, "Russian");

  Complex c0;
  Complex c1(1.0, 2.0);
  Complex c2(3.3, -4.4);
  Complex c3(c1);
  Complex c4(3.3);

  Complex *pc0 = new Complex();
  Complex *pc1 = new Complex(1.0, 2.0);
  Complex *pc3 = new Complex(c1);
  Complex *pc4 = new Complex(3.3);

  std::cout << "Число, созданное конструктором по умолчанию: с0 = " << c0 << std::endl;
  std::cout << "Число, созданное конструктором инициализации: с1 = " << c1 << std::endl;
  std::cout << "Число, созданное конструктором инициализации: с2 = " << c2 << std::endl;
  std::cout << "Число, созданное конструктором копирования: с3 = " << c3 << std::endl;
  std::cout << "Число, созданное конструктором преобразования типа: с4 = " << c4 << std::endl;

  std::cout << "Вывод с помощью функции output: с4 = ";
  c4.output();

  Complex c5;
  c5 = c2;
  std::cout << "Результат применения присваивания c2 новой переменной: с5 = " << c5 << std::endl;

  Complex c6;
  c6 = c3.Add(c2);
  std::cout << "Результат сложения функцией сложения: с6 = c3 + c2 = " << c6 << std::endl;

  Complex c7;
  c7 = c3 + c2;
  std::cout << "Результат сложения с помощью перегруженного оператора: c7 = c3 + c2 = " << c7 << std::endl;

  Complex c8;
  c8 = c3 - c2;
  std::cout << "Результат сложения с помощью перегруженного оператора: c8 = c3 - c2 = " << c8 << std::endl;

  Complex c9;
  c9 = c3 * c2;
  std::cout << "Результат сложения с помощью перегруженного оператора: c9 = c3 * c2 = " << c9 << std::endl;

  Complex c10;
  c10 = c3 / c2;
  std::cout << "Результат сложения с помощью перегруженного оператора: c10 = c3 / c2 = " << c10 << std::endl;

  Complex c7_;
  c7_ = 5.0 + c1;
  std::cout << "Результат сложения с помощью перегруженного оператора: c7_ = 5.0 + c1 = " << c7_ << std::endl;

  Complex c8_;
  c8_ = 5.0 - c1;
  std::cout << "Результат сложения с помощью перегруженного оператора: c8_ = 5.0 - c1 = " << c8_ << std::endl;

  Complex c9_;
  c9_ = 5.0 * c1;
  std::cout << "Результат сложения с помощью перегруженного оператора: c9_ = 5.0 * c1 = " << c9_ << std::endl;

  Complex c10_;
  c10_ = 5.0 / c1;
  std::cout << "Результат сложения с помощью перегруженного оператора: c10_ = 5.0 / c1 = " << c10_ << std::endl;

  Complex c7__;
  c7__ = c1 + 5.0;
  std::cout << "Результат сложения с помощью перегруженного оператора: c7_ = c1 + 5.0 = " << c7__ << std::endl;

  Complex c8__;
  c8__ = c1 - 5.0;
  std::cout << "Результат сложения с помощью перегруженного оператора: c8_ = c1 - 5.0 = " << c8__ << std::endl;

  Complex c9__;
  c9__ = c1 * 5.0;
  std::cout << "Результат сложения с помощью перегруженного оператора: c9_ = c1 * 5.0 = " << c9__ << std::endl;

  Complex c10__;
  c10__ = c1 / 5.0;
  std::cout << "Результат сложения с помощью перегруженного оператора: c10_ = c1 / 5.0 = " << c10__ << std::endl;

  if (c1 == c3) {
    std::cout << "Перегруженный опрератор == говорит, что с1 равно с3" << std::endl;
  }

  if (c1 != c10) {
    std::cout << "Перегруженный опрератор != говорит, что с1 не равно с10" << std::endl;
  }

  Complex c11;
  std::cout << "Пытаемся разделить на 0. Результат:" << std::endl;
  c11 = c3 / c0;
  std::cout << "c10 = c3 / c0 = " << c11 << std::endl;

  delete pc0;
  delete pc1;
  delete pc3;
  delete pc4;

  Complex t1(10, 5);
  Complex t2(10, 10);
  Complex t3;
  t3 = t1 / t2;
  std::cout << t3 << std::endl;
  std::cout << t1 * t2 << std::endl;
  std::cout << "Созданные указатели были удалены без ошибок" << std::endl;

  system("pause");
  return 0;
}

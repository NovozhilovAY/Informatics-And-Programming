# Informatics-And-Programming
Репозиторий, предназначенный для выполнения практических заданий по курсу Информатика и программирование

В рамках проекта разработанны следующие задачи:

## Ветка Time

Разработан класс Time для работы с временем, представленным в виде тройки hour ,min и sec.
Реализованный класс содержит:
    
	*все необходимые конструкторы (включая преобразования типа из строки вида “12:24:35”
и деструктор;
	
    *метод представления времени в виде строки: “12:24:35”;
	
В классе перегружены следующие операции:

    *присваивания;
	
    *сложения (и вычитания) времени с количеством секунд (переполнение результата «вверх»
или «вниз»  выполняtn переход на следующие или предыдущие сутки с
«отбрасываем» количества суток );
	
    *сравнения;
	
    *операция ввода/вывода в поток.
	
Также проведена проверка реализованных конструкторов, деструктора,
функций и перегруженных операторов. Добавлен пример использования
разработанного класса.
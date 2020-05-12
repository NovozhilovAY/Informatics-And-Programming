# Informatics-And-Programming
Репозиторий, предназначенный для выполнения практических заданий по курсу Информатика и программирование

В рамках проекта разработанны следующие задачи:

## Ветка TicketOffice
Класс Билетная касса имитирует работу кассы по продаже билетов на киносеансы
в многозальном кинотеатре. Продажа билетов проводится на сеансы в пределах трех
дней от текущей даты. Каждый сеанс описывается датой, временем начала сеанса, названием
фильма, номером зала, стоимостью билета в зависимости от зоны (VIP и обычная). Покупатель указывает тип зоны и требуемое число билетов, а места выделяются
кассой автоматически (при наличии свободных). Зрительные места в каждом зале описываются
номером ряда и номером в ряду. Число мест во всех рядах в одном
зале одинаково. Продажа билетов на сеанс прекращается через 10 минут после начала сеанса.
Информация о всех сеансах на ближайшие 30 дней проката хранится в классе Кинотеатр.
Для каждого зала установлена базовая стоимость билетов (на дневные сеансы – от 12.00 до
18.00). Стоимость билетов на утренние сеансы (до 12.00) составляет 75% от базовой, стоимость
билетов на вечерние сеансы (после 18.00) – 150% от базовой. Информация о зрительных местах
(свободно/занято) в каждом зале на каждом сеансе также хранится в классе Кинотеатр.
Класс Билетная касса предоставляет следующие операции: 
*1) принять заказ билетов покупателя: дату, время сеанса, название фильма, номер зала, тип зоны, число мест, 
*2) проверить наличие требуемого количества свободных мест в требуемой зоне
*3) зарезервировать требуемое количество мест
*4) рассчитать общую стоимость билетов
*5) отменить заказ билетов
*6)сформировать билеты (каждый билет включает: дату, время сеанса, название фильма, номер
зала, номер ряда, номер места в ряду).
#include <iostream>
#include <memory>

// 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. Перегрузите оператор вывода для данного класса.
// Создайте два "умных" указателя today и date. Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date, 
// а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
// Затем переместите ресурс, которым владеет указатель today в указатель date.Проверьте, являются ли нулевыми указатели today и date 
// и выведите соответствующую информацию об этом в консоль.

class Date
{
	private:
		int m_day = 1;
		int m_month = 1;
		int m_year = 1;
	public:
		
		Date(int day, int month, int year)
			: m_day(day), m_month(month), m_year(year) {}
		~Date() {}

		
		void setDay(int day) { m_day = day; }
		void setMonth(int month) { m_month = month; }
		void setYear(int year) { m_year = year; }

		int getDay() { return m_day; }
		int getMonth() { return m_month; }
		int getYear() { return m_year; }
		
		friend std::ostream& operator<< (std::ostream& out, const Date& date);
 };


std::ostream& operator<<(std::ostream& out, Date& date) {
	return out << '(' << date.getDay() << '.' << date.getMonth()
		<< '.' << date.getYear() << ')' << std::endl;
}

// 2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
// Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой(сравнение происходит по датам).
// Функция должна вернуть более позднюю дату.
// Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
// Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

void function1 (const std:: unique_ptr <Date>& date1, const std::unique_ptr <Date>& date2) {
	if ((date1->getYear()) > (date2->getYear())) {
		std::cout << *date1;
	}
	else if ((date1->getYear()) < (date2->getYear()))
		std::cout << *date2;
	else
		if ((date1->getMonth()) > (date2->getMonth()))
		{
			std::cout << *date1;
		}
		else if ((date1->getMonth()) < (date2->getMonth()))
			std::cout << *date2;
		else
			if ((date1->getDay()) > (date2->getDay()))
			{
				std::cout << *date1;
			}
			else if ((date1->getDay()) < (date2->getDay()))
				std::cout << *date2;
			else
				std::cout << "Dates are equal." << std::endl;

}

void function2(std::unique_ptr <Date>& date1, std::unique_ptr <Date>& date2) {

	std::unique_ptr<Date> temp = std::move(date1);
	date1 = std::move(date2);
	date2 = std::move(temp);
	std::cout << "Now date1 is ";
	std::cout << *date1;
	std::cout << "Now date2 is ";
	std::cout << *date2;

}

int main()
{
	// Task 1.

	std::cout << "Task 1" << std::endl;
	std::cout << '\n';
	std::unique_ptr <Date> u_date;
	std::unique_ptr <Date> u_today = std::make_unique<Date>(27, 3, 2021);
	u_today->getDay();
	u_today->getMonth();
	u_today->getYear();
	std::cout << "u_today is ";
	std::cout << *u_today;
	std::cout << '\n' << std::endl;

	u_date = std::move(u_today);
	std::cout << "Checking for nullptr."<<std::endl;
	if (u_today)
	{
		std::cout << "u_today is not nullptr" << std::endl;
		std::cout << *u_today;
	}
	else 
		std::cout << "u_today is nullptr" << std::endl;
	if (u_date)
	{
		std::cout << "u_date is not nullptr" << std::endl;
		std::cout << *u_date;
	}
	else
		std::cout << "u_date is null." << std::endl;

	// Task 2.

	std::cout << '\n'<< '\n';
	std::cout << "Task 2." << std::endl;
	std::cout << '\n';


	std::unique_ptr <Date> date1 = std::make_unique<Date>(27, 3, 2021);
	std::cout << "date1 is ";
	std::cout << *date1;
	std::unique_ptr <Date> date2 = std::make_unique<Date>(25, 3, 2022);
	std::cout << "date2 is ";
	std::cout << *date2;

	std::cout << '\n';
	std::cout << "Print function1:"<< std::endl;
	function1(date1, date2);
	
	std::cout << '\n';
	std::cout << "Print function2:" << std::endl;
	function2(date1, date2);

	return 0;
}


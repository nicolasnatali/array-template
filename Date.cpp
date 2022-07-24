#include "Date.h"

Date::Date() = default;

Date::Date(unsigned int year, unsigned int month, unsigned int day) : year(year), month(month), day(day) {}

[[maybe_unused]] void Date::setDate(unsigned int y, unsigned int m, unsigned int d) {
    if (isValid(y, m, d)) {
        setYear(y);
        setMonth(m);
        setDay(d);
    }
}

[[maybe_unused]] unsigned int Date::getYear() const {
    return year;
}

void Date::setYear(unsigned int y) {
    Date::year = y;
}

[[maybe_unused]] unsigned int Date::getMonth() const {
    return month;
}

void Date::setMonth(unsigned int m) {
    Date::month = m;
}

[[maybe_unused]] unsigned int Date::getDay() const {
    return day;
}

void Date::setDay(unsigned int d) {
    Date::day = d;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.day << " " << Date::getMonthName(date.month) << " " << date.year;
    return os;
}

bool Date::isValid(unsigned int year, unsigned int month, unsigned int day) {
    if ((month < 1 || month > 12) || (day < 1 || day > 31)) {
        return false;
    } else if (month == 2) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return (day <= 29);
        } else {
            return (day <= 28);
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return (day <= 30);
    } else {
        return true;
    }
}

std::string Date::getMonthName(unsigned int month) {
    std::array<std::string, 12> monthNames{
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
    };
    return monthNames[month - 1];
}

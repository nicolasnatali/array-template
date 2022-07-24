#ifndef ARRAY_TEMPLATE_DATE_H
#define ARRAY_TEMPLATE_DATE_H

#include <array>
#include <ostream>

class Date {
public:
    Date();

    Date(unsigned int year, unsigned int month, unsigned int day);

    [[maybe_unused]] void setDate(unsigned int y, unsigned int m, unsigned int d);

    [[maybe_unused]] [[nodiscard]] unsigned int getYear() const;

    void setYear(unsigned int y);

    [[maybe_unused]] [[nodiscard]] unsigned int getMonth() const;

    void setMonth(unsigned int m);

    [[maybe_unused]] [[nodiscard]] unsigned int getDay() const;

    void setDay(unsigned int d);

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

private:
    unsigned int year{1970};
    unsigned int month{1};
    unsigned int day{1};

    static bool isValid(unsigned int year, unsigned int month, unsigned int day);

    static std::string getMonthName(unsigned int month);
};

#endif //ARRAY_TEMPLATE_DATE_H

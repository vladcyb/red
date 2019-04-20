#pragma once

#include <string>
#include <ostream>
#include <tuple>
using namespace std;

#define DATE_ATTR(x)

struct Date {
    int year, month, day;
};

struct Time {
    int hours, minutes;
};

struct AirlineTicket {
    string from;
    string to;
    string airline;
    Date departure_date;
    Time departure_time;
    Date arrival_date;
    Time arrival_time;
    int price;
};

bool operator<(const Date& lhs, const Date& rhs){
    return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Date& lhs, const Date& rhs){
    return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

bool operator<(const Time& lhs, const Time& rhs){
    return tie(lhs.hours, lhs.minutes) < tie(rhs.hours, rhs.minutes);
}

bool operator==(const Time& lhs, const Time& rhs){
    return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);
}

ostream& operator<<(ostream& stream, const Time& t){
    return stream << t.hours << ":" << t.minutes;
}

ostream& operator<<(ostream& stream, const Date& d){
    return stream << d.year << "/" << d.month << "/" << d.day;
}
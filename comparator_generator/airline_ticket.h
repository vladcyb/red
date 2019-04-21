#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <tuple>
using namespace std;

struct Date {
    int year, month, day;
    // void operator=(const string& s){
    //
    // }
};

struct Time {
    int hours, minutes;
    // void operator=(const string& s){
    //     stringstream ss(s);
    //     ss >> hours;
    //     ss.ignore(1);
    //     ss >> minutes;
    // }
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

stringstream& operator>>(stringstream& stream, Date& d){
    stream >> d.year;
    stream.ignore(1);
    stream >> d.month;
    stream.ignore(1);
    stream >> d.day;
    return stream;
}

stringstream& operator>>(stringstream& stream, Time& t){
    stream >> t.hours;
    stream.ignore(1);
    stream >> t.minutes;
    return stream;
}
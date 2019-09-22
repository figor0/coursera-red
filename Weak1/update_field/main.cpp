#include "airline_ticket.h"
#include "test_runner.h"
#include <map>
#include <string>
#include <iterator>

using namespace std;

bool operator<(const Time& lhs, const Time& rhs)
{
	if ( lhs.hours == rhs.hours)
		return lhs.minutes < rhs.minutes;
	else
		return lhs.hours < rhs.hours;
}

bool operator==(const Time& lhs, const Time& rhs)
{
	return (lhs.hours == rhs.hours) && (lhs.minutes == rhs.minutes);
}

ostream& operator<<(ostream& reader, const Time& time){
	reader << time.hours << ' ' << time.minutes;
	return reader;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if ( lhs.year == rhs.year){
		if (lhs.month == rhs.month)
			return lhs.day < rhs.day;
		else
			return lhs.month < rhs.month;
	} else
		return lhs.year < rhs.year;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day);
}

ostream& operator<<(ostream& reader, const Date& date)
{
	reader << date.year << ' ' << date.month << ' ' << date.day;
	return reader;
}

istream& operator>>(istream& filler, Date& date){
	char need = '-';
	bool ok = true;

	ok = ok && (filler >> date.year);
	ok = ok && (filler.peek() == need);
	filler.ignore(1);

	ok = ok && (filler >> date.month);
	ok = ok && (filler.peek() == need);
	filler.ignore(1);

	ok = ok && (filler >> date.day);
	ok = ok && filler.eof();
	if (!ok) {
		throw std::logic_error("Wrong date format");
	}
	return filler;
}

istream& operator>>(istream& filler, Time& time){
	char need = ':';
	bool ok = true;

	ok = ok && (filler >> time.hours);
	ok = ok && (filler.peek() == need);
	filler.ignore(1);

	ok = ok && (filler >> time.minutes);
	ok = ok && filler.eof();
	if (!ok) {
		throw std::logic_error("Wrong date format");
	}
	return filler;
}

#define UPDATE_FIELD(ticket, field, values)		\
{																							\
	map<string, string>::const_iterator it; 		\
	it = values.find(#field);											\
	if( it != values.end() ){	 										\
		istringstream filler(it->second); 					\
		filler >> ticket.field; 											\
	}																						\
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}

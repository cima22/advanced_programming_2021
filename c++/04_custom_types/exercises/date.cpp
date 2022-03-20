#include <iostream>

enum class months {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class Date {
 unsigned int _day;
 months _month;
 unsigned int _year;

 public:

 Date(unsigned int d, months m, unsigned int y)
 : _day{d}, _month{m}, _year{y}{}

  unsigned int day() const  {return _day;}

  enum months month() const {return _month;}

  unsigned int year() const {return _year;}

  void add_days(const unsigned int n){
   for(auto i = 0u; i < n; i++)
    add_day();
  }

  private:
   void add_day();
};

void Date::add_day(){
 unsigned int lim;
 switch(_month){
  case months::apr: case months::jun: case months::sep: case months::nov: 
   lim = 30;
   break;

  case months::feb:
   lim = 28;
   break;

  default:
   lim = 31;
   break;
 }

 if(_day + 1 > lim){
  _year = _month == months::dec ? _year + 1 : _year;
  _month = _month == months::dec ? months::jan : months(static_cast<int>(_month) + 1);
  _day = 1;
  return;
 }

 _day+=1;

}

int main(){

 Date d{1,months::jan,2022};

for(auto i = 0u; i < 365; i+=30){
 d.add_days(i);
 std::cout << "Day = " << d.day() << ", month = " << static_cast<int>(d.month()) << ", year = " << d.year() << std::endl;
}

return 0;
}

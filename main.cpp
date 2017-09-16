#include <iostream>
#include <string>

using namespace std;

class Week {
private:
    string days_week[7];
    string day;
public:
    Week();

    void EnterDay();

    void set();

    int check();

    void print(int c);

    string prev_day();

    string next_day();

    string add(int a);
};

int main() {
    Week a;
    int num;
    a.EnterDay();
    int b = a.check();
    cout << "Enter number of days you want to add: " << endl;
    cin >> num;
    a.print(b);
    cout << "The previous day of the week is: " << a.prev_day() << endl;
    cout << "The next day of the week is: " << a.next_day() << endl;
    cout << "The added day is: " << a.add(num) << endl;
    return 0;
}

void Week::EnterDay() {
    cout << "Enter day of the week";
    cin >> day;
}

void Week::set() {
    days_week[0] = "Monday";
    days_week[1] = "Tuesday";
    days_week[2] = "Wednesday";
    days_week[3] = "Thursday";
    days_week[4] = "Friday";
    days_week[5] = "Saturday";
    days_week[6] = "Sunday";

}

int Week::check() {
    for (int i = 0; i < 7; i++)
        if (day == days_week[i]) {
            return i;
        }

}

void Week::print(int c) {
    cout << "The day of the week is: " << day << endl;

}

string Week::prev_day() {
    int i = 0;
    for (i = 0; i < 7; i++) {
        if (day == days_week[i]) {
            if (i == 0) {
                return days_week[6];

            } else
                return days_week[i - 1];
        }

    }
}

Week::Week() {
    set();
}

string Week::next_day() {
    int i = 0;
    for (i = 0; i < 7; i++) {
        if (day == days_week[i]) {
            if (i == 6) {
                return days_week[0];

            } else
                return days_week[i + 1];
        }

    }
}

string Week::add(int a) {
    int rem;
    int final;
    rem = abs(a);
    rem = rem % 7;
    //cout << rem << endl;
    if (a < 0) {

        rem = 7 - rem;
    } else {
        rem = rem;
        //rem = abs(rem);
    }
   // cout << rem;
    final = check() + rem;
    if (final < 7)
        return days_week[final];

    if (final >= 7) {
        final = (check() + rem) % 7;
        return days_week[final];
    }
}
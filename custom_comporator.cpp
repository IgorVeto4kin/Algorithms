#include <bits/stdc++.h> 
#define ll long long
using namespace std;
struct Date {
    int year = 1970;
    int month = 1;
    int day = 1;
};
int oper (const Date& v1, const Date& v2) {
    if (v1.year != v2.year) {
        return v1.year - v2.year;
    }
    if (v1.month != v2.month) {
        return v1.month - v2.month;
    }
    return v1.day - v2.day;
}
int cmp(const void* a, const void* b) {
    const Date& date1 = *(const Date*)a;
    const Date& date2 = *(const Date*)b;
    return oper(date1, date2);
}


 
int main() {
    vector<Date> dates = {
        {2020, 3, 15},
        {2019, 1, 21},
        {2021, 1, 30}
    };
    void * elem1 = &dates[0];
    for (int i = 0; i< dates.size(); i++){
        cout<<dates[i].day<<" "<<dates[i].month<<" "<<dates[i].year<<"\n";
    }
    //cout<<elem1<<endl;
    qsort(elem1, dates.size(), sizeof(Date), cmp);
    //sort(dates.begin() , dates.end());
    // напечатаем содержимое:
    for (const auto& [year, month, day] : dates) {
        //cout << year << "." << month << "." << day << "\n";
    }
    for (int i = 0; i< dates.size(); i++){
        cout<<dates[i].day<<" "<<dates[i].month<<" "<<dates[i].year<<"\n";
    }
}

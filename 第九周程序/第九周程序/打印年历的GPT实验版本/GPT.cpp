#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// 使用Zeller公式计算给定日期的星期
int zeller(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int c = y / 100;
    y %= 100;
    int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
    return (w % 7 + 7) % 7;  // 确保结果为非负数
}

// 打印星期标题头
void printMonthHeaders() {
    cout << "Sun Mon Tue Wed Thu Fri Sat     ";
}

// 打印三个月的标题头
void printQuarterHeader(int startMonth) {
    for (int i = 0; i < 3; i++) {
        cout << "           " << setw(2) << setfill(' ') << startMonth + i << "月";
        if (i < 2) cout << "                           ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        printMonthHeaders();
    }
    cout << endl;
}

// 假设recordCalendar函数的实现已经存在，用于打印日历的每个月的具体日期
int daysInMonth(int year, int month) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        return 29;
    }
    return days[month - 1];
}

void recordCalendar(int year, int month1, int month2, int month3, int day1, int day2, int day3) {
    int n1 = daysInMonth(year, month1);
    int n2 = daysInMonth(year, month2);
    int n3 = daysInMonth(year, month3);

    int record[7][24] = {}; // Initialize all to zero
    int offsets[3] = { 0, 8, 16 }; // Offset for each month in the record grid
    int days[3] = { day1, day2, day3 };
    int months[3] = { n1, n2, n3 };

    // Fill calendar data for each month
    for (int m = 0; m < 3; m++) {
        int r = 1; // Start from the first row for each month
        for (int i = 1; i < days[m] + 1; i++) {
            record[1][i + offsets[m]] = 666; // Fill empty spaces before the first day
        }
        for (int i = 1; i <= months[m]; i++) {
            record[r][days[m] + 1 + offsets[m]] = i;
            if (days[m] == 6) {
                record[r][days[m] + 2 + offsets[m]] = 666; // Fill the space after Saturday
                r++;
            }
            days[m] = (days[m] + 1) % 7;
        }
    }

    // Output the calendar
    for (int i = 1; i <= 6; i++) { // Assume maximum 6 rows needed
        for (int j = 1; j < 24; j++) {
            if (record[i][j] == 666 || record[i][j] == 0)
                cout << setiosflags(ios::left) << setw(4) << " ";
            else
                cout << setiosflags(ios::left) << setw(4) << record[i][j];
            if (j == 23)
                cout << endl;
        }
    }
}

int main() {
    system("mode con cols=120 lines=45");
    int year;
    while (true) {
        cout << "请输入年份[1900-2100]: ";
        cin >> year;
        if (cin.fail() || year < 1900 || year > 2100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "无效输入，请输入1900至2100之间的年份。\n";
        }
        else {
            break;
        }
    }

    cout << year << "年的日历:\n\n";
    int week[13];  // 存储每月的起始星期

    for (int quarter = 1; quarter <= 4; quarter++) {
        int startMonth = (quarter - 1) * 3 + 1;
        printQuarterHeader(startMonth);
        for (int i = 0; i < 3; i++) {
            week[startMonth + i] = zeller(year, startMonth + i, 1);
        }
        recordCalendar(year, startMonth, startMonth + 1, startMonth + 2, week[startMonth], week[startMonth + 1], week[startMonth + 2]);
        cout << endl;
    }

    return 0;
}


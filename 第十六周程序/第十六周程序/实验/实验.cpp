#include <iostream>
#include <cstring>
#include <cwchar>
using namespace std;

int main() {
    /*
    int width = 20;
    int judge = 0;
    const char* title = "²Ëµ¥Ñ¡Ïî1";
    int l = strlen(title);
    if (l % 2 == 1) {
        judge = 1;
        l = l + 1;
    }
    cout << "¨X";
    for (int i = 1; i <= (width - l) / 4; i++) {
        cout << "¨T";
    }
    cout << title;
    if (judge == 1)
        cout << " ";
    for (int i = 1; i <= (width - l) / 4; i++) {
        cout << "¨T";
    }
    cout << "¨[" << endl;

    cout << "¨^";
    for (int i = 1; i <= width / 2; i++) {
        cout << "¨T";
    }
    cout << "¨a";
    */
    char c = 0xA1;
    cout << int(c);
}
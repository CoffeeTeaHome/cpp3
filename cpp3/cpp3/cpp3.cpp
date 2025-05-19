#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <random>
#include <locale>


using namespace std;

void guessTheNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    int secretNumber = distrib(gen);
    int guess;
    int attempts = 0;

    cout << "Добро пожаловать в игру 'Угадай число'!" << endl;

    while (true) {
        cout << "Введите число от 1 до 100: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите число." << endl;
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            cout << "Загаданное число больше." << endl;
        }
        else if (guess > secretNumber) {
            cout << "Загаданное число меньше." << endl;
        }
        else {
            cout << "Поздравляю! Вы угадали число за " << attempts << " попыток." << endl;
            break;
        }
    }
}

void storyGenerator() {
    vector<string> heroes = { "смелый рыцарь", "хитрый вор", "волшебник", "отважный пират", "дерзкий исследователь" };
    vector<string> places = { "в далёком королевстве", "на заброшенной фабрике", "в густом лесу", "на просторах космоса", "у подножия гор" };
    vector<string> actions = { "победил дракона", "обнаружил сокровища", "выиграл битву", "устроил бал", "раскрыл древнюю тайну" };
    vector<string> details = { "с волшебным мечом", "на летающем ковре", "под звуки волшебной музыки", "с удивительной силой", "в сопровождении магического существа" };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, heroes.size() - 1);

    string story = heroes[distrib(gen)] + " " + places[distrib(gen)] + ", " + actions[distrib(gen)] + " " + details[distrib(gen)] + ".";

    cout << "\nСгенерированная история:\n" << story << endl;

    char saveChoice;
    cout << "Сохранить историю в файл (stories.txt)? (Y/N): ";
    cin >> saveChoice;

    if (saveChoice == 'Y' || saveChoice == 'y') {
        ofstream outFile("stories.txt", ios::app);
        if (outFile.is_open()) {
            outFile << story << "\n";
            outFile.close();
            cout << "История сохранена в файл stories.txt" << endl;
        }
        else {
            cout << "Ошибка открытия файла!" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    while (true) {
        cout << "\nВыберите игру:" << endl;
        cout << "1. Угадай число" << endl;
        cout << "2. Генератор историй" << endl;
        cout << "3. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            guessTheNumber();
        }
        else if (choice == 2) {
            storyGenerator();
        }
        else if (choice == 3) {
            cout << "Выход из программы." << endl;
            break;
        }
        else {
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }

    return 0;
}

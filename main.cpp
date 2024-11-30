#include "Logger.h" // Naglówek Loggera, odpowiedzialny za zarzadzanie logami
#include <iostream> // Do obslugi wejscia i wyjscia

int main() {
    // Pobieramy jedyna instancje Loggera (Singleton)
    Logger* logger = Logger::getInstance();

    int choice; // Zmienna do przechowywania wyboru uzytkownika

    // Glówna petla programu
    do {
        // Wyswietlamy menu dla uzytkownika
        std::cout << "1. Add log\n2. Show logs\n3. Exit\nChoose an option: ";
        std::cin >> choice; // Pobieramy wybór od uzytkownika

        if (choice == 1) {
            // Obsluga opcji dodania nowego logu
            std::string type, message;
            std::cout << "Enter log type (1.Info 2.Warning 3.Error): ";
            std::cin >> type; // Pobieramy typ logu jako string (dla obslugi nieprawidlowych wartosci)
            std::cin.ignore(); // Ignorujemy znak nowej linii, aby umozliwic poprawne wczytanie wiadomosci
            std::cout << "Enter message: ";
            std::getline(std::cin, message); // Pobieramy tresc wiadomosci

            // Konwertujemy typ logu na liczbe calkowita i dodajemy log
            logger->logMessage(stoi(type), message);
        } else if (choice == 2) {
            // Obsluga opcji wyswietlenia wszystkich logów
            logger->showLogs();
        } else if (choice != 3) {
            // Obsluga nieprawidlowego wyboru
            std::cout << "Nie rozumiem" << std::endl;
        }
    } while (choice != 3); // Konczymy program, gdy uzytkownik wybierze opcje 3

    return 0; // Zwracamy 0, oznaczajac poprawne zakonczenie programu
}

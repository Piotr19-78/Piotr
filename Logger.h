#ifndef LOGGER_H
#define LOGGER_H

#include "Log.h"        // Bazowa klasa dla logów
#include "LogFactory.h" // Fabryka logów do tworzenia obiektów logów
#include <vector>       // Kontener do przechowywania logów
#include <memory>       // Wskazniki inteligentne
#include <iostream>     // Obsluga wejscia i wyjscia (std::cout, std::cerr)

// Klasa Logger - Singleton do zarzadzania logami
class Logger {
    // Statyczne pole przechowujace jedyna instancje klasy Logger
    static Logger* instance;

    // Wektor przechowujacy wskazniki do logów
    std::vector<std::unique_ptr<Log>> logs;

    // Prywatny konstruktor - zapobiega tworzeniu obiektów klasy Logger poza nia
    Logger() = default;

public:
    // Metoda statyczna zapewniajaca dostep do jedynej instancji Loggera
    static Logger* getInstance() {
        // Jesli instancja nie istnieje, utwórz ja
        if (!instance) instance = new Logger();
        return instance;
    }

    // Metoda dodajaca nowy log
    // type: Typ logu (1 = Info, 2 = Warning, 3 = Error)
    // message: Tresc logu
    void logMessage(const int& type, const std::string& message) {
        try {
            // Tworzy log za pomoca fabryki i dodaje go do wektora
            logs.push_back(LogFactory::createLog(type, message));
        } catch (const std::invalid_argument& e) {
            // Obsluguje wyjatek w przypadku nieprawidlowego typu logu
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    // Metoda wyswietlajaca wszystkie przechowywane logi
    void showLogs() const {
        std::cout << "=== Przechowywane logi ===" << std::endl;
        for (const auto& log : logs) {
            // Wywoluje getMessage dla kazdego logu
            std::cout << log->getMessage() << "\n";
        }
        std::cout << "======== KONIEC =========" << std::endl << std::endl;
    }

    // Zabrania kopiowania obiektów klasy Logger
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

// Definicja statycznego pola instancji Loggera
Logger* Logger::instance = nullptr;

#endif // LOGGER_H

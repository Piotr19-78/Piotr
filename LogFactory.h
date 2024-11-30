#ifndef LOGFACTORY_H
#define LOGFACTORY_H

#include "Log.h"       // Naglówek zawierajacy definicje klas logów (InfoLog, WarningLog, ErrorLog)
#include <memory>      // Biblioteka do pracy ze wskaznikami inteligentnymi (std::unique_ptr)
#include <stdexcept>   // Biblioteka do obslugi wyjatków (std::invalid_argument)

// Klasa LogFactory - fabryka logów
// Odpowiada za tworzenie obiektów logów na podstawie typu i wiadomosci
class LogFactory {
public:
    // Statyczna metoda fabrykujaca
    // Przyjmuje:
    // - type: Typ logu (1 = Info, 2 = Warning, 3 = Error)
    // - message: Tresc logu
    // Zwraca wskaznik std::unique_ptr na obiekt klasy Log
    static std::unique_ptr<Log> createLog(const int& type, const std::string& message) {
        // Jesli typ to 1, zwróc obiekt InfoLog
        if (type == 1) return std::make_unique<InfoLog>(message);

        // Jesli typ to 2, zwróc obiekt WarningLog
        if (type == 2) return std::make_unique<WarningLog>(message);

        // Jesli typ to 3, zwróc obiekt ErrorLog
        if (type == 3) return std::make_unique<ErrorLog>(message);

        // Jesli typ jest nieznany, rzuc wyjatek std::invalid_argument
        throw std::invalid_argument("Unknown log type");
    }
};

#endif // LOGFACTORY_H

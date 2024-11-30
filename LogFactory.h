#ifndef LOGFACTORY_H
#define LOGFACTORY_H

#include "Log.h"       // Nagl�wek zawierajacy definicje klas log�w (InfoLog, WarningLog, ErrorLog)
#include <memory>      // Biblioteka do pracy ze wskaznikami inteligentnymi (std::unique_ptr)
#include <stdexcept>   // Biblioteka do obslugi wyjatk�w (std::invalid_argument)

// Klasa LogFactory - fabryka log�w
// Odpowiada za tworzenie obiekt�w log�w na podstawie typu i wiadomosci
class LogFactory {
public:
    // Statyczna metoda fabrykujaca
    // Przyjmuje:
    // - type: Typ logu (1 = Info, 2 = Warning, 3 = Error)
    // - message: Tresc logu
    // Zwraca wskaznik std::unique_ptr na obiekt klasy Log
    static std::unique_ptr<Log> createLog(const int& type, const std::string& message) {
        // Jesli typ to 1, zwr�c obiekt InfoLog
        if (type == 1) return std::make_unique<InfoLog>(message);

        // Jesli typ to 2, zwr�c obiekt WarningLog
        if (type == 2) return std::make_unique<WarningLog>(message);

        // Jesli typ to 3, zwr�c obiekt ErrorLog
        if (type == 3) return std::make_unique<ErrorLog>(message);

        // Jesli typ jest nieznany, rzuc wyjatek std::invalid_argument
        throw std::invalid_argument("Unknown log type");
    }
};

#endif // LOGFACTORY_H

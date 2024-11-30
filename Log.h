#ifndef LOG_H
#define LOG_H

#include <string> // Biblioteka standardowa do pracy z ciagami znaków

// Bazowa klasa Log - definiuje interfejs dla róznych typów logów
class Log {
public:
    virtual ~Log() = default; // Wirtualny destruktor, aby obsluzyc poprawne niszczenie obiektów dziedziczacych
    virtual std::string getMessage() const = 0; // Czysto wirtualna metoda zwracajaca wiadomosc logu
};

// Klasa reprezentujaca log typu "INFO"
class InfoLog : public Log {
    std::string message; // Przechowuje wiadomosc logu
public:
    // Konstruktor ustawia wiadomosc logu z prefiksem "INFO: "
    explicit InfoLog(const std::string& msg) : message("INFO: " + msg) {}
    
    // Implementacja metody getMessage, która zwraca wiadomosc
    std::string getMessage() const override { return message; }
};

// Klasa reprezentujaca log typu "WARNING"
class WarningLog : public Log {
    std::string message; // Przechowuje wiadomosc logu
public:
    // Konstruktor ustawia wiadomosc logu z prefiksem "WARNING: "
    explicit WarningLog(const std::string& msg) : message("WARNING: " + msg) {}
    
    // Implementacja metody getMessage, która zwraca wiadomosc
    std::string getMessage() const override { return message; }
};

// Klasa reprezentujaca log typu "ERROR"
class ErrorLog : public Log {
    std::string message; // Przechowuje wiadomosc logu
public:
    // Konstruktor ustawia wiadomosc logu z prefiksem "ERROR: "
    explicit ErrorLog(const std::string& msg) : message("ERROR: " + msg) {}
    
    // Implementacja metody getMessage, która zwraca wiadomosc
    std::string getMessage() const override { return message; }
};

#endif // LOG_H

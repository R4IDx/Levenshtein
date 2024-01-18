#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "levenshteinDistance.h"

// Sicherstellung von einmaligem Einfuegen im Programm
#ifndef cards_H
#define cards_H

using namespace std;

// Aufgabe 2

// Erstellen der Klasse cards
class cards
{   public:
        // set-Funktionen
        void setName(string name) { m_name = name; }
        void setMana(string mana) { m_mana = mana; }
        void setCmc(int cmc) { m_cmc = cmc; }
        void setType(string type) { m_type = type; }
        void setCount(int count) { m_count = count; }

        // get-Funktionenn
        string getName() { return m_name; }
        string getMana() { return m_mana; }
        int getCmc() { return m_cmc; }
        string getType() { return m_type; }
        int getCount() { return m_count; }

        // Funktionen
        static vector<string> readNameFromReference(string fileName);
        static void restoreCardName(); // Aufgabe 6
        static void repairStatus(); // Kontrollausgabe
    private:
        // Variablen der Klasse
        string m_name;
        string m_mana;
        int m_cmc;
        string m_type;
        int m_count;
};
#endif
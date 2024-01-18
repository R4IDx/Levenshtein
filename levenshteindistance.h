#include <string>
#include <algorithm>

#ifndef CSTRINGMETRICS_H // Sicherstellung von einmaligem Einfuegen im Programm
#define CSTRINGMETRICS_H

using namespace std;

// Aufgabe 1

class stringMetrics
{   public:
    static int levenshteinDistance(string s, string t); // Definieren der Levenshtein-Distanz in der Klasse stringMetrics
};

#endif
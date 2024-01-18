#include <fstream>
#include <vector>
#include "cards.h"

using namespace std;

class fileOperations {  // Klasse enthaelt alle Methoden zur Arbeit mit einem File
public:
    static void writeRepairedCards(string fileName, cards card, string repairedName); // Aufgabe 4 bzw. 7
    static vector<cards> readCards(const string& fileName); // Aufgabe 3
};
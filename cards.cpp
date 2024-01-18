#include "cards.h"
#include "fileOperations.h"

//hashdefines für dateipfade
#define PATH_SCRAMBLED "scrambled.txt"
#define PATH_REPAIRED "repairedCards.txt"
#define PATH_REFERENCE "reference.txt"

using namespace std;


// Aufgabe 5

vector<string> cards::readNameFromReference(string fileName)
{   vector<string> cardNames;
    string line;

    // Oeffnen des Files
    ifstream file(fileName);
    // Fehlerhandling
    if (!file.is_open())
    {   cout << "Fehler beim Oeffnen des Files" << fileName << '\n';
        exit(1);
    }
    // Speichern der ausgelesenen Namen im Vektor (Zeile für Zeile)
    while (getline(file, line))
    {   cardNames.push_back(line);  }
    return cardNames; // Zurueckgeben des Vektors mit den Kartenamen aus der Referenzliste
}



void cards::restoreCardName()
{   // Die Inhalte der Files in Listen packen
    vector<cards> scrambledNames = fileOperations::readCards(PATH_SCRAMBLED);
    vector<string> referenceNames = readNameFromReference(PATH_REFERENCE);

    int wordLenght;
    int levenshteindistance;

    // Schleife um durch die scrambledNames-Liste zu gehen
    for (int i = 0; i < scrambledNames.size(); i++)
    {   // Schleife um durch die referenceNames-Liste zu gehen
        for (int j = 0; j < referenceNames.size(); j++)
        {   wordLenght = scrambledNames[i].getName().length();
            levenshteindistance = stringMetrics::levenshteinDistance(scrambledNames[i].getName(), referenceNames[j]);

            // Berechnung, um die richtige Version des Wortes zu finden
            if (levenshteindistance <= 0.2675 * wordLenght)
            {   // Aufruf fuer Aufgabe 7
                fileOperations::writeRepairedCards(PATH_REPAIRED, scrambledNames[i], referenceNames[j]);
                break;
            }
        }
    }
}

// Ausgabe der Anzahl der reparierten Karten + Karten gesamt
void cards::repairStatus()
{   vector<cards> scrambledCards = fileOperations::readCards(PATH_SCRAMBLED);
    vector<cards> repairedCards = fileOperations::readCards(PATH_REPAIRED);
    cout << "Es wurden " << repairedCards.size() << " Namen repariert. Das Kartendeck besteht aus " << scrambledCards.size() << " Karten.";
}
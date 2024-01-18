#include "fileOperations.h"

// Aufgabenteil 3

// Funktion zum Auslesen der Text-Files
vector<cards> fileOperations::readCards(const string& fileName)
{   // Liste zum Zurueckgeben
    vector<cards> cardList;
    ifstream cardFile(fileName);
    if (cardFile.is_open())
    {   string line;
        while (getline(cardFile, line)) // Solange nicht am Ende des Files
        {   cards card;
            int index = 0;
            size_t first = 0;
            size_t last = line.find_first_of("|");
            while (last != string::npos)
            {   switch (index) // abhaengig von index wird in die jenigen Variablen geschrieben
                    {   case 0:
                            card.setName(line.substr(first, last - first));
                            break;
                        case 1:
                            card.setMana(line.substr(first, last - first));
                            break;
                        case 2:
                            card.setCmc(stoi(line.substr(first, last - first)));
                            break;
                        case 3:
                            card.setType(line.substr(first, last - first));
                            break;
                    }
                first = last + 1;
                last = line.find_first_of("|", first);
                index++;
            }   card.setCount(stoi(line.substr(first, last - first))); // alles nach dem letzten Trennungszeichen
                cardList.push_back(card);
        }   cardFile.close();
    }   // Fehlerhandling
    else {
        cout << "Fehler beim Oeffnen des Files " << fileName << '\n';
        exit(1);
    }
    return cardList;
}

// Aufgabenteil 4

void fileOperations::writeRepairedCards(string fileName, cards card, string repairedName)
{   // Name der Karte wird geaendert
    card.setName(repairedName);

    // Variablen der Karte
    string name = card.getName();
    string mana = card.getMana();
    int cmc = card.getCmc();
    string type = card.getType();
    int count = card.getCount();

    // Oeffnen des Files
    ofstream file;
    file.open(fileName, ios::app); // beginnt am Ende des Files, damit es nicht ueberschreibt
    // Schreiben in das File
    file << name << "|" << mana << "|" << cmc << "|" << type << "|" << count << '\n';
    // Schliessen des Files
    file.close();
    // Fehlerhandling
    if (file.fail())
    {   cout << "Fehler beim Schliessen des Files " << fileName << '\n';
        exit(1);
    }
}
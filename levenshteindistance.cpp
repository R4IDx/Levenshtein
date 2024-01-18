#include "levenshteinDistance.h"

// Aufgabe 1

int stringMetrics::levenshteinDistance(string s, string t)  {
        int n = s.length(); // Laenge von s und t als n und m
        int m = t.length();
        int M[n + 1][m + 1]; // Matrix für die Ausfuehrung des Algorithmus
        for (int i = 0; i <= n; i++) // Fuellt erste Spalte und erste Zeile mit 1 bis n+1, bzw. m+2
        {   M[i][0] = i;    }
        for (int j = 0; j <= m; j++)
        {   M[0][j] = j;    }
        for (int i = 1; i <= n; i++) // Fuehrt Schritt 2 des Algorithmus durch, iteriert durch die leeren Eintraege der Matrix
        {   for (int j = 1; j <= m; j++)    {
                int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;              // Berechnet c wie in (a) beschrieben
                int replace = M[i - 1][j - 1] + cost;                   // Berechnet rep wie in (b) beschrieben
                int insert = M[i][j - 1] + 1;                           // Berechnet ins wie in (b) beschrieben
                int deleteOP = M[i - 1][j] + 1;                         // Berechnet del wie in (d) beschrieben
                M[i][j] = min({replace, insert, deleteOP});     }}   // Setzt den Eintrag bei (i,j) auf das Minimum von rep, ins und del
        return M[n][m];// Liest die Editierdistanz aus
}
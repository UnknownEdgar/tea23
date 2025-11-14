#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>

enum Zustand{
    Garagentor_zu,
    Fahre_hoch,
    Stop_auf_dem_Weg_nach_oben,
    Garagentor_offen,
    Fahre_runter,
    Stop_auf_dem_Weg_nach_unten
};

enum Ereignis{
    Taste,
    Endschalter_Oben,
    Endschalter_Unten
};

Zustand zustand = Garagentor_zu;

void eingabe(Ereignis ereignis){
    switch (zustand)
    {
        case Garagentor_zu:
            if (ereignis == Taste) zustand = Fahre_hoch;
            break;

        case Fahre_hoch:
            if (ereignis == Endschalter_Oben) zustand = Garagentor_offen;
            else if (ereignis == Taste) zustand = Stop_auf_dem_Weg_nach_oben;
            break;
        
        case Stop_auf_dem_Weg_nach_oben:
            if (ereignis == Taste) zustand = Fahre_runter;
            break;

        case Garagentor_offen:
            if (ereignis == Taste) zustand = Fahre_runter;
            break;
        
        case Fahre_runter:
            if(ereignis == Endschalter_Unten) zustand = Garagentor_zu;
            else if (ereignis == Taste) zustand = Stop_auf_dem_Weg_nach_unten;
            break;
            
        case Stop_auf_dem_Weg_nach_unten:
            if (ereignis == Taste) zustand = Fahre_hoch;
            break;
            
    }
}

void printZustand(){
    switch (zustand)
    {
        case Garagentor_offen:
            fmt::println("Garagentor offen");
            break;

        case Fahre_hoch:
            fmt::println("Garagentor faehrt hoch");
            break;

        case Stop_auf_dem_Weg_nach_oben:
            fmt::println("Garagentor auf dem Weg hoch gestoppt");
            break;

        case Garagentor_zu:
            fmt::println("Garagentor geschlossen");
            break;

        case Fahre_runter:
            fmt::println("Garagentor faehrt runter");
            break;

        case Stop_auf_dem_Weg_nach_unten:
            fmt::println("Garagentor auf dem Weg runter gestoppt");
            break;
    }
}

int main() {
    Ereignis ablauf[] = {
        Taste,                // Garagentor_zu -> Fahre_hoch
        Taste,                // Fahre_hoch -> Stop_auf_dem_Weg_nach_oben
        Taste,                // Stop_auf_dem_Weg_nach_oben -> Fahre_runter
        Taste,                // Fahre_runter -> Stop_auf_dem_Weg_nach_unten
        Taste,                // Stop_auf_dem_Weg_nach_unten -> Fahre_hoch
        Endschalter_Oben,     // Fahre_hoch -> Garagentor_offen
        Taste,                // Garagentor_offen -> Fahre_runter
        Endschalter_Unten     // Fahre_runter -> Garagentor_zu
    };

    int n = sizeof(ablauf) / sizeof(ablauf[0]);
    printZustand();
    for (int i = 0; i < n; ++i) {
        eingabe(ablauf[i]);
        printZustand();
    }
    return 0;
}

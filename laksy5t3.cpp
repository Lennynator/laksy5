#include <iostream>

class DynaaminenLuokka {
private:
    int* dynaaminenTieto;

public:
    // Konstruktori, joka luo dynaamisen muuttujan
    DynaaminenLuokka() {
        dynaaminenTieto = new int(42);
        std::cout << "Luokan konstruktori, arvo: " << *dynaaminenTieto << std::endl;
    }

    // Kopiokonstruktori
    DynaaminenLuokka(const DynaaminenLuokka& toinen) {
        dynaaminenTieto = new int(*(toinen.dynaaminenTieto));
        std::cout << "Kopiokonstruktori, arvo: " << *dynaaminenTieto << std::endl;
    }

    // Sijoitusoperaattori
    DynaaminenLuokka& operator=(const DynaaminenLuokka& toinen) {
        if (this != &toinen) {  // Itsesijoitus tarkistus
            delete dynaaminenTieto;  // Vapautetaan vanha dynaaminen muuttuja
            dynaaminenTieto = new int(*(toinen.dynaaminenTieto));
            std::cout << "Sijoitusoperaattori, arvo: " << *dynaaminenTieto << std::endl;
        }
        return *this;
    }

    // Destruktori, joka vapauttaa dynaamisen muuttujan
    ~DynaaminenLuokka() {
        std::cout << "Luokan destruktori, arvo: " << *dynaaminenTieto << std::endl;
        delete dynaaminenTieto;
    }

    void tulostaArvo() const {
        std::cout << "Arvo: " << *dynaaminenTieto << std::endl;
    }
};

int main() {
    DynaaminenLuokka eka;
    DynaaminenLuokka toka;

    // Sijoitus ilman kopiokonstruktoria
    toka = eka;

    // Kopiokonstruktori
    DynaaminenLuokka kolmas(eka);

    return 0;
}

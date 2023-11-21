#include <iostream>
#include <thread>
#include <chrono>

class Viisari {
private:
    int arvo;
    int maksimi;
    Viisari* successor;

public:
    Viisari(int alkuarvo, int maksimi, Viisari* successor = nullptr) : arvo(alkuarvo), maksimi(maksimi), successor(successor) {}

    int etene() {
        arvo = (arvo + 1) % maksimi;
        return arvo == 0 ? 0 : 1;
    }

    void nayta() const {
        if (arvo < 10)
            std::cout << "0";
        std::cout << arvo;
    }

    void setSuccessor(Viisari* successor) {
        this->successor = successor;
    }

    Viisari* getSuccessor() const {
        return successor;
    }
};

class Kello {
private:
    Viisari* tunnit;
    Viisari* minuutit;
    Viisari* sekunnit;

public:
    Kello(int h, int m, int s) {
        tunnit = new Viisari(h, 12);
        minuutit = new Viisari(m, 60);
        sekunnit = new Viisari(s, 60);

        tunnit->setSuccessor(minuutit);
        minuutit->setSuccessor(sekunnit);
    }

    ~Kello() {
        delete tunnit;
        delete minuutit;
        delete sekunnit;
    }

    void nayta() const {
        tunnit->nayta();
        std::cout << ":";
        minuutit->nayta();
        std::cout << ":";
        sekunnit->nayta();
        std::cout << std::endl;
    }

    void kay() {
        Viisari* current = tunnit;
        while (current != nullptr) {
            if (current->etene() == 0) {
                current = current->getSuccessor();
            }
            else {
                break;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

int main() {
    Kello* rolex = new Kello(12, 0, 0);

    while (1) {
        system("cls");
        rolex->kay();
        rolex->nayta();
    }

    delete rolex;

    return 0;
}
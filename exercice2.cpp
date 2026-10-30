#include <iostream>
#include <string>

using namespace std;
class Compte {
protected:
    string numero;
    double solde;

public:
    Compte(string num, double soldeInitial) {
        numero = num;
        solde = soldeInitial;
    }
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Ajout de " << montant << " EUR effectue." << endl;
        } else {
            cout << "Erreur : Montant invalide " << endl;
        }
    }
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait de " << montant << " EUR effectue." << endl;
        } else {
            cout << "Erreur : Fonds insuffisants" << endl;
        }
    }
    void afficher() {
        cout << "Compte numero : " << numero << " | Solde : " << solde << " EUR";
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    CompteEpargne(string num, double soldeInitial, double taux) : Compte(num, soldeInitial) {
        tauxInteret = taux;
    }

    void calculerInteret() {
        double interets = solde * (tauxInteret / 100.0);
        solde += interets;
        cout << "Ajout des interets de " << interets << " EUR (Taux : " << tauxInteret << "%)" << endl;
    }
    void afficher() {
        Compte::afficher();
        cout << " | Taux d'interet : " << tauxInteret << "%" << endl;
    }
};

int main() {
    cout << "Test du Compte Epargne" << endl;
    CompteEpargne ce1("FR7612345678", 5000.0, 4.0);
    cout << "\n1. Etat initial du compte :" << endl;
    ce1.afficher();
    cout << "\n2. Operations de depot et retrait :" << endl;
    ce1.deposer(1200.0);
    ce1.retirer(500.0);
    cout << "\n3. Calcul des interets :" << endl;
    ce1.calculerInteret();
    cout << "\n4. Etat final apres interets :" << endl;
    ce1.afficher();

    return 0;
}
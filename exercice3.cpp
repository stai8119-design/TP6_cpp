#include <iostream>
#include <string>

using namespace std;
class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(string n, double p) {
        nom = n;
        prix = p;
    }
    virtual ~Produit() {}
    virtual void afficherInfos() {
        cout << "Produit : " << nom << " | Prix : " << prix << " EUR";
    }
};
class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(string n, double p, string date) : Produit(n, p) {
        dateExpiration = date;
    }
    void afficherInfos() override {
        cout << "[Alimentaire] " << nom << " | Prix : " << prix << " EUR | Expire le : " << dateExpiration << endl;
    }
};
class ProduitElectronique : public Produit {
private:
    int garantieMois;

public:
    ProduitElectronique(string n, double p, int garantie) : Produit(n, p) {
        garantieMois = garantie;
    }
    void afficherInfos() override {
        cout << "Electronique" << nom << " | Prix : " << prix << " EUR | Garantie : " << garantieMois << " mois" << endl;
    }
};

int main() {
    cout << "Test du Polymorphisme avec Methodes Virtuelles" << endl;
    ProduitAlimentaire p1("Lait", 12.5, "15/11/2026");
    ProduitElectronique p2("Smartphone", 3500.0, 24);

    cout << "\n1. Affichage direct via les objets :" << endl;
    p1.afficherInfos();
    p2.afficherInfos();
    cout << "\n2. Affichage via une collection polymorphe:" << endl;
    
    Produit* catalogue[2];
    catalogue[0] = &p1;
    catalogue[1] = &p2;

    for (int i = 0; i < 2; i++) {
        catalogue[i]->afficherInfos();
    }

    return 0;
}
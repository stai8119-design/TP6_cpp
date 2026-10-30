#include <iostream>
#include <string>

using namespace std;
class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int identifiant, float salaire) {
        nom = n;
        id = identifiant;
        salaireDeBase = salaire;
    }
    virtual ~Employe() {
        cout << "[DESTRUCTEUR] Suppression de l'employe ID : " << id << endl;
    }
    virtual void afficherInfos() {
        cout << "ID : " << id << " | Nom : " << nom << " | Salaire de base : " << salaireDeBase << " EUR";
    }
};
class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int identifiant, float salaire, float prime) : Employe(n, identifiant, salaire) {
        primeAnnuelle = prime;
    }
    ~Permanent() override {}
    void afficherInfos() override {
        cout << "[Permanent] ";
        Employe::afficherInfos(); 
        cout << " | Prime annuelle : " << primeAnnuelle << " EUR" << endl;
    }
};
class Contractuel : public Employe {
private:
    int dureeContrat;  
    float tauxHoraire;

public:
    Contractuel(string n, int identifiant, float salaire, int duree, float taux) : Employe(n, identifiant, salaire) {
        dureeContrat = duree;
        tauxHoraire = taux;
    }
    ~Contractuel() override {}
    float calculerSalaireMensuel(int heures) {
        return salaireDeBase + (heures * tauxHoraire);
    }
    void afficherInfos() override {
        cout << "[Contractuel] ";
        Employe::afficherInfos();
        cout << " | Duree contrat : " << dureeContrat << " mois | Taux horaire : " << tauxHoraire << " EUR/h" << endl;
    }
};

int main() {
    cout << "Test du Systeme de Gestion des Employes" << endl << endl;
    const int taille = 3;
    Employe* entreprise[taille];
    entreprise[0] = new Permanent("Yassine", 101, 8500.0f, 1200.0f);
    entreprise[1] = new Contractuel("Fatima", 102, 4000.0f, 6, 45.5f);
    entreprise[2] = new Permanent("Mehdi", 103, 9200.0f, 1500.0f);

    cout << "Liste des employes de l'entreprise" << endl;
    for (int i = 0; i < taille; i++) {
        entreprise[i]->afficherInfos();
    }
    cout << "\nTest de calcul de salaire mensuel" << endl;
    Contractuel* c = dynamic_cast<Contractuel*>(entreprise[1]);
    if (c != nullptr) {
        int heuresTravaillees = 160;
        cout << "Salaire total pour Fatima avec " << heuresTravaillees << "h : " 
             << c->calculerSalaireMensuel(heuresTravaillees) << " EUR" << endl;
    }
    cout << "\nLiberation de la memoire" << endl;
    for (int i = 0; i < taille; i++) {
        delete entreprise[i];
    }

    cout << "\nFin du programme" << endl;
    return 0;
}
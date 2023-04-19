#include <iostream>
#include <string>

using namespace std;

// Fonction pour déterminer si une année est bissextile ou non
bool estBissextile(int annee) {
    if (annee % 4 != 0) {
        return false;
    } else if (annee % 100 != 0) {
        return true;
    } else if (annee % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

// Fonction pour déterminer si une date est valide
bool estDateValide(int jour, int mois, int annee) {
    if (annee < 1800 || annee > 9999) {
        return false;
    }
    if (mois < 1 || mois > 12) {
        return false;
    }
    if (mois == 2) {
        if (estBissextile(annee)) {
            return jour <= 29;
        } else {
            return jour <= 28;
        }
    }
    if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        return jour <= 30;
    }
    return jour <= 31;
}

// Fonction pour déterminer le signe astrologique associé à une date de naissance
string getAstroSign(int jour, int mois) {
    string signesAstro[] = {"Capricorne", "Verseau", "Poissons", "Bélier", "Taureau", "Gémeaux", "Cancer", "Lion", "Vierge", "Balance", "Scorpion", "Sagittaire"};
    int index = mois - (jour < (20 + ((mois - 1) % 3 == 0 ? 1 : 0)) ? 2 : 1);
    if (index < 0) {
        index += 12;
        
         cout << "Entrez le jour de naissance (1-31) : ";
    cin >> jour;

    cout << "Entrez le mois de naissance (1-12) : ";
    cin >> mois;

    if ((mois == 1 && jour >= 20) || (mois == 2 && jour <= 18))
        cout << "Votre signe astrologique est Verseau" << endl;
    else if ((mois == 2 && jour >= 19) || (mois == 3 && jour <= 20))
        cout << "Votre signe astrologique est Poisson" << endl;
    else if ((mois == 3 && jour >= 21) || (mois == 4 && jour <= 19))
        cout << "Votre signe astrologique est Bélier" << endl;
    else if ((mois == 4 && jour >= 20) || (mois == 5 && jour <= 20))
        cout << "Votre signe astrologique est Taureau" << endl;
    else if ((mois == 5 && jour >= 21) || (mois == 6 && jour <= 20))
        cout << "Votre signe astrologique est Gémeaux" << endl;
    else if ((mois == 6 && jour >= 21) || (mois == 7 && jour <= 22))
        cout << "Votre signe astrologique est Cancer" << endl;
    else if ((mois == 7 && jour >= 23) || (mois == 8 && jour <= 22))
        cout << "Votre signe astrologique est Lion" << endl;
    else if ((mois == 8 && jour >= 23) || (mois == 9 && jour <= 22))
        cout << "Votre signe astrologique est Vierge" << endl;
    else if ((mois == 9 && jour >= 23) || (mois == 10 && jour <= 22))
        cout << "Votre signe astrologique est Balance" << endl;
    else if ((mois == 10 && jour >= 23) || (mois == 11 && jour <= 21))
        cout << "Votre signe astrologique est Scorpion" << endl;
    else if ((mois == 11 && jour >= 22) || (mois == 12 && jour <= 21))
        cout << "Votre signe astrologique est Sagittaire" << endl;
    else if ((mois == 12 && jour >= 22) || (mois == 1 && jour <= 19))
        cout << "Votre signe astrologique est Capricorne" << endl;
    else
        cout << "La date de naissance est invalide." << endl;

   
    }
    return signesAstro[index];
}




   
}


int main() {
    int jour, mois, annee;
    bool dateValide = false;

    while (!dateValide) {
        cout << "Veuillez saisir votre date de naissance" << endl;
        cout << "Jour : ";
        cin >> jour;
        cout << "Mois : ";
        cin >> mois;
        cout << "Année : ";
        cin >> annee;

        dateValide = estDateValide(jour, mois, annee);
        if (!dateValide) {
            cout << "Erreur, la date saisie est invalide. Veuillez réessayer." << endl;
        }
    }

    // Déterminer le signe astrologique
    string signeAstro = getAstroSign(jour, mois);

    // Afficher le résultat
    cout << "Votre signe astrologique est : " << signeAstro << endl;

    return 0;
}

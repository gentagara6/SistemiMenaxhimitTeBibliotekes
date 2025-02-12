#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_LIBRA 100

struct Libri
{
    int id = 0;
    string titulli = " ";
    string autori = " ";
    int viti_publikimit = 0;
    bool ekziston = false;
    int vleresimi = 0;
    string kategoria = " ";
};

Libri biblioteka[MAX_LIBRA];
int numri_librave;

void gjejLibrinMeTeVjeterDheMeTeRi()
{
    if (numri_librave == 0)
    {
        cout << "Nuk ka libra n\x89 bibliotek\x89!\n";
        return;
    }

    Libri libriMeIVjeter;
    Libri libriMeIRi;

    bool kaLibraMeTeVjeter = false;
    bool kaLibraMeTeRi = false;

    for (int i = 0; i < numri_librave; i++)
    {
        if (biblioteka[i].ekziston)
        {
            if (!kaLibraMeTeVjeter || biblioteka[i].viti_publikimit < libriMeIVjeter.viti_publikimit)
            {
                libriMeIVjeter = biblioteka[i];
                kaLibraMeTeVjeter = true;
            }

            if (!kaLibraMeTeRi || biblioteka[i].viti_publikimit > libriMeIRi.viti_publikimit)
            {
                libriMeIRi = biblioteka[i];
                kaLibraMeTeRi = true;
            }
        }
    }
    if (kaLibraMeTeVjeter)
    {
        cout << "\nLibri m\x89 i vjet\x89r:\n"
            << "Titulli: " << libriMeIVjeter.titulli << "\n"
            << "Autori: " << libriMeIVjeter.autori << "\n"
            << "Viti i publikimit: " << libriMeIVjeter.viti_publikimit << "\n\n";
    }
    if (kaLibraMeTeRi)
    {
        cout << "Libri m\x89 i ri:\n"
            << "Titulli: " << libriMeIRi.titulli << "\n"
            << "Autori: " << libriMeIRi.autori << "\n"
            << "Viti i publikimit: " << libriMeIRi.viti_publikimit << "\n";
    }
}

void fshiLiber()
{
    int id;
    cout << "Sh\x89noni ID-n\x89 e librit q\x89 d\x89shironi t\x89 fshini: ";
    cin >> id;

    for (int i = 0; i < numri_librave; i++)
    {
        if (biblioteka[i].ekziston && biblioteka[i].id == id) {
            biblioteka[i].ekziston = false;
            cout << "Libri \"" << biblioteka[i].titulli << "\" u fshi me sukses!\n";
            return;
        }
    }

    cout << "Libri nuk u gjet!\n";
}


int main() {




	return 0;
}

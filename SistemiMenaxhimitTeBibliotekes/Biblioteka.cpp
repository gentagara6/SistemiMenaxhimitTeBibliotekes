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

void inicializoBiblioteken()
{
    Libri librat_fillestare[] =
    {
        { 101, "K\x89shtjella", "Ismail Kadare", 1970, true, 5, "Histori" },
        { 102, "Sherlock Holmes", "Arthur Conan Doyle", 1887, true, 4, "Mister" },
        { 103, "Krenari dhe Paragjykim", "Jane Austen", 1813, true, 4, "Romanc\x89" },
        { 104, "Hamleti", "William Shakespeare", 1603, true, 5, "Dram\x89" },
        { 105, "Historia e Sk\x89nderbeut", "Naim Frash\x89ri", 1898, true, 5, "Histori" }
    };

    int numri_librave_fillestare = sizeof(librat_fillestare) / sizeof(librat_fillestare[0]);

    for (int i = 0; i < numri_librave_fillestare; i++)
    {
        biblioteka[numri_librave] = librat_fillestare[i];numri_librave++;
    }
}

void shtoLiber()
{
    if (numri_librave >= MAX_LIBRA)
    {
        cout << "Biblioteka \x89sht\x89 e mbushur! Nuk mund t\x89 shtoni m\x89 shum\x89 libra.\n";
        return;
    }

    Libri libri;
    cout << "Sh\x89noni ID-n\x89 e librit: ";
    cin >> libri.id;
    cin.ignore();

    cout << "Sh\x89noni titullin e librit: ";
    cin>>libri.titulli;

    cout << "Sh\x89noni autorin e librit: ";
    cin>>libri.autori;

    cout << "Sh\x89noni vitin e publikimit: ";
    cin >> libri.viti_publikimit;

    cout << "Sh\x89noni vleresimin (1-5): ";
    cin >> libri.vleresimi;

    cout << "Sh\x89noni kategorin\x89 e librit: ";
    cin>>libri.kategoria;

    libri.ekziston = true;
    biblioteka[numri_librave] = libri;
    numri_librave++;

    cout << "Libri \"" << libri.titulli << "\" u shtua me sukses!\n";
}

void shfaqLibrat()
{
    if (numri_librave == 0)
    {
        cout << "Biblioteka \x89sht\x89 bosh!\n";
        return;
    }

    cout << "\nLista e librave n\x89 bibliotek\x89:\n";
    for (int i = 0; i < numri_librave; i++)
    {
        if (biblioteka[i].ekziston)
        {
            cout << "ID: " << biblioteka[i].id
                << " | Titulli: " << biblioteka[i].titulli
                << " | Autori: " << biblioteka[i].autori
                << " | Viti: " << biblioteka[i].viti_publikimit
                << " | Vler\x89simi: " << biblioteka[i].vleresimi
                << " | Kategoria: " << biblioteka[i].kategoria << endl;
        }
    }
}

void kerkoLiber()
{
    int id;
    cout << "Sh\x89noni ID-n\x89 e librit q\x89 po k\x89rkoni: ";
    cin >> id;

    for (int i = 0; i < numri_librave; i++)
    {
        if (biblioteka[i].ekziston && biblioteka[i].id == id)
        {
            cout << "\nLibri u gjet!\n"
                << "Titulli: " << biblioteka[i].titulli << endl
                << "Autori: " << biblioteka[i].autori << endl
                << "Viti i publikimit: " << biblioteka[i].viti_publikimit << endl
                << "Vler\x89simi: " << biblioteka[i].vleresimi << endl
                << "Kategoria: " << biblioteka[i].kategoria << endl;
            return;
        }
    }

    cout << "Libri nuk u gjet!\n";
}

void numriLibrave()
{
    int numerimi = 0;
    for (int i = 0; i < numri_librave; i++)
    {
        if (biblioteka[i].ekziston) {
            numerimi++;
        }
    }

    cout << "\nNumri total i librave n\x89 bibliotek\x89: " << numerimi << endl;
}

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


int main() 
{
    inicializoBiblioteken();

    int zgjedhja = 0;

    do {
        cout << "\n=====================================================\n";
        cout << "|         SISTEMI I MENAXHIMIT TE BIBLIOTEKES       |\n";
        cout << "=====================================================\n";
        cout << "|  [1]  Shto nj\x89 lib\x89r t\x89 ri                        |\n";
        cout << "|  [2]  Shfaq t\x89 gjith\x89 librat                      |\n";
        cout << "|  [3]  K\x89rko nj\x89 lib\x89r                             |\n";
        cout << "|  [4]  Fshi nj\x89 lib\x89r                              |\n";
        cout << "|  [5]  Numri i librave n\x89 bibliotek\x89               |\n";
        cout << "|  [6]  Gjej librin m\x89 t\x89 vjet\x89r dhe m\x89 t\x89 ri       |\n";
        cout << "|  [7]  Dil nga programi                            |\n";
        cout << "=====================================================\n";
        cout << "| Zgjedhja juaj: ";
        cin >> zgjedhja;


        switch (zgjedhja) {
        case 1:
            shtoLiber();
            break;
        case 2:
            shfaqLibrat();
            break;
        case 3:
            kerkoLiber();
            break;
        case 4:
            fshiLiber();
            break;
        case 5:
            numriLibrave();
            break;
        case 6:
            gjejLibrinMeTeVjeterDheMeTeRi();
            break;
        case 7:
            cout << "Faleminderit p\x89r p\x89rdorimin e sistemit! Duke dalur...\n";
            break;
        default:
            cout << "Zgjedhje e pavlefshme! Provo p\x89rs\x89ri.\n";
        }
    } while (zgjedhja != 7);

    return 0;
}
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
        
int main() {




	return 0;
}
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

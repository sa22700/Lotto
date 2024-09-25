#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
//luodaan luokka Lottokone.
class Lottokone
{
    //asetetaan julkisiksi vector taulukot jotka tallentavat integerejä.
public: vector<int> lotto;
        vector<int> oikeaRivi;
        vector<vector<int>> tilasto;
        int i;
        //Vektorien koko on 9 ja arvot on 0.
        Lottokone() : lotto(9, 0), oikeaRivi(9, 0) {}

        //luodaan funktio mikä ei palauta mitään.
        void arvoNumerot()
        {
            //alustaa satunnaisluvut, tämä on siis aikariippuvainen.
            srand(time(NULL));
            cout << "Päänumerot ovat:" << endl;
            //loopataan 7 randomia lukua ja tallennetaan ne lotto taulukkoon väliltä 1-40.
            for (i = 0; i < 7; i++)
            {
                lotto[i] = rand() % 40 + 1;
                cout << lotto[i] << endl;
            }
            cout << "Lisänumerot ovat:" << endl;
            //loopataan 2 randomia lukua ja tallennetaan ne lotto taulukkoon väliltä 1-40.
            for (i = 7; i < 9; i++)
            {
                lotto[i] = rand() % 40 + 1;
                cout << lotto[i] << endl;
            }
        }
        //luodaan funktio mikä ei palauta mitään.
        void valitseNumerot()
        {
            cout << "Valitse 7 päänumeroa väliltä 1-40: " << endl;
            //luodaan for looppi, jossa käyttäjä saa arpoa itse 7 lukua
            for (i = 0; i < 7; i++)
            {
                int num = 0;
                //luodaan while, jolla tarkistetaan että annetut numerot ovat sallittujen arvojen sisällä 
                while (num < 1 || num > 40)
                {
                    cin >> num;
                    //tässä tarkistus tapahtuu
                    if (num < 1 || num > 40)
                    {
                        cout << "Numero ei kelpaa" << endl;
                    }
                }
                //num arvot tallentuvat lotto taulukkoon
                lotto[i] = num;
            }
            cout << "Valitse 2 lisänumeroa väliltä 1-40: " << endl;
            //luodaan looppi, jossa käyttäjä saa arpoa itse 2 lukua
            for (i = 7; i < 9; i++)
            {
                int num = 0;
                //luodaan while, jolla tarkistetaan että annetut numerot ovat sallittujen arvojen sisällä
                while (num < 1 || num > 40)
                {
                    cin >> num;
                    //tässä tarkistus tapahtuu
                    if (num < 1 || num > 40)
                    {
                        cout << "Numero ei kelpaa" << endl;
                    }
                }
                //num arvot tallentuvat lotto taulukkoon
                lotto[i] = num;
            }
        }
        //luodaan funktio, ei palauta mitään
        void OikeaRivi()
        {
            //alustaa satunnaisluvut, tämä on siis aikariippuvainen.
            srand(time(NULL));
            //for loopissa luodaan ensimmäiset satunnais 7 lukua väliltä 1-40
            for (i = 0; i < 7; i++)
            {
                oikeaRivi[i] = rand() % 40 + 1;
            }
            //for loopissa luodaan ensimmäiset satunnais 2 lukua väliltä 1-40
            for (i = 7; i < 9; i++)
            {
                oikeaRivi[i] = rand() % 40 + 1;
            }
            //ehdolla tarkistetaan onko rivi oikea ja jos on se tallentuu tilasto taulukkoon, tässä kaytetään toista funktiota hyödyksi
            if (tarkistaRivi() == true)
            {
                tilasto.push_back(oikeaRivi);
            }
        }
        //luodaan funktio, eikä palauta mitään
        void Tilasto()
        {
            cout << "Tilasto oikeista riveistä" << endl;
            int i = 0;
            //while loopilla tarkistetaan että onko taulu suurempi kuin 0, eli ettei ole tyhjä
            while (i < tilasto.size())
            {
                int j = 0;
                //while loopilla tarkistetaan kuinka monta arvoa tauluun on tallennettu ja tulostetaan ne
                while (j < tilasto[i].size())
                {
					cout << tilasto[i][j] << " ";
					j++;
				}
                i++;
                cout << endl;
            }
        }
        //luodaan funktio, joka palauttaa totuusarvon
        bool tarkistaRivi()
        {
            //tässä tarkistetaan onko oikearivi sama kuin lotto rivi
            if (oikeaRivi == lotto)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    //olio Lottokoneesta
    Lottokone Lotto;
    //yritetään kääntää tulostuksia suomeksi
    setlocale(LC_ALL, "fi-FI");
    int valinta;
    cout << "-- Tämä on lottokone --" << endl;
    //while looppi pyörii niinkauan kuin arvo on totuusarvo
    while (true)
    {
        cout << "Valitse numero 1 - 3 välillä ( 0 lopettaa )" << endl;
        cin >> valinta;
        //tarkistetaan syöttääkö käyttäjä arvon 0 jolloin ohjelma päättyy
        if (valinta == 0)
        {
            cout << "Ohjelma lopetetaan!" << endl;
            break;
        }
        // tarkistetaan jos käyttäjä syöttää arvon 1, jolloin alustetaan uudet oikeat rivi ja kone arpoo uudet numerot
        else if (valinta == 1)
        {
            Lotto.OikeaRivi();
            Lotto.arvoNumerot();
        }
        //tarkistetaan jos käyttäjä syöttää arvon 2, jolloin käyttäjä syöttää numerot ja muuten kaikki tapahtuu samoin kuin 1 valinnassa
        else if (valinta == 2)
        {
            Lotto.OikeaRivi();
            Lotto.valitseNumerot();
        }
        //tarkistetaanjos käyttäjä syöttää arvon 3, jolloin tarkistetaan onko tilasto taulukkoon tallentunut mitään
        else if (valinta == 3)
        {
            Lotto.Tilasto();
        }
        //jos käyttähä syöttää joitain muita arvoja kuin edellä mainittuja niin antaa tämän tulosteen
        else
        {
            cout << "Virheellinen valinta!" << endl;
        }
    }
    //palautetaan 0
    return 0;
}
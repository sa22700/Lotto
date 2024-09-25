#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
//luodaan luokka Lottokone.
class Lottokone
{
    //asetetaan julkisiksi vector taulukot jotka tallentavat integerej�.
public: vector<int> lotto;
        vector<int> oikeaRivi;
        vector<vector<int>> tilasto;
        int i;
        //Vektorien koko on 9 ja arvot on 0.
        Lottokone() : lotto(9, 0), oikeaRivi(9, 0) {}

        //luodaan funktio mik� ei palauta mit��n.
        void arvoNumerot()
        {
            //alustaa satunnaisluvut, t�m� on siis aikariippuvainen.
            srand(time(NULL));
            cout << "P��numerot ovat:" << endl;
            //loopataan 7 randomia lukua ja tallennetaan ne lotto taulukkoon v�lilt� 1-40.
            for (i = 0; i < 7; i++)
            {
                lotto[i] = rand() % 40 + 1;
                cout << lotto[i] << endl;
            }
            cout << "Lis�numerot ovat:" << endl;
            //loopataan 2 randomia lukua ja tallennetaan ne lotto taulukkoon v�lilt� 1-40.
            for (i = 7; i < 9; i++)
            {
                lotto[i] = rand() % 40 + 1;
                cout << lotto[i] << endl;
            }
        }
        //luodaan funktio mik� ei palauta mit��n.
        void valitseNumerot()
        {
            cout << "Valitse 7 p��numeroa v�lilt� 1-40: " << endl;
            //luodaan for looppi, jossa k�ytt�j� saa arpoa itse 7 lukua
            for (i = 0; i < 7; i++)
            {
                int num = 0;
                //luodaan while, jolla tarkistetaan ett� annetut numerot ovat sallittujen arvojen sis�ll� 
                while (num < 1 || num > 40)
                {
                    cin >> num;
                    //t�ss� tarkistus tapahtuu
                    if (num < 1 || num > 40)
                    {
                        cout << "Numero ei kelpaa" << endl;
                    }
                }
                //num arvot tallentuvat lotto taulukkoon
                lotto[i] = num;
            }
            cout << "Valitse 2 lis�numeroa v�lilt� 1-40: " << endl;
            //luodaan looppi, jossa k�ytt�j� saa arpoa itse 2 lukua
            for (i = 7; i < 9; i++)
            {
                int num = 0;
                //luodaan while, jolla tarkistetaan ett� annetut numerot ovat sallittujen arvojen sis�ll�
                while (num < 1 || num > 40)
                {
                    cin >> num;
                    //t�ss� tarkistus tapahtuu
                    if (num < 1 || num > 40)
                    {
                        cout << "Numero ei kelpaa" << endl;
                    }
                }
                //num arvot tallentuvat lotto taulukkoon
                lotto[i] = num;
            }
        }
        //luodaan funktio, ei palauta mit��n
        void OikeaRivi()
        {
            //alustaa satunnaisluvut, t�m� on siis aikariippuvainen.
            srand(time(NULL));
            //for loopissa luodaan ensimm�iset satunnais 7 lukua v�lilt� 1-40
            for (i = 0; i < 7; i++)
            {
                oikeaRivi[i] = rand() % 40 + 1;
            }
            //for loopissa luodaan ensimm�iset satunnais 2 lukua v�lilt� 1-40
            for (i = 7; i < 9; i++)
            {
                oikeaRivi[i] = rand() % 40 + 1;
            }
            //ehdolla tarkistetaan onko rivi oikea ja jos on se tallentuu tilasto taulukkoon, t�ss� kaytet��n toista funktiota hy�dyksi
            if (tarkistaRivi() == true)
            {
                tilasto.push_back(oikeaRivi);
            }
        }
        //luodaan funktio, eik� palauta mit��n
        void Tilasto()
        {
            cout << "Tilasto oikeista riveist�" << endl;
            int i = 0;
            //while loopilla tarkistetaan ett� onko taulu suurempi kuin 0, eli ettei ole tyhj�
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
            //t�ss� tarkistetaan onko oikearivi sama kuin lotto rivi
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
    //yritet��n k��nt�� tulostuksia suomeksi
    setlocale(LC_ALL, "fi-FI");
    int valinta;
    cout << "-- T�m� on lottokone --" << endl;
    //while looppi py�rii niinkauan kuin arvo on totuusarvo
    while (true)
    {
        cout << "Valitse numero 1 - 3 v�lill� ( 0 lopettaa )" << endl;
        cin >> valinta;
        //tarkistetaan sy�tt��k� k�ytt�j� arvon 0 jolloin ohjelma p��ttyy
        if (valinta == 0)
        {
            cout << "Ohjelma lopetetaan!" << endl;
            break;
        }
        // tarkistetaan jos k�ytt�j� sy�tt�� arvon 1, jolloin alustetaan uudet oikeat rivi ja kone arpoo uudet numerot
        else if (valinta == 1)
        {
            Lotto.OikeaRivi();
            Lotto.arvoNumerot();
        }
        //tarkistetaan jos k�ytt�j� sy�tt�� arvon 2, jolloin k�ytt�j� sy�tt�� numerot ja muuten kaikki tapahtuu samoin kuin 1 valinnassa
        else if (valinta == 2)
        {
            Lotto.OikeaRivi();
            Lotto.valitseNumerot();
        }
        //tarkistetaanjos k�ytt�j� sy�tt�� arvon 3, jolloin tarkistetaan onko tilasto taulukkoon tallentunut mit��n
        else if (valinta == 3)
        {
            Lotto.Tilasto();
        }
        //jos k�ytt�h� sy�tt�� joitain muita arvoja kuin edell� mainittuja niin antaa t�m�n tulosteen
        else
        {
            cout << "Virheellinen valinta!" << endl;
        }
    }
    //palautetaan 0
    return 0;
}
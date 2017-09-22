/**
 *TODO
 *
 *exemple d'utilisation --> $ cat texte.txt | ./detecte-vigenere
 *                      --> $ cat lafontaine-az.txt | ./chiffre-vigenere AZERTY | ./detecte-vigenere
 */
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include  <math.h>

#include "utils.h"
#include "freqs.h"

using namespace std;

float indiceFR = 0.0780531 ;
float indiceRandom = 0.0384615 ;


int main( int argc, char** argv )
{
  string s = readInput( cin );

  std::vector<float> frequenFR( 26 );
  std::vector<float> frequenRandom( 26 );
  std::vector<float> frequen( 26 );
  std::vector<float> bestFrequen( 26 );

  frequenFR = frequenciesFrench();
  frequenRandom = frequenciesRandom();

  bool EstFR = false;

  cout << "\n##############################################\n"
       << "Taille du texte = " << s.size()
       << "  --   Nb de saut = " << s.size()/10
       << "\n##############################################\n"
       << "\n\n" << endl;

  for (int saut = 1; saut <= int(s.size()/10) ; saut++)
  {

    int nb_fr = 0;

    for (int shift = 0; shift <= saut-1; shift++)
    {

      string subTextATraiter = subtext(s, saut, shift);

      EstFR = itIsRandomOrFR (subTextATraiter);

      if (EstFR) {
        nb_fr++;
      }
    }

    if (nb_fr == saut)
    {
      /* code */
      cout << "--> Semble etre du francais pour saut : " << saut << endl;

      std::vector<char> cle( saut );

      for (int lettreCle = 0; lettreCle < saut - 1; lettreCle++)
      {
        //on cherche le caractere c entre A et Z qui maximise la coincidence mutuelle avec freq_fr
        float bestIndiceCoincidence = 0;

        for (int lettreAlphabet = 0; lettreAlphabet < 26; lettreAlphabet++)
        {

          string subTextCheckLettre = subtext(s, saut, lettreAlphabet);
          frequen = frequencies(subTextCheckLettre);
          float indiceCoincidence = indiceDeCoincidence(frequen , subTextCheckLettre.size()) ;

          if (fabs(indiceFR - indiceCoincidence) < fabs(indiceFR - bestIndiceCoincidence))
          {
            bestIndiceCoincidence = indiceCoincidence;
            cle[lettreCle] = (char) (lettreAlphabet + 'A');
            std::cout << "saut : " << saut
             << " indiceCoincidence actuelle = " << bestIndiceCoincidence <<
            " lettre choisi : " << (char) (lettreAlphabet + 'A') << '\n';
          }
        }
      }

      // ######## Affiche la clé
      for ( int i = 0; i < saut; i++ )
      {
        //affiche la frequance de chaque lettre
        cout << "la " << i << " eme lettre = " << cle[i] << endl;
      }
      // ######## FIN Affiche la clé

    }
  }
  return 0;
}



    /*DEBUG
    cout << "saut = " << saut << endl;
    cout << "indiceCoincidence = " << indiceCoincidence << endl;
    cout << "-- abs(indiceFR - indiceCoincidence) = " << fabs (indiceFR - indiceCoincidence) << endl;
    cout << "-- abs(indiceFR - bestIndiceCoincidence) = " << fabs (indiceFR - bestIndiceCoincidence) <<"\n" << endl;
    */

    // On test si l'indice est bien plus proche du francais que le precedant


    /*
    if (fabs(indiceFR - indiceCoincidence) < fabs(indiceFR - bestIndiceCoincidence))
    {
        bestIndiceCoincidence = indiceCoincidence;
        bestSaut = saut;
        bestFrequen = frequen;
        cout << "bestIndiceCoincidence = " << bestIndiceCoincidence << endl;
        cout << "--> bestSaut = " << bestSaut <<"\n\n"<< endl;



        for (size_t lettre = 0; lettre < 25; lettre++) {
            //on cherche le caractere c entre A et Z qui maximise la coincidence mutuelle avec freq_fr

            cle[lettre] =
        }
    }
  }



}*/

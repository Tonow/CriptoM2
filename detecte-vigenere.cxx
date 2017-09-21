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

  float bestIndiceCoincidence = 0;
  int bestSaut = 0;

  cout << "\n##############################################\n"
       << "Taille du texte = " << s.size()
       << "  --   Nb de saut = " << s.size()/10
       << "\n##############################################\n"
       << "\n\n" << endl;

  for (int saut = 1; saut <= int(s.size()/10) ; saut++) {

    string subTextATraiter = subtext(s, saut, 0);

    frequen = frequencies(subTextATraiter);

    float indiceCoincidence = indiceDeCoincidence(frequen , s.size()) ;

    /*DEBUG
    cout << "saut = " << saut << endl;
    cout << "indiceCoincidence = " << indiceCoincidence << endl;
    cout << "-- abs(indiceFR - indiceCoincidence) = " << fabs (indiceFR - indiceCoincidence) << endl;
    cout << "-- abs(indiceFR - bestIndiceCoincidence) = " << fabs (indiceFR - bestIndiceCoincidence) <<"\n" << endl;
    */

    // On test si l'indice est bien plus proche du francais que le precedant
    if (fabs(indiceFR - indiceCoincidence) < fabs(indiceFR - bestIndiceCoincidence))
    {
        bestIndiceCoincidence = indiceCoincidence;
        bestSaut = saut;
        bestFrequen = frequen;
        cout << "bestIndiceCoincidence = " << bestIndiceCoincidence << endl;
        cout << "--> bestSaut = " << bestSaut <<"\n\n"<< endl;
    }
  }



  for ( int i = 0; i < 26; i++ )
  {
    //affiche la frequance de chaque lettre
    cout << (char)('A'+i) << " = " << bestFrequen[i] << endl;
  }


  cout << "\nidcFrance = " << indiceFR << endl;
  cout << "indiceRandom = " << indiceRandom << endl;
  cout << "idc = " << bestIndiceCoincidence << endl;
  cout << "bestSaut = " << bestSaut << endl;

  if (((indiceFR + indiceRandom) / 2) > bestIndiceCoincidence &&
        bestIndiceCoincidence > indiceRandom)
  {
    cout<<"\nCe texte parait plutot aleatoire ! "<< endl ;
  }
  else if (((indiceFR + indiceRandom) / 2) < bestIndiceCoincidence &&
        bestIndiceCoincidence < indiceFR)
  {
    cout << "\nCe texte semble francais ! "<< endl ;
  }
  else
  {
    cout << "\n!!! indiceCoincidence mal calculer !!! "<< endl ;
  }

  return 0;
}

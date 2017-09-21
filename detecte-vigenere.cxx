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

  for (unsigned int saut = 1; saut <= s.size()/10 ; saut++) {

    //TODO : Probleme les saut ne vont pas jusqu'a s.size()/10 ?????

    cout << "saut = " << saut << endl;

    s = subtext(s, saut, 0);

    frequen = frequencies(s);

    float indiceCoincidence = indiceDeCoincidence(frequen , s.size()) ;

    cout << "indiceCoincidence = " << indiceCoincidence << endl;
    cout << "-- abs(indiceFR - indiceCoincidence) = " << fabs (indiceFR - indiceCoincidence) << endl;
    cout << "-- abs(indiceFR - bestIndiceCoincidence) = " << fabs (indiceFR - bestIndiceCoincidence) <<"\n" << endl;

    if (fabs(indiceFR - indiceCoincidence) < fabs(indiceFR - bestIndiceCoincidence))
    {
        bestIndiceCoincidence = indiceCoincidence;
        bestSaut = saut;
        bestFrequen = frequen;
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

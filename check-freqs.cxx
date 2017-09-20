/**
 *retourne la fréquence de chaque lettre majuscule dans une chaîne de caractères
 *et donne l'indice de corélation
 *
 *exemple d'utilisation --> $ cat texte.txt | ./check-freqs
 */
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "utils.h"
#include  <math.h>
#include "freqs.h"

using namespace std;

float indiceFR = 0.0780531 ;
float indiceRandom = 0.0384615 ;

int main( int argc, char** argv )
{
  string s = readInput( cin );

  std::vector<float> frequen( 26 );
  std::vector<float> frequenFR( 26 );
  std::vector<float> frequenRandom( 26 );

  frequen = frequencies(s);
  frequenFR = frequenciesFrench();
  frequenRandom = frequenciesRandom();

  float indiceCoincidence = indiceDeCoincidence(frequen , s.size()) ;

  for ( int i = 0; i < 26; i++ )
  {
    //affiche la frequance de chaque lettre
    cout << (char)('A'+i) << " = " << frequen[i] << endl;
  }


  cout << "\nidcFrance = " << indiceFR << endl;
  cout << "indiceRandom = " << indiceRandom << endl;
  cout << "idc = " << indiceCoincidence << endl;

  if ((indiceFR + indiceRandom / 2) > indiceCoincidence )
  {
    cout<<"\nCe texte parait plutot aleatoire ! "<< endl ;
  }
  else {
    cout << "\nCe texte semble francais ! "<< endl ;
  }

  return 0;
}

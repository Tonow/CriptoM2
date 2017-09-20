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
#include  <math.h>

#include "utils.h"
#include "freqs.h"

using namespace std;

float indiceFR = 0.0780531 ;
float indiceRandom = 0.0384615 ;

int main( int argc, char** argv )
{
  string s = readInput( cin );

  cout << "argc = " << argc << endl;
  cout << "argv[1] = " << argv[1] << endl;
  cout << "argv[2] = " << argv[2] << "\n" << endl;

  // ######### TODO #########
  // Je ne comprend pas cela n'a pas l'air de passer dans ce if
  // par exemple avec cette requette :
  // cat lafontaine-az.txt | ./chiffre-vigenere AZERTY | ./check-freqs 6 0
  if (argc <= 1) {
      int k = atoi(argv[1]); //decalage de Cesare
      int r = atoi(argv[2]); //saut

      cout << "decalage de Cesare = " << k << endl;
      cout << "saut\n = " << r << endl;

      s = subtext(s, r, k);

      cout << "\n" << s << "\n" << endl;

  } // #####################

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

  if (((indiceFR + indiceRandom) / 2) > indiceCoincidence )
  {
    cout<<"\nCe texte parait plutot aleatoire ! "<< endl ;
  }
  else {
    cout << "\nCe texte semble francais ! "<< endl ;
  }

  return 0;
}

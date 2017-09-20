/**
 * @file check_freqs.cxx
 *
 * @author MP
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

float indiceDeCoincidence( std::vector<float> frequences , int size){
  float indice = 0.0;
  for (unsigned int i= 0 ; i< frequences.size() ; i++){
    indice += frequences[i] * size * ((frequences[i] * size) - 1.0 );
  }
  indice = (1.0 / (size * (size -1.0 ) )) * indice ;
  return indice;
}

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
  for ( int i = 0; i < 26; i++ ){
    cout << (char)('A'+i) << " = " << frequen[i] << endl;
    }
  cout << "idcFrance = " << indiceFR << endl;
   cout << "indiceRandom = " << indiceRandom << endl;
  cout << "idc = " << indiceCoincidence << endl;
  if ((indiceFR + indiceRandom / 2) > indiceCoincidence ){
    cout<<" texte random ! "<< endl ;
  }
  else {
    cout << " c'est du francais ! "<< endl ;
  }

  return 0;
}

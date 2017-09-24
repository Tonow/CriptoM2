#include <iostream>
#include <fstream>

#include "freqs.h"

using namespace std;

float freqLettresFr[26] =
  { 0.0840, 0.0106, 0.0303, 0.0418, 0.1726, 0.0112, 0.0127, 0.0092, 0.0734,
    0.0031, 0.0005, 0.0601, 0.0296, 0.0713, 0.0526, 0.0301, 0.0099, 0.0655,
    0.0808, 0.0707, 0.0574, 0.0132, 0.0004, 0.0045, 0.0030, 0.0012 };

float freqDigrammesFr[676];

int computeDigrammesFr( const std::string & fname );

int initFreqs( const std::string & dig_fname )
{
  return computeDigrammesFr( dig_fname );
}

/**
 * Must be called before using frequencies services.
 *
 * @param dig_fname the file name containing the frequencies of
 * digrams (not necessarily normalized)
 *
 * @return 0 if everything went well.
 */
int computeDigrammesFr( const std::string & fname )
{
  ifstream f_in( fname.c_str() );
  if ( f_in.bad() ) return 1;
  int i = 0;
  int nb = 0;
  int freq = 0;
  while ( ! f_in.eof() )
    {
      f_in >> freq;
      freqDigrammesFr[ i ] += (float) freq;
      nb += freq;
      i++;
    }
  cout << "Found " << i << " digram frequencies with total " << nb
	    << endl;
  for ( i = 0; i < 676; i++ )
    freqDigrammesFr[ i ] /= (float) nb;
  return 0;
}

/**
* @param s string : une chaîne de caractères chiffrée (A-Z).
* @return freqLettre vector : la fréquence des lettres 'A' à 'Z' (0='A', 25='Z').
*/
std::vector<float> frequencies( const std::string & s )
{
  std::vector<float> freqLettre ( 26 );
  for ( unsigned int i=0 ; i < s.size() ; i++)
  {
    // nombre de fois ou on trouve la  lettre / taille du texte
    freqLettre[(s[i]-'A')] += 1.0 / s.size();
  }
  return freqLettre;
}


/**
* @param s string : une chaîne de caractères chiffrée (A-Z).
* @return freqDigram vector : la fréquence des digrammes du texte
*  'A' à 'Z' (0='A', 25='Z').
 */
std::vector<float> frequenciesDigrams(const std::string & s)
{
  std::vector<float> freqDigram( 26*26 );
  //DEBUG std::cout << "--> dans frequenciesDigrams" << '\n';
  for ( unsigned int i = 0; i < (s.size() - 1) ; i++ )
  {
    freqDigram[ (s[i]-'A') * (s[i+1]-'A')] += 1.0 / s.size();
    /*//DEBUG
    std::cout << " i = " << i <<" " << (char) (s[i])
    << " -- i+1 = " << i+1 << " " <<(char) (s[i+1])
    << " digram : "<< (s[i]-'A') + (s[i+1]-'A') << '\n';
    */

  }

  return freqDigram;
}



/**
* @param frequences vector<float> ensemble de frequence d'apparition des lettre
*                                 du chiffre
* @param size int la taille du texte
* @return indice float  indice de coincidence
*/
float indiceDeCoincidence( std::vector<float> frequences , int size){
  float indice = 0.0;
  for (unsigned int i= 0 ; i< frequences.size() ; i++){
    indice += frequences[i] * size * ((frequences[i] * size) - 1.0 );
  }
  indice = (1.0 / (size * (size -1.0 ) )) * indice ;
  return indice;
}

/**
* @param frequences vector<float> ensemble de frequence d'apparition des lettre
*                                 du chiffre
* @return indice float  indice de coincidence
*/
float indiceDeCoincidenceSommeFreqCarre( std::vector<float> frequences)
{
  float indice = 0.0;
  for (unsigned int i= 0 ; i< frequences.size() ; i++){
    indice += (float) frequences[i] * (float) frequences[i];
  }
  return indice;
}

/**
 * @param n a number between 0 and 25.
 *
 * @return the frequency of the letter ('A'+n) in common french as a
 * number between 0 and 1.
 */
float freqN( int n )
{
  return freqLettresFr[ n ];
}

/**
 * @param m a number between 0 and 25.
 * @param n a number between 0 and 25.
 *
 * @return the frequency of the digram ('A'+m)('A'+n) in common french as a
 * number between 0 and 1.
 */
float freqMN( int m, int n )
{
  return freqDigrammesFr[ m*26 + n ];
}

/**
 * @return the frequency of the letters ('A'+n) in common french as a
 * number between 0 and 1.
 */
std::vector<float> frequenciesFrench()
{
  std::vector<float> ff( 26 );
  for ( unsigned int i = 0; i < ff.size(); ++i )
    ff[ i ] = freqN( i );
  return ff;
}

/**
 * @return the frequency of the letters ('A'+n) for a random text as
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesRandom()
{
  std::vector<float> ff( 26 );
  for ( unsigned int i = 0; i < ff.size(); ++i )
    ff[ i ] = 1.0 / 26.0;
  return ff;
}

/**
 * @return the frequency of the digrams ('AA'+n) in common french as a
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesFrenchDigrams()
{
  std::vector<float> ff( 26*26 );
  for ( unsigned int i = 0; i < ff.size(); ++i )
    ff[ i ] = freqMN( i/26, i%26 );
  return ff;
}

/**
 * @return the frequency of the digrams ('AA'+n) for a random text as
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesRandomDigrams()
{
  std::vector<float> ff( 26*26 );
  for ( unsigned int i = 0; i < ff.size(); ++i )
    ff[ i ] = 1.0 / (26.0*26.0);
  return ff;
}

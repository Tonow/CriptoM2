#ifndef _FREQS_H_
#define _FREQS_H_

/**
 * @file freqs.h
 *
 * @author JOL
 */
#include <string>
#include <vector>

extern float freqLettresFr[26];
extern float freqDigrammesFr[676];

/**
* @param s string : une chaîne de caractères chiffrée (A-Z).
* @return freqLettre vector : la fréquence des lettres 'A' à 'Z' (0='A', 25='Z').
*/
std::vector<float> frequencies( const std::string & s );

/**
* @param frequences vector<float> ensemble de frequence d'apparition des lettre
*                                 du chiffre
* @param size int la taille du texte
* @return indice float  indice de coincidence
*/
float indiceDeCoincidence( std::vector<float> frequences , int size);

/**
 * Must be called before using frequencies services.
 *
 * @param dig_fname the file name containing the frequencies of
 * digrams (not necessarily normalized)
 *
 * @return 0 if everything went well.
 */
int initFreqs( const std::string & dig_fname );

/**
 * @param n a number between 0 and 25.
 *
 * @return the frequency of the letter ('A'+n) in common french as a
 * number between 0 and 1.
 */
float freqN( int n );

/**
 * @param m a number between 0 and 25.
 * @param n a number between 0 and 25.
 *
 * @return the frequency of the digram ('A'+m)('A'+n) in common french as a
 * number between 0 and 1.
 */
float freqMN( int m, int n );

/**
 * @return the frequency of the letters ('A'+n) in common french as a
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesFrench();

/**
 * @return the frequency of the letters ('A'+n) for a random text as
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesRandom();

/**
 * @return the frequency of the digrams ('AA'+n) in common french as a
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesFrenchDigrams();

/**
 * @return the frequency of the digrams ('AA'+n) for a random text as
 * numbers between 0 and 1.
 */
std::vector<float> frequenciesRandomDigrams();

#endif

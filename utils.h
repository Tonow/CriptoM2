#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <string>
#include <vector>

std::string readInput( std::istream & in );
std::string filter_az( const std::string & s );
std::string filter_AZ( const std::string & s );
std::string subtext( const std::string & s, int every, int shift );
// Extract digrams starting at shift and every every.
std::string subtext2( const std::string & s, int every, int shift );

std::string subtextDigram( const std::string & s, int every, int shift );

/**
   Le clair en minuscule.
   La clé est écrite en majuscule ("ADEF..DB").
   La sortie est en majuscule.
*/
std::string chiffreVigenere( const std::string & clair,
                             const std::string & cle );

/**
   Le chiffre en majuscule.
   La clé est écrite en majuscule ("ADEF..DB").
   La sortie est en minuscule.
*/
std::string dechiffreVigenere( const std::string & chiffre,
                               const std::string & cle );



/**
 * @return la fréquence des digrammes 'AA' à 'ZZ' (0='AA', 675='ZZ') en lisant 2 lettres par 2 lettres..
 */
std::vector<float> frequencies2( const std::string & s );

float coincidence( const std::vector<float> & f );

float coincidenceMutuelle( const std::vector<float> & f1,
	   const std::vector<float> & f2,
	   unsigned int shift2 = 0 );

float coincidence2( const std::vector<float> & f );

float coincidenceMutuelle2( const std::vector<float> & f1,
                            const std::vector<float> & f2,
                            unsigned int shift2 = 0 );

#endif /* _UTILS_H_ */

/*
* @param s string le texte d'entrer
* @return bool vrais cela est plus proche du francais que du random
*
*la fonction prend un texte calcule sont indice de coincidence et test si
*ce derniere est plus proche du frncais que du random
*/
bool itIsRandomOrFR ( const std::string & s );


/*
* @param s string le texte d'entrer
* @return bool vrais cela est plus proche du francais que du random
*
*la fonction prend un texte calcule sont indice de coincidence avec des digrammes
*et test si ce derniere est plus proche du francais que du random
*/
bool itIsRandomOrFrDigramm ( const std::string & s );

/**
*Chiffre un texte a l'aide d'une cle
*
*exemple d'utilisation --> $ cat texte.txt | ./chiffre-vigenere CLEDUTEXT
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "freqs.h"


using namespace std;



int main( int argc, char** argv )
{
	string s = readInput( cin );
	string cle = argv[1];
  	cout << chiffreVigenere( s , cle ) << endl;
  	return 0;
}

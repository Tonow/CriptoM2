#include <string>
#include <iostream>
#include <sstream>
#include "utils.h"

using namespace std;


std::string chiffreVigenere(const std::string & clair , const std::string & cle )
{
    ostringstream chiffre( ostringstream::out );
    for ( unsigned int i = 0; i < s.size(); ++i )
      {
        char c = s[ i ];
        if ( ( c >= 'a' ) && ( c <= 'z' ) )
  	s2 << c;
        else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
  	s2 << (char) ( c-'A'+'a' );
      }
    return chiffre.str();
}

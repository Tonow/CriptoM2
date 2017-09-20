#include <string>
#include <iostream>
#include <sstream>
#include "utils.h"

using namespace std;

string readInput( istream & in )
{
  ostringstream s( ostringstream::out );
  while ( in.good() )
    {
      char c;
      in >> c;
      s << c;
    }
  return s.str();
}

string filter_az( const std::string & s )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < s.size(); ++i )
    {
      char c = s[ i ];
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	s2 << c;
      else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	s2 << (char) ( c-'A'+'a' );
    }
  return s2.str();
}

string chiffreVigenere( const std::string & clair,
           const std::string & cle ){
  ostringstream chiffre( ostringstream::out );
  string claire = filter_az(clair);
  string clee = filter_AZ(cle);
  for ( unsigned int i = 0; i < claire.size(); ++i ){
    char c = claire[i];
    char s = clee[i%clee.size()];
    if ( ( c >= 'a' ) && ( c <= 'z' ) && ( s >= 'A' ) && ( s <= 'Z' ) && (((c-'a'+'A')+s) <= 'Z'))
  chiffre << (char) (c-'a'+'A')+s;
      else if  ( ((c-'a'+'A')+s) > 'Z' )
  chiffre << (char) ((((c-'a'+'A')+s) %  26 )+ 'A');
    }
  return chiffre.str();

}

string filter_AZ( const std::string & s )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = 0; i < s.size(); ++i )
    {
      char c = s[ i ];
      if ( ( c >= 'a' ) && ( c <= 'z' ) )
	s2 << (char) ( c-'a'+'A' );
      else if ( ( c >= 'A' ) && ( c <= 'Z' ) )
	s2 << c;
    }
  return s2.str();
}

string subtext( const string & s, int every, int shift )
{
  ostringstream s2( ostringstream::out );
  for ( unsigned int i = shift; i < s.size(); i += every )
    s2 << s[ i ];
   return s2.str();
}

#include <string>
#include <iostream>
#include <sstream>

#include "utils.h"
#include "freqs.h"

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

/**
*@param clair string : le texte a chiffrée
*@param cle string : la clé de chiffrement
*@return chiffre string : le texte chiffé
*
*la fonction chiffre le texte entré minuscule pour resortire le texte chiffré
*en majuscule
*/
string chiffreVigenere( const std::string & clair,
                        const std::string & cle )
{
  ostringstream chiffre( ostringstream::out );
  string claire = filter_az(clair);
  string clee = filter_AZ(cle);
  for ( unsigned int i = 0 ; i < claire.size() ; ++i )
  {
    char c = claire[i];
    char s = clee[i%clee.size()];

    if (  ( c >= 'a' ) &&
          ( c <= 'z' ) &&
          ( s >= 'A' ) &&
          ( s <= 'Z' ) &&
          (((c-'a'+'A')+s) <= 'Z')
        )
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


/*
* @param s string le texte d'entrer
* @return bool vrais cela est plus proche du francais que du random
*
*la fonction prend un texte calcule sont indice de coincidence et test si
*ce derniere est plus proche du frncais que du random
*/
bool itIsRandomOrFR ( const string & s )
{
    float indiceFR = 0.0780531 ;
    float indiceRandom = 0.0384615 ;

    std::vector<float> frequenFR( 26 );
    std::vector<float> frequenRandom( 26 );
    std::vector<float> frequen( 26 );
    std::vector<float> bestFrequen( 26 );

    frequenFR = frequenciesFrench();
    frequenRandom = frequenciesRandom();

    frequen = frequencies(s);

    float indiceCoincidence = indiceDeCoincidence(frequen , s.size()) ;

    /*
    cout << "\nidcFrance = " << indiceFR << endl;
    cout << "indiceRandom = " << indiceRandom << endl;
    cout << "idc = " << bestIndiceCoincidence << endl;
    cout << "bestSaut = " << bestSaut << endl;
    */

    if (((indiceFR + indiceRandom) / 2) > indiceCoincidence)
    {
      //cout<<"\nSemble aleatoire"<< endl ;
      return false;
    }
    else
    {
      //cout << "\n--> Ce texte semble francais ! "<< endl ;
      return true;
    }
}

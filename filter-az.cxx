/**
 * @file test_freqs.cxx
 *
 * @author JOL
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "freqs.h"

using namespace std;

std::string chiffreVigenere(const std::string & clair , const std::string & cle )
{
    int longueurCle = cle.size();

    cout << "Longueur de la chaine : " << longueurCle;

    //boost::to_upper(clair);
    //std::string chiffre = boost::to_upper_copy<std::string>(clair);

    cout << "La chaine contient : " << clair << endl;

    std::string chiffre;
    return chiffre;
}

int main( int argc, char** argv )
{
  string s = readInput( cin );
  chiffreVigenere(s, "lechiffre");
  cout << filter_az( s ) << endl;
}

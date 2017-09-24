Reponse au TP du lien suivant:
http://www.lama.univ-savoie.fr/~lachaud/Cours/INFO910/Tests/doc/html/tp0.html

type de commande qui fonctionne apres un "make" dans le dossier:

$ cat baudelaire.txt | ./filter-az > baudelaire-az.txt

$ cat baudelaire-az.txt | ./chiffre-vigenere TOTO

$ cat baudelaire-c1.txt | ./check-freqs

$ cat lafontaine-az.txt | ./chiffre-vigenere AZERTY | ./check-freqs


$ cat lafontaine-az.txt | ./chiffre-vigenere AZERTY | ./check-freqs 6 0

$ cat liberte-az.txt | ./chiffre-vigenere TESTECLE | ./detecte-vigenere

$ cat liberte-az.txt | ./chiffre-vigenere TESTECLE | ./detecte-vigenere-digram

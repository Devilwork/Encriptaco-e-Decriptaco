
#include <string>
#include <iostream>
using namespace std;
char converter(char ch, int chave)
{
    if (!isalpha(ch)) return ch;
    char offset = isupper(ch) ? 'A' : 'a';
    return (char)((((ch + chave) - offset) % 26) + offset);
}
string criptografar( string entrada, int chave )
{
    string saida = "";
    size_t len = entrada.size();
    for( size_t i = 0; i < len; i++ )
        saida += converter( entrada[i], chave );
    return saida;
}
string decriptografar( string entrada, int chave )
{
    return criptografar( entrada, 26 - chave );
}
int main( void )
{
    int chave = 13;
    string txt = "teste!";
    cout << "Texto Original: " << txt << endl;
    string cripto = criptografar( txt, chave );
    cout << "Texto Cifrado: " << cripto << endl;
    string decripto = decriptografar( cripto, chave );
    cout << "Texto Decifrado: " << decripto << endl;
    return 0;
}

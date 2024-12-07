//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <cctype>  // Para std::isdigit

#include "Unit1.h"
#include <fstream>     // Para manejar archivos con fstream
#include <vcl.h>       // Para usar AnsiString en RAD Studio (C++ Builder)
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


// Funci�n para convertir un car�cter a may�scula
char Mayus(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - ('a' - 'A'); // Convertir min�scula a may�scula
	}
	return c; // Si ya es may�scula o no es letra, devolver el car�cter tal cual
}

void ConvertirMayus(AnsiString nom) {
	char x;
	unsigned int p, q; // Usamos unsigned int en lugar de Cardinal
	fstream f(nom.c_str(), ios::in | ios::out); // modo de lectura y escritura

    if (!f.fail()) {
        p = 0;
        do {
			f.seekg(p);       // Posicionar el puntero de lectura en p
			x = f.get();      // Leer un car�cter
			q = f.tellg();    // Obtener la posici�n actual del puntero de lectura
			if (!f.eof()) {
                x = Mayus(x); // Convertir a may�scula
                f.seekp(p);   // Posicionar el puntero de escritura en p
                f.put(x);     // Escribir el car�cter convertido
                q = f.tellp(); // Obtener la posici�n actual del puntero de escritura
                if (x == 10)  // Si es un salto de l�nea (EOL)
                    p = p + 2;
                else
                    p++;
            }
        } while (!f.eof());
        f.close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute()){
		ConvertirMayus( OpenTextFileDialog1->FileName );
	}
}
//---------------------------------------------------------------------------





bool EsLetra(char z){
	AnsiString min, may, letra;
	min = "qwertyuiopasdfghjklzxcvbnm������";
	may = "QWERTYUIOPASDFGHJKLZXCVBNM������";

	letra = min + may;
    return letra.Pos(z) > 0;
}

bool EsExcep(char z){
	AnsiString ex = " ,.";
	return ex.Pos(z) > 0;
}

void EminNoAlfa(AnsiString nom) {
    char x;
	ifstream fi(nom.c_str());
    if (!fi.fail()) {
        ofstream fo("temporal.tmp");
		do {
            x = fi.get();
            if (!fi.eof()) {
                if (EsLetra(x) || EsExcep(x) || x == 10) {
                    fo.put(x);
                }
            }
        } while (!fi.eof());
        fi.close();
        fo.close();
		remove(nom.c_str());
        rename("temporal.tmp", nom.c_str());
    }
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute()){
		EminNoAlfa( OpenTextFileDialog1->FileName );
	}
}
//---------------------------------------------------------------------------




// Funci�n para convertir un car�cter a min�scula
char ToLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // Sumar la diferencia entre may�scula y min�scula
    }
    return c; // Si no es may�scula, devolver el car�cter sin cambios
}
void ConvertirTextToLowerCase(AnsiString nombreArchivo){
	char x;
	Cardinal posicionActual, posicionAnterior;
    fstream file( nombreArchivo.c_str(), ios::in | ios::out );

	if(!file.fail()){
		posicionActual = 0;

		do{
			file.seekg( posicionActual );
			x = file.get();
            posicionAnterior = file.tellg();
			if( !file.eof() ){
                x = ToLowerCase( x );
				file.seekg( posicionActual );
				file.put(x);
				posicionAnterior = file.tellg();

				if(x == 10){
                    posicionActual += 2;
				}else{
                    posicionActual++;
                }
			}

		}while( !file.eof() );
	}
    file.close();
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute()){
		ConvertirTextToLowerCase( OpenTextFileDialog1->FileName );
	}
}
//---------------------------------------------------------------------------




bool EsVocal( char c ){
	AnsiString vocal = "aeiouAEIOU";
	return vocal.Pos( c );
}
char CodificarVocal( char c ){
	if(EsVocal(c)){
		if(c == 'a') return '1';
		if(c == 'e') return '2';
		if(c == 'i') return '3';
		if(c == 'o') return '4';
		if(c == 'u') return '5';
		if(c == 'A') return '6';
		if(c == 'E') return '7';
		if(c == 'I') return '8';
		if(c == 'O') return '9';
		if(c == 'U') return '0';
	}
	return c;
}
void CodificarVocales( AnsiString nombreArchivo ){
	char x;
	ifstream file( nombreArchivo.c_str() );

	if( !file.fail() ){
      	ofstream temporal( "temporal.tmp" );
		do{
            x = file.get();
			if( !file.eof() ){
				x = CodificarVocal(x);
				temporal.put(x);
			}
		}while( !file.eof() );

		file.close();
		temporal.close();
		remove( nombreArchivo.c_str() );
		rename( "temporal.tmp", nombreArchivo.c_str() );
	}
}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute()){
		CodificarVocales( OpenTextFileDialog1->FileName );
	}
}
//---------------------------------------------------------------------------


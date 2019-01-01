				//autor:ament matija
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<string>
#include<array>
using namespace std;

string ispis(string p[]);	//deklaracija funkcije ispisa tablice

int main()
{
	int plaX[15];		//prostor za pohranu odabira igraca
	int plaO[15];		//prostor za pohranu odabira igraca

	int unosX = 0;
	int unosO = 0;
	
	bool uneseno = false;
	int uneseniNiz[9];

	int turnCnt = 0;
	int playerCnt = 0;
	int switchCnt = 1;

	bool win = false;
	bool w_message = false;
	string winner;
	string ispisniNiz[11] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
	//------------------------------------------------------------------------------------------------------------------------

	ispis(ispisniNiz);		//pocetni ispis tablice na zaslon

	while (!win)
	{		
		if (switchCnt % 2 == 0)							//switch izmedju playera
		{			
			int nizSize = sizeof(uneseniNiz) / sizeof(*uneseniNiz);		// za uvjetovanje u iducoj for petlji
			std::cout << "\nUnesi broj polja:";
			std::cout << "\nX:";
			std::cin >> unosX;						//prihvat unosa

			bool uneseno = false;						//provjera dostupnosti odabranog polja(uneseno?)
			for (int i = 0; i <= nizSize; i++)		
			{										
				if (uneseniNiz[i] == unosX)			 
				{									
					uneseno = true;					
				}									
			}										

			if ((unosX >= 1) && (unosX <= 9) && (!uneseno))			//unos su slobodna polja 1-9
			{
				playerCnt++;
				turnCnt++;
				++switchCnt;
				uneseno = false;
				uneseniNiz[turnCnt - 1] = unosX;
				plaX[playerCnt] = unosX;
			}			
		}
																		//drugo stanje switcha:
		else{
			int nizSize = sizeof(uneseniNiz) / sizeof(*uneseniNiz);		// za uvjetovanje u iducoj for petlji
			std::cout << "\nUnesi broj polja:";
			std::cout << "\nO:";
			std::cin >> unosO;						//prihvat unosa 
													
			bool uneseno = false;						//provjera dostupnosti odabranog polja
			for (int i = 0; i <= nizSize; i++)			
			{											
				if (uneseniNiz[i] == unosO)				
				{										
					uneseno = true;						
				}										
			}											

			if ((unosO >= 1) && (unosO <= 9) && (!uneseno))
			{
				playerCnt++;
				turnCnt++;
				++switchCnt;
				uneseno = false;
				uneseniNiz[turnCnt - 1] = unosO;
				plaO[playerCnt] = unosO;
			}
			
		}
	//------------------------------------------------------------------------------------------------------------------------
		for (int i = 0; i <= 9; i++)		//		pretvaranje unosa u niz krizica i kruzica
		{									
			for (int j = 0; j <=9 ; j++)	//		pretvaranje unosa X-a
			{										
				if (i == plaX[j])			
				{							
					ispisniNiz[i-1] = "x";	
				}							
			}								
			for (int k = 0; k <=9; k++)		//	pretvaranje unosa O-a
			{								
				if (i == plaO[k])			
				{							
					ispisniNiz[i-1] = "o";	
				}							
			}								
		}									
	//------------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------------------
		if (switchCnt % 2 != 0)																
		{		//provjera pobjednickih kombinacija kod X
			if ((ispisniNiz[0] == "x" && ispisniNiz[1] == "x" && ispisniNiz[2] == "x") ||	
				(ispisniNiz[3] == "x" && ispisniNiz[4] == "x" && ispisniNiz[5] == "x") ||
				(ispisniNiz[6] == "x" && ispisniNiz[7] == "x" && ispisniNiz[8] == "x") ||

				(ispisniNiz[0] == "x" && ispisniNiz[3] == "x" && ispisniNiz[6] == "x") ||
				(ispisniNiz[1] == "x" && ispisniNiz[4] == "x" && ispisniNiz[7] == "x") ||
				(ispisniNiz[2] == "x" && ispisniNiz[5] == "x" && ispisniNiz[8] == "x") ||

				(ispisniNiz[0] == "x" && ispisniNiz[4] == "x" && ispisniNiz[8] == "x") ||
				(ispisniNiz[2] == "x" && ispisniNiz[4] == "x" && ispisniNiz[6] == "x"))
			{
				winner = "krizic";
				w_message = true;
				win = true;				
			}
		}
		else
		{		 //provjera pobjednickih kombinacija kod O
			if ((ispisniNiz[0] == "o" && ispisniNiz[1] == "o" && ispisniNiz[2] == "o") ||		
				(ispisniNiz[3] == "o" && ispisniNiz[4] == "o" && ispisniNiz[5] == "o") ||
				(ispisniNiz[6] == "o" && ispisniNiz[7] == "o" && ispisniNiz[8] == "o") ||

				(ispisniNiz[0] == "o" && ispisniNiz[3] == "o" && ispisniNiz[6] == "o") ||
				(ispisniNiz[1] == "o" && ispisniNiz[4] == "o" && ispisniNiz[7] == "o") ||
				(ispisniNiz[2] == "o" && ispisniNiz[5] == "o" && ispisniNiz[8] == "o") ||

				(ispisniNiz[0] == "o" && ispisniNiz[4] == "o" && ispisniNiz[8] == "o") ||
				(ispisniNiz[2] == "o" && ispisniNiz[4] == "o" && ispisniNiz[6] == "o"))
			{
				winner = "kruzic";
				w_message = true;
				win = true;				
			}
		}
	//------------------------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------------------
		
		system("cls");				// clean screen
		ispis(ispisniNiz);			// generiranje tablice iz niza "ispisniNiz"
		
		if (turnCnt > 8) { break; }		//break ako je broj turnova veci od 8, a win je i dalje false
	}
	
	if (w_message==true)
	{			
		std::cout << "\nCestitam!\nPobjednik je " << winner << "!\a\n\n\n\n\n\n\n\n\n";
	}
	else
	{	
		std::cout << "\n\aNerijeseno!"<<endl;
	}
	return 0;

}

string ispis(string p[]) {	   //ispis tablice

	std::cout << "  -------------          -------------" << endl;
	std::cout << "  | " << p[0] << " | " << p[1] << " | " << p[2] << " |          | 1 | 2 | 3 |" << endl;
	std::cout << "  | " << p[3] << " | " << p[4] << " | " << p[5] << " |          | 4 | 5 | 6 |" << endl;
	std::cout << "  | " << p[6] << " | " << p[7] << " | " << p[8] << " |          | 7 | 8 | 9 |" << endl;
	std::cout << "  -------------          -------------" << endl;
	return "print";
}


// ProiectPPCBinPacking.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

// Global variables
int Ace = 1;
int J = 10;
int Q = 10;
int K = 10;
int deck[] = {Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
			  Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
			  Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
			  Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};

/* Begin Function:shuffler **************************************************


****************************************************************************/
int *shuffler()
{
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++)
		swap(deck[i], deck[rand() % 52]);
	cout << "deck:" << endl;
	int t = 0;
	for (int j : deck)
	{
		cout << j << " ,";
		t++;
		if (t % 13 == 0)
			cout << endl;
	}
	return deck;
}
/* End Function:shuffler ***************************************************/

void ClaculProbabilitate()
{
	int sumaBin = 0;
	double probabilitate = 0;
	int n = sizeof(deck) / sizeof(deck[0]);
	do
	{
		for (int i = 0; i < n; i++)
		{
			int cartiCareNuDauBust = 0;
			int cartiCareDauBust = 0;
			int puncteRamasePanaLaBust = 21;
			sumaBin += deck[i];
			puncteRamasePanaLaBust -= sumaBin;

			if (puncteRamasePanaLaBust > 0)
			{
				for (int j = i + 1; j < n - i + 1; j++)
				{
					if (deck[j] <= puncteRamasePanaLaBust)
					{
						cartiCareNuDauBust++;
					}
					else
					{
						cartiCareDauBust++;
					}
				}

				double cazuriFavorabile = cartiCareDauBust;
				double cazuriPosibile = n - i;

				probabilitate = cazuriFavorabile / cazuriPosibile;
				cout << "Probabilitate : " << probabilitate << endl;
			}
			else
			{
				return;
			}
		}
	} while (sumaBin <= 21);
}

// Returns number of bins required using next fit online algorithm
int nextFit(int weight[], int n, int c)
{
	// Initialize result (Count of bins) and remaining
	// capacity in current bin.
	int res = 0, bin_rem = c;

	// Place items one by one
	for (int i = 0; i < n; i++)
	{
		// If this item can't fit in current bin
		if (weight[i] > bin_rem)
		{
			res++; // Use a new bin
			bin_rem = c - weight[i];
		}
		else
			bin_rem -= weight[i];
	}
	return res;
}

int main()
{
	// Shuffle deck
	shuffler();

	//int binCapacity = 21;
	//int n = sizeof(deck) / sizeof(deck[0]);
	//cout << "Number of bins required in Next Fit : "
	//	<< nextFit(deck, n, binCapacity);

	ClaculProbabilitate();
	return 0;
}

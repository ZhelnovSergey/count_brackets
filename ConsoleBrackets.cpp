// ConsoleBrackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;



int Counter = 0;
void CountBrackets( vector<char> vectBrackets, int N, int Left, int Right, bool flLeft, bool flRight )
{			
	if( flLeft )
		vectBrackets.push_back( '(' );

	if( flRight )
		vectBrackets.push_back( ')' );
	
	if( Left + Right == 2*N )
	{
		Counter++;

		for( int i = 0; i < vectBrackets.size();i++ )
			printf( "%c", vectBrackets[ i ] );
		printf( "\n" );

		vectBrackets.clear();

		return;
	}
	
	if( Left < N )
	{
		CountBrackets( vectBrackets, N, Left + 1, Right, true, false );
	}	
	
	if( (Right < N) && (Right < Left) )
	{
		CountBrackets( vectBrackets, N, Left, Right + 1, false, true );
	}
}

unsigned char array_yliana[10];

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	printf( "Num brackets: " );
	scanf( "%d", &N );
	
	vector<char> vectBrackets;
	
	CountBrackets( vectBrackets, N, 0, 0, false, false );
	printf( "Combinations: %d\n", Counter );

	return 0;
}


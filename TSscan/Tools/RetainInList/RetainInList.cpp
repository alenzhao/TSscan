#include "../../cswu/Common.h"
#include "../../cswu/Table.h"
#include "../../cswu/Map.h"

void PrintUsage();

int main(int argc, char **argv)
{
	Str2BoolMap theMap;
	char str[MaxLineSize+1];

	if(argc != 4)
	{	PrintUsage();	return 1;	}	

	theMap.AddIntoMap( argv[2], atoi(argv[3])-1 );

	for( TableRow theRow; theRow.Get(); )
	{
		ColCpy( str, theRow.Column(atoi(argv[1])-1) );		

		if( theMap.IsInMap(str) == true )
			theRow.Print();
	}

	return 0;
}

void PrintUsage()
{
	ErrMsg("Retain the unlisted entries.\n\n");

	ErrMsg("RetainInList [Key1] [List] [Key2]\n\n");

	ErrMsg("[Key1]          INTEGER     The key column in the table.\n");
	ErrMsg("[List]          FILE        The filename of a table as the list.\n");
	ErrMsg("[Key2]          INTEGER     The key column in the list.\n\n");

	ErrMsg("Example: Retain the rows if their 'subject id' are occured in the list.balst as 'query id'.\n");
	ErrMsg("cat Input | RemoveInList 2 list.blast 1 > Output\n\n");
}

#include <stdlib.h>
#include <stdio.h>
#include "rlutil.h"
#include "TpgAed.h"


main()
{
	int op=0;
	
	menu(op);
	
	switch(op)
	{
		case 0:
			
			while(op!=4)
			{
				coach(op);
			
				switch(op)
				{
					case 0:
						login();
						break;
					case 1:
						coachList();
						break;
					case 4:
						break;
				}
			}
			break;
		case 1:
				
			while(op!=4)
			{
				recep(op);
			
				switch(op)
				{
					case 0:
						login();
						break;
					case 1:
						coachList();
						break;
					case 4:
						break;
				}
			}
			break;
		case 2:
				
			while(op!=4)
			{
				admin(op);
			
				switch(op)
				{
					case 0:
						login();
						break;
					case 1:
						coachList();
						break;
					case 4:
						break;
				}
			}
			break;
		case 4:
			
			break;
	}
	
}


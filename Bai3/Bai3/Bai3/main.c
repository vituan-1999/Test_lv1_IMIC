#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define sizeObject 6
#define sizeState 4

// edit database follow the json file
#define device1 "light"
#define device2 "fan"
#define device3 "motor"
#define state_of_device1 0
#define state_of_device2 0
#define state_of_device3 0

typedef struct
{
	char object[sizeObject];
	char state[sizeState];
}JSON_t;

void takeValue(JSON_t *json, char findState)	// print value, take value, reset struct
{
	char state1 = 0, state2 = 0, state3 = 0;	// state of 3 objects from json
	if (!strcmp(json->object, device1))
	{
		if (!findState)
		{
			if (!strcmp(json->state, "on"))
				state1 = 1;
			else
				state1 = 0;
			printf("%d\n", state1);
		}
		else
			printf("\t%s: ", device1);
	}
	else if (!strcmp(json->object, device2))
	{
		if (!findState)
		{
			if (!strcmp(json->state, "on"))
				state2 = 1;
			else
				state2 = 0;
			printf("%d\n", state2);
		}
		else
			printf("\t%s: ", device2);
	}
	else if (!strcmp(json->object, device3))
	{
		if (!findState)
		{
			if (!strcmp(json->state, "on"))
				state3 = 1;
			else
				state3 = 0;
			printf("%d\n", state3);
		}
		else
			printf("\t%s: ", device3);
	}

	if (!findState)	// reset struct for new cycle when the cursor at the end of each line
	{
		for (char i = 0; i < sizeObject; i++)
		{
			json->object[i] = 0;
			if (i < sizeState)
				json->state[i] = 0;
		}
	}
}

int main(void)
{
	char character = 0;					// store string data
	char find = 0;						// find " "
	char findState = 0;					// seperate (1: object and 0: state) in json
	char object = 0, state = 0;			// count variable
	JSON_t json = { 0 };
	FILE *file = fopen("data.txt", "r");
	if (file == NULL)
	{
		printf("\n\tFail to open file!\n\n");
		exit(1);
	}

	printf("\n\tSuccess to open file!");
	printf("\n\tThe main content in file:\n");
	character = fgetc(file);
	while (character != EOF)
	{
		if (character == 34)		// "
		{
			find = !find;
			if (find)				// start the content in " "
				findState = !findState;
			else
			{
				takeValue(&json, findState);
			}
			object = 0; state = 0;	// reset count varible
		}
		else
		{
			if (find)		// "
			{
				if (findState)
				{
					json.object[object] = character;
					object++;
				}
				else
				{
					json.state[state] = character;
					state++;
				}

			}
		}
		character = fgetc(file);
	}
	fclose(file);
	file = NULL;
	return 0;
}

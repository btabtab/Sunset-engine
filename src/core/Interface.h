#include <stdlib.h>
#include <stdio.h>

typedef struct Interface
{
	/*
	The (void*) in the arguments is to be typecast
	to whatever struct for the data that you want to use.
	*/

	/*Takes the width and height of the desired window and it's name.*/
	void (*RenderInitialise)(int, int, const char*);
	/*This will render the application's data.*/
	void (*Render)(void*);
	/*This will handle the input to the game. by
	returning the key pressed as an integer*/
	int (*InputHandle)();
	/*This will be if you want to alter how the application's data is processed.*/
	void (*specialProcess)(void*);

}
Interface;

/*
This will give the default
interface for the engine, it uses Raylib
for renering and input.
*/
Interface getTestInterface();

/*
This function checks that the application is
set up properly.
returns:
	true if the Interface is or isn't configured properly
	but can be configured to a safe default.
	
	false if the Interface isn't configured
	properly and cannot be corrected.
*/
bool ApplicationInitialise(Interface);

//This is the function that will take the interface and then run the application
void Application(Interface);

Interface getTestInterface()
{
}

bool ApplicationInitialise(Interface interface)
{
	if(interface.specialProcess == NULL)
	{
		printf("interface.specialProcess is null, cannot assign default, exiting program.\n");
		return false;
	}
	
	if(interface.Render == NULL)
	{
		printf("interface.Render is null, assigning default renderer.\n");
	}
	
	if(interface.InputHandle == NULL)
	{
		printf("interface.InputHandle is null, cannot assign default, exiting program.\n");
		return false;
	}

	if(interface.RenderInitialise == NULL)
	{
		printf("interface.RenderInitialise is null, Assigning default.\n");
	}
	return false;
}

void Application(Interface);

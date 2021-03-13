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
	/*This will handle the input to the game.*/
	void (*InputHandle)();
	/*This will be if you want to alter how the application's data is processed.*/
	void (*specialProcess)(void*);

}
Interface;

//This is the function that will take the interface and then run the application
void Application(Interface*);
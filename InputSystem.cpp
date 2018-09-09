/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "InputSystem.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "PauseEvent.h"
#include "EscapeEvent.h"
#include "UpArrowEvent.h"
#include "DownArrowEvent.h"
#include "RightArrowEvent.h"
#include "LeftArrowEvent.h"
#include "SpaceBarEvent.h"
#include "allegro5\allegro.h"


InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::initInputSystem()
{
	//initializes and registers the keyboard and creates an event queue
	mKeyboardEventQueue = al_create_event_queue();
	al_register_event_source(mKeyboardEventQueue, al_get_keyboard_event_source());
	al_register_event_source(mKeyboardEventQueue, al_get_mouse_event_source());
	
}

void InputSystem::cleanupInputSystem()
{
}

void InputSystem::updateInputSystem(double dt)
{
	updateKeyboard();
}

void InputSystem::updateKeyboard()
{
	//different variables needed for keyboard/mouse states
	int posX, posY;
	bool myBool = false;
	bool isPressedMouse = false;
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_KEYBOARD_STATE keyState;

	//Creates an event system
	EventSystem* mEventSystem = EventSystem::getInstance();
	ALLEGRO_EVENT ev;

	//gets the state of the mouse and keyboard
	al_get_keyboard_state(&keyState);
	al_get_mouse_state(&mouseState);

	//does this while there is still another event to process
	while (al_get_next_event(mKeyboardEventQueue, &ev))
	{
		//checks to see if the escape key is pressed
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			//fires off event
			mEventSystem->fireEvent(EscapeEvent(true));
		}
		
		//checks to see if up key is pressed
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			//fires off event
			mEventSystem->fireEvent(UpArrowEvent());
		}

		//checks to see if the down key is pressed
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			//fires off event
			mEventSystem->fireEvent(DownArrowEvent());
		}

		//checks to see if the left key is pressed
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			//fires off event
			mEventSystem->fireEvent(LeftArrowEvent());
		}

		//checks to see if the right key is pressed
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			//fires off event
			mEventSystem->fireEvent(RightArrowEvent());
		}

		//checks to see if the space key is pressed
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
		{
			//fires off event
			mEventSystem->fireEvent(SpaceBarEvent());
		}

		//checks to see if the mouse button is pressed
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button == 1)
		{
			//gets the position of the mouse and calls an add unit event at the position
			isPressedMouse = false;
			posX = mouseState.x;
			posY = mouseState.y;
			mEventSystem->fireEvent(AddUnitEvent(posX, posY));

		}

		//checks to see if the right mouse button is pressed 
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button == 2)
		{
			//gets the coordinates of the mouse button and then fires off an event to delete a unit at that place if there is one
			posX = mouseState.x;
			posY = mouseState.y;
			mEventSystem->fireEvent(DeleteUnitEvent(posX, posY));

		}
	}

	

}


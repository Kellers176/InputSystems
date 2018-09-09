/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "InputTranslator.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "PauseEvent.h"
#include "EscapeEvent.h"
#include "InstantiateEvent.h"
#include "RemoveEvent.h"
#include "TempStopEvent.h"
#include "StopEvent.h"
#include "UpArrowEvent.h"
#include "DownArrowEvent.h"
#include "RightArrowEvent.h"
#include "LeftArrowEvent.h"
#include "SpaceBarEvent.h"
#include "MoveDownEvent.h"
#include "MoveLeftEvent.h"
#include "MoveRightEvent.h"
#include "MoveUpEvent.h"
#include "NextLevelEvent.h"


InputTranslator::InputTranslator()
{
	
}

InputTranslator::~InputTranslator()
{
	cleanupInputTranslator();
}

void InputTranslator::initInputTranslator()
{
	//adds listeners to the scripts
	EventSystem::getInstance()->addListener(ADD_UNIT_EVENT, this);
	EventSystem::getInstance()->addListener(DELETE_UNIT_EVENT, this);
	EventSystem::getInstance()->addListener(PAUSE_EVENT, this);
	EventSystem::getInstance()->addListener(ESCAPE_EVENT, this);
	EventSystem::getInstance()->addListener(LEFT_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(RIGHT_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(UP_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(DOWN_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(SPACE_BAR_EVENT, this);
}

void InputTranslator::cleanupInputTranslator()
{
	//removes listeners from the script
	EventSystem::getInstance()->removeListener(ADD_UNIT_EVENT, this);
	EventSystem::getInstance()->removeListener(DELETE_UNIT_EVENT, this);
	EventSystem::getInstance()->removeListener(PAUSE_EVENT, this);
	EventSystem::getInstance()->removeListener(ESCAPE_EVENT, this);
	EventSystem::getInstance()->removeListener(LEFT_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(RIGHT_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(UP_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(DOWN_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(SPACE_BAR_EVENT, this);
}

void InputTranslator::handleEvent(const Event & theEvent)
{
	//gets the event type and continues with the appropriate action
	if (theEvent.getType() == ADD_UNIT_EVENT)
	{
		//Sends off an event to add a unit
		const AddUnitEvent& addEvent = static_cast<const AddUnitEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(InstantiateEvent(addEvent.getPosX(), addEvent.getPosY()));

	}
	if (theEvent.getType() == DELETE_UNIT_EVENT)
	{
		//sends off an event to delete a unit
		const DeleteUnitEvent& deleteEvent = static_cast<const DeleteUnitEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(RemoveEvent());

	}
	if (theEvent.getType() == PAUSE_EVENT)
	{
		//sends off an event to pause the game
		const PauseEvent& pauseEvent = static_cast<const PauseEvent&>(theEvent);
 		EventSystem::getInstance()->fireEvent(TempStopEvent());

	}
	if (theEvent.getType() == ESCAPE_EVENT)
	{
		//sends off an event to escape and quit the game
		const EscapeEvent& escapeEvent = static_cast<const EscapeEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(StopEvent());

	}
	if (theEvent.getType() == UP_ARROW_EVENT)
	{
		//sends off an event to move the player up
		const UpArrowEvent& upEvent = static_cast<const UpArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveUpEvent());
	}
	if (theEvent.getType() == RIGHT_ARROW_EVENT)
	{
		//sends an event to move the player right
		const RightArrowEvent& upEvent = static_cast<const RightArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveRightEvent());
	}
	if (theEvent.getType() == LEFT_ARROW_EVENT)
	{
		//sends an event to move the player left
		const LeftArrowEvent& upEvent = static_cast<const LeftArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveLeftEvent());
	}
	if (theEvent.getType() == DOWN_ARROW_EVENT)
	{
		//sends an event to move the player down
		const DownArrowEvent& upEvent = static_cast<const DownArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveDownEvent());
	}
	if (theEvent.getType() == SPACE_BAR_EVENT)
	{
		//sends an event to move game to the next level
		const SpaceBarEvent& spaceEvent = static_cast<const SpaceBarEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(NextLevelEvent());
	}
		
}

void InputTranslator::updateInputTranslator(double dt)
{
}

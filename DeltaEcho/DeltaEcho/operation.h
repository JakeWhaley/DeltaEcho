enum GOP {
	ENDOPERATION,	//Tells thread to tell every daughter thread to halt
	ENDTHREAD,		//Tells thread to end itself and all daughter threads
	TEXT,			//Prepare for opening & saving text files
	SQLITE,			//Prepare for opening & saving SQLite databses
	MODELOPEN,		//Load a new model into the model queue
	MODELCOPY,		//Copy an existing model into the model	queue
	MODELDELETE,	//Delete a specific model in the model queue
	MODELOP,		//Operate on a particular model
	VARMOD,			//Create or Modify a variable in the variable queue
	THREADSLEEP,	//Tell this thread to sleep for X milliseconds
	THREADLOCK,		//Tell this thread to lock until it's unlocked
	THREADUNLOCK,	//Unlock said thread
	GRENDER,		//Render Graphics based on current model and variable queue
	ARENDER,		//Render Audio based on current sound and variable queue
	CLEANUP,		//Search for turned off models, sounds, & variables & dispose
	GNORMALIZE,		//Applies delta time animations for msec
	ANORMALIZE,		//Applies delta time on sounds
	TSTREAM,		//Prepares thread for text stream operations
	PATHFIND,		//Prepares thread for AI Pathfinding
	NETOP,			//Prepares thread for network operations
	TRIGGERPROCESS,	//Process all existing triggers
	TRIGGEROP,		//Adds/removes triggers
	AIPHYS,			//AI that handles terrain traversal & actions
	AIABSTRACT,		//AI that handles decision making

}
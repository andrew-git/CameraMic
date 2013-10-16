#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif


#include <hx/CFFI.h>
#include "CameraMic.h"


using namespace cameramic;

AutoGCRoot *handler = 0;

static value cameramic_getappdirectorypath ()
{
	//return val_get_string(GetAppDirectoryPath());
	return alloc_string(GetAppDirectoryPath());
}
DEFINE_PRIM (cameramic_getappdirectorypath, 0);

static void cameramic_getphoto (value hxObject)
{
	handler = new AutoGCRoot(hxObject);
	// message is a String, just get its value
    // const char* cStr = val_get_string(message);
    // call our Tweet function with it
    // and return true or false to haxe
    GetPhoto();
}
DEFINE_PRIM (cameramic_getphoto, 1);

static void cameramic_startrecordingaudio (value hxObject)
{
	handler = new AutoGCRoot(hxObject);
	StartRecordingAudio();
}
DEFINE_PRIM (cameramic_startrecordingaudio, 1);

static void cameramic_stoprecordingaudio ()
{
	StopRecordingAudio();
}
DEFINE_PRIM (cameramic_stoprecordingaudio, 0);

static void cameramic_playaudio (value inputValue)
{
	PlayAudio(val_get_string(inputValue));
}
DEFINE_PRIM (cameramic_playaudio, 1);


extern "C"
{
	void cameramic_main ()
	{

	}
	DEFINE_ENTRY_POINT (cameramic_main);

	int cameramic_register_prims ()
	{
		return 0;
	}

	// event dispatcher
	void cameramic_filename_callback(const char *filename) 
	{
	 	// value o = alloc_empty_object();
	 	// alloc_field(o, val_id("filename"), alloc_string(filename));
	 	
	 	val_call1(handler->get(), alloc_string(filename));
	}
}
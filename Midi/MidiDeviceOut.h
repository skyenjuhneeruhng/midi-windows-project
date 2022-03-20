#ifndef __MIDI_DEVICE_OUT_H__
#define __MIDI_DEVICE_OUT_H__

#include <Windows.h>
#include <mmsystem.h>

class MidiDeviceOut
{
private:
	HMIDIOUT sender;
public:
	MidiDeviceOut();
	~MidiDeviceOut();

	// Device manipulation
	void open(unsigned int device_id);
	void close();
	bool sendData(unsigned long data);
};


#endif /* __MIDI_DEVICE_OUT_H__ */

#include "stdafx.h"
#include "MidiDeviceOut.h"


MidiDeviceOut::MidiDeviceOut()
{
}

MidiDeviceOut::~MidiDeviceOut()
{
}

void MidiDeviceOut::open(unsigned int device_id)
{
	MMRESULT result;

	result = midiOutOpen(&sender, device_id, 0, 0, CALLBACK_NULL);
	if (result != 0) {
		//TODO log this error
		return;
	}
}

void MidiDeviceOut::close()
{
	midiOutReset(sender);
	midiOutClose(sender);
}

bool MidiDeviceOut::sendData(unsigned long data)
{
	MMRESULT result;
	result = midiOutShortMsg(sender, data);
	if (result != MMSYSERR_NOERROR) {
		//TODO log this error
		return false;
	}
	return true;
}

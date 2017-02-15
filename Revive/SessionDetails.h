#pragma once

#include <map>

class SessionDetails
{
public:
	enum Hack
	{
		// Hack: Wait for running start in ovr_GetTrackingState().
		// Games like Dirt Rally do a lot of rendering-independent work on the rendering thread.
		// Calling WaitGetPoses() in ovr_GetTrackingState() allows Dirt Rally to do that work before
		// we block waiting for running state.
		HACK_WAIT_IN_TRACKING_STATE,
	};

	SessionDetails();
	~SessionDetails();

	bool UseHack(Hack hack);

private:
	struct HackInfo
	{
		const char* m_filename; // The filename of the main executable
		Hack m_hack;            // Which hack is it?
		bool m_usehack;         // Should it use the hack?
	};

	static HackInfo m_known_hacks[];
	
	std::map<Hack, HackInfo> m_hacks;
};


#pragma once
#include <chrono>

namespace antares
{
	class Time
	{
	private:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_rep = clock::rep;

	public:
		Time() : 
			m_startTime{ clock::now() },
			m_frameTime{ clock::now() }
		{}

		void Tick();
		void Reset() { m_startTime = clock::now(); }

		clock_rep GetElapsedNanoseconds();
		clock_rep GetElapsedMicroseconds();
		clock_rep GetElapsedMilliseconds();
		float GetElapsedSeconds();

		float GetTime() { return m_time; }
		float getDeltaTime() { return m_deltaTime; }

	private:
		float m_time;
		float m_deltaTime;
		clock::time_point m_startTime;
		clock::time_point m_frameTime;
	};

	extern Time g_time;
}
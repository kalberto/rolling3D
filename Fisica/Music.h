#include<SDL.h>
#include<SDL_mixer.h>
#include<vector>



class Sons
{
private:

	std::vector<Mix_Music*>m_list_sons;
public:
	void Create()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048);
		m_list_sons.push_back(Mix_LoadMUS("BxB.wav"));
	}

	static Sons & getInstance()
	{
		static Sons som;

		return som;
	}

	static void TocaSom(int n)
	{
		Mix_PlayMusic(getInstance().m_list_sons[n], 1);
	}
};
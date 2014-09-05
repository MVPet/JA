#ifndef _ANIMATIONHOLDER
#define _ANIMATIONHOLDER

#include "Animation.hpp"
#include <memory>
#include <assert.h>

class AnimationHolder
{
public:
	void		load(std::string charName, std::string name, std::vector<AnimFrame*> fData, bool loop);
	//void		load(Animation* animation, std::string name);
	Animation*	get(std::string name);

private:
	std::map<std::string, Animation*> AnimationMap;
};

#endif // AnimationHolder.hpp
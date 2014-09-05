#include "AnimationHolder.hpp"

void AnimationHolder::load(std::string charName, std::string name, std::vector<AnimFrame*> fData, bool loop)
{
	Animation* anim;
	anim = new Animation(charName, name, fData, loop);
	auto inserted = AnimationMap.insert(std::make_pair(name, anim));
	assert(inserted.second);
}

/*void AnimationHolder::load(Animation* animation, std::string name)
{
	Animation* anim = animation;
	auto inserted = AnimationMap.insert(std::make_pair(name, anim));
	assert(inserted.second);
}*/

Animation* AnimationHolder::get(std::string name)
{
	auto found = AnimationMap.find(name);
	assert(found != AnimationMap.end());

	return found->second;
}
#include "AnimationHolder.hpp"

void AnimationHolder::load(std::string charName, std::string animName, int frameAmount)
{
	Animation* anim;
	anim = new Animation(charName, animName, frameAmount);
	auto inserted = AnimationMap.insert(std::make_pair(animName, anim));
	assert(inserted.second);
}

Animation* AnimationHolder::get(std::string name)
{
	auto found = AnimationMap.find(name);
	assert(found != AnimationMap.end());

	return found->second;
}
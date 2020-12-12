#ifndef ANIMATION_H
#define ANIMATION_H

struct Animation
{
	int index = 0;
	int speed = 0;
	int frames = 0;

	Animation(){}
	Animation(int index_, int speed_, int frames_)
	{
		index = index_;
		speed = speed_;
		frames = frames_;


	}

};
#endif // !ANIMATION_H




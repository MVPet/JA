#ifndef _CATEGORY
#define _CATEGORY

// Entity/scene node category, used to dispatch commands
namespace Category
{
	enum Type
	{ 
		None	= 0, 
		Scene	= 1 << 0, 
		Player	= 1 << 1,
		Enemy	= 1 << 2,
	};
}

#endif // Category.hpp
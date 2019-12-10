#ifndef ECS_TYPE_REGISTRATOR_H_
#define ECS_TYPE_REGISTRATOR_H_

#include "Types.h"

namespace ecs
{
	namespace utils
	{
		template<typename TypeFamily>
		class TypeRegistrator
		{
			static TypeID m_counter;

		public:
			template<typename Type>
			static const TypeID registerNewType()
			{
				static const TypeID STATIC_TYPE_ID = m_counter++;
				return STATIC_TYPE_ID;
			}
		};
	}
}

#endif // ECS_TYPE_REGISTRATOR_H_

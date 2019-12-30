#ifndef ECS_SYSTEM_H_
#define ECS_SYSTEM_H_

#include <vector>
#include "Types.h"
#include "TypeRegistrator.h"

namespace ecs
{
	class IComponent;

	class ISystem
	{
	public:
		virtual void update(double delta_ms, IComponent** p_components) = 0;
	};

	TypeID utils::TypeRegistrator<ISystem>::m_counter = 0;

	template<typename T>
	class System : public ISystem
	{
		/// Class members
	private:
		std::vector<TypeID> m_componentTypes;

	public:
		static const TypeID ID;

		/// Class methods
	public:
		const std::vector<TypeID>& getComponentTypes()
		{
			return m_componentTypes;
		}

	protected:
		void addComponentType(TypeID type)
		{
			const auto it = std::find(m_componentTypes.begin(), m_componentTypes.end(), type);

			if (it == m_componentTypes.end())
				m_componentTypes.push_back(type);
		};
	};

	template<typename T>
	const TypeID System<T>::ID(utils::TypeRegistrator<ISystem>::registerNewType<T>());
}

#endif // ECS_SYSTEM_H_
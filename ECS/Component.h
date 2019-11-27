#ifndef ECS_COMPONENT_H_
#define ECS_COMPONENT_H_

namespace ecs
{
	using ComponentID = size_t;
	using ComponentTypeID = size_t;

	class BaseComponent
	{
	public:
		BaseComponent() {}; // TODO: private? protected?
		virtual ~BaseComponent() {}; // TODO: private? protected?

		inline ComponentID GetComponentID() const
		{
			return this->m_id;
		}

		inline ComponentTypeID GetComponentTypeID() const
		{
			return this->m_type;
		}

	private:
		ComponentID m_id;
		ComponentTypeID m_type;		
	};

	class Component : public BaseComponent
	{

	};
}


#endif  // ECS_COMPONENT_H_

#include "Box2DCollisionComponent.h"
#include "Box2DPhysicsComponent.h"
#include "SpriteComponent.h"
#include "Framework/Actor.h"

namespace antares {
	CLASS_DEFINITION(Box2DCollisionComponent);

	bool Box2DCollisionComponent::Initialize() {
		auto component = m_owner->GetComponent<Box2DPhysicsComponent>();
		if (component) {
			
			auto sComponent = m_owner->GetComponent<SpriteComponent>();
			if (sComponent) {
				if (data.size.x == 0 && data.size.y == 0) {
					data.size = vec2{ sComponent->source.w, sComponent->source.h };
				}
				data.offset = sComponent->origin - vec2{ 0.5f, 0.5f };
			}
			
			data.size = data.size * scaleOffset * m_owner->transform.scale;

			if (component->m_body->GetType() == b2_staticBody) {
				PhysicsSystem::Instance().SetCollisionBoxStatic(component->m_body, data, m_owner);
			}
			else {
				PhysicsSystem::Instance().SetCollisionBox(component->m_body, data, m_owner);
			}
		}

		return true;
	}

	void Box2DCollisionComponent::Update(float dt) {
		
	}

	void Box2DCollisionComponent::Read(const json_t& value) {
		READ_NAME_DATA(value, "size", data.size);
		READ_NAME_DATA(value, "density", data.density);
		READ_NAME_DATA(value, "friction", data.friction);
		READ_NAME_DATA(value, "restitution", data.restitution);
		READ_NAME_DATA(value, "isTrigger", data.isTrigger);

		READ_DATA(value, scaleOffset);
	}
}
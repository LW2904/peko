#pragma once

#include "common.h"

namespace sdk {
	using namespace hazedumper::netvars;
	using namespace hazedumper::signatures;

	// TODO: This belongs in a utils namespace or something.
	template<typename T>
	inline T get_virtual(void *base, unsigned int index) {
		return reinterpret_cast<T>((*reinterpret_cast<int **>(base))[index]);
	}

	class base_client_dll;
	class client_entity_list;
	class engine_client;

	// Credit for c_base_player and c_base_attributable_item:
	// https://aixxe.net/2016/09/linux-skin-changer

	class c_base_player {
	public:
		unsigned char get_life_state() {
			return *(unsigned char *)((uintptr_t)this + m_lifeState);
		}

		int *get_weapons() {
			return (int *)((uintptr_t)this + m_hMyWeapons);
		}
	};

	class c_base_attributable_item {
	public:
		int *get_item_definition_index() {
			return (int *)((uintptr_t)(this + m_AttributeManager + m_Item +
				m_iItemDefinitionIndex));
		}

		int *get_item_id_high() {
			return (int *)((uintptr_t)(this + m_AttributeManager + m_Item +
				m_iItemIDHigh));
		}

		int *get_entity_quality() {
			return (int *)((uintptr_t)(this + m_AttributeManager + m_Item +
				m_iEntityQuality));
		}

		char *get_custom_name() {
			return (char *)((uintptr_t)(this + m_AttributeManager + m_Item +
				m_szCustomName));
		}

		int *get_fallback_paint_kit() {
			return (int *)((uintptr_t)
				this + m_nFallbackPaintKit);
		}

		int *get_fallback_seed() {
			return (int *)((uintptr_t)
				this + m_nFallbackSeed);
		}

		float *get_fallback_wear() {
			return (float *)((uintptr_t)
				this + m_flFallbackWear);
		}

		int *get_fallback_stat_trak() {
			return (int *)((uintptr_t)
				this + m_nFallbackStatTrak);
		}
	};
}

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
	class client_mode;

	// Credit for c_base_player and c_base_attributable_item:
	// https://aixxe.net/2016/09/linux-skin-changer

	class c_base_player {
	public:
		unsigned char get_life_state() {
			return *(unsigned char *)((uintptr_t)this + m_lifeState);
		}

		int get_health() {
			return *(int *)((uintptr_t)this + m_iHealth);
		}

		int *get_weapons() {
			return (int *)((uintptr_t)this + m_hMyWeapons);
		}

		int get_flags() {
			return *(int *)((uintptr_t)this + m_fFlags);
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

	enum cmd_buttons {
		IN_ATTACK = (1 << 0),
		IN_JUMP = (1 << 1),
		IN_DUCK = (1 << 2),
		IN_FORWARD = (1 << 3),
		IN_BACK = (1 << 4),
		IN_USE = (1 << 5),
		IN_CANCEL = (1 << 6),
		IN_LEFT = (1 << 7),
		IN_RIGHT = (1 << 8),
		IN_MOVELEFT = (1 << 9),
		IN_MOVERIGHT = (1 << 10),
		IN_ATTACK2 = (1 << 11),
		IN_RUN = (1 << 12),
		IN_RELOAD = (1 << 13),
		IN_ALT1 = (1 << 14),
		IN_ALT2 = (1 << 15),
		IN_SCORE = (1 << 16),
		IN_SPEED = (1 << 17),
		IN_WALK = (1 << 18),
		IN_ZOOM = (1 << 19),
		IN_WEAPON1 = (1 << 20),
		IN_WEAPON2 = (1 << 21),
		IN_BULLRUSH = (1 << 22),
		IN_GRENADE1 = (1 << 23),
		IN_GRENADE2 = (1 << 24),
		IN_ATTACK3 = (1 << 25)
	};

	struct c_usercmd {
		int pad;
		int command_number;
		int tick_count;
		float pad0;
		float pad1;
		float pad2;
		float pad3;
		float pad4;
		float pad5;
		float forwardmove;
		float sidemove;
		float upmove;
		int buttons;
		char impulse;
		int weaponselect;
		int weaponsubtype;
		int randomseed;
		short mousedx;
		short mousedy;
		bool hasbeenpredicted;
	};
}

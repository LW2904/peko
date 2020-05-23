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
		in_attack = (1 << 0),
		in_jump = (1 << 1),
		in_duck = (1 << 2),
		in_forward = (1 << 3),
		in_back = (1 << 4),
		in_use = (1 << 5),
		in_cancel = (1 << 6),
		in_left = (1 << 7),
		in_right = (1 << 8),
		in_moveleft = (1 << 9),
		in_moveright = (1 << 10),
		in_attack2 = (1 << 11),
		in_run = (1 << 12),
		in_reload = (1 << 13),
		in_alt1 = (1 << 14),
		in_alt2 = (1 << 15),
		in_score = (1 << 16),
		in_speed = (1 << 17),
		in_walk = (1 << 18),
		in_zoom = (1 << 19),
		in_weapon1 = (1 << 20),
		in_weapon2 = (1 << 21),
		in_bullrush = (1 << 22),
		in_grenade1 = (1 << 23),
		in_grenade2 = (1 << 24),
		in_attack3 = (1 << 25)
	};

	struct c_usercmd {
		int pad;
		int command_number;
		int tick_count;
		float p0;
		float p1;
		float p2;
		float p3;
		float p4;
		float p5;
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

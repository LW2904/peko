#pragma once

#include "common.h"

#include "sdk/sdk.h"

namespace glow {
	inline bool enabled = false;

	constexpr int END_OF_FREE_LIST = -1;
	constexpr int ENTRY_IN_USE = -2;

	template<class T, class I = int>
	class utl_memory {
	public:
		T &operator[](int i) {
			return memory[i];
		};

		T *memory;
		int allocation_count;
		int grow_size;
	};

	template<class T, class A = utl_memory<T>>
	class utl_vector {
	public:
		T &operator[](int i) {
			return memory[i];
		};

		A memory;
		int size;
		T *elements;
	};

	struct glow_object_definition {
		// Actually a C_BaseEntity *
		void *entity;

		// Vector m_vGlowColor;
		float r;
		float g;
		float b;

		float glow_alpha;
		char pad0[8];
		float bloom_amount;
		char pad1[4];
		bool render_when_occluded;
		bool render_when_unoccluded;
		bool full_bloom_render;
		char pad2;
		int full_bloom_stencil_test_value;
		char pad3[4];
		int split_screen_slot;
		int next_free_slot;
	};

	class glow_object_manager {
	public:
		utl_vector<glow_object_definition> glow_object_definitions;
		int first_free_slot;
	};

	void hook();
}

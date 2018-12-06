#ifndef ALLOCATION_BLOCK_HPP
#define ALLOCATION_BLOCK_HPP

#include <cstdlib>
#include <iostream>
#include "queue.hpp"

class AllocationBlock
{
	public:
		AllocationBlock(size_t size, size_t count);

		void *allocate();
		void deallocate(void *ptr);
		bool has_free_blocks();

		virtual ~AllocationBlock();

	private:
		size_t m_size, m_count, free_count;
		char *used_blocks;
		Queue<void*> free_blocks;
};

#endif

#include "allocation_block.hpp"

AllocationBlock::AllocationBlock(size_t size, size_t count): m_size{size}, m_count{count}
{
	used_blocks = (char*)malloc(m_size * m_count);

	for(size_t i = 0; i < m_count; ++i)
		free_blocks.push(std::make_shared<void*> (used_blocks + i * m_size));

	free_count = m_count;
}

void *AllocationBlock::allocate()
{
	void *result = nullptr;

	if(free_count > 0)
	{
		result = *free_blocks.pop();
		--free_count;
		std::cout << "Выделено памяти: " << m_count - free_count << " из " << m_count << std::endl;
	}
	else
	{
		std::cout << "Не удалось выделить память" << std::endl;
	}

	return result;
}

void AllocationBlock::deallocate(void *ptr)
{
	std::cout << "Память перераспределена" << std::endl;
	free_blocks.push(std::make_shared<void*> (ptr));
	free_count++;
}

bool AllocationBlock::has_free_blocks()
{
	return free_count > 0;
}

AllocationBlock::~AllocationBlock()
{
	if(free_count < m_count) std::cout << "Утечка памяти" << std::endl;
	else std::cout << "Память освобождена" << std::endl;

	delete used_blocks;
}

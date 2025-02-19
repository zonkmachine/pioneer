// Copyright © 2008-2025 Pioneer Developers. See AUTHORS.txt for details
// Licensed under the terms of the GPL v3. See licenses/GPL-3.txt

#pragma once

#include "graphics/Types.h"
#include "graphics/UniformBuffer.h"

#include <memory>

namespace Graphics {
	namespace Dummy {

		class UniformBuffer final : public Graphics::UniformBuffer {
		public:
			UniformBuffer(uint32_t size, BufferUsage usage) :
				Graphics::UniformBuffer(size, usage),
				m_data(new uint8_t[size])
			{}
			~UniformBuffer() override {}

			void Unmap() override {}
			void BufferData(const size_t, void *) override {}

		private:
			void *MapInternal(BufferMapMode) override { return m_data.get(); }
			std::unique_ptr<uint8_t[]> m_data;
		};

	} // namespace Dummy
} // namespace Graphics

/*
Copyright(c) 2016 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//= INCLUDES ===================
#include <vector>
#include "../Graphics/Texture.h"
///=============================

class TexturePool
{
public:
	TexturePool();
	~TexturePool();

	Texture* Add(Texture* texture);
	Texture* Add(const std::string& texturePath, TextureType textureType);
	void Add(std::vector<std::string> filePaths);

	Texture* GetTextureByName(const std::string& name);
	Texture* GetTextureByID(const std::string& ID);
	Texture* GetTextureByPath(const std::string& path);
	void GetAllTextureFilePaths(std::vector<std::string>& paths);

	void RemoveTextureByPath(const std::string& path);
	void Clear();

private:
	std::vector<Texture*> m_textures;

	/*------------------------------------------------------------------------------
							[HELPER FUNCTIONS]
	------------------------------------------------------------------------------*/
	int GetTextureIndex(Texture* texture);
};

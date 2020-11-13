#ifndef __ModuleAssetImporter_H__
#define __ModuleAssetImporter_H__

#include "Module.h"
#include "Globals.h"
#include "Libs/DevIL/include/IL/il.h"
#include "vector3.h"

class GameObject;

class Mesh
{
public:
	Mesh() {};
	~Mesh() {};
public:

	char* name = nullptr;
	uint id_index = 0; // index in VRAM
	uint num_index = 0;
	uint* index = nullptr;
	uint id_vertex = 0; // unique vertex in VRAM
	uint num_vertex = 0;
	vec3* vertex = nullptr;
	uint id_tex_coord = 0;
	float* tex_coord = nullptr;

	bool hasNormals = false;
	vec3* normals = nullptr;

	bool isSelected = false;

	uint textureNumber = 999;

	vec3 position = { 0,0,0 }; 
	vec3 rotation = { 0,0,0 };
	float scale = 1.0f;

	bool isDrawEnabled = true;
	bool isFaceNormalsEnabled = false;
	bool isVertexNormalsEnabled = false;

	const char* path = nullptr;

};

class Texture
{
public:
	uint GetId() { return id; }
public:
	const char* path = nullptr;
	char* name = nullptr;
	uint id;
	uint w;
	uint h;

	uint textureIterator;
};

class ModuleAssetImporter : public Module
{
public:
	ModuleAssetImporter(Application* app, bool start_enabled = true);
	~ModuleAssetImporter();

	bool Init();
	bool Start();
	bool CleanUp();

	Texture* LoadTexture(const char* path);

	GameObject* Load(const char* path);

public:

	Texture* defaultTexture = nullptr;
	Texture* houseTexture = nullptr;
	std::list<Texture*> textureList;

	int textureIterator = 1;
	int meshIterator = 0;

};

#endif // __ModuleAssetImporter_H__
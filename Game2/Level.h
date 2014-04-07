#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "GameObject.h"
#include <fstream>
#include "Box.h"
#include "Player.h"
#include "Enemy.h"
#include "Wall.h"
//#include "Tower"


using std::vector;

class Level {
private:
public:
	vector<Wall> walls;
	vector<Enemy*> enemies;
	vector<Light> spotLights;
private:
	//vector<Tower> towers;

	//vector<Part> parts;

	int enlargeByC;
	Vector3 levelDimensions;
	Vector3 playerLoc;
	Vector3 exitLoc;
	Player* player;
	ID3D10Device* md3dDevice;
	ID3D10EffectTechnique* mTech;
	ID3D10EffectMatrixVariable* mfxWVPVar;
	ID3D10EffectMatrixVariable* mfxWorldVar;
	ID3D10EffectShaderResourceVariable* diffuseMapVar;
public:
	Level();
	Level(ID3D10Device* device); 

	void fillLevel(string s);
	void update(float dt);
	void draw(Matrix mVP);
	void setMTech(ID3D10EffectTechnique* tech) { mTech = tech; }
	void setEffectVariables(ID3D10EffectMatrixVariable* wvpVar, ID3D10EffectMatrixVariable* worldVar);
	void setDiffuseMap(ID3D10EffectShaderResourceVariable* var);





};



#endif
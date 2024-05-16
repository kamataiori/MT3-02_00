#pragma once
#include "imgui.h"
#include "MathFunctions.h"
#include "struct.h"

static const int kWindowWidth = 1280;
static const int kWindowHeight = 720;

class Result
{
public:

	Vector3 cameraTranslate{};
	Vector3 cameraRotate{};
	Vector3 rotate{};
	Vector3 translate{};
	Vector3 cameraPosition{};
	Matrix4x4 worldMatrix{};
	Matrix4x4 cameraMatrix{};
	Matrix4x4 viewMatrix{};
	Matrix4x4 projectionMatrix{};
	Matrix4x4 worldviewProjectionMatrix{};
	Matrix4x4 viewportMatrix{};
	Sphere sphere{};
	Sphere sphere2{};
	//float distance{};
	Segment segment{};
	Vector3 point{};
	Vector3 project{};
	Vector3 closestPoint{};
	Sphere pointSphere{};
	Sphere closestPointSphere{};

	Result();

	void Initialize();

	void Updata();

	void Draw();

};




#pragma once
#include "Vector2.h"
#include "Vector3.h"

typedef struct Matrix2x2
{
	float m[2][2];
}Matrix2x2;

typedef struct Matrix3x3
{
	float m[3][3];
}Matrix3x3;

typedef struct Matrix4x4
{
	float m[4][4];
}Matrix4x4;

//Transform
struct Transform {
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};

struct Sphere {
	Vector3 center;
	float radius;
};

struct Line {
	Vector3 origin;  //始点
	Vector3 diff;  //終点への差分ベクトル
};

struct Ray
{
	Vector3 origin;  //始点
	Vector3 diff;  //終点への差分ベクトル
};

struct Segment
{
	Vector3 origin;  //始点
	Vector3 diff;  //終点への差分ベクトル
}; 
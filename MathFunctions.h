#pragma once
#define _USE_MATH_DEFINES
#include <struct.h>
#include <assert.h>
#include <Novice.h>
#include <cmath>
#include <math.h>
#include <objidl.h>
#include <corecrt_math.h>


//逆行列
Matrix4x4 Inverse(const Matrix4x4& matrix);

//座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

//1. X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);

//2. Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);

//3. Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

Matrix4x4  Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// アフィン変換行列計算関数
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

//1.透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

//2.正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

//3.ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

//グリッド
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

//球
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

// 円（球）の衝突判定関数
bool isColliding(const Sphere& c1, const Sphere& c2);

// 線形補間関数の定義
Vector3 lerp(const Vector3& a, const Vector3& b, float t);

Vector3 Project(const Vector3& v1, const Vector3& v2);

Vector3 ClosestPoint(const Vector3& point, const Vector3& segment);

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

Vector3 Subtract(const Vector3& v1, const Vector3& v2);
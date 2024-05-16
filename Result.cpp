#include "Result.h"

Result::Result()
{
}

void Result::Initialize()
{
	cameraTranslate = { 0.0f,1.9f,-6.49f };
	cameraRotate = { 0.26f,0.0f,0.0f };
	rotate = {};
	translate = {};
	worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
	cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	viewMatrix = Inverse(cameraMatrix);
	projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	worldviewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
	sphere.center.x = 0;
	sphere.center.y = 0;
	sphere.center.z = 0;
	sphere.radius = 0.5f;
	sphere2.center.x = 0;
	sphere2.center.y = 0;
	sphere2.center.z = 0;
	sphere2.radius = 0.8f;
	//distance = isColliding(sphere, sphere2);
	Segment segment1 = { {-2.0f,-1.0f,0.0f},{3.0f,2.0f,2.0f} };
	Vector3 point1{ -1.5f,0.6f,0.6f };
	Vector3 project1 = Project(Subtract(point1, segment1.origin), segment1.diff);
	Vector3 closestPoint1 = ClosestPoint(point1, segment1.diff);
	Sphere pointSphere1{ point1,0.01f };
	Sphere closestPointSphere1{ closestPoint1,0.01f };
	
}

void Result::Updata()
{

}

void Result::Draw()
{

	DrawGrid(worldviewProjectionMatrix, viewportMatrix);
	DrawSphere(pointSphere1, worldviewProjectionMatrix, viewportMatrix, RED);
	DrawSphere(closestPointSphere1, worldviewProjectionMatrix, viewportMatrix, BLACK);
	
	//線分の描画
	Vector3 start = Transform(Transform(segment1.origin, worldviewProjectionMatrix), viewportMatrix);
	Vector3 end = Transform(Transform(Add(segment1.origin, segment1.diff), viewportMatrix),viewportMatrix);
	Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), WHITE);

	
	//ImGui
	ImGui::Begin("Window");
	ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
	ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
	ImGui::DragFloat3("SphereTranslate", &sphere.center.x, 0.01f);
	ImGui::DragFloat("SphereRadius", &sphere.radius, 0.01f);

	ImGui::DragFloat3("Sphere2Translate", &sphere2.center.x, 0.01f);
	ImGui::DragFloat("Sphere2Radius", &sphere2.radius, 0.01f);
	ImGui::End();

}


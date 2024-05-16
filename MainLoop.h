#pragma once
#include <Novice.h>

const char kWindowTitle[] = "学籍番号";

class MainLoop {

private:

	//// キー入力結果を受け取る箱
	char keys[256];
	char preKeys[256];

public:

	MainLoop();

	~MainLoop();

	/// 
	/// キー入力を受け取る
	/// 
	void InPut();

	/// 
	/// 更新処理
	/// 
	void Updata();

	///
	/// 描画処理
	///
	void Draw();

	///
	/// 全体のループ
	/// 
	void WholeLoop();
};



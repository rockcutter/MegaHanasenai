﻿#pragma once
#include <Siv3D.hpp>
#include "ToggleButton.h"
#include "IconTemplate.h"
// 上部のメニュー

extern User me;

class Header {
private:
	int32 txidx = me.iconIndex;
	String name = Unicode::Widen(me.name);
	Texture img;
	ToggleButton microphone;
	ToggleButton headphone;
	int32 radius = 25;
	int32 height = 60;
	ColorF bgColor = ColorF(0.3, 0.1, 1.0);
	Circle circle = Circle(0, 0, radius).movedBy(height / 2, height / 2);
	Font font = Font(30);
	RectF namearea;
public:

	// コンストラクタ
	const Header()
	{
		IconTemplate::Init();
		img = IconTemplate::textures[me.iconIndex % IconTemplate::textures.size()];
		microphone = ToggleButton(0xf130, height / 2 * 3, height / 2, radius);
		headphone = ToggleButton(0xf028, height / 2 * 5, height / 2, radius);
		//headphone = ToggleButton(0xf6a8, height / 2 * 5, height / 2, radius);
	}

	// 毎フレームの更新
	void update(const bool& sIn, const bool& sOut)
	{
		circle = Circle(0, 0, radius).movedBy(height / 2, height / 2);

		// アイコンの設定
		microphone.update(sIn);
		headphone.update(sOut);

		// 名前表示部分のRect
		namearea = font(name).region(
			Arg::leftCenter = Point(height * 3 + 10, height / 2)
		);
	}

	bool nameLeftClicked() {
		return namearea.leftClicked();
	}

	bool update_sIn () {
		return microphone.leftClicked();
	}

	bool update_sOut() {
		return headphone.leftClicked();
	}

	// 描画
	void draw() const
	{
		Rect(
			Arg::center = Point(Scene::Center().x, height / 2),
			Scene::Width(), height
		).draw(bgColor);

		// ユーザのアイコンを描画
		circle.draw();
		circle(img(85, 0, 120, 120)).draw();
		microphone.draw();
		headphone.draw();
		font(name).draw(Arg::leftCenter = Point(height * 3 + 10, height / 2), Palette::White);
	}
};

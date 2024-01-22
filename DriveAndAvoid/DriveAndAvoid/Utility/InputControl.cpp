#include "InputControl.h"
#include "DxLib.h"

//静的メンバ変数定義
bool InputControl::now_button[16] = {};
bool InputControl::old_button[16] = {};
float InputControl::trigger[2] = {};
Vector2D InputControl::stick[2] = {};

//入力機能::更新処理
void InputControl::Update()
{
	//XInputコントローラーの入力値を取得する
	XINPUT_STATE input_state = {};
	GetJoypadXInputState(DX_INPUT_PAD1, &input_state);

	//ボタン入力値の更新
	for (int i = 0; i < 16; i++)
	{
		old_button[i] = now_button[i];
		now_button[i] = (bool)input_state.Buttons[i];
	}

	//トリガー入力値の更新
	trigger[0] = (float)input_state.LeftTrigger / (float)UCHAR_MAX;
	trigger[1] = (float)input_state.RightTrigger / (float)UCHAR_MAX;

	//左スティック入力値の更新（-1.0f～1.0fに範囲を制限する）
	if (input_state.ThumbLX > 0.0f)
	{
		stick[0].x = (float)input_state.ThumbLX / (float)SHRT_MAX;
	}
	else
	{
		stick[0].x = -((float)input_state.ThumbLX / (float)SHRT_MIN);
	}

	if (input_state.ThumbLY > 0.0f)
	{
		stick[0].y
	}
}

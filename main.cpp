/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
//�ȈՃ^�C�}�[

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"

//########## �}�N����` ##########
#define GAME_WIDTH	800	//��ʂ̉��̑傫��
#define GAME_HEIGHT	600	//��ʂ̏c�̑傫��
#define GAME_COLOR	32	//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_BAR	0	//�^�C�g���o�[�̓f�t�H���g�ɂ���
#define GAME_WINDOW_NAME	"GAME TITLE"	//�E�B���h�E�̃^�C�g��

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);						//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//�w��̐��l�ŃE�B���h�E��\������
	SetWindowStyleMode(GAME_WINDOW_BAR);		//�^�C�g���o�[�̓f�t�H���g�ɂ���
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));	//�E�B���h�E�̃^�C�g���̕���
	SetAlwaysRunFlag(TRUE);						//��A�N�e�B�u�ł����s����

	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������

	int DrawX = 0;	//�\���ʒuX
	int DrawY = 0;	//�\���ʒuY
	int time, time_2 = 0;

	SetDrawScreen(DX_SCREEN_BACK);	//Draw�n�֐��͗���ʂɕ`��
	time = GetNowCount();

	//�������[�v(6�b��������I��)
	while ((time_2 - time) < 6000)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��
		//DrawFormatString(0, 100, GetColor(255, 255, 255), "�����オ���Ă���%d�~���b", time);

		time_2 = GetNowCount();
		DrawFormatString(0, 100, GetColor(255, 255, 255), "�� %d�b", (time_2 - time) / 1000);
		DrawString(DrawX, DrawY, "Hello World", GetColor(255, 255, 255));	//������`��

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��
	}
	DxLib_End();	//�c�w���C�u�����g�p�̏I������

	return 0;
}
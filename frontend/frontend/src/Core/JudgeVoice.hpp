#pragma once

#include <Siv3D.hpp>

//JudgeVoice::judgetype ���f��̒�`
#define AVE_AMP 0x1     //�U���̕���
#define PITCH 0x2
#define L_PITCH 0x4
#define L_AVE_AMP 0x8

class JudgeVoice {
public:
	JudgeVoice(int type_ = AVE_AMP);
	void SetThre(int type_, double thre_);
	void SetType(int type_);
	bool Judge(Microphone mic);
	double GetAveAmp(FFTResult fft);
	double GetPitch(FFTResult fft);
	double GetAmpThre() {
		return amp_thre;
	};
	double GetPitchThre() {
		return pitch_thre;
	};
	int GetType() {
		return judgetype;
	};
private:
	bool JudgeforAveAmp(FFTResult fft);
	bool JudgeforPitch(FFTResult fft);
	int judgetype; //���f�
	double amp_thre;
	double pitch_thre;
};

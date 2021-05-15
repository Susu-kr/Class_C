#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
float Calc_Angle(int hour, int min, int sec);

int main(void) {
	int h, m, s;
	printf("�ð��� �Է��ϼ��� (??�� ??�� ??��) : ");
	scanf("%d%d%d", &h, &m, &s);
	float Angle = Calc_Angle(h, m, s);
	printf("��ħ�� ��ħ�� ���� : %.4lf��", Angle);
	return 0;
}

float Calc_Angle(int hour, int min, int sec) {
	// 1 ~ 12 -> 1�ð��� 30��, 5�д� 30��, 5�ʴ� 30��
	// ��ħ�� -> 10�д� 5�� -> 1�д� 0.5�� -> 60�ʴ� 0.5�� -> 10�ʴ� 0.08333�� -> 1�ʴ� 0.008333��
	// ��ħ�� -> 5�д� 30�� -> 1�д� 6�� -> 60�ʴ� 6�� -> 10�ʴ� 1�� -> 1�ʴ� 0.1��
	float h_angle, m_angle;
	int h = hour;
	if (h > 12) h %= 12;
	h_angle = (float)h * 30.0 + (float)min * 0.5 + (float)sec / 120; 
	m_angle = (float)min * 6.0 + (float)sec * 0.1;
	printf("��ħ�� ���� : %.4lf\n", h_angle);
	printf("��ħ�� ���� : %.4lf\n", m_angle);

	return h_angle > m_angle ? h_angle - m_angle : m_angle - h_angle;
}
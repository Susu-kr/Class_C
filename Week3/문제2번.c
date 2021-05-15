#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
float Calc_Angle(int hour, int min, int sec);

int main(void) {
	int h, m, s;
	printf("시간을 입력하세요 (??시 ??분 ??초) : ");
	scanf("%d%d%d", &h, &m, &s);
	float Angle = Calc_Angle(h, m, s);
	printf("시침과 분침의 각은 : %.4lf도", Angle);
	return 0;
}

float Calc_Angle(int hour, int min, int sec) {
	// 1 ~ 12 -> 1시간당 30도, 5분당 30도, 5초당 30도
	// 시침은 -> 10분당 5도 -> 1분당 0.5도 -> 60초당 0.5도 -> 10초당 0.08333도 -> 1초당 0.008333도
	// 분침은 -> 5분당 30도 -> 1분당 6도 -> 60초당 6도 -> 10초당 1도 -> 1초당 0.1도
	float h_angle, m_angle;
	int h = hour;
	if (h > 12) h %= 12;
	h_angle = (float)h * 30.0 + (float)min * 0.5 + (float)sec / 120; 
	m_angle = (float)min * 6.0 + (float)sec * 0.1;
	printf("시침의 각도 : %.4lf\n", h_angle);
	printf("분침의 각도 : %.4lf\n", m_angle);

	return h_angle > m_angle ? h_angle - m_angle : m_angle - h_angle;
}
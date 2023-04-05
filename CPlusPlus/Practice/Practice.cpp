#include <iostream>
#include "Bullet.h"


int main()
{
	for (int i = 0; i < Bullet::ArrBulletCount; i++)
	{
		Bullet::GetArrBullet()->ValueSetting(i, i);
		printf_s("%d\n", Bullet::GetArrBullet()->GetValue(i));
	}


	int a = 0;
}




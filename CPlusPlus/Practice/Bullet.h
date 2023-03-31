#pragma once

class Bullet
{
public:
	static const int ArrBulletCount = 30;

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	void ValueSetting(int _index, int _Value)
	{
		ArrBullet[_index].Value = _Value;
	}

	int GetValue(int _index)
	{
		return ArrBullet[_index].Value;
	}

protected:

private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();

	int Value = 0;
};

